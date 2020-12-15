//
//  STStringModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STStringModel : NSObject

@end

NS_ASSUME_NONNULL_END






/*********************************************
 *
 *  NSString
 *
 *
 *
 1.在C语言中，是没有专门的字符串类型，我们是通过字符数组来实现一个字符串。
 2.在OC中专门的类型来描述字符串类型，NSString。
 3.字符串比较特殊，遵循一个"不变模式"，一个字符串一但创建，字符串对象就不可以改变，不可改变的字符串是可以重复使用的，所以相同值的字符串对象，一般只会创建一个对象。
 4.有些字符串存在常量值中(代码区)，有些字符串直接存在堆区。
 5.字符串的使用
   a.字符串创建
     1)空字符串 NSString* str = [[NSString alloc]init];
     2)字符串在创建的时候，如果已经存在，不会创建新的字符串。NSString* str = @"Hello";
      NSString* str2 = @"Hello";
      3)按指定格式来创建字符串
        NSString* str3 = [NSString stringWithFormat:@"%@ World",str];
       4)如果使用stringWithFormat方法创建的字符串，就算内容相同，地址也不一样。
 5)通过文件内容创建字符串，注意存在编码集的问题，默认为ASC(不包含中文)，要指定相应的中文编码集(GBK简体中文、GB2312简体中文、BIG5繁体中文、UTF8全世界主流语言…)
     参数1 文件的路径
     参数2 指定文件的编码集
     参数3 出现异常处理
     NSString* str7 = [NSString stringWithContentsOfFile:@"/Users/apple/Desktop/testString" encoding:NSUTF8StringEncoding error:nil]
 b.字符串的比较 判断等值
     1)str==str1 XXX
         ==只能判断两个字符串是否指向了同一个对象，(引用的地址是否相同)不能判断两个字符串的内容是否相同。
     2)判断两个字符串值是否相同，isEqualToString方法，比较当前字符串与对应字符串值是否相同，严格区分大小写的。
 练习：
 模拟系统登录：创建两个文件，分别保存用户名、密码，创建两个数据库的用户名、密码，匹配登录信息，如果匹配就显示登录成功，否则显示登录失败。

 c.比较字符串的大小
       通常在字符串排序的时候，需要用到比较字符串的小。
             1）compare方法可以比较两个字符串，比较字符串中的字符的ASC码的值
             2）返回值有三种结果 NSComparetionResult
         NSOrderedSame 两者相等 0
         NSOrderedAscending后者比前者大 -1升序
         NSOrderedDecending前者比后者大 1降序
 d.忽略大小写比较字符串
             1)caseInsensitiveCompare这个方法
             2)在验证码功能的时候，会用到此方法
 *
 *
 *
 *             NSMutableString 可变字符串
 可以改变字符串内容的功能，它是NSString的子类。
     1.初始化
         a.空字符串 有意义
      NSMutableString* str = [[NSMutableString alloc]init];
    b.创建字面值 无意义
      不建议用此方式创建可变字符串，字面值字符串的内容，在代码区是无法改变的
     NSMutableString* str2 = @"abc";
 2.修改字符串的内容
      a.在指定位置 添加新的字符串
  参数1 添加的字符串内容
  参数2 添加的字符串在原字符串中的位置
       注：下标是从0开始计算
 [str3 insertString:@"123" atIndex:1];
     b.可以替换指定位置的字符串
    NSRange range={1,3};//位置,长度
    [str3 replaceCharactersInRange:range withString:@"bcd"];
     c.删除指定位置的字符串，后面的字符串会向前补齐
 [str3 deleteCharactersInRange:range];
 3.两个字符串对象的操作
      a.追加字符串
       [str4 appendString:@"bcd"];
   b.按照指定格式追加字符串
       [str4 appendFormat:@"123%@bcd",@"def"];
 4.截取字符串
         a.从指定下标开始，包含开始位置截取字符串
             subStringFromIndex
             从中间到最后
         b.从0开始，到指定位置，不包含指定位置
             subStringToIndex
             从开始到中间
         c.指定范围截取字符串
             subStringWithRange
             NSRange range = {location,length};
 5.字符串大小写转换
         a.将所有的字符串内容变为大写字母
             uppercaseString
         b.将所有的字符串内容变为小写字母
             lowercaseString
         c.将单词的首字母大写
             capitalizedString 转换
 6.得到字符串的前缀和后缀
         TRStudent.h 前缀(TR)和后缀(.h)
         如果一个字符串是文件名，那么可以得到这个字符串的前缀和后缀。
         a.判断一个文件是否有某个前缀
             BOOL b = [str hasPrefix:@"TR"];
         b.判断一个文件是否有某个后缀
             BOOL b = [str hasSuffix:@".h"];

 
 *
 */
