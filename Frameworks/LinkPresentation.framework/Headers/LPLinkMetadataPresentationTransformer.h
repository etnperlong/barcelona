//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class LPWebLinkPresentationProperties, NSURL, LPLinkMetadata;

@interface LPLinkMetadataPresentationTransformer : NSObject
{
    _Bool _complete;
    _Bool _allowsTapToLoad;
    LPLinkMetadata *_metadata;
    NSURL *_URL;
    unsigned long long _preferredSizeClass;
    LPImage *_sourceContextIcon;
    NSString *_sourceBundleIdentifier;
    double _scaleFactor;
}

@property(nonatomic) double scaleFactor; // @synthesize scaleFactor=_scaleFactor;
@property(copy, nonatomic) NSString *sourceBundleIdentifier; // @synthesize sourceBundleIdentifier=_sourceBundleIdentifier;
@property(retain, nonatomic) LPImage *sourceContextIcon; // @synthesize sourceContextIcon=_sourceContextIcon;
@property(nonatomic) unsigned long long preferredSizeClass; // @synthesize preferredSizeClass=_preferredSizeClass;
@property(nonatomic) _Bool allowsTapToLoad; // @synthesize allowsTapToLoad=_allowsTapToLoad;
@property(nonatomic, getter=isComplete) _Bool complete; // @synthesize complete=_complete;
@property(copy, nonatomic) NSURL *URL; // @synthesize URL=_URL;
@property(copy, nonatomic) LPLinkMetadata *metadata; // @synthesize metadata=_metadata;
- (void)_populateProperties:(id)arg1 withPrimaryIcon:(id)arg2 iconProperties:(id)arg3;
- (void)_populateProperties:(id)arg1 withPrimaryIcon:(id)arg2;
- (void)_populateProperties:(id)arg1 withPrimaryImage:(id)arg2;
- (_Bool)_prefersLeadingIconWithStyle:(long long)arg1;
- (_Bool)_prefersImageAsIconWithStyle:(long long)arg1;
- (_Bool)_prefersIconAsImage;
- (unsigned long long)_rowConfiguration;
@property(readonly, nonatomic) _Bool hasMedia;
- (id)presentationProperties;
- (id)unspecializedPresentationPropertiesForStyle:(long long)arg1;
- (id)unspecializedPresentationProperties;
- (id)commonPresentationPropertiesForStyle:(long long)arg1;
- (id)backgroundColorForStyle:(long long)arg1;
- (id)audioForStyle:(long long)arg1;
- (id)videoForStyle:(long long)arg1;
- (id)imageForStyle:(long long)arg1 icon:(id *)arg2 alternateImages:(id *)arg3;
- (id)quotedTextForStyle:(long long)arg1;
- (id)subtitleForStyle:(long long)arg1;
- (id)titleForStyle:(long long)arg1;
- (id)mainCaptionBarForStyle:(long long)arg1;
- (long long)rendererStyle;
@property(readonly, copy, nonatomic) NSURL *canonicalURL;
@property(readonly, copy, nonatomic) NSURL *originalURL;
- (id)init;

@end
