//
//  STDesignModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STDesignModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *  设计模式
 *  mvc
 *  model-view-controller
 *
 *1. MVC
 1.1  是什么
     是一个大型综合的设计模式
         设计模式是解决某一类问题的一种最优的办法
 1.2 为什么要用设计模式
     可重用性，可扩展性，可维护性
     苹果的系统大量使用设计模式
 1.3 MVC 简介
     M:   Model              模型
             处理数据和业务逻辑， 保存数据，业务计算，网络通信
     V:    View                视图
             给用户提供界面显示，接收用户的输入
     C:    Controller     控制器
         控制程序流程及跳转， 协调View和Model之间的工作


     CV:
          C—>V(IBOutlet)
         V—>C(Target-Action, Delegate)
     CM:
         C—>M
         M 不能直接访问C， 但可以用通知的方式发消息
     MV:
         M和V不可以通信

 *
 *
 *
 *  mvvm
 *  model-view-viewmodel
 *
 *建立项目时，细分功能模块，文件夹创立好分类，管理方便
 *
 *
 *附图
 *
 *
 *
 *
 *路由
 *route 就是一条路由，它将一个URL路径和一个函数进行映射，例如：
 
 *  *****  /users        ->  getAllUsers()
****** /users/count  ->  getUsersCount()
 
 
 在任意也秒跳转到指定页面
 * 随时随地弹出指定页面等等
 *
 *当同一个表视图需要展示十几种不同样式的UI时，可以根据type的不同，来指定展示样式

 *
 *简单讲 路由就是URL到函数的映射
 *
 *优点
 *1.低耦合，支持热小型热更新
 *
 *2.样式不定，事件不定，全部由服务端来控制
 *
 *3.客户端bug出现减少！
 *
 */
