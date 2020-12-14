//
//  AppDelegate.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/14.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow * window;


@end




/*********************************************
 *
 *  在Xcode 11之后，创建新项目会有SceneDelegate
 *如果你的应用不使用像ipad的多窗口，可以把plist文件里的 Application Scene Manifest 删掉，并删掉Scenedelegate.h和Scenedelegate.m这两个文件，再进入APPdelegate.m,注释或者删掉 新增的两个方法就行了
 *
 *在AppDelegate中添加window属性
 *@property (strong, nonatomic) UIWindow * window;

 删除plist中 application scene MainFest
 *
 */

