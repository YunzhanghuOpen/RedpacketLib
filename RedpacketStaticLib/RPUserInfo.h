
 // Create by Mr.Yang 
 // Copyright © 2017年 云账户. All rights reserved. 
 // 云账户：http://www.yunzhanghu.com 
 // @Project：红包SDK京东支付版
 // @File：RPUserInfo.h 
 // @Version: 3.5.1 


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

