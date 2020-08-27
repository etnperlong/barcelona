//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <CoreUI/CUIThemeRendition.h>

@class CUIPSDGradient, NSDictionary;

@interface CUIThemeSchemaRendition : CUIThemeRendition
{
    NSDictionary *cuiInfo;
    unsigned long long _nimages;
    struct CGImage *_image[9];
    struct CGRect _layoutRects[9];
    struct CGSize _intrinsicSize;
    struct CGRect _elementRect;
    long long _columnSlices;
    long long _rowSlices;

    CUIPSDGradient *_gradient;
}

- (id)scaleLocalizedString;
- (id)lookLocalizedString;
- (id)drawingLayerLocalizedString;
- (id)dimension2LocalizedString;
- (id)dimension1LocalizedString;
- (id)presentationStateLocalizedString;
- (id)sizeLocalizedString;
- (id)previousValueLocalizedString;
- (id)valueLocalizedString;
- (id)stringForValue:(unsigned short)arg1;
- (id)directionLocalizedString;
- (id)previousStateLocalizedString;
- (id)stateLocalizedString;
- (id)stringForState:(unsigned short)arg1;
- (id)typeLocalizedString;
- (id)description;
- (unsigned short)localization;
- (unsigned short)appearance;
- (unsigned short)layer;
- (unsigned short)identifier;
- (unsigned short)keyScale;
- (unsigned short)look;
- (unsigned short)drawingLayer;
- (unsigned short)dimension2;
- (unsigned short)dimension1;
- (unsigned short)size;
- (unsigned short)previousValue;
- (unsigned short)value;
- (unsigned short)direction;
- (unsigned short)presentationState;
- (unsigned short)previousState;
- (unsigned short)state;
- (struct CGPoint)renditionCoordinatesForPartFeatures:(long long)arg1;
- (long long)rowSlices;
- (long long)columnSlices;
- (id)defaultTemplateName;
- (id)referenceImage;
- (id)coreUIOptions;
- (id )contentInsets;
- (struct CGRect)edgeInsets:(BOOL)arg1;
- (struct CGRect)alignmentRectangle;
- (id)slices;
- (void)_initializeCoreUIOptions:(id)arg1;
- (BOOL)initializeCustomWidget:(const struct CUIDescriptor *)arg1;
- (BOOL)_initializeFromSystemAppearance:(const struct CUIDescriptor *)arg1 withWidget:(long long)arg2;
- (unsigned int)_subtypeFromRenditionInfo;
- (void)_initWithRowHeights:(id)arg1 columnWidths:(id)arg2 drawScale:(double)arg3 drawBlock:(id)arg4;
- (void)_initWithRowCount:(long long)arg1 columnCount:(long long)arg2 rowHeight:(long long)arg3 columnWidth:(long long)arg4 drawScale:(double)arg5 drawBlock:(id)arg6;
- (void)_initWithSolidColor:(struct CGColor *)arg1 rowCount:(long long)arg2 columnCount:(long long)arg3 rowHeight:(long long)arg4 columnWidth:(long long)arg5;
- (BOOL)_initializeFromHorizontal6PartControl:(const struct CUIDescriptor *)arg1;
- (id)_referenceArtworkRendition;
- (BOOL)_initializeDockBadge:(const struct CUIDescriptor *)arg1;
- (BOOL)_initializeSearchFieldCancel:(const struct CUIDescriptor *)arg1;
- (BOOL)_initializeSearchFieldFind:(const struct CUIDescriptor *)arg1;
- (BOOL)_initializeProgressSpinnerDeterminate:(const struct CUIDescriptor *)arg1;
- (BOOL)_initializeProgressBarIndeterminate:(const struct CUIDescriptor *)arg1;
- (struct CGRect)alignBarBoundsHack:(const struct CUIDescriptor *)arg1 originalBarBounds:(struct CGRect)arg2;
- (BOOL)_initializeFromTableViewHeaderParts:(const struct CUIDescriptor *)arg1;
- (id)_GetWidthOverridesForHorizontal6Part:(const struct CUIDescriptor *)arg1;
- (void)_EstablishSizeAndLayoutRectsForManyPart:(id)arg1;
- (void)_initializeWithGradientColors:(id)arg1 locations:(id)arg2 midpointLocations:(id)arg3 angle:(double)arg4;
- (void)_initializeFromOnePartImage:(long long)arg1 withInfo:(const struct CUIDescriptor *)arg2;
- (id)_rendererInitializationDictionary;
- (void)_initializeToEmptyImage;
- (struct CGImage *)_copyImage:(struct CGImage *)arg1 intoCanvasOfSize:(struct CGSize)arg2 anchorRight:(BOOL)arg3 anchorTop:(BOOL)arg4;
- (struct CGImage *)_newEmptyImageWithSize:(struct CGSize)arg1 fill:(BOOL)arg2;
- (double)scale;
- (void)dealloc;
- (id)initWithCoreUIOptions:(id)arg1 forKey:(const struct _renditionkeytoken *)arg2 artworkStatus:(long long)arg3;
- (id)initWithCoreUIOptions:(id)arg1 forKey:(const struct _renditionkeytoken *)arg2;
@property(readonly, nonatomic) CUIPSDGradient *gradient;
@property(readonly, nonatomic) struct CGRect *sliceRects;
@property(readonly, nonatomic) unsigned long long numberOfSlices;

@end
