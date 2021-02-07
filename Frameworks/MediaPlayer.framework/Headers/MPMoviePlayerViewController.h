//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIViewController.h>

@class MPMoviePlayerController;

@interface MPMoviePlayerViewController : UIViewController
{
    id _internal;
    _Bool _statusBarWasHidden;
}


- (void)_moviePlayerViewController_playbackDidFinishNotification:(id)arg1;
- (void)_moviePlayerViewController_applicationDidEnterBackgroundNotification:(id)arg1;
- (_Bool)_shouldUseFullScreenLayoutInWindow:(id)arg1 parentViewController:(id)arg2;
- (_Bool)_canReloadView;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (unsigned long long)supportedInterfaceOrientations;
- (void)didRotateFromInterfaceOrientation:(long long)arg1;
- (void)willAnimateRotationToInterfaceOrientation:(long long)arg1 duration:(double)arg2;
- (_Bool)shouldAutorotateToInterfaceOrientation:(long long)arg1;
- (_Bool)prefersStatusBarHidden;
- (_Bool)shouldAutorotate;
- (void)loadView;
- (void)remoteControlReceivedWithEvent:(id)arg1;
- (_Bool)canBecomeFirstResponder;
@property(readonly, nonatomic) MPMoviePlayerController *moviePlayer;
- (void)dealloc;
- (id)initWithAsset:(id)arg1;
- (id)initWithContentURL:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initWithCoder:(id)arg1;

@end
