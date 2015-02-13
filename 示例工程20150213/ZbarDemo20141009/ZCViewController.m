//
//  ZCViewController.m
//  ZbarDemo20141009
//
//  Created by 张诚 on 14-10-9.
//  Copyright (c) 2014年 zhangcheng. All rights reserved.
//

#import "ZCViewController.h"
#import "ZCZBarViewController.h"
#import "QRCodeGenerator.h"
@interface ZCViewController ()

@end

@implementation ZCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    //点击扫描二维码
    [self createButton];
    
    //生成二维码
    UIImageView*imageView=[[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 100, 100)];
    //300数值越高越清晰
    imageView.image=[QRCodeGenerator qrImageForString:@"www.baidu.com" imageSize:300];
    imageView.center=self.view.center;
    [self.view addSubview:imageView];
	// Do any additional setup after loading the view, typically from a nib.
}
-(void)createButton{
    UIButton*button=[UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"二维码扫描" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    button.frame=CGRectMake(100, 100, 100, 60);
    [button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}
-(void)buttonClick:(UIButton*)button{

    
    ZCZBarViewController*vc=[[ZCZBarViewController alloc]initWithIsQRCode:NO Block:^(NSString *result, BOOL isFinish) {
        if (isFinish) {
                    NSLog(@"最后的结果%@",result);
                }
        
    }];
    
    [self presentViewController:vc animated:YES completion:nil];

}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
