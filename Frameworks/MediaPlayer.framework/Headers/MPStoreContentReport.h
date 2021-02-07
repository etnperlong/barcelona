//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <MediaPlayer/NSCopying-Protocol.h>

@class NSString;

@interface MPStoreContentReport : NSObject
{
    NSString *_userID;
    NSString *_contentID;
    long long _concernItemType;
    NSString *_commentText;
    NSString *_aucType;
    NSString *_concernTypeID;
    NSString *_displayText;
}


@property(copy, nonatomic) NSString *displayText; // @synthesize displayText=_displayText;
@property(copy, nonatomic) NSString *concernTypeID; // @synthesize concernTypeID=_concernTypeID;
@property(copy, nonatomic) NSString *aucType; // @synthesize aucType=_aucType;
@property(copy, nonatomic) NSString *commentText; // @synthesize commentText=_commentText;
@property(nonatomic) long long concernItemType; // @synthesize concernItemType=_concernItemType;
@property(copy, nonatomic) NSString *contentID; // @synthesize contentID=_contentID;
@property(copy, nonatomic) NSString *userID; // @synthesize userID=_userID;
- (id)description;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end
