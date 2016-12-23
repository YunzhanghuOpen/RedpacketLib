//
//  RedpacketViewControl.h
//  ChatDemo-UI3.0
//
//  Created by Mr.Yang on 16/3/8.
//  Copyright © 2016年 Mr.Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RedpacketMessageModel.h"


typedef NS_ENUM(NSInteger,RPRedpacketControllerType){
    RPRedpacketControllerTypeSingle,    //点对点红包
    RPRedpacketControllerTypeRand,      //小额度随机红包
    RPRedpacketControllerTypeTransfer,  //转账
    RPRedpacketControllerTypeGroup,     //群红包
};

typedef void(^RedpacketSendBlock)(RedpacketMessageModel *model);
typedef void(^RedpacketMemberListFetchBlock)(NSArray<RedpacketUserInfo *> * groupMemberList);
typedef void (^RedpacketMemberListBlock)(RedpacketMemberListFetchBlock completionHandle);
typedef void(^RedpacketAdvertisementAction)(NSDictionary *args);
typedef void(^RedpacketGrabBlock)(RedpacketMessageModel *messageModel);


/** 发红包的控制器, 开发者无需持有此对象 */
@interface RedpacketViewControl : NSObject

/*!
 抢红包事件触发器
 
 @required //必需
        @param messageModel 校验红包数据模型
                messageModel.redpacketId            @required //当前红包唯一ID
                messageModel.redpacketType          @required //红包的类型 如果红包类型是转账 则必传RedpacketTransfer 否则非必传
                messageModel.redpacketSender        @optional //红包发送者信息
                messageModel.redpacketReceiver      @optional //红包接受者信息
 
        @param fromViewController 当前栈顶的控制器 红包页面基于此控制器的页面进行展示
        @param grabTouch          抢红包成功后的回调事件
 
 @optional //非必须
        @param advertisementAction 广告红包用户行为回调(接入广告红包后才需要传)
 */
+ (void)redpacketTouchedWithRedPacketID:(RedpacketMessageModel *)messageModel
                     fromViewController:(UIViewController *)fromViewController
                      redpacketGrabBlock:(RedpacketGrabBlock)grabTouch
                     advertisementAction:(RedpacketAdvertisementAction)advertisementAction;

/*!
 发送红包事件触发器
 
 @required //必需
        @param controllerType   发送红包类型 //点对点红包 小额度红包 转账红包 只能在单人聊天中使用
        @param fromeController  当前栈顶的控制器 红包页面基于此控制器的页面进行展示
        @param count            群成员人数(单人聊天时为0)
        @param receiver         红包接受者信息
               receiver.userId                  @required   //红包接受者ID(如红包为群红包 则传入群唯一ID)
               receiver.userNickname            @required   //红包接受者昵称(如红包为群红包,则传nil。)
               receiver.userAvatar              @required   //红包接受者头像(如红包为群红包,则传nil。)
        @param sendBlock        红包发送成功后的回调
 
 @optional //非必须
        @param memberBlock      群专属红包触发专属人选择事件 需回传当前群用户信息 如果不用专属红包此处可以不传
 */
+ (void)presentRedpacketViewController:(RPRedpacketControllerType)controllerType
                       fromeController:(UIViewController *)fromeController
                      groupMemberCount:(NSInteger)count
                 withRedpacketReceiver:(RedpacketUserInfo *)receiver
                       andSuccessBlock:(RedpacketSendBlock)sendBlock
         withFetchGroupMemberListBlock:(RedpacketMemberListBlock)memberBlock;

/** 零钱接口返回零钱 */
+ (void)getChangeMoney:(void (^)(NSString *amount))amount;

/** 零钱页面控制器 */
+ (UIViewController*)changePocketViewController;

@end
