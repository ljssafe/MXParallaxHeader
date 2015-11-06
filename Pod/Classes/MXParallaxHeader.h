// MXParallaxHeader.h
//
// Copyright (c) 2015 Maxime Epain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

/**
 The parallac header mode.
 */
typedef NS_ENUM(NSInteger, MXParallaxHeaderMode) {
    /**
     The option to center the content in the header’s bounds, keeping the proportions the same.
     */
    MXParallaxHeaderModeCenter = 0,
    /**
     The option to scale the content to fill the size of the header. Some portion of the content may be clipped to fill the header’s bounds.
     */
    MXParallaxHeaderModeFill,
    /**
     The option to center the content aligned at the top in the header's bounds.
     */
    MXParallaxHeaderModeTop,
    /**
     The option to center the content aligned at the bottom in the header’s bounds.
     */
    MXParallaxHeaderModeBottom
};

/**
 MXProgressBlock type definition.
 
 @param progress The scroll progress.
 */
typedef void (^MXProgressBlock) (CGFloat progress);

/**
 The MXParallaxHeader class represents a parallax header for UIScrollView.
 */
@interface MXParallaxHeader : NSObject

/**
 The content view on top of the UIScrollView's content.
 */
@property (nonatomic,strong,readonly,nonnull) UIView *contentView;

/**
 The header's view.
 */
@property (nonatomic,strong,nullable) UIView *view;

/**
 The header's default height. 0 0 by default.
 */
@property (nonatomic) CGFloat height;

/**
 The header's minimum height while scrolling up. 0 by default.
 */
@property (nonatomic) CGFloat minimumHeight;

/**
 The parallax header behavior mode.
 */
@property (nonatomic) MXParallaxHeaderMode mode;

/**
 The progress block called when scroll is progressing.
 */
@property (nonatomic, strong, nullable) MXProgressBlock progressBlock;

/**
 Initializes a `MXParallaxHeader` object.
 
 @param view   The view to be set in the header.
 @param height The header height.
 @param mode   The behavior mode.
 
 @return The initialized MXParallaxHeader object.
 */
- (nullable instancetype)initWithView:(nonnull UIView *)view height:(CGFloat)height mode:(MXParallaxHeaderMode)mode;

@end

/**
 A UIScrollView category with a MXParallaxHeader.
 */
@interface UIScrollView (MXParallaxHeader)

/**
 The parallax header.
 */
@property (nonatomic,strong,readonly, nonnull) MXParallaxHeader *parallaxHeader;

@end
