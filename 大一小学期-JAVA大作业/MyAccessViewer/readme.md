#### 1 支持环境和软件

本软件在64位Windows系统下开发，使用Eclispe编译器，Java环境如下：
java version "1.7.0_80"
Java(TM) SE Runtime Environment (build 1.7.0_80-b15)
Java HotSpot(TM) 64-Bit Server VM (build 24.80-b11, mixed mode)
由于Java从JDK1.8之后就移除了Access桥接驱动，若使用JDK1.8及以上版本的Java运行时，将发生错误无法进行数据库操作，弹窗提示数据库驱动错误。
使用的本机数据库版本为Microsoft Access 2010，所有功能均经过本机测试能正常使用。
如遇中文乱码问题，请检查编码格式是否统一。

#### 2 使用方法

MyAccessViewer主项目
	MyAccessViewer.jar是整个项目打成的jar包,直接双击运行，打开登录界面。
	MyAccessViewer2项目文件夹
		.setting目录 eclipse生成的元数据目录
		bin 工程输出路径，存放了编译生成的.class文件
		src源代码文件夹
			MyAccessConnection文件夹
				MyBusiness.java为具体事务操作（连接数据库，获取、增加、删改、查询记录等）
			MyVisualization文件夹
				AboutMe.java为作者说明界面
				MyLogin.java为登录界面
				MyMainFrame.java为主页面，可显示表格和相关数据
				UpdateDialog.java为操作对话框，输入语句后进行相关操作更新数据库表格显示或弹出查询结果
		.classpath和.project为eclipse生成的工程描述文件
	Access文件夹
		AccessDatabase.mdb 数据库，使用时请先将其设为数据源
	readme.md 使用说明文档，在登录界面点击使用说明打开
在数据源已设置的情况下，双击.jar文件，打开登录界面，点击登录，打开主页面，双击表格名打开表格，单击菜单栏相关操作可打开交互对话窗进行增删改查操作。
增加记录格式为：
表名+值 
如：Student+'2019308160102','试验202','cs'
删除记录格式为：
表名+主键
如：Student+'2019308160102'
修改记录格式为：
表名+修改值和条件
如：Student+专业 = 'ee' where 专业 = 'cs'
查询记录格式为：
表名+查询条件
如：Student+学号='2019308160102'