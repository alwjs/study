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
