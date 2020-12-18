//
//  STControlModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STControlModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *  window对象
 在一个iOS的应用中，window对象一般只有一个。
 window对象负责系统的一些功能，比如键盘的管理是由window对象负责的。一般不负责具体的界面。
 为了可以在一个应用中切换多个界面， 我们不会直接在window中放置一些具体的控件(label), 而是应该给window对象设置一个根根视图控制器，做为第一个显示界面。
 程序员一般很少去频繁地操作window对象

视图控制器(ViewController)和视图(View)
 1 具体功能
     视图(View)  就是我们看见的界面。
             视图是UIView类或子类的对象
     视图控制器(ViewController, 简称为VC)
             是控制视图如何显示的对象
             是UIViewController类或子类的对象
 2 之间关系
     视图是视图控制器的小跟班。
     一般情况下，视图控制器默认拥有一个视图。
     只在创建一个视图控制器对象(VC)，此VC就拥有一个视图对象,做为VC的一个属性而存在:  self.view
     如果将一个VC做为window的根视图控制器，程序一启动，我们看见的就是这个VC的小跟班，self.view

VC类中的viewDidLoad方法
 1 是什么
     是UIViewController类中定义的。
 2 在什么时候调用
     当VC所控制的界面(View)第一次需要显示出来时，要先加载VC,等VC加载完后，自动调用此方法。
 3 干什么
     在此方法中设计界面的初始显示
 4 注意
     一般在此方法的第一行会调用父类的方法，目的是让父类中的设置也起作用。

frame属性
 label.frame = …;
 1 是什么
     是CGRect结构体类型的变量
     CGRect {
             CGPoint origin;
             CGSize size;
     };
     CGPoint{
         CGFloat x;
         CGFloat y;
     };
     CGSize{
         CGFloat width;
         CGFloat height;
     };
     CGRect frame = {x, y, width, height};
     CGRect frame = CGRectMake(x, y, width, height);
     CGPoint point = CGPointMake(x, y);
     CGSize size = CGSizeMake(width, height);
 2 干什么用
     设置视图占用父视图的位置和大小
 3 父视图的坐标系
     父视图坐标系原点(0, 0)在左上角。
     
控件(Control)
 1 什么是控件
     严格来说，凡是UIControl类及子类的对象才叫控件。控件会触发事件。严格来说UIButton是控件，而UILabel不是。

     一般情况下，口头上经常将界面上能看见的东西叫控件。
 2 和视图的关系
     控件就是视图的一种。
     UIControl是UIView的子类。
 
按钮控件(UIButton)
 1 创建按钮
         使用工厂方法
         按钮的类型:
             UIButtonTypeSystem
 2 设置相关属性
     title
     用方法setTitle设置标题，要设置指定状态下的标题:
             Normal
             Highlighted
             Disable
             Selected
     .frame
     …
 3 加入到父视图

 4 添加事件(Event)
     addTarget:action:forControlEvents:
     target： 目标
         当按钮触发了事件时，向哪个对象发消息，经常会用self, 向当前对象发消息
     action:  动作
         向target对象发什么消息
     events: 事件
         当用户触发了按钮对象的哪种事件时，才向target发action消息
     UIControlEventTouchUpInside  手指在按钮上按下并抬起时触发此事件
     UIControlEventTouchDown  手指在按钮上按下时触发此事件

 Interface Builder (IB)
     1 是什么
         是一个工具软件， 以前是独立的，从xcode4开始集成到xcode中
     2 干什么用
         帮助程序员设计和构建界面用的
         可以不写代码或少写来构建界面，提高开发效率
         所见即所得
     3 工作原理
         将界面上需要的控件(或视图)的创建、属性的设置、之间的关系等都保存到一个xml文件中， 程序运行时，从xml文件中读取所有的控件(或视图)的配置，自动创建出这些对象，加入到父视图中。
     4 一些文件
         VC类   ==>    XxxxYyyy.h   XxxxYyyy.m
         IB文件  ==>    XxxxYyyy.xib

     5 如何使用
         1> 创建VC类时，选中XIB
         2> 创建VC对象时，用了initWithNibName: bundle:
         3> 从右边栏下方的对象库中拖拽对象到xib中
         

 *
 */
