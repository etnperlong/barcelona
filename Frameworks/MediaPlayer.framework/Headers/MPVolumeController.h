//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <MediaPlayer/MPVolumeControllerDataSourceDelegate-Protocol.h>

@class NSString;
@protocol MPVolumeControllerDataSource, MPVolumeControllerDelegate;

@interface MPVolumeController : NSObject
{
    id _dataSource;
    int _volumeChangeCoalescingCount;
    unsigned int _volumeCapabilities;
    id _delegate;
}

+ (id)descriptionForWarningState:(long long)arg1;

@property(retain, nonatomic) id dataSource; // @synthesize dataSource=_dataSource;
@property(readonly, nonatomic) unsigned int volumeCapabilities; // @synthesize volumeCapabilities=_volumeCapabilities;
@property(nonatomic) __weak id delegate; // @synthesize delegate=_delegate;
- (_Bool)muted;
@property(copy, nonatomic) NSString *volumeAudioCategory;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolumeAudioCategory:(id)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolumeWarning:(long long)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeEUVolumeLimitEnforced:(_Bool)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeEUVolumeLimit:(float)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolumeLabel:(id)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolumeCapabilities:(unsigned int)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolumeControlAvailability:(_Bool)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeVolume:(float)arg2;
- (void)volumeControllerDataSource:(id)arg1 didChangeMuted:(_Bool)arg2;
- (void)_updateVolumeControlAvailability;
- (void)updateVolumeWarningState;
@property(readonly, nonatomic) float EUVolumeLimit;
@property(readonly, nonatomic) long long volumeWarningState;
@property(readonly, nonatomic) _Bool volumeWarningEnabled;
- (void)endDecreasingRelativeVolume;
- (void)beginDecreasingRelativeVolume;
- (void)endIncreasingRelativeVolume;
- (void)beginIncreasingRelativeVolume;
- (void)setVolume:(float)arg1 withNoticationDelay:(float)arg2;
- (void)getVolumeValueWithCompletion:(id)arg1;
- (void)adjustVolumeValue:(float)arg1;
- (void)updateVolumeValue;
@property(nonatomic, getter=isMuted) _Bool muted;
@property(nonatomic) float volumeValue;
@property(readonly, copy, nonatomic) NSString *volumeControlLabel;
@property(readonly, nonatomic, getter=isVolumeControlAvailable) _Bool volumeControlAvailable;
- (id)initWithDataSource:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end
