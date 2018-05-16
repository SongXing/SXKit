//
//  SPSDK.h
//
//
//  Created by sunn on 2017/2/24.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define SP_SDK_VERSION @"4.4.6"

// 通知回调类常量
extern NSString *const SPY_LOGIN_SUCCUESS;
extern NSString *const SPY_PAY_SUCCUESS;
extern NSString *const SPY_PAY_PUCHESSING;
extern NSString *const SPY_PAY_FAIL;

extern NSString *const SPY_SHARE_RESULT;

// 基本参数类常量
extern NSString *const SPY_PRM_USER_ID;          // 登录成功后返回的星彼 userId
extern NSString *const SPY_PRM_ROLE_ID;          // 游戏角色 ID
extern NSString *const SPY_PRM_ROLE_NAME;        // 游戏角色名
extern NSString *const SPY_PRM_ROLE_LEVEL;       // 游戏角色等级
extern NSString *const SPY_PRM_ROLE_VIP_LEVEL;   // 游戏角色VIP等级
extern NSString *const SPY_PRM_ROLE_SERVER_ID;   // 游戏角色所在服务器
extern NSString *const SPY_PRM_ROLE_SERVER_NAME; // 游戏角色所在服务器名称

// 分享参数类常量
extern NSString *const SPY_PRM_SHARE_TYPE;                      // 分享类型
extern NSString *const SPY_PRM_SHARE_CONTENT_DESCRIPTION;       // 分享内容
extern NSString *const SPY_PRM_SHARE_CONTENT_TITLE;             // 分享标题。应用名字
extern NSString *const SPY_PRM_SHARE_CONTENT_URL;               // 分享应用链接
extern NSString *const SPY_PRM_SHARE_IMAGE_URL;                 // 分享图片链接
extern NSString *const SPY_PRM_SHARE_IMAGE;                     // 分享的图片（增加）

extern NSString *const SPY_PRM_SHARE_WX_SCENE_KEY;                     // 微信分享场景key
extern NSString *const SPY_PRM_SHARE_WX_CONTENT_KEY;                   // 微信分享内容类型key

extern NSString *const SPY_SHARE_SCENE_SESSION;                     // 微信分享场景-对话
extern NSString *const SPY_SHARE_SCENE_TIMELINE;                     // 微信分享场景-朋友圈

extern NSString *const SPY_SHARE_CONTENT_MESSAGE;                     // 微信分享内容value-信息分享
extern NSString *const SPY_SHARE_CONTENT_MEDIA;                     // 微信分享内容value-网页分享

// 分享类型常量
extern NSString *const SPY_SHARE_TYPE_FACEBOOK;         // 分享类型 Facebook
extern NSString *const SPY_SHARE_TYPE_WECHAT;         // 分享类型 Wechat

// 储值参数常量
extern NSString *const SPY_PRM_PAY_MODE;            // 储值类型
extern NSString *const SPY_PRM_PAY_PRODUCT_ID;      // 充值时的商品 ID
extern NSString *const SPY_PRM_PAY_CP_ORDER_ID;     // 充值时厂商生产的订单号
extern NSString *const SPY_PRM_PAY_EXTRA;           // 充值时额外提供的参数

// 储值类型
extern NSString *const SPY_PAY_MODE_DEFAULT;            // 储值类型 内购
extern NSString *const SPY_PAY_MODE_WEB;                // 储值类型 第三方储值
extern NSString *const SPY_PAY_MODE_CPVIEW;             // 储值类型 第三方储值,使用CP的界面，需要订单号和商品ID

// web 参数常量
extern NSString *const SPY_PRM_WEB_MODE;                // web 类型
extern NSString *const SPY_PRM_WEB_URL;                // web URL

extern NSString *const SPY_WEB_MODE_CP;                // web 类型 CP的链接
extern NSString *const SPY_WEB_MODE_SDK;                // web 类型 SDK的链接

@interface SPSDK : NSObject

/**
 应用跳转回调（适用于 iOS 8 及以下）
 
 */
+ (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

/**
 应用跳转回调（适用于 iOS 9 及以上）
 */
+ (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options;

/**
 单例

 @return Satrpy 单例对象
 */
+ (instancetype)shareStarpy;

/**
 登录
 */
- (void)sp_login;


/**
 存储游戏角色信息

 @param roleInfo 角色信息参数集合
 SPY_PRM_ROLE_ID             不可为 nil 或 空字符串
 SPY_PRM_ROLE_NAME           不可为 nil 或 空字符串
 SPY_PRM_ROLE_LEVEL          不可为 nil 或 空字符串
 SPY_PRM_ROLE_SERVER_ID      不可为 nil 或 空字符串
 SPY_PRM_ROLE_SERVER_NAME    不可为 nil ，可为 空字符串
 SPY_PRM_ROLE_VIP_LEVEL      不可为 nil ，可为 空字符串
 */
- (void)sp_setRoleInfo:(NSDictionary *)roleInfo;

/**
 充值
 充值有两种模式：A 苹果内购 B 第三方网页充值（可选）
 根据传参数 SPY_PRM_PAY_TYPE 来区分
 
 @param payParms 充值参数集合
 */
- (void)sp_pay:(NSDictionary *)payParms;


/**
 客服
 
 @param     serviceParms 原来需要传角色信息，现已不需要，可直接传 nil
 仍保留该参数，以作备用
 */
- (void)sp_customer_service:(NSDictionary *)serviceParms;


/**
 社交分享

 @param shareParams 分享参数集合
 SPY_PRM_SHARE_TYPE                     分享类型(SP_SHARE_FACEBOOK)
 SPY_PRM_SHARE_CONTENT_DESCRIPTION      分享内容
 SPY_PRM_SHARE_CONTENT_TITLE            分享标题
 SPY_PRM_SHARE_CONTENT_URL              分享应用链接
 SPY_PRM_SHARE_IMAGE_URL                分享图片链接
 */
- (void)sp_share:(NSDictionary *)shareParams;

/**
 社交邀请 （暂未开发完毕）

 @param inviteParams 邀请参数集合
 */
- (void)sp_invitation:(NSDictionary *)inviteParams;

/**
 webview
 
 @param webParams web参数集合
 若要显示 CP 指定的webview，需要传入以下两个参数
 SPY_PRM_WEB_MODE                web 类型 （SPY_WEB_MODE_CP）
 SPY_PRM_WEB_URL                 web URL
 
 若要显示 SDK 的 webview，可传 nil 或
 SPY_PRM_WEB_MODE                web 类型 （SPY_WEB_MODE_SDK）
 
 默认显示的是 SDK 的 webview
 */
- (void)sp_webview:(NSDictionary *)webParams;

/**
 内置平台（Built-in platform）
 
 @param plfmParams platform参数集合
 */
- (void)sp_platform:(NSDictionary *)plfmParams;

/**
 远程推送注册
 */
- (void)sp_registerForRemoteNotifications;


/**
 远程推送token上报(为国内做推送预留)
 
 @param deviceToken 设备 token
 */
- (void)sp_postRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

@end




