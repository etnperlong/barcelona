//
//  Attachment.swift
//  CoreBarcelona
//
//  Created by Eric Rabil on 9/11/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import BarcelonaDB
import CoreGraphics
import IMCore

public struct Size: Codable, Hashable {
    public var width: Float
    public var height: Float
    
    public init(cgSize: CGSize) {
        width = abs(Float(cgSize.width))
        height = abs(Float(cgSize.height))
    }
    
    public init(width: CGFloat, height: CGFloat) {
        self.width = abs(Float(width))
        self.height = abs(Float(height))
    }
}

public extension IMFileTransfer {
    @_transparent private var compatibilityGUIDKey: String {
        "__kIMFileTransferCompatibilityGUIDKey"
    }
    
    private func setCompatibilityGUID(_ guid: String) {
        objc_setAssociatedObject(self, compatibilityGUIDKey, guid, .OBJC_ASSOCIATION_COPY_NONATOMIC)
    }
    
    /// A fake GUID created in place of a real GUID. This is constant for the lifetime of this instance. This is a shim, and will result in strange behavior.
    private var compatibilityGUID: String {
        get {
            if let guid = objc_getAssociatedObject(self, compatibilityGUIDKey) as? String {
                return guid
            }
            let guid = UUID().uuidString
            setCompatibilityGUID(guid)
            return guid
        }
        set {
            setCompatibilityGUID(newValue)
        }
    }
    
    /// A non-nil GUID which will more than likely be true to the underlying transfer.
    var assertedGUID: String {
        if let guid = guid {
            return guid
        } else {
            CLFault("IMFileTransfer+Barcelona", "Encountered an IMFileTransfer with no GUID. Returning a fake GUID for compatibility.")
            return compatibilityGUIDKey
        }
    }
}

public struct Attachment: Codable, Hashable {
    public init(mime: String? = nil, filename: String, id: String, uti: String? = nil, origin: ResourceOrigin? = nil, size: Size? = nil, sticker: StickerInformation? = nil) {
        self.mime = mime
        self.filename = filename
        self.id = id
        self.uti = uti
        self.origin = origin
        self.size = size
        self.sticker = sticker
    }
    
    public init(_ transfer: IMFileTransfer) {
        transfer.ensureLocalPath()
        
        mime = transfer.mimeType
        filename = transfer.filename
        id = transfer.assertedGUID
        uti = transfer.type
        size = transfer.mediaSize
        
        if transfer.isSticker {
            sticker = StickerInformation(transfer.stickerUserInfo)
        } else {
            sticker = nil
        }
    }
    
    public init?(guid: String) {
        guard let item = IMFileTransferCenter.sharedInstance().transfer(forGUID: guid, includeRemoved: false), item.ensuredLocalPath != nil else {
            return nil
        }
        
        self.init(item)
    }
    
    public var mime: String?
    public var filename: String
    public var id: String
    public var originalGUID: String?
    public var uti: String?
    public var origin: ResourceOrigin?
    public var size: Size?
    public var sticker: StickerInformation?
    
    public var name: String {
        filename
    }
    
    public var existingFileTransfer: IMFileTransfer? {
        BLLoadFileTransfer(withGUID: id)
    }
    
    public var path: String? {
        existingFileTransfer?.localPath
    }
    
    public var url: URL? {
        path.map(URL.init(fileURLWithPath:))
    }
    
    @discardableResult
    public func initializeFileTransferIfNeeded() -> IMFileTransfer? {
        if let transfer = existingFileTransfer {
            return transfer
        } else if let url = url {
            return CBInitializeFileTransfer(filename: filename, path: url)
        } else {
            return nil
        }
    }
}
