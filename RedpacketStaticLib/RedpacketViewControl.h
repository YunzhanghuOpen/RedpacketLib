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
    RPRedpacketControllerTypeTransfer,  //转账(仅京东支付版本支持)
    RPRedpacketControllerTypeGroup,     //群红包
};

/** 发红包成功后的回调， MessageModel红包相关的数据，发红包者信息，收红包者信息，抢到的红包金额*/
typedef void(^RedpacketSendBlock)(RedpacketMessageModel *model);
/** 开发者查询成功列表成功的回调*/
typedef void(^RedpacketMemberListFetchBlock)(NSArray<RedpacketUserInfo *> * groupMemberList);
/** 获取定向红包，群成员列表的回调，开发者查询成功后，通过fetchFinishBlock回调给SDK*/
typedef void(^RedpacketMemberListBlock)(RedpacketMemberListFetchBlock fetchFinishBlock);
/** 广告红包事件回调*/
typedef void(^RedpacketAdvertisementAction)(NSDictionary *args);
/** 抢红包成功后的回调*/
typedef void(^RedpacketGrabBlock)(RedpacketMessageModel *messageModel);
/** 生成红包ID成功后的回调*/
typedef void(^RedpacketIDGenerateBlock)(NSString *redpacketID);
/** 查询红包状态的回调*/
typedef void(^RedpacketCheckRedpacketStatusBlock)(RedpacketMessageModel *model, NSError *error);


@interface RedpacketViewControl : NSObject

/** 生成红包的方法和回调*/
+ (void)presentRedpacketViewController:(RPRedpacketControllerType)controllerType            //  红包类型
                       fromeController:(UIViewController *)fromeController                  //  要展示红包的控制器
                      groupMemberCount:(NSInteger)count                                     //  群成员人数，可以为0
                 withRedpacketReceiver:(RedpacketUserInfo *)receiver                        //  单聊红包红包接收者相关信息， 群聊红包只传群ID
                       andSuccessBlock:(RedpacketSendBlock)sendBlock                        //  发送红包成功后的回调（红包生成成功后，开发者将此红包数据通过响应的数据通道传给对应的接收人或者群）
         withFetchGroupMemberListBlock:(RedpacketMemberListBlock)memberBlock                //  定向红包获取群成员列表的回调
           andGenerateRedpacketIDBlock:(RedpacketIDGenerateBlock)generateBlock;             //  发送红包生成红包ID的回调

/** 抢红包的方法和事件回调*/
+ (void)redpacketTouchedWithMessageModel:(RedpacketMessageModel *)messageModel              //  红包相关信息(发红包成功后会产生一个消息体，有这个消息体转换而来)
                      fromViewController:(UIViewController *)fromViewController             //  要展示红包的控制器
                      redpacketGrabBlock:(RedpacketGrabBlock)grabTouch                      //  抢红包成功后的回调
                     advertisementAction:(RedpacketAdvertisementAction)advertisementAction; //  广告红包的事件回调


/** 弹出零钱页面控制器(如果为支付宝授权版本则是红包记录页面) */
+ (void)presentChangePocketViewControllerFromeController:(UIViewController *)viewController;

/** 红包页面 @return1 如果是钱包版SDK返回的是零钱页面 @return2 如果是支付宝版则是红包记录页面 */
+ (UIViewController *)changePocketViewController;

@end


@interface RedpacketViewControl (RedpacketInfo)

/** 零钱接口返回零钱(如果为支付宝授权版本则不存在此接口) */
+ (void)getChangeMoney:(void (^)(NSString *amount))amount;

/** 红包状态查询 */
+ (void)checkRedpacketStatusWithRedpacketID:(NSString *)redpacketID
                              andCheckBlock:(RedpacketCheckRedpacketStatusBlock)checkBlock;

@end
