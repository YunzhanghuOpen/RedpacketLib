//
//  RPRedpacketModel.h
//  ChatDemo-UI3.0
//
//  Created by Mr.Yang on 16/3/8.
//  Copyright © 2016年 Mr.Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPUserInfo.h"


typedef NS_ENUM(NSInteger, RPRedpacketType) {
    
    RPRedpacketTypeSingle = 2001,     /***  点对点红包*/
    RPRedpacketTypeAmount,            /***  小额随机红包*/
    
    RPRedpacketTypeGroupRand,         /***  拼手气红包*/
    RPRedpacketTypeGroupAvg,          /***  普通红包*/
    RPRedpacketTypeGoupMember,        /***  专属红包*/
    
    RPRedpacketTypeSystem,            /***  系统红包*/
    
    RPRedpacketTypeAdvertisement,     /***  广告红包*/
    
    RPRedpacketTypeTransfer           /***  转账*/
    
};

typedef NS_ENUM(NSInteger, RPRedpacketStatusType) {
    
    RPRedpacketStatusTypeOutDate = -1,        /***  红包已过期*/
    RPRedpacketStatusTypeCanGrab = 0,         /***  红包可以抢*/
    RPRedpacketStatusTypeGrabFinish = 1       /***  红包被抢完*/
    
};


/// 红包相关信息
@interface RPRedpacketModel : NSObject

/// 红包ID
@property (nonatomic,   copy) NSString *redpacketID;
/// 红包的类型
@property (nonatomic, assign) RPRedpacketType redpacketType;
/// 红包的字符串类型
@property (nonatomic,   copy) NSString *redpacketTypeStr;
/// 红包的类型
@property (nonatomic, assign) RPRedpacketStatusType statusType;
/// 群红包，群组ID
@property (nonatomic,   copy) NSString *groupID;
/// 金额
@property (nonatomic,   copy) NSString *money;
/// 红包数量
@property (nonatomic, assign) NSInteger count;
/// 祝福语
@property (nonatomic,   copy) NSString *greeting;
/// 转账时间
@property (nonatomic,   copy) NSString *tranferTime;
/// 红包详情里我抢到的金额
@property (nonatomic, assign) NSString *receiveMoney;
/// 当前用户是否是红包的发送者
@property (nonatomic, assign) BOOL isSender;
/// 当前用户信息
@property (nonatomic, readonly) RPUserInfo *currentUser;
/// 红包发送者信息
@property (nonatomic, strong) RPUserInfo *sender;
/// 红包接受者信息
@property (nonatomic, strong) RPUserInfo *receiver;
/// 红包详情页使用字典信息
@property (nonatomic, strong) NSDictionary *redpacketDetailDic;

/*!
 @brief 查询红包详情时，生成红包Model
 @param redpacketID     红包ID
 @param redpacketType   红包类型
 @param transferTime    发送者
 */
+ (RPRedpacketModel *)modelWithRedpacketID:(NSString *)redpacketID
                             redpacketType:(NSString *)redpacketType
                        andRedpacketSender:(RPUserInfo *)sender;

/*!
 @brief 查询转账详情时，生成转账Model
 @param redpacketID     红包ID
 @param transferMoney   转账金额
 @param transferTime    转账时间
 @param sender          转账者
 */
+ (RPRedpacketModel *)modelByTransferTypeWithRedpacketID:(NSString *)redpacketID
                                           transferMoney:(NSString *)transferMoney
                                            transferTime:(NSString *)transferTime
                                       andTransferSender:(RPUserInfo *)sender;


@end
