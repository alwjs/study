//
//  STDicModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STDicModel : NSObject

@end

NS_ASSUME_NONNULL_END




/*********************************************
 *
 *  字典 NSDictionary NSMutableDictionary
 1.概念
     a.是由键-值对组成的集合，正如，我在查询字典的单词的定义一样。Key-value
     b.通过key(键)，相应的value(值)。通常来讲，key的值是字符串类型，value的值是任意对象类型。
     c.key值是不允许重复的，value的值是可以重复的。
             d.通来来讲key与value的值，不允许为空
            e.可以保存多条数据。
 2.集合的使用
         a.初始化
             NSDictionary* dic = [[NSDictionary alloc]init];
      初始化时，会依次添加元素的value和key
      NSDictionary* dic2 = [NSDictionary dictionaryWithObjectsAndKeys:@"4",@"four",@"3",@"three",@"2",@"two",@"1",@"one", nil];
     b.如果key重复，会舍掉后面的，编译不会报错
 3.向集合中添加元素 NSMutableDictionary
     添加一个元素
    [dic2 setValue:@"5" forKey:@"five"];
 4.查找集合中的元素
     NSString* value = [dic2 objectForKey:@"three"];
 5.得到所有key值
     NSArray* keys = [dic2 allKeys];
 6.遍历
 NSArray* keys = [dic2 allKeys];
 for (NSString* key in keys) {
    NSString* value = [dic2 objectForKey:key];
    NSLog(@"key:%@->value:%@",key,value);
         }

 
 
 *
 */


