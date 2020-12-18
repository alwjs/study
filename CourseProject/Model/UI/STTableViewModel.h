//
//  STTableViewModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STTableViewModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *  1. UITableViewController (表视图控制器)
 1.1  是什么
     是列表方式展示数据的一种VC
 1.2 在哪儿用
     非常常见， 有规律的展示固定样式的数据
     如果不用TableView, 管理大量数据时:
         1>  手动管理布局，计算坐标
         2>  手动判断和处理事件
         3>  手动设置每一个控件的值
         4>  手动管理内存
 1.3 能帮助我们干什么
         管理布局，管理事件，有规律的展示数据，管理内存...
 1.4 组成：
     UITableViewController 中的view类型是UITableView
     UITableViewController
     +   tableView  : UITableView
          +   Table Header                   表头
                 +   Section      *                 分区
                     +   Section  Header    分区头
                         +   Row    *                 行
                     +   Section  Footer      分区尾
          +   Table Footer                     表尾
     
     表头，表尾，分区头，分区尾都可以没有。
     TableView 有两种Style:
         Plain  :   普通Style   没有分区(只有一个分区)
         Group:   组   有多个分区
 1.5 UITableView两个委托
         .dataSource : id<UITableViewDataSource>
                 数据源   是TableView显示的数据的来源
         .delegate ：id<UITableViewDelegate>
                 处理一些除数据源之处的其他事项如触发的事件等
 1.6 [Demo1]  如何创建一个UITableViewController界面
         1> 创建一个自己的类TRMyTableViewController , 继承自UITableViewController.
         2> 在此TRMyTableViewController中回答dataSource协议要求的问题
         3> 将此VC展示出来

 1.7 UITableVIew 最重要的问题:
         三问一响应, 之三问:
             1> 你有几个区要显示？
             2> 你每个区有几行要显示？
             3> 你每一行显示的内容是啥样的？
         一响应:
             当用户选中某一行时，调用的方法
 
 1.8  当我们的VC继承UITableViewController时发生的事:
         1> Xcode自动将此VC设置为VC中的tableView的数据源和Delegate
         2> VC继承的父类UITableViewController已经遵守了两个协议:UITableViewDataSource, UITableViewDelegate
         3> VC类已经实现了三个方法:
             有多少区， 多少行， 每行的内容
 1.9 [Demo2] 多分区
         1> 创建一个VC继承自UITableViewController
         2>
         
 1.10 indexPath
     NSIndexPath
     是一种集合， 用来存储路径。
     在UIKit Framework中，定义了一个分类，分类中：
         .section  描述哪个分区
         .row         描述此分区的哪一行

 1.11 TableView的原理
     参照图table_work.png

 1.12 UITableViewCell类
     1> 是什么
         TableView中每一行就是一个UITableViewCell类型的对象
         UITableViewCell其实是UIView的子类， 他是一人视图
     2> 此视图有以下子视图，都是其属性：
         .textLabel  : UILabel   用于在Cell上显示文字内容
         .detailTextLabel : UILabel 用于显示详细内容
         .imageView : UIImageView  用于显示图片
     3> Cell的Style（系统提供的）
         Default:   默认， 不显示详细信息
         Value1:  左右显示主要信息和详细信息
         Value2:  居中显示详细信息，不显示图片信息
         Subtitle:  可以显示详细信息，详细信息另起一行显示
         也可以自定义Cell
     4> Cell的重用
         4.1 第一种重用方式
             [Demo3]
             tableView在运行期间，出了界面的Cell并不会释放，而是放入了tableView中的队列中，所以，需要在创建Cell对象之前先试着从此队列中去拿已经存在的Cell对象，如果能拿到，就不需要再创建，而是重用此Cell对象。
     
     演示用TableView显示数组中的数据。
     
     4.2 第二种重用方式
         [Demo4]
         向tableView注册一个重用的Cell类
         [self.tableView registerClass:[UITableViewCell class]  forCellReuseIdentifier:cellIdentifier];
         注册后，如果向tableView索要队列中的Cell对象时，如果队列中没有Cell对象，tableView会自动帮我们创建一个并返回。这样可以确保dequeue方法一定会返回一个Cell对象供我们使用。


2. TableView三问一响应之一响应 及展示数据
 [Demo4]
     2.1 从TableView中推出一个普通的VC  [Demo5]
         + areas   :  NSArray
                 + [item] :  TRArea
                     +  name : NSString
                     +  population : NSUInteger
                     +  imageName : NSString
     2.2 从TableView中推出一个新的TableView  [Demo6]
         + areas   ： NSArray
             + [item]  :  TRArea
                 +   name  :  NSString
                 +   imageName : NSString
                 +   population : NSUInteger
                 +   subareas  : NSArray
                         +  [item]   :   NSString
     2.3 用多个分区显示每个子地区的数据  [Demo7]
         数据模型和2.2相同
         
3. 如何向TableView中增加一行数据
 [Demo8]
     1> 增加时跳转到一个新的VC，等待用户输入
     2>用户输入完成，点确定按钮， 返回
     3> 返回前向delegate发消息，传参数

     自己的TableViewController要做三件事:
         1>遵守协议
         2>实现方法
         3>将自己设置成委托方的delegate
     
     在方法中， 先将传来有数据加入到数据源中
     再更新tableView:
         1>  reloadData   全部更新
         2> insertRowsAtIndexPath:…   局部更新



 
 
 --------------------------------------------
 *
 * 1. TableView的编辑模式
 1.1 是什么
         可以被 插入、删除、移动Cell的一种状态
 1.2 如何进入编辑模式
         1> UITableView有个属性editing(BOOL),将其设置为YES会进入编辑模式，NO会退出编辑模式
         2> 如果用继承的方式创建TableViewController时，Xcode会在viewDidLoad方法中加入一句:
                 self.navigationItem.rightBarButtonItem = self.editButtonItem;
             self.editButtonItem是父类准备好的一个按钮对象，此按钮对象按下后，TableView就会进入编辑模式，再按一次就会退出编辑模式
 1.3 如何删除和插入行
     两问一响应:
         之两问：
         1> 哪些行可以进入编辑模式:（默认是所有行）
             -(BOOL)tableView:canEditRowAtIndexPath:
         2> 进入编辑模式后的样式是什么: （默认是删除样式)
             可选的样式只有两种:  删除行和插入行
             - (UITableViewCellEditingStyle)tableView: editingStyleForRowAtIndexPath:
         之一响应:
             当用户真正要删除或插入一行时，调用的方法
     - (void)tableView: commitEditingStyle: forRowAtIndexPath:
     删除行:
             //1. 先删除数据源中的数据
     [self.contacts removeObjectAtIndex:indexPath.row];
     //2. 再删除tableView中对应的行
     [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
插入行:
   //1. 先向数据源增加数据
     TRContact *contact = [[TRContact alloc]init];
     contact.name = @"Shasha";
     contact.age = 19;
     contact.phoneNumber = @"18612345678";
     [self.contacts addObject:contact];
     //2. 再向TableView增加行
     NSIndexPath *indexPath = [NSIndexPath indexPathForRow:self.contacts.count - 1 inSection:0];
     [tableView insertRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
         
     1.4 移动行
         一问一响应
         一问:  哪些行可以移动 (默认所有行都可以移动)
                 - (BOOL)tableView: canMoveRowAtIndexPath:
         一响应: 当用户进行移动时，调用的哪个方法处理数据
             - (void)tableView: moveRowAtIndexPath: toIndexPath:
             在此方法中要做的事情是，更新数据源中的数据顺序
 
2. UITableViewCell高级
 2.1 是什么
     是视图， 是UIView的子类
 2.2 组成:
     两大视图:
     + contentView :  UIView        内容视图
         +  textLabel  : UILabel
         +  detailTextLabel   :   UILabel
         +  imageView  :  UIImageView
     + accessoryView : UIView    辅助视图
         默认情况下，accessoryView是nil
         编辑模式下，accessoryView会自动隐藏起来

 2.3 辅助视图(accessoryView)
     1> 是UIView类型的属性，可以指向任何类型的视图
     2> 系统提供了4种已经定义好的辅助视图
         系统提供的辅助视图通过属性accessoryType来指定
     3> 除了系统的提供的外，我们还可以自定义辅助视图
         自定义的辅助视图通过属性accessoryView直接赋值的方式来指定
     4> 当Cell走入编辑模式，辅助视图会自动隐藏起来
     
 2.4 系统提供的4种辅助视图：
     由一个枚举类型区分:
         UITableViewCellAccessoryType:
             DisclosureIndicator
                     :  一个“>”号，提示用户点击此Cell有更详细的信息
             DetailDisclosureButton
                     ： 一个“i”按钮+”>” 提示用户，点击此按钮而不是Cell会有更详细的信息,调用一个方法来展示详细信息
             - (void)tableView:accessoryButtonTappedForRowWithIndexPath:
   Checkmark
     ： 一个”√” ，相当打个标记
   DetailButton
     ： 一个“i”按钮， 提示用户，点击此按钮会调用一个方法
             - (void)tableView:accessoryButtonTappedForRowWithIndexPath:
     2.5 自定义的accessoryView
         cell.accessoryView = …(任意视图，如按钮，开关…)
         [Demo2]

     2.6 自定义的contentView
         contentView中的子视图.textLabel, detailTextLabel, imageView如果不赋值，都是nil
         如果我们不给这三个属性赋值，而是自定义一些视图addSubview到contentView,那么,contentView中的内容就完全成自定义的。
         [Demo3]

     用到了tag属性
         任何一个视图对象都有tag属性， 可以用于标记一个父视图中唯一的子视图，相当于编号
         我们可以用此编号从父视图中拿指定编号的子视图对象:
             [superView viewWithTag:tag];
     

 -----------------------------------------
 
 1. TableView中的自定义Cell
     1.1 基本原理
         UITableViewCell类是TableView的标准Cell类
         自定义Cell就是自己写一个Cell类，然后在三问的最后一个问题“每一行的Cell”中回答时，创建自己定义的Cell类的对象并返回。
      1.2 如何实现
         借助xib文件的功能，创建自定义Cell的界面，然后和自定义的Cell类进行绑定即可。
         [Demo1]
             1> 创建自定义的Cell类, 继承UITableViewCell
             2> 创建自定义的Cell的xib文件
             3> 在xib文件中设计Cell的样子
             4> 选中xib中的Cell,在检查器3中绑定类
             5> 将xib中的界面控件连线到类中的公开属性上
             6> 使用Cell类
                 在TableViewController中回答第三个问题时，返回的对象为自定义的Cell类型的对象
                 注意：需要在viewDidLoad方法中注册此Cell类，注册方式是使用xib进行注册:
     [self.tableView registerNib:nib forCellReuseIdentifier:cellIdentifier];
             
             向TableView dequeue一个Cell对象时：
             if(根据标识符, 有可重用的Cell){
                     return 可重用的Cell;
             }else if(当前请求的Cell的标记识已经被注册过){
                     return 自动创建一个Cell对象；
             }else{
                     return nil;
             }
         
 2. 静态(Static)的TableView
         2.1 什么是
             程序员直接写死TableView中多少分区，多少行，及每行的内容
         前面一直在使用动态的TableView, 动态(Dynamic)的TableView指的是多区的个数，行数，每行的内容都是数据模型来决定，而不是写死。
         2.2 如何创建静态的TableView
             硬代码直接回答所有问题
             可能会在大量的if  else语句，或switch
             [Demo2]
         2.3 应用广泛
             各种设置界面
             展示一个对象的信息
         
             静态TableView并不意味着Cell中的内容不会变化


       2.4 使用xib创建静态TableView
             [Demo3]
             
             1> 一个xib文件中除了可以创建一个VC的V部分，还可以创建任何View对象，比如一个UITableViewCell对象
             2>一般一个xib文件只会有一个根对象，但其实可以有很多的根对象
             3> 每一个根对象，在控制器被加载时创建(viewDidLoad方法调用时已经创建好了)
             4> 一般情况，多个根对象，其中只有一个对象是和控制器类绑定在一起的，其他的根对象，一般会做为控制器的属性存在。
             
         
 3. 灵活的使用TableView
     [Demo4]
     3.1 代码+xib的方式
             从对象中拖拽一个TableView到任意视图中
             然后选中TableView,在第6个检查器中指定DataSource和Delegate
             在TableView的DataSource和Delegate类(一般会是当前的VC)中遵守相关协议(UITableViewDataSource,UITableViewDelegate)
             并实现应该有的方法
     3.2 纯代码
             
 到此， UITableViewController基本讲完了


 
 
 
 -----------------------------------------
 *
 *
 2. UICollectionViewController
     2.1  是什么
         是一个展示大量数据的控制器，功能几乎和UITableViewController差不多，其实是UITableViewController是变种。 是正直的二维表(多行多列)。
         从iOS6开始支持
     2.2 使用
         使用方式类似TableViewController:
     2.3 UITableViewController和UICollectionViewController比较        2.3.1 相似点

 UITableViewController:
     .tableView   :   UITableView
         .dataSource  :   id<UITableViewDataSource>
         .delegate  :  id<UITableViewDelegate>
     DataSource三问:
         多少个分区
         多少行
         每行的Cell啥样  cell  : UITableViewCell
     Delegate中的一响应:
         用户点击Cell时调用啥方法

 UICollectionViewController:
     .collectionView  :   UICollectionView
         .dataSource  :  id<UICollectionViewDataSource>
         .delegate :  id<UICollectionViewDelegate>
     DataSource 三问:
         多少个区
         每区多少条目(Item)
         每个Cell啥样  cell   :  UICollectionViewCell
     Delegate一响应:
         用户点击Cell时调用的方法

         2.3.2 不同点：
             1> CollectionView是多行多列
             2> CollectionView中的Cell一般需要自定义
                 UICollectionViewCell中都没有定义.textLabel  .detailTextLabel  .imageView等属性，所以一般情况下，Cell需要自定义。
             3> CollectionView可以指定布局类，进行布局
                 可以使用UIKit提供的一个布局类UICollectionViewFlowLayout, 也可以自定义布局类

         2.4 [Demo1]
             1> 创建CollectionViewController类
             2> xib中删除view, 增加一个CollectionView
                 设置Cell大小等相关属性
                 将CVC中的view属性连线到CollectionView
                 设置CollectionView的dataSource和Delegate
             3> 自定义Cell
                 方式和TableViewCell一样:
                     创建类，继承UICollectionViewCell
                     创建空xib, 拖拽CollectionViewCell
                     设计界面
                     绑定类
                     拉属性
             4> 注意Cell类
             5> 回答三问，使用Cell类
         
         2.5 CollectionView的一些常用设置属性：
             layout  :  Flow  / Custom
             如果选择了Custom, 需要指定一个布局类，此类一般需要自定义
             Scroll Direction : 滚动的方向，默认是垂直，可以水平
         CollectionView是UIScrollView的子类，所以有pagingEnabled属性

         2.6  布局
             2.6.1 是什么
                 CollectionView的布局是其精髓，相当于CollectionView的大脑和中枢，负责设置CollectionView的一些属性:
                 位置
                 尺寸
                 透明度
                 层级关系
                 形状
                 。。。。
         2.6.2  本质
                 布局是对象， 是UICollectionViewLayout类的子类的对象。 UIKit提供一个布局类：
             UICollectionViewFlowLayout : UICollectionViewLayout
         流式布局类， 所有的Cell挨着放。
     
         2.6.3 自定义布局
             写一个类， 继承自UICollectionViewLayout或继承UICollectionViewFlowLayout
             创建此类的对象，设置为collectionView的布局属性即可
         [Demo1]
             在此，演示一下纯代码方式使用CollectionView

             1> 自定义一个类, 继承自UICollectionViewFlowLayout
             2> 创建一个普通的ViewController
             3> 在Controller中的viewDidLoad方法中，纯代码创建CollectionView对象:
                     1>创建布局对象
                         设置布局的相关属性: itemSize  min…
                     2>创建CollectionView对象，并设置布局
                     3>设置DataSource和delegate
                     4>加入到self.view中

 

 
 
 *
 */
