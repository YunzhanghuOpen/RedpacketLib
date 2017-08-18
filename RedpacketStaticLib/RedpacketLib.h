
 // Create by Mr.Yang 
 // Copyright © 2017年 云账户. All rights reserved. 
 // 云账户：http://www.yunzhanghu.com 
 // @Project：红包SDK京东支付版 
 // @File：RedpacketLib.h 
 // @Version: 3.5.1

 //                            _ooOoo_
 //                           o8888888o
 //                           88" . "88
 //                           (| -_- |)
 //                           O\  =  /O
 //                        ____/`---'\____
 //                      .'  \\|     |//  `.
 //                     /  \\|||  :  |||//  \
 //                    /  _||||| -:- |||||-  \
 //                    |   | \\\  -  /// |   |
 //                    | \_|  ''\---/''  |   |
 //                    \  .-\__  `-`  ___/-. /
 //                   ___`. .'  /--.--\  `. . __
 //                ."" '<  `.___\_<|>_/___.'  >'"".
 //              | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 //              \  \ `-.   \_ __\ /__ _/   .-` /  /
 //         ======`-.____`-.___\_____/___.-`____.-'======
 //                            `=---='
 //         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 //                  佛祖镇楼                  BUG辟易



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
