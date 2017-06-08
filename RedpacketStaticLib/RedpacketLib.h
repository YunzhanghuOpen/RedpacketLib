//
//  RedpacketLib.h
//  RedpacketLib
//
//  Created by Mr.Yang on 16/9/20.
//  Copyright © 2016年 Mr.Yang. All rights reserved.
//

#ifndef RedpacketLib_h
#define RedpacketLib_h

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE

#import "RPRedpacketBridge.h"
#import "RPRedpacketModel.h"
#import "RPRedpacketErrorCode.h"
#import "RedpacketViewControl.h"
#import "RPUserInfo.h"

#else
#import <RedpacketLib/RPRedpacketBridge.h>
#import <RedpacketLib/RPRedpacketModel.h>
#import <RedpacketLib/RPRedpacketErrorCode.h>
#import <RedpacketLib/RedpacketViewControl.h>
#import <RedpacketLib/RPUserInfo.h>

#endif

#endif /* RedpacketLib_h */
