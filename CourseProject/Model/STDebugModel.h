//
//  STDebugModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STDebugModel : NSObject

@property(nonatomic,copy)NSString *userID;
@property(nonatomic,copy)NSString *userName;
@property(nonatomic,copy)NSString *pwd;


@end

NS_ASSUME_NONNULL_END


/*********************************************
 *
 *  调试窗口 command+shift+Y
 *
 *断点(Breakpoint)绝对是调试程序的第一大选择，基础技能。
 *
 *command+\ 设置断点
 *
 *
 *条件断点
 *
 *condition 填写当前需要设置的条件
 *
 *ignore 忽视断点次数
 *
 *demo:当登录时，会有多次的网路访问，此时我们可以忽略前面固定次数的网路访问，来给需要的情况下断。
 *
 *异常断点
 *exception breakpoint
 *
 *当出现crash时候，会指向崩溃位置
 *
 *
 *
 *符号断点
 *Symbolic Breakpoint
 *
 *
 *
 *符号断点的创建也同异常断点。一般符号断点可以在你指定的[类名 方法名]时中断执行
 *
 *[UIViewController viewDidLoad];

 *或者 viewDidLoad
 *

 *
 *lldb命令
 *po命令、print命令在断点中可以输出变量
 *
 *thread 可以查看不同条件分支结果
 *
 *
 *
 *
 */
