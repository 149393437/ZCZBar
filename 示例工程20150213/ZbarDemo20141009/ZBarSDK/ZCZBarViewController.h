//
//  ZCZBarViewController.h
//  ZbarDemo
//
//  Created by ZhangCheng on 14-4-18.
//  Copyright (c) 2014年 ZhangCheng. All rights reserved.
//
/*
 版本说明 iOS研究院 305044955
 1.8版本 剔除生成二维码文件，使用iOS7原生生成二维码
 1.7版本 修复了开启相机点击，用户如果点击拒绝，会导致崩溃的问题
 1.6版本 增加了支持了区别条码和二维码，可以关闭扫描二维码来增加条码扫描速度
 1.5版本 修正了iOS6下扫描会卡死，增加了iOS7下支持条形码,修改了算法，增加了效率
 1.4版本 支持iOS8系统，修改了相应UI的适配问题
 1.3版本 全新支持arm7s arm64 全新支持ARC
 1.2版本 ZC封装的ZBar二维码SDK
    1、更新类名从CustomViewController更改为ZCZBarViewController
    2、删除掉代理的相关代码
 1.1版本 ZC封装的ZBar二维码SDK~
    1、增加block回调
    2、取消代理
    3、增加适配IOS7（ios7在AVFoundation中增加了扫描二维码功能）
 1.0版本 ZC封装的ZBar二维码SDK~1.0版本初始建立
 
 二维码编译顺序
 Zbar编译
 需要添加AVFoundation  CoreMedia  CoreVideo QuartzCore libiconv
 
 
//示例代码
扫描代码
BOOL代表是否关闭二维码扫描，专门扫描条形码
 ZCZBarViewController*vc=[[ZCZBarViewController alloc]initWithIsQRCode:NO Block:^(NSString *result, BOOL isFinish) {
 if (isFinish) {
 NSLog(@"最后的结果%@",result);
 }
 
 }];
 
 [self presentViewController:vc animated:YES completion:nil];
 
 
生成二维码
 [ZCZBarViewController createImageWithImageView:imageView String:@"http://www.baidu.com"Scale:4];
 */
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "ZBarReaderController.h"
#import <CoreImage/CoreImage.h>
#define IOS7 [[[UIDevice currentDevice] systemVersion]floatValue]>=7


@interface ZCZBarViewController : UIViewController<AVCaptureVideoDataOutputSampleBufferDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate,ZBarReaderDelegate,AVCaptureMetadataOutputObjectsDelegate>
{
    int num;
    BOOL upOrdown;
    NSTimer * timer;
    UIImageView*_line;
}


@property (nonatomic,strong) AVCaptureVideoPreviewLayer *captureVideoPreviewLayer;
@property (nonatomic, strong) AVCaptureSession *captureSession;

@property (nonatomic, assign) BOOL isScanning;

@property (nonatomic,copy)void(^ScanResult)(NSString*result,BOOL isSucceed);
@property (nonatomic)BOOL isQRCode;


//初始化函数
-(id)initWithIsQRCode:(BOOL)isQRCode Block:(void(^)(NSString*,BOOL))a;

//正则表达式对扫描结果筛选
+(NSString*)zhengze:(NSString*)str;

//创建二维码
+(void)createImageWithImageView:(UIImageView*)imageView String:(NSString*)str Scale:(CGFloat)scale;


@end
