//
//  STViewModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STViewModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *
 1. IBOutlet,IBAction
  IBOutlet是一种属性，这种属性指向了xib中的一个对象
  IBAction是一个方法，这个方法连接到了xib中的一个控件的某个事件上。当用户触发了这个控制的这个事件，就会调用此方法。
  2. 事件方法的参数
      任何一个控件产生事件时，如果调用一个方法，且这个方法有参数，就会将控件自身传给这个参数。
  
 3. UIStepper, UISlider, UISwitch
  [Demo2]
  3.1 UIStepper控件
      重要属性:
          .value                            当前值
          .stepValue                步进值(每点一次增减多少)
          .minimumValue      最小值
          .maximumValue     最大值
      最常用事件:
          valueChanged
  3.2 UISlider控件   滑块
      重要属性：
          .value
          .minimumValue      最小值
          .maximumValue     最大值
      常用事件:
          valueChanged
  3.3 UISwitch   开关
          重要属性:
              .on     :  BOOL   (isOn)
          常用事件:
              valueChanged
          
      在iOS中，改变一个控件的属性会导致界面发生变化的，这种属性一般都会提供一个方法:
      setXxxx:animated:
      可以让我们选择在属性改变时界面的变化是否需要动画。
      

  
  4. UITextField控件
      4.1 是什么
          是一个单行文本框， 用来接收用户输入的一个控件
      4.2 使用
          [Demo3]
      4.3 属性
      4.4 第一响应者(First responder)
          一个界面中一般只有一个第一响应者。如果UITextField控件变成第一响应者时，键盘会自动弹出。
          如果想取消键盘，就得让UITextField控件放弃第一响应者身份。
          给TextField控件发消息: resignFirstResponder, 就可以让其放弃第一响应者身份。
          1>  在确定按钮的方法中让两个TextField放弃第一响应者身份
              [self.usernameTextField resignFirstResponder];
              [self.passwordTextField resignFirstResponder];
          2> 用户点击背景时让两个TextField放弃第一响应者身份
                1>  选中view对象
                2>  在第3个检查器中将view的类型从UIView改成UIControl
                3>  从view上接线到代码中，创建方法，方法的事件要选择Touch Up Inside
      
          4.5 常用事件
          Did End On Exit
          当用户点击了键盘右下角的按钮时触发此事件。
          
  5. UIAlertView类（对话框）
      5.1 基本API
              UIAlertView *alert = [[UIAlertView alloc]initWithTitle:…..];
              [alert show];
      5.2 委托(Delegate)
          5.2.1 是什么
              一个对象(对象A)委托另一个对象(对象B)做事(调用方法), 我们把对象A叫委托方， 对象B叫被委托方。
          5.2.2 委托协议
              委托方希望被委托方能做的事情写入协议
              UIAlertView是委托方， UIAlertView同时定义了一个协议UIAlertViewDelegate
          5.2.3 被委托方需要做的事:
              1>   遵守协议  @interface Xxxx <UIAlertViewDelegate>
              2>   实现协议中规定的相关方法
              3>   将自己设置成委托方的delegte对象, 委托方对象有一个属性叫delegate,需要指向被委托方。
          
              我们经常将委托对象回头调用被委托对象中的方法的这种方式叫回调(Callback)
              
 
 
 
 
 
 
  UINavigationController(导航视图控制器)
     1 是什么
         是控制器(UIViewController的子类)， 是一个控制器的控制器,是用来管理其他VC的VC
     2 有什么用
         管理和控制VC的走向， 比present方式更好，更清晰
     3 怎么用
         1> 创建UINavigationController对象
                 初始化时指定一个根视图控制器
         2> 推出一个界面(VC)
                 pushViewController:xxx
         3> 回退前一个界面:
                 不写任何代码
                 或者:  popViewController
         [Demo4]
     4 内部原理
         1> navi内部维护着一个VC对象的数组
             self.navigationController.viewControllers
             将此数组当做栈来管理
             栈是一种数据结构，特点先进后出(FILO) 后进先出(LIFO)
         2>navi必须有一个根VC， 第一个被navi包含的VC
                 [[UINavigationController alloc]initWithRootViewController:xxxx];
         3> push一个新界面(VC)， 旧的VC不会释放
         4> navi会保持所有push进去的VC的引用， push一个VC其实是将此VC放入navi中的数组中。
         5> 当pop一个VC从navi中出来时，此VC就会被释放。
         6> 不能pop根VC
         
     5 使用方式

     5.1   NavigationBar(导航栏)
         1> 标题(Title)
                 在具体的VC中，设置一个属性.title
         2> 按钮
                 .navigationItem.leftBarButtonItem
                 .navigationItem.rightBarButtonItem
         3> UIBarButtonItem
                 专门用于各种Bar上的按钮，和UIButton不一样
             
             系统按钮
                 initWithBarButtonSystemItem:target:action初始化的

             文字按钮
                 initWithTitle:style:target:action 初始化的
         4> 多个按钮
                 .navigationItem.leftBarButtonItems
                 .navigationItem.rightBarButtonItems
     
         2.5.2 ToolBar（工具条）
             1> NavigationController自身带着ToolBar
                 默认情况下，此ToolBar是隐藏的
                 如果需要，可以如下设置显示:
                 self.navigationController.toolBarHidden = NO;
             2> 给ToolBar加按钮
                 self.toolBarItems
             3> 特效按钮
                     
                     Fixed  :     木棍效果， 填补指定宽度的空间
                             UIBarButtonSystemItemFixedSpace
                             fixed.width  棍长

                     Flexible :   弹簧效果， 尽可能的填补空白
                             UIBarButtonSystemItemFlexibleSpace
     
         5.3 属性设置的生效范围
             .title
             .navigationItem.left/rightBarButtonItem(s)
             .toolBarItems
                 只在当前VC中生效

             self.navigationController.toolbarHidden
                 生效于所有被navi包含的vc

         5.4 在NavigationController中再次present一个NavigationController
  
 
 
 
 
 
 
 图像UIImageView
     1 基本概念
         NSString    ==>   UILabel
         UIImage    ==>   UIImageView
     2 在界面上显示图像
         UIImageView对象， 加入到父视图（如self.view）
         [[UIImageView alloc]initWithImage:UIImage];
         注意：代码创建的UIImageView的frame大小默认与图片的大小相同。
     3 .contentMode属性
         任何视图都有的一个属性
         类型是UIViewContentMode类型(枚举)
         
             UIViewContentModeScaleToFill, //默认值， 拉伸
             UIViewContentModeScaleAspectFit;//保持宽高比,显示完整图片，留边
             UIViewContentModeScaleAspectFill //保持宽高比， 不留边，不保证显示完整图片
     
 UIScrollView
         1 作用
             在有限的区域中显示较大的数据(图片，文字)
         2 本质
             是一个View的View
             用来管理其他视图的
         3 如何使用
             将其他的视图放入ScrollView，设置相关属性即可
         4 关键属性
             .frame   //scrollView有多大
             .contentSize  //scrollView中的内容的大小
          这两个属性设置好后，即可滚动。但前提是.contentSize一定是比.frame的size大。
         5 如何让scrollView进行缩放
             1> 设置相关属性
                 .minimumZoomScale
       .maximumZoomScale
            2> 给scrollView指定delegate对象，回答以下问题:
      scrollView中的哪个子视图需要缩放
     - (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
     
            其他属性
             .contentInsets
             .contentOffset
             setContentOffset:animated:
             .pagingEnable
         

 UIPageControl
     1 重要属性
        currentPage
         numberOfPages
        pageIndicatorTintColor
        currentPageIndicatorTintColor
        userInteractionEnabled
   2 和ScrollView配合使用
   
 
 
 
 
 UITabBarController(标签控制器)
     1 是什么
         类似于UINavigationController, 也是一个控制器的控制器
         经常看见的UITabBarController表现为UITabbar
     2 如何使用
         创建UITabBarController
         设置属性.viewControllers = @[vc1, vc2, vc3, vc4]
     3 重要属性
             设置VC的属性:  .title   .tabBatItem, 来显示TabBar上不同的内容
         [Demo5]
     
     4 Navigation和TabBar一起工作
             此时，UITabBarController是window的根视图控制器
             UITableViewController包含NavigationController,有可能会包含多个UINavigationController对象
             每一个具体的VC就是每个NavigationController的根视图控制器
         Window==>TabBar==>Navigation==>VC


 
 
 
 *
 */
