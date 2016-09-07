//
//  GDTSplashAd.h
//  GDTMobApp
//
//  广点通开屏广告，目前只支持iPhone设备上展示垂直方向的开屏广告
//  Created by GaoChao on 15/8/20.
//  Copyright © 2015年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GDTSplashAd;

@protocol GDTSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告成功展示
 */
-(void)splashAdSuccessPresentScreen:(GDTSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
-(void)splashAdFailToPresent:(GDTSplashAd *)splashAd withError:(NSError *)error;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)splashAdApplicationWillEnterBackground:(GDTSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)splashAdClicked:(GDTSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)splashAdClosed:(GDTSplashAd *)splashAd;

/**
 *  开屏广告点击以后即将弹出全屏广告页
 */
- (void)splashAdWillPresentFullScreenModal:(GDTSplashAd *)splashAd;

/**
 *  开屏广告点击以后弹出全屏广告页
 */
- (void)splashAdDidPresentFullScreenModal:(GDTSplashAd *)splashAd;

/**
 *  点击以后全屏广告页将要关闭
 */
- (void)splashAdWillDismissFullScreenModal:(GDTSplashAd *)splashAd;

/**
 *  点击以后全屏广告页已经关闭
 */
- (void)splashAdDidDismissFullScreenModal:(GDTSplashAd *)splashAd;

@end

@interface GDTSplashAd : NSObject

/**
 *  委托对象
 */
@property (nonatomic, weak) id<GDTSplashAdDelegate> delegate;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundColor，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) int fetchDelay;

/**
 *  开屏广告的背景色
 *  可以设置开屏图片来作为开屏加载时的默认图片
 */
@property (nonatomic, copy) UIColor *backgroundColor;

/**
 * 跳过按钮的位置
 */
@property (nonatomic, assign) CGPoint  skipButtonCenter;

/**
 *  构造方法
 *  详解：appkey是应用id, placementId是广告位id
 */
-(instancetype)initWithAppkey:(NSString *)appkey placementId:(NSString *)placementId;

/**
 *  广告发起请求并展示在Window中
 *  详解：[可选]发起拉取广告请求,并将获取的广告以全屏形式展示在传入的Window参数中
 *  @param window 展示全屏开屏的容器
 */
-(void)loadAdAndShowInWindow:(UIWindow *)window;

/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意bottomView需设置好宽高，所占的空间不能过大，并保证广告界面的高度大于360
 *  @param window 展示开屏的容器
 *         bottomView 自定义底部View，可以在此View中设置应用Logo
 */
-(void)loadAdAndShowInWindow:(UIWindow *)window withBottomView:(UIView *)bottomView;

@end
