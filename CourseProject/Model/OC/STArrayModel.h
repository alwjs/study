//
//  STArrayModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STArrayModel : NSObject

@end

NS_ASSUME_NONNULL_END




/*********************************************
 *
 *  NSArray 数组
 1.概述
     数组是一组有序的集合，通过索引下标取到数组中的各个元素，与字符串相同，数组也有可变数组(NSMutableArray)和不可变数组(NSArray)，数组中不可以保存基本数据类型、结构体数据类型，需要使用NSNumber和NSValue进行数据"封装"。
 2.初始化方法
     a.空数组
       NSArray* array = [NSArray array];
     b.数组中只有一个元素
           NSArray* array2 = [NSArray arrayWithObject:@"one"];
     c.数组中有多个元素
         NSArray* array3 = [NSArray arrayWithObjects:@"one",@"two",@"three", nil];
     d.通过一个已有的数组 创建新的数组
   NSArray* array4 = [NSArray arrayWithArray:array3];
 3.数组的常用方法
       a.数组的长度
         NSUInteger length = [array4 count];
       b.通过数组的下标得到数组中元素
         NSString* objStr = [array4 objectAtIndex:0];
 3.数组的常用方法
     c.遍历数组
         for (int i = 0; i<[array4 count]; i++) {
             NSString* str = [array4 objectAtIndex:i];
         }
 *
 *
 4.在原来数组上添加”一组对象”并创建新的数组
         NSArray* array4 = [array arrayByAddingObjectsFromArray:array2];
 5.在原来数组上添加”一个数组对象”并创建新的数组
          NSArray* array3 = [array arrayByAddingObject:array2];
 *
 *6.将数组中的元素按指定符号连接起来变为字符串。
 NSString* arrayStr = [array4 componentsJoinedByString:@":"];

7.将字符串拆分成数组
 NSArray* stringArray = [arrayStr componentsSeparatedByString:@":"];
8.判断数组中是否包含某个对象，返回值是布尔值类型
BOOL b = [stringArray containsObject:@"5"];
9.获取某个对象在数组的下标，如果数组中不存在该对象，则返回一个垃圾值下标
NSUInteger index = [stringArray indexOfObject:@"5"];
10.获取数组中最后一个元素
 NSString* lastObject = [stringArray lastObject];
11.如果数组中保存某个对象，给数组中所有该对象发送一个消息，数组中的所有对象必须拥有该消息。
存在安全性问题 慎用
 [students makeObjectsPerformSelector:@selector(study)];

 
 
 NSMutableArray(可变数组)
 1.初始化方法
 NSMutableArray* array = [NSMutableArray array];

 NSMutableArray* array2 = [NSMutableArray arrayWithObjects:@"one",@"two",@"three", nil];
 2.向数组中添加一个元素
         [array2 addObject:@"1"];
 3.向数组中添加一个元素在指定位置
         [array2 insertObject:@"2" atIndex:2];
 4.删除数组中指定下标元素
         [array2 removeObjectAtIndex:1];
 5.删除指定对象
         [array2 removeObject:@"1"];
 6.替换指定下标的元素
    参数1 下标 参数2 替换的内容
         [array2 replaceObjectAtIndex:1 withObject:@"two"];

 7.删除数组所有元素
         [array2 removeAllObjects];
         

 NSArray支持的新语法
 1.ios6.0及osx10.8之后，编译器LLVM支持
 2.初始化数据
       C:int array[]={1,2,3};
       OC:[NSArray arrayWithObjects:@"a",@"b",nil];
       OC新:NSArray* array = @[@"a",@"b"];
 3.根据下标得到数组中的元素的值
       OC:[array objectAtIndex:0];
       OC新:array[0];
 六、数组复制（深拷贝(内容复制)、浅拷贝(引用复制)）
 1.复制对象：指针复制（浅拷贝）、内容复制（深拷贝
 2.数组中的元素，对象的引用。
 3.浅拷贝:新数组和原有数组共享内存中的对象。
     NSArray* array2 = [[NSArray alloc]initWithArray:array copyItems:NO];
 4.深拷贝:新数组和原有数组都有独享的对象。
     NSArray* array3 = [[NSArray alloc]initWithArray:array copyItems:YES];

 
 
 *
 */


