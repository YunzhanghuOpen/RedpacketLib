//
//  RPUserInfo.h
//  RedpacketRequestDataLib
//
//  Created by Mr.Yang on 2017/6/6.
//  Copyright © 2017年 Mr.Yang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RPUserInfo : NSObject
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy, readonly) NSString *userNameOrigin;
@property (nonatomic, copy) NSString *avatar;

/// 生成用户信息Model
+ (RPUserInfo *)userInfoWithUserID:(NSString *)userID
                          UserName:(NSString *)userName
                         andAvatar:(NSString *)avatar;

/// 群组红包时，生成群接收者
+ (RPUserInfo *)userInfoWithGroupID:(NSString *)groupID;

@end

