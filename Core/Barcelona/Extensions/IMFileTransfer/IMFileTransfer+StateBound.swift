//
//  IMFileTransfer+StateBound.swift
//  Barcelona
//
//  Created by Eric Rabil on 8/10/21.
//  Copyright © 2021 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore

public extension IMFileTransfer {
    enum IMFileTransferState: NSInteger {
        case archiving = -1
        case waitingForAccept = 0
        case accepted = 1
        case preparing = 2
        case transferring = 3
        case finalizing = 4
        case finished = 5
        case error = 6
        case recoverableError = 7
        case unknown
        
        fileprivate init(transfer: IMFileTransfer) {
            self = .init(rawValue: transfer.value(forKey: "transferState") as! NSInteger) ?? .unknown
        }
    }
    
    var state: IMFileTransferState {
        IMFileTransferState(transfer: self)
    }
}