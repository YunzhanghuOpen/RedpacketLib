//
//  RedpacketUserAccount.h
//  ChatDemo-UI3.0
//
//  Created by Mr.Yang on 16/3/1.
//  Copyright © 2016年 Mr.Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YZHRedpacketBridgeProtocol.h"

/** Token注册的几种方式 */
@interface RedpacketRegisitModel : NSObject

/**  签名方式 */
+ (RedpacketRegisitModel *)signModelWithAppUserId:(NSString *)appUserId     //  App的用户ID
                                       signString:(NSString *)sign          //  当前用户的签名 (App Server端获取)
                                          partner:(NSString *)partner       //  App ID （商户注册后可得到）
                                     andTimeStamp:(NSString *)timeStamp;    //  签名的时间戳 (App Server端获取)

/**  环信的方式 */
+ (RedpacketRegisitModel *)easeModelWithAppKey:(NSString *)appkey           //  环信的注册商户Key
                                      appToken:(NSString *)appToken         //  环信IM的Token
                                  andAppUserId:(NSString *)appUserId;       //  环信IM的用户ID

/**  容联云的方式 */
+ (RedpacketRegisitModel *)rongCloudModelWithAppId:(NSString *)appId        //  容联云的AppId
                                         appUserId:(NSString *)appUserId;   //  容联云的用户ID

@end


@interface YZHRedpacketBridge : NSObject

/** 获取Token*/
@property (nonatomic, weak) id <YZHRedpacketBridgeDelegate> delegate;
/** 获取用户信息*/
@property (nonatomic, weak) id <YZHRedpacketBridgeDataSource>dataSource;

/** 是否隐藏红包记录详情页我的红包按钮，默认显示 */
@property (nonatomic, assign)   BOOL isHiddenMyRedpacketButton;

/** 是否是调试模式, 默认为NO */
@property (nonatomic, assign)   BOOL isDebug;

/** 支付宝回调当前APP时的URL Scheme, 
    默认为当前App的Bundle Identifier */
@property (nonatomic, copy)  NSString *redacketURLScheme;

+ (YZHRedpacketBridge *)sharedBridge;

@end


/** 已经不再使用的API，请注意修改 */
@interface YZHRedpacketBridge (Deprecated)

@end
