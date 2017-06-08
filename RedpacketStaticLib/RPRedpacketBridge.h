//
//  RedpacketUserAccount.h
//  ChatDemo-UI3.0
//
//  Created by Mr.Yang on 16/3/1.
//  Copyright © 2016年 Mr.Yang. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Token注册的几种方式
@interface RPRedpacketRegisitModel : NSObject

/*!
 @brief 签名方式
 @param appUserId   App的用户ID
 @param sign        当前用户的签名(App Server端获取)
 @param partner     AppID商户在官网注册后可得到
 @param timeStamp   签名的时间戳 (App Server端获取)
 @return 注册对象,在token注册回调时，传入此对象
 */
+ (RPRedpacketRegisitModel *)signModelWithAppUserId:(NSString *)appUserId
                                         signString:(NSString *)sign
                                            partner:(NSString *)partner
                                       andTimeStamp:(NSString *)timeStamp;

/*!
 @brief 环信的方式
 @param appkey      环信的注册商户Key
 @param appToken    环信IM的Token
 @param appUserId   环信IM的用户ID
 @return 注册对象,在token注册回调时，传入此对象
 */
+ (RPRedpacketRegisitModel *)easeModelWithAppKey:(NSString *)appkey
                                        appToken:(NSString *)appToken
                                    andAppUserId:(NSString *)appUserId;

/*!
 @brief 容联云的方式
 @param appId       容联云的AppId
 @param appUserId   容联云的用户ID
 @return 注册对象,在token注册回调时，传入此对象
 */
+ (RPRedpacketRegisitModel *)rongCloudModelWithAppId:(NSString *)appId
                                           appUserId:(NSString *)appUserId;

@end


///  Token初始化参数回传， 如果初始化失败请传入nil
typedef void (^RPFetchRegisitParamBlock)(RPRedpacketRegisitModel *model);


@class RPUserInfo;

/// 桥接代理，用来获取当前用户信息和SDK注册Token使用
@protocol RPRedpacketBridgeDelegate <NSObject>

@required

/// 获取当前登录用户的信息
- (RPUserInfo *)redpacketUserInfo;

/*!
 @discussion
    使用红包服务时，如果红包Token不存在或者过期，则回调此方法，需要在RedpacketRegisitModel生成后，通过fetchBlock回传给红包SDK
 @remark
    如果错误error不为空，可能是一下情况
    1. 如果是环信IM，则刷新环信ImToken
    2. 如果是签名方式， 则刷新签名
 */
- (void)redpacketFetchRegisitParam:(RPFetchRegisitParamBlock)fetchBlock withError:(NSError *)error;

@end

/*! 
 @brief 红包SDK和App之间进行桥接的工具
 */
@interface RPRedpacketBridge : NSObject

@property (nonatomic, weak) id <RPRedpacketBridgeDelegate> delegate;

/// 是否是调试模式, 默认为NO
@property (nonatomic, assign)   BOOL isDebug;

/*!
 @remark
    支付宝回调当前APP时的URL Scheme,
    默认为当前App的Bundle Identifier
 */
@property (nonatomic, copy)  NSString *redacketURLScheme;

/// 是否隐藏红包记录详情页我的红包按钮，默认显示
@property (nonatomic, assign)   BOOL isHiddenMyRedpacketButton;

+ (RPRedpacketBridge *)sharedBridge;

@end


