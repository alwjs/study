//
//  STLifeCycleModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STLifeCycleModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *
 *
 *生命周期
 *iOS main函数 UIApplicationMain
 *
 *状态如下：
 
 Not running  未运行  程序没启动

 Inactive   未激活   程序在前台运行，不过没有接收到事件。在没有事件处理情况下程序通常停留在这个状态

 Active    激活      程序在前台运行而且接收到了事件。这也是前台的一个正常的模式

 Backgroud   后台   程序在后台而且能执行代码，大多数程序进入这个状态后会在在这个状态上停留一会。时间到之后会进入挂起状态(Suspended)。有的程序经过特殊的请求后可以长期处于Backgroud状态

 Suspended    挂起     程序在后台不能执行代码。系统会自动把程序变成这个状态而且不会发出通知。当挂起时，程序还是停留在内存中的，当系统内存低时，系统就把挂起的程序清除掉，为前台程序提供更多的内存。

  
 
 application:willFinishLaunchingWithOptions: - 在启动时的第一次机会来执行代码
 application:didFinishLaunchingWithOptions: - 在显示app给用户之前执行最后的初始化操作
 applicationDidBecomeActive: - app已经切换到active状态后需要执行的操作
 applicationWillResignActive: - app将要从前台切换到后台时需要执行的操作
 applicationDidEnterBackground: - app已经进入后台后需要执行的操作
 applicationWillEnterForeground: - app将要从后台切换到前台需要执行的操作，但app还不是active状态
 applicationWillTerminate: - app将要结束时需要执行的操作

 
 
 ViewController
 
 - (void)viewDidLoad；-页面加载时

 - (void)viewWillAppear:(BOOL)animated；-页面即将显示时

 - (void)viewDidAppear:(BOOL)animated；-页面显示时

 - (void)viewWillDisappear:(BOOL)animated；-页面即将消失时

 - (void)viewDidDisappear:(BOOL)animated；-页面消失时
 *
 *
 *
 *
 *
 *
 *
 *
 */
