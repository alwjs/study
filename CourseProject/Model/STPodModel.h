//
//  STPodModel.h
//  CourseProject
//
//  Created by 王继昇 on 2020/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STPodModel : NSObject

@end

NS_ASSUME_NONNULL_END



/*********************************************
 *
 *
 *
 *查看当前ruby是否安装
 *
 *  ruby -v
 *
 *
 *
 *  sudo gem update --system
 
 gem sources --remove https://rubygems.org/

 gem sources --add https://gems.ruby-china.com/
 *
 *gem sources -l
 *
 *
 *  查看rvm是否安装
 *
 *  rvm -v
 *
 *安装rvm
 *  curl -L https://get.rvm.io | bash -s stable
 *
 * source ~/.rvm/scripts/rvm
 *
 *
 *安装ruby
 *brew install ruby
 *
 *sudo gem update -system
 *
 *安装cocoapods
 *sudo gem install cocoapods
 *
 *安装xcode工具
 *xcode-select --install
 *
 *常见问题
 *1.无法连接服务器
 *  配置host
 *      /etc/hosts
 *          将hosts复制到桌面 ，添加完host地址 再覆盖系统文件
 *          https://www.ipaddress.com IP查询
 *          97.107.133.48    get.rvm.io
            199.232.96.133    raw.githubusercontent.com
 *
 *
 *2.权限问题
 *关闭系统sip
 *关机 Command ⌘ + R进入实用工具，打开终端
 *  csrutil disable 关闭
 *  csrutil enable  开启
 *
 *
 *-------------------------------------
 *新建一个Xcode工程，使用终端cd到工程目录下
 
 创建Podfile文件：

 pod init
 *
 *
 *打开Podfile文件：
 
 
 open Podfile
 添加：

 pod 'AFNetworking'
 *
 *
 *安装库
 *pod install
 *
 *
 *开始用workspace编程
 *
 *
 * *----------------------------------------------------------------------------------------------------------
 *rvm官方文档
 *http://www.rvm.io/rvm/upgrading
 *
 *cocoapods官方文档
 *https://guides.cocoapods.org/using/the-podfile.html
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
