ZCZBarSDK
=========

 版本说明 iOS研究院 305044955
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

ZCZBarViewController*vc=[[ZCZBarViewController alloc]initWithBlock:^(NSString *str, BOOL isScceed) {
    if (isScceed) {
    NSLog(@"扫描后的结果~%@",str);
            }
 }];
 [self presentViewController:vc animated:YES completion:nil];
 
 
生成二维码
 拖拽libqrencode包进入工程，注意点copy
 添加头文件#import "QRCodeGenerator.h"
 imageView.image=[QRCodeGenerator qrImageForString:@"这个是什么" imageSize:imageView.bounds.size.width];
