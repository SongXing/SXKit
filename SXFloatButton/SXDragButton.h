//
//  SXDragButton.h
//  SXFloatButton
//
//  Created by sunn on 2017/5/25.
//  Copyright © 2017年 sunn. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SXDragButtonDelegate <NSObject>

- (void)dragButtonClicked:(UIButton*)sender;

@end

///////////////

@interface SXDragButton : UIButton

/**
 *  悬浮窗所依赖的根视图
 */
@property (nonatomic,strong) UIView *rootView;

/**
 *  UIDragButton的点击事件代理
 */
@property (nonatomic,weak) id<SXDragButtonDelegate> btnDelegate;

@end
