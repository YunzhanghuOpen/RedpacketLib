## 1. 开发准备

**1.1 注册商户**
* [注册地址](https://bv2.yunzhanghu.com/app/register)

**1.2 下载SDK相关资源(目前共两个版本)**

1. [官网下载集成](https://www.yunzhanghu.com/developer-im.html)
2. cocoapods集成（红包SDK默认关联了支付宝SDK，无需再集成）

    * 京东版本(需要绑银行卡)：[RedpacketLib](https://cocoapods.org/?q=Redpacket)
    * 支付宝版本：[RedpacketAliAuthLib](https://cocoapods.org/?q=RedpacketAliAuthLib)

3. [集成演示Demo](https://github.com/YunzhanghuOpen/Redpacket-Demo-iOS)

## 2. 红包SDK配置

* 需要在工程中的`BuildSetting`中搜索`OtherLinkFlag`并添加`-ObjC`标记
* 需要支持支付宝回调，请在`Info.plist`中添加`URL Types`，默认添加为APP的 `Bundle Identifier`
* 需要处理支付宝回调，请在[集成Demo](https://github.com/YunzhanghuOpen/Redpacket-Demo-iOS)中查找`AppDelegate+Redpacket`,并添加到工程

## 3. 红包SDK初始化

**3.1 注册Token（共三种）**

```
@interface YZHRedpacketBridge : NSObject
@property (nonatomic, weak) id <YZHRedpacketBridgeDelegate> delegate;
// 注册Token回调
- (void)redpacketFetchRegisitParam:(FetchRegisitParamBlock)fetchBlock withError:(NSError *)error;

// 注册信息通过以下回调传回SDK
typedef void (^FetchRegisitParamBlock)(RedpacketRegisitModel *model); 

```
**1. 签名方式（任何App都可以基于此方式实现红包功能）**
 签名方法见：[云账户REST API文档](https://github.com/YunzhanghuOpen/yun-doc/blob/master/intro/server.md)

```
+ (RedpacketRegisitModel *)signModelWithAppUserId:(NSString *)appUserId     //  App的用户ID
                                       signString:(NSString *)sign          //  当前用户的签名（签名方法获取）
                                          partner:(NSString *)partner       //  在云账户注册的合作者（网站注册后可得到）
                                     andTimeStamp:(NSString *)timeStamp;    //  签名的时间戳（签名方法获取）
```
**2. 环信方式**

```
+ (RedpacketRegisitModel *)easeModelWithAppKey:(NSString *)appkey           //  环信的注册商户Key
                                      appToken:(NSString *)appToken         //  环信IM的Token
                                  andAppUserId:(NSString *)appUserId;       //  环信IM的用户ID
                                  
```
**3. 容联云方式**

```
+ (RedpacketRegisitModel *)rongCloudModelWithAppId:(NSString *)appId        //  容联云的AppId
                                         appUserId:(NSString *)appUserId;   //  容联云的用户ID
                                         
```
**3.2 红包Token注册时机**

开发者实现以上方法后，SDK会在下列情况时进行回调
    1. 使用红包服务，且Token不存在时
    2. 使用红包服务，但是Token已经过期

**3.3 实现获取当前用户信息获的代理**

```
@interface YZHRedpacketBridge : NSObject
@property (nonatomic, weak) id <YZHRedpacketBridgeDataSource>dataSource;

@protocol YZHRedpacketBridgeDataSource <NSObject>

- (RedpacketUserInfo *)redpacketUserInfo;
- 
@end

```

### 4. 发红包
**单聊红包（限单聊）**

```
+ (void)presentRedpacketViewController:RPRedpacketControllerTypeSingle
                       fromeController:#当前页面的控制器#
                      groupMemberCount:0
                 withRedpacketReceiver:#红包接收者信息#
                       andSuccessBlock:#发送成功后的回调#
         withFetchGroupMemberListBlock:nil
         andGenerateRedpacketIDBlock:nil
         
```

**小额随机红包（限单聊）**

```
+ (void)presentRedpacketViewController:RPRedpacketControllerTypeRand
                       fromeController:#当前页面的控制器#
                      groupMemberCount:0
                 withRedpacketReceiver:#红包接收者信息#
                       andSuccessBlock:#发送成功后的回调#
         withFetchGroupMemberListBlock:nil
         andGenerateRedpacketIDBlock:nil
```

**普通群聊红包（限群聊）**

```
+ (void)presentRedpacketViewController:RPRedpacketControllerTypeGroup
                       fromeController:#当前页面的控制器#
                      groupMemberCount:0
                 withRedpacketReceiver:#红包接收者信息#
                       andSuccessBlock:#发送成功后的回调#
         withFetchGroupMemberListBlock:nil
         andGenerateRedpacketIDBlock:nil
         
```

**专属红包（限群聊）**

* 可以指定群里某一个接收者
* 包含普通群组功能

```
+ (void)presentRedpacketViewController:RPRedpacketControllerTypeGroup
                       fromeController:#当前页面控制器#
                      groupMemberCount:0
                 withRedpacketReceiver:#红包接收者信息#
                       andSuccessBlock:#发送成功后的回调#
         withFetchGroupMemberListBlock:#获取群成员列表的回调#
         andGenerateRedpacketIDBlock:nil
```

* 红包发送成功后，调用`RedpacketMessageModel`中的`redpacketMessageModelToDic`生成需要在消息通道中传递的数据


## 5. 拆红包

* 他人收到红包消息后，将消息体中的字典通过`RedpacketMessageModel`中的`redpacketMessageModelWithDic`转换成`MessageModel`然后调用下列方法

```
+ (void)redpacketTouchedWithMessageModel:#上文中生成的MessageModel#
                     fromViewController:#当前页面控制器#
                      redpacketGrabBlock:#拆红包成功后的回调#
                     advertisementAction:nil
```

**营销红包(原广告红包)**

```
+ (void)redpacketTouchedWithMessageModel:#上文中生成的MessageModel#
                     fromViewController:#当前页面控制器#
                      redpacketGrabBlock:#拆红包成功后的回调#
                     advertisementAction:#广告红包抢红包成功后的行为回调(查看详情，分享)#

```

## 5. 关于GenerateRedpacketIDBlock （可选策略）
 在发红包页面可以拿到红包ID， 通过红包详情查询方法，可以查询红包详情。此方案为在极端情况下，红包SDK发红包一直超时时，红包发送成功，但是开发者没有收到回调。开发者可以通过此ID，重新查询红包是否发送成功。此方案为可选策略，开发者可以忽略。

## 6. 注意事项

**相关UI（红包样式）**

* [集成Demo](https://github.com/YunzhanghuOpen/Redpacket-Demo-iOS)中已经提供开源代码，请在Demo中查找其它IM，请在不同的IM开源Demo中查找即可。

**三方支付回调**

* 请在[集成Demo](https://github.com/YunzhanghuOpen/Redpacket-Demo-iOS) 中查找`AppDelegate+Redpacket`，在工程中引入即可

**回调地址(默认为`Bundle Identifier`)**

* 请在工程中的Info.plist中添加此回调地址

**Other Link Flag（引入类别）**

* 请在工程中的BuildSetting中搜索`OtherLinkFlag`并添加`-ObjC`标记

**支付宝集成文档（如果遇到了支付宝集成困难请查询此文档）**

* [支付宝集成链接](https://doc.open.alipay.com/doc2/detail.htm?spm=a219a.7629140.0.0.UccR9D&treeId=59&articleId=103676&docType=1)

**集成Demo**（可以演示也可以参考集成方式）

* [集成Demo](https://github.com/YunzhanghuOpen/Redpacket-Demo-iOS)




