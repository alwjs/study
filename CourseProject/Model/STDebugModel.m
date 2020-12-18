//
//  STDebugModel.m
//  CourseProject
//
//  Created by 王继昇 on 2020/12/18.
//

#import "STDebugModel.h"

@implementation STDebugModel


-(instancetype)init{
    self = [super init];
    if (self) {
//                        NSMutableArray *muArr = [NSMutableArray arrayWithObjects:@"1",@"2",@"3",@"4", nil];
        for (int i=0 ; i<10; i++) {
            
            NSLog(@"i的值:%d",i);
//                                NSLog(@"%@",muArr[i]);
        };
        
        for(int i=0;i<26;i++){

            char  value = i+'A';

            NSLog(@"字符：%c",value);

        };
        
        self.userID = @"123";
        self.userName = @"我是用户名";
        self.pwd = @"我是密码";

        
        if ([self login]) {
            NSLog(@"登录成功");
        }else{
            NSLog(@"登录失败");

        }
        
    }
    return self;
}


-(BOOL)login{
    return YES;
    
}

@end
