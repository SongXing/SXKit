//
//  SXDragButton.m
//  SXFloatButton
//
//  Created by sunn on 2017/5/25.
//  Copyright © 2017年 sunn. All rights reserved.
//

// 屏幕高度
#define ScreenH [UIScreen mainScreen].bounds.size.height
// 屏幕宽度
#define ScreenW [UIScreen mainScreen].bounds.size.width

#import "SXDragButton.h"
#import "AppDelegate.h"

@interface SXDragButton ()
@property (nonatomic,assign) CGPoint startPos;
@end

@implementation SXDragButton

typedef NS_ENUM(NSUInteger, SXDirection)
{
    D_LEFT,
    D_RIGHT,
    D_TOP,
    D_BOTTOM,
};

/**
 *  开始触摸，记录触点位置用于判断是拖动还是点击
 */
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    _startPos = [touch locationInView:_rootView];
}

/**
 *  手指按住移动过程,通过悬浮按钮的拖动事件来拖动整个悬浮窗口
 */
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint curPoint = [touch locationInView:_rootView];
    // 移动按钮到当前触摸位置
    self.superview.center = curPoint;
}

/**
 *  拖动结束后使悬浮窗口吸附在最近的屏幕边缘
 */
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    // 获得触摸在根视图中的坐标
    UITouch *touch = [touches anyObject];
    CGPoint curPoint = [touch locationInView:_rootView];
    // 通知代理,如果结束触点和起始触点极近则认为是点击事件
    if (pow((_startPos.x - curPoint.x),2) + pow((_startPos.y - curPoint.y),2) < 1) {
        [self.btnDelegate dragButtonClicked:self];
        // 点击后不吸附
        return;
    }
    
    CGFloat left = curPoint.x;
    CGFloat right = ScreenW - curPoint.x;
    CGFloat top = curPoint.y;
    CGFloat bottom = ScreenH - curPoint.y;
    // 计算四个距离最小的吸附方向
    SXDirection minDir = D_LEFT;
    CGFloat minDistance = left;
    if (right < minDistance) {
        minDistance = right;
        minDir = D_RIGHT;
    }
    if (top < minDistance) {
        minDistance = top;
        minDir = D_TOP;
    }
    if (bottom < minDistance) {
        minDir = D_BOTTOM;
    }
    
    // 开始吸附
    switch (minDir) {
        case D_LEFT:
        {
            [UIView animateWithDuration:0.3 animations:^{
                self.superview.center = CGPointMake(self.superview.frame.size.width/2, self.superview.center.y);
            }];
            break;
        }
        case D_RIGHT:
        {
            [UIView animateWithDuration:0.3 animations:^{
                self.superview.center = CGPointMake(ScreenW - self.superview.frame.size.width/2, self.superview.center.y);
            }];
            break;
        }
        case D_TOP:
        {
            [UIView animateWithDuration:0.3 animations:^{
                self.superview.center = CGPointMake(self.superview.center.x, self.superview.frame.size.height/2);
            }];
            break;
        }
        case D_BOTTOM:
        {
            [UIView animateWithDuration:0.3 animations:^{
                self.superview.center = CGPointMake(self.superview.center.x, ScreenH - self.superview.frame.size.height/2);
            }];
            break;
        }
        default:
            break;
    }
}

@end
