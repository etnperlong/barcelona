//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <LinkPresentation/LPSpecializationMetadata.h>

#import "LPLinkMetadataBackwardCompatibility.h"
#import "LPLinkMetadataPresentationTransformer.h"
#import "LPLinkMetadataPreviewTransformer.h"

@class NSDate, NSString;

@interface LPWalletPassMetadata : LPSpecializationMetadata <LPLinkMetadataPreviewTransformer, LPLinkMetadataBackwardCompatibility>
{
    NSString *_name;
    long long _style;
    NSDate *_eventDate;
    NSDate *_expirationDate;
}

+ (id)keyPathsForValuesAffecting_dummyPropertyForObservation;
+ (BOOL)supportsSecureCoding;

@property(retain, nonatomic) NSDate *expirationDate; // @synthesize expirationDate=_expirationDate;
@property(retain, nonatomic) NSDate *eventDate; // @synthesize eventDate=_eventDate;
@property(nonatomic) long long style; // @synthesize style=_style;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(readonly) unsigned long hash;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)populateMetadataForBackwardCompatibility:(id)arg1;
- (id)previewImageForTransformer:(id)arg1;
- (id)previewSummaryForTransformer:(id)arg1;
- (BOOL)canGeneratePresentationPropertiesForURL:(id)arg1;
- (id)presentationPropertiesForTransformer:(id)arg1;
- (id)_subtitle;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

