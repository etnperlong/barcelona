//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <LinkPresentation/LPSpecializationMetadata.h>

#import "LPLinkMetadataPresentationTransformer.h"

@class NSString;

@interface LPSummarizedLinkMetadata : LPSpecializationMetadata
{
}

+ (id)keyPathsForValuesAffecting_dummyPropertyForObservation;
+ (BOOL)supportsSecureCoding;
@property(readonly) unsigned long hash;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (BOOL)canGeneratePresentationPropertiesForURL:(id)arg1;
- (id)presentationPropertiesForTransformer:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

