//
//  STGrammarModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STGrammarModel : NSObject

@end

NS_ASSUME_NONNULL_END




/*********************************************
 *
 *OC语法
 *
 *
 *
 *  1.变量的类型
 
 1.1 变量的类型有两种
     整数
     浮点数
         int x;
         float y;
     另一种说法4种:  char   int   float   double
 1.2 整数类型
     有符号的:
     1) 整数
         int x;   4bytes   -2147483648  ~  2147483647   -2G  ~2G
     2) 短整数
         short int x;  2bytes  01011101 00111111   -32768~32767
     3) 长整数
         long int x;   8Bytes(64Bit系统中)   4Bytes(32bit系统中)
     4) 长长整数
         long long int x;  8Bytes
     无符号:
     1)整数
         unsigned int x;  0~4G  4Bytes
     2)短整数
         unsigned short int x;  0~65535
     3)长整数
         unsigned long int x;
     4) 长长整数
         unsigned long long int x;
     有符号和无符号的类型占用的内存空间是相同的，只是无符号不能表示负数。
2.特殊整数
 2.1  保存整数
     char   1Byte    -128~127
     unsigned char  1Byte  0~255

 2.2 保存字符
     char 还可以保存字符
     char类型的变量保存的其实是字符的编码。
     'A'      65
     'a'      97
     '0'      48
     ASCII
     字符就是整数。

3. 浮点数
 3.1 有三种类型的浮点数:
 float  4Bytes
 double  8Bytes
 long double   16Bytes
 没有无符号的说法，所有的浮点数都是有符号的。
 3.2 浮点数的表示方式:
         1)普通方式
             double d = 3.14;
             .314   ==> 0.314
             314.     ==> 314.00
         2)科学计数法
             3.14E0  ==> 3.14
             3.14E1  ==> 31.4
             3.14E-1 ==> 0.314
             .314E3  ==> 314
4. 赋值
 4.1 给整数赋值
     1) 常见方式(十进制赋值)
             int x = 123;
     2) 八进制赋值, 以前缀'0'开头的数是八进制整数
             x = 0100;
     3) 十六进制赋值，以前缀"0x"开头的数
             x = 0x100;
 4.2 进制
     逢十进一叫十进制，逢八进一叫八，逢十六进一叫十六进制
 4.3 进制之间的转换
     十进制  ==>   二进制
         100 ==>   00000000 01100100
         100 = 64 + 32 + 4   1100100
     八进制  ==> 二进制: 一个八进制对应三个二进制位
         0123  ==>  00000000 01010011  ==>64+16+2+1
     十六进制  ==> 二进制:  一个十六进制数对应4个二进制位
         0x3E  ==>  00000000 00111110 ==>62
     二进制 ==> 十进制
     01111101  ==> 2(6)+2(5)+2(4)+2(3)+2(2)+2(0) = 125
     二进制 ==> 八进制
      01111101  ==> 001 111 101 ==> 0175
     二进制 ==> 十六进制
     01111101   ==> 0111 1101  ==> 0x7D

5、 运算符
5.1 运算符的特性
     如  +   -   *   /    这些对数据进行计算的符号叫运算符。
     1) 优先级
         在一个表达式中，一些运算符需要先算，一些需要后算，运算符的先后就是所谓的优先级。
         优先级最高的运算符是 ( )
         优先级最低的运算符是 赋值运算符  = += -=….
         单目运算符的优先比双目高， 双目比三目高。
         遵循数学习惯  ：  乘除比加减高 …
   2) 结合性
         当优先级一样时，从左向右算叫左结合，从右向左算叫右结合。
         一般的运算符都是左结合的，右结合的运算如:
         ++
         --
         赋值
         x = 3 + 4;
         x = y = z = 1;

6.流程控制语句
6.1
if (){
}else if(){
}
6.2
switch(表达式){
     case 1个整数常量:  0~n条语句;
     case 1个整数常量:  0~n条语句;
     case 1个整数常量:  0~n条语句;
     case 1个整数常量:  0~n条语句;
     default: 0~n条语句;
 }
6.3
for(表达式1; 表达式2; 表达式3)语句;
6.4
while;
do…..while;

7.    函数(function)
7.1.概念
 f(x) = x(2) + 2x + 4;
 
 int fa(int x){
     return x*x + 2*x + 4;
 }
 函数其实是一段要执行的代码，这段代码有一个名字，就是函数名。这段代码相当于一个算法，有输入，叫函数的参数，有输出，就是函数的结果，一般只能返回一个结果。

返回值类型 函数名(参数列表){
     函数体部分(0~n条语句)
     return 值;
 }

7.2.名词解释
 2.1 函数名
     一个变量有名字，一个函数也有名字。函数的名字代表函数中那段代码的开始位置(地址)
 2.2 参数列表
     一个函数有可能会有参数，也可能没有。参数实质上是变量，如果有多个参数，就定义多个变量，变量之间用","号隔开。
 2.3 返回值
     可以认为返回值是一个函数计算的结果。在函数内部，用 return语句将返回值返回。

7.3. 调用函数
 用函数名调用函数，目的是为了执行函数中的代码，并要求得到一个结果。调用函数时需要传参数，函数要求几个参数，得传几个。

7.4. 函数的参数
 7.4.1 形式参数(形参)和实际参数(实参)
     定义函数时，参数列表中应该定义形参。
     调用函数时，传参数是实参。传参相当于赋值。
 7.4.2 参数的个数
     0，1，2 …. n
     1) 无参，可以传任意多的参数给函数，但没意义。
     2) void形参，规定必须不能传任何参数给函数
     3) 多个形参，之间要用","隔开，函数有几个形参，调用时就得传几个实参。个数要完全一致。
     4) 当形参和实参的类型不一致，编译器会试图将实参的类型转换成形参的类型，转换的后果未知。

7.5. 函数的返回值
 7.5.1 函数的返回值基本相当于函数的运算结果。在函数中用return语句返回需要的值。如果return 语句后面跟的值的类型和函数的返回值类型不一致，编译器会试图将返回值转换成函数的返回值类型，后果未知。
 请试试返回值类型不同会怎么样
 7.5.2 函数没有返回值，函数前加"void"
     这种函数，函数体中一般不会有return,在这种函数中return相当于结束函数的执行。
 7.5.4 如何处理返回值
     1)  用一个变量保存起来，以后使用
     2)  让返回值直接参于运算
     3)  直接将返回值丢弃掉
     4)  直接当做实参传递
     
     其实，函数的返回值是一个临时变量。
     但是，临时变量是不能做为左值。

8. 指针
 8.1 指针是变量
     用来保存地址的变量，叫地址变量，也叫指针变量，简称指针。
     当一个指针变量(如px)保存了另一个变量(如x)的地址时,我们就说"px指针指向了x".
 8.2 指针的应用
     1)  在函数的参数上使用指针
         可以让函数修改函数外面的变量的值
         可以让函数的指针参数带回来一些函数运算的结果
     2) 函数也可以返回一个指针
         不要在函数中返回局部变量的地址，因为函数一旦返回，局部变量的空间就会马上释放，指向这片空间地指针就会变成悬空指针，这是非常危险的事情。

9. 指针和数组
9.1. 数组(array)
 9.1.1  概念
 数组就是很多同类型的变量。数组中的变量经常叫数组的元素，而且这些元素没有名字，统一用数组的下标来表示这些变量。
 下标是一个序号，序号从0开始，依次递增。这个序号叫下标。
  数组中的元素在内存中是连续的，数组本身就是内存中的一片连续的空间。所以数组中的元素，只要知道它的下标，就可以计算出它的地址。
 数组本身其实是一个变量，有类型，有名字。数组名其实是整个数组内存空间的首地址。
 9.1.2 语法
     定义数组:  元素类型  数组名[元素个数];
     访问元素:  数组名[下标]
 9.1.3 下标
     下标不能越界，如果越界，可能会导致以下后果:
         1) 程序直接崩溃
         2) 莫明的改变了其他变量或数据空间的值
         3) 什么事儿都没有
 9.1.4 数组的初始化
         当数组定义好之后，如果没有初始化，数组中的数据就是垃圾数据。
 所以，数组定义时一般要做初始化工作。
         数组元素类型  数组名[长度] = 初始化表达式;
     初始化表达式： {1,2,3,4,..}
     
 9.1.5 数组名
     数组名是一个地址，而且是不可变的地址。数组名不可以做为左值，就是不能出现在赋值语句的左边。初始化除外。
     数组名是常量(指针)。 所以不能赋值
 9.2 数组的本质
     定义一个数组，其实是在内存中分配一片空间，数组名就是这片空间的首地址。数组名其实就是一个指针，只是这个指针是常指针,其值不可改变。
     int a[10];
                 
 9.3 指针的运算
     +  -  ++ --  *
     两个指针(地址)不能相加，但指针(地址)可以加一个整数
     两个指针(地址)可以相减，且指针(地址)也可以减一个整数
     指针(地址)可以++，也可以减减，前提是，此指针变量不是只读的。

 9.4 将数组做为参数传递
     1) 当将数组做为参数传递时，传递的其实是数组的首地址，所以，在函数中，可以用指针来接收。由于是地址，函数无法获取数组的长度，所以，一般情况下，传一个数组给函数时，要用两个参数:数组的地址(数组名)和数组的长度(元素的个数).
     2) 函数不可以返回一个数组,但是，可以返回指针。

10.指针和字符串
10.2. 字符串
 10.2.1 概念
     双引号引起来的就是字符串。
     "I am a string.\n"
     
 10.2.2 如果保存字符串
     C语言中没专门的字符串类型，所以保存字符串一般会用字符数组；
     约定，所有的字符串都有一个结束符,这个结束符就是'\0', '\0'字符是个不存在的字符， 它的编码就是0. 所以，C语言中的字符串应该如下保存:
                 char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
                 char str[6] = "hello";
                 char str[] = "hello";
 10.2.3 C语言表示字符串的两种方式
         char str[10] = "hello";
         char* str = "hello";
     它们的本质上相同的，都是一个指针指向了一串字符，这串字符以'\0'结束，所以叫字符串。

11.函数指针
 指向函数的指针。
 指针就可以当函数使用，也可以当变量。
 函数名就是地址，调用函数就是通过地址去调用。
 函数指针可以让我们写出更加通用的代码。

12. const关键字
 12.1 概念
 修饰变量的定义，当变量定义前加const，说明这个变量是一个常量。
 常量就是值不可改变的量。
 12.2 const 和指针变量
       如果const出现在"*"号前面，指指针指向的空间不可以通过该指针去修改。如果const出现"*"号后面，是说指针本身的值不可修改，即指针再也不能指向其它的空间了。"*"号前后都出现const，都起作用。
     建议，当指针指向的空间本身就不可修改时，"*"前加const,如:
         char* str = "hello world"; 建议写成:
         const char* str = "hello world";

13.结构体
 13.1 概念
     一个结构体变量是由多个其他变量组成，组成结构体的变量类型可以不同，而且有变量名。
 struct{
     int i;
     char c;
     double d;
 }s;

 s.i = 10;
 s.c = 'A';
 s.d = 3.14;
 13.2 结构体的使用方式
     13.2.1 直接定义变量，这种方式不太常用
             struct{
                     int i;
                     char c;
                     double d;
             }s;
     13.2.2 用结构体定义类型：
             struct Parter{
                 char name[10];
                 int count;
             };
             现在，struct Parter就是类型，如同int,double等类型一样。
             int x;//定义变量
             struct Parter  p;//定义变量
             用户自定义类型
     13.2.3 使用结构体变量和使用基本数据类型变量基本一致。比如可以将结构体亦是传参，做为函数返回值，做为数组类型等。
     13.2.4 使用->运算符访问结构体成员
         当一个结构体指针指向一个结构体变量时，可以通过以下方式访问成员：
         struct Point point = {1,2};
         struct Point* p = &point;
         p->x = 10; //相当于(*p).x = 10;
         p->y = 20;// (*p).y = 20;
 13.3 给结构体起别名
         struct Point {...};
         typedef struct Point Point;
         typedef struct Rect{
                 //...
         }Rect;
 13.4 初始化方式
     Point p3 = {1,2};
 Point p4 = {.y=4, .x=3};
 Rect r2 = {.width = 10, .height = 20};
 Rect r3 = {
     width : 100,
     height : 200
 };
 Rect r4 = {};//清零
13.5 对齐和补齐(内存分配)
     结构体中的变量内存空间要对齐：变量的起始位置一定要是这个变量大小的整数倍。如：int 型的变量一定放在0,4,8,12...的位置处。
     其目的是为了提高访问结构体成员的效率。
     补齐：整个结构体变量所占的内存空间一定要是结构体成员中最大的那个成员的空间整数倍，不足时补齐。
14.枚举
 枚举就是列举
 enum WEEK {MON, TUE, WED, ….};
 唯一的作用是，提高程序的可读性以及编程的方便性
 枚举本质上是整数。
15. typedef
 给类型起别名。
 如果要给类型起别名，按照以下步骤：
     1）  用这种类型定义一个变量
     2）  在定义前加"typedef"
     3）  将变量名改成需要的别名。
15. 预处理器和预处理指令
 15.1 概念
     预处理器是一个程序，用来处理源程序中的预处理指令。
 一个程序在编译之前一般都要经过预处理。
 15.2 预处理指令
     以"#"开头的指令叫预处理指令
     可以出现在任何位置，必须一行结束，如果要换行，须得用"\"来连接两行内容
 15.3 预处理指令 #include
     功能是包含指定的文件到指令的位置。
     ""  <>  的区别
 15.4 宏定义的预处理指令
     #define
     分为两种，简单的宏和宏函数
     1)简单的宏
         ＃define N 100
     2)宏函数
         形式上类似于函数，本质上还是宏替换。


 *
 */
