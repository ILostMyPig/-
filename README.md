@[toc]

末尾附有源代码的下载地址，软件免费使用，感谢大家共同上传BUG和改进。

# 霸屏浏览器

## 软件介绍

霸屏浏览器作用：使电脑仅提供Web浏览器功能，屏蔽所有其它功能。比如，不允许退出浏览器，不允许关机和重启，不允许使用任务管理器，不允许使用开始菜单和任务栏，不允许跳转其它软件。

开发目的是为了给公共区域的自助电脑使用，比如触摸屏浏览器、自助机浏览器。网上没找到免费产品，收费的授权方式又很不讲理，所以自己开发了一个。

  **注意：程序会自动获取管理员权限，但部分操作系统因为优化和修改，导致要手动允许管理员权限才能运行：右击cs_fxb_win_hook.exe->点属性->点兼容性->勾选以管理员身份运行此程序。**

## 软件信息

  - 软件授权：免费软件
  - 软件类型：国产软件
  - 应用平台：windows 7 sp1 32位
  - 软件语言：简体中文


## 更新日志

V7.5.10

- 自动关机功能不能启动。

V7.5.9（大范围重构）

功能增减：

- 将浏览器默认为ie11，且可通过set_ini.exe改为ie的其它版本。
- 能阻止“javascript:{0}”方式在新窗口中打开页面。
- 执行“运行我，制作绿色版.bat”前，无需手动生成解决方案。
- class FileIni支持修改分隔符了。
- class Class_WriteLog支持Exception.InnerException了。

优化和修正：

- 去除class FileIni的自定义异常。
- 去除class ShiftConversion的自定义异常。
- 改变部分函数执行失败时的反馈方式，从用返回值表示，改为抛出异常。
- 把键盘钩子从debug状态，改为release状态。
- 修改set_ini.exe的界面。
- 修改class FileIni算法，使之更符合高内聚低耦合。
- 删除残留的鼠标钩子代码。
- 优化class ContinuousPW的SetPw。
- 简化class Class_WriteLog。

V6.2.1

- 键盘钩子的算法存在bug。

V6.2.0

- 更改为绿色版，删除安装打包工具的配置。

V6.1.2

- 删除鼠标钩子，原因是没有必要拦截鼠标消息。
- 优化键盘钩子，并放宽拦截规则。
- 修改提示信息中的错误内容。
- 部分设备将此程序设置为开机时自动运行，导致屏幕变暗。修复此问题。

V5.17.0

- 允许使用右键菜单中的复制和粘贴功能。

V5.16.0

- 为了方便操作，允许不影响屏蔽功能的按键使用：允许在按键的同时移动鼠标和使用鼠标滚轮。

V5.15.3

- 部分位置增加数据验证。
- 历遍数组操作，将固定的上下限改为动态获取。
- 修复按住shift进行字符转换时，单引号错转换为中括号的问题。
- 修复“霸屏浏览器设置”程序无法重新建立配置文件的问题。
- 修复system.windows.forms.applcation.exit功能抛出index out of range异常的问题。

V5.13.5

- 优化键盘钩子算法。
- 密码类增加清空已输入的字符的方法。
- 优化部分变量的名称，使之更规范。
- 全部变量类增加thisPath字段来保存exe文件的所在路径。
- 优化自定义消息筛选器接口的算法。
- 增加守护进程在获得无需守护的指令后，清空guard文件夹的功能。
- 完善DEBUG状态下的日志功能。
- 修复小键盘的加减乘除和回车键被按了没用的问题。
- 修复键入非字符键，依旧可以连续输入密码的问题。
- 修复退出程序时，定时关机线程不能即时关闭的问题。
- 修复出现日志文件的情况。
- 修复先按下某个非alt键，再按下alt键，然后松开某键，再松开alt键，会使鼠标不能操作的情况。

V5.6.3

- 禁止鼠标和键盘同时按键，以防止鼠标+键盘的组合键。例如“shift+鼠标左键”会打开新窗口。
- 增加ctrl+c、+v、+x快捷键。因为鼠标右键被禁用，导致右键菜单的复制、粘贴、剪切功能也无法使用，所以增加这三个快捷键。
- 防止打开新窗口，并将新窗口的页面在本窗口访问。
- 用“join”来等待线程结束。
- 修复“浏览器载入页面时会卡主，导致钩子超时而被系统卸载，从而无法监控键盘、鼠标”的问题。
- 修复“关闭页面功能，会导致浏览器卡主”的问题。例如“javascript:self.close()”、“window.close();”。
- 修复“小键盘的小数点键无效”的问题。

V5.2.3

- 重做“霸屏浏览器设置”，使之更简洁、更易操作。
- 增加“guard”程序，来守护“霸屏浏览器”的运行。
- 增加定时关机功能。因为屏蔽了关机功能，使得用户无法使用自己的定时关机功能。
- 使用相对路径来包含数据文件，使源代码无需任何配置即可编译。
- “霸屏浏览器设置”不能正确保存内容。
- 修改关闭密码的获取方式。因为原来的获取方式在切换到“微软拼音新体验输入风格”输入法后，获取不到输入的关闭密码。

V4.0.0

- 将部分功能模块化。
- 使用新的程序异常处理方式。

V3.0.0

- 使用新的安装打包工具。

V2.0.0

- 优化源代码。

V1.1.0

- 增加了修改配置文件的界面。

V1.0.0

- 第一版。

## 下载文件

  ### 最新版

**霸屏浏览器**

  - 下载地址：[霸屏浏览器](https://pan.baidu.com/s/1xd7G6BWvde8HF81SPjFrsg)提取码：9x2o

**霸屏浏览器启动程序 ：cs_fxb_win_hook.exe。**
**设置程序：set_ini.exe。**

  ### 开发环境

  - 安装打包工具（自V6.2.0开始停止使用）：[InstallShield 2015 Limited Edition for Microsoft Visual Studio 2010, 2012, 2013 and 2015](https://pan.baidu.com/s/1mboAgy0ZXLYZTAMeVvyepQ)提取码：c2eb
  - 开发工具：[Microsoft Visual Studio 2010 professional sp1](https://pan.baidu.com/s/1ihtcSj4DzyZBs43QYGX8oQ)提取码：p2px

  ### 源代码

  - 所有版本的源代码：[霸屏浏览器（code）](https://github.com/ILostMyPig/BPLLQ)

  ### 程序流程图

  - 下载地址：[霸屏浏览器程序流程图](https://pan.baidu.com/s/1tpqniq9CoicXlXnL9B90PA)提取码：nyxp