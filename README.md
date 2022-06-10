# Personal-Note-Computer-Organization-and-Design-MIPS-
个人计组笔记
# 计算机组成1

[TOC]

## 第一章: 计算机系统概述

###### • **冯·诺依曼机（Von Neumann Machine）**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610194452275.png" alt="image-20220610194452275" style="zoom:33%;" />

冯·诺依曼结构的主要思想是什么呢？

1. 计算机应由运算器、控制器、存储器、输入设备和输出设备
五个基本部件组成。
2. 各基本部件的功能是：
• 存储器不仅能存放数据，而且也能存放指令，形式上两者
没有区别，但计算机应能区分数据还是指令；
• 控制器应能自动取出指令来执行；
• 运算器应能进行加/减/乘/除四种基本算术运算，并且也
能进行一些逻辑运算和附加运算；
• 操作人员可以通过输入设备、输出设备和主机进行通信。
3. 内部以二进制表示指令和数据。每条指令由操作码和地址码
两部分组成。操作码指出操作类型，地址码指出操作数的地
址。由一串指令组成程序。
4. 采用“存储程序”工作方式。

###### • **“存储程序”思想**

任何要计算机完成的工作都要先被编写成程序，然后将程序和原始数据送入主存并启动执行。一旦程序被启动，计算机应能在不需操作人员干预下，自动完成逐条取出指令和执行指令的任务。

###### • **计算机五个基本部件**

• 存储器不仅能存放数据，而且也能存放指令，形式上两者没有区别，但计算机应能区分数据还是指令；
• 控制器应能自动取出指令来执行；
• 运算器应能进行加/减/乘/除四种基本算术运算，并且也能进行一些逻辑运算和附加运算；
• 操作人员可以通过输入设备、输出设备和主机进行通信。

###### • **冯.诺依曼体系结构 vs 哈佛体系结构**

不独立/独立的指令内存和数据内存

![image-20220609161349608](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609161349608.png)

###### • **ISA**

**软件和硬件的界面：** **ISA（Instruction Set Architecture ）**指令集体系结构

ISA是一种规约（Specification），它规定了如何使用硬件
• 可执行的指令的集合，包括指令格式、操作种类以及每种操作对应的操作数的相应规定；

• 指令可以接受的操作数的类型； 

•  操作数所能存放的寄存器组的结构，包括每个寄存器的名称、编号、长度和用途； 

• 操作数所能存放的存储空间的大小和编址方式；

• 操作数在存储空间存放时按照大端还是小端方式存放；

​		大端存储：数据的高字节存储在低地址中，数据的低字节存储在高地址中

​		小端存储：数据的高字节存储在高地址中，数据的低字节存储在低地址中 

• 指令获取操作数的方式，即寻址方式； 

• 指令执行过程的控制方式，包括程序计数器、条件码定义等

###### • **高级语言、汇编、机器码**

hello.c的进程：

![image-20220609163149401](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609163149401.png)

###### • **计算机性能评价：响应时间、吞吐量**

**完成一项任务所需时间** 

**单位时间内完成的工作量**

考量一个计算机系统性能的两个基本指标

###### • **CPI、MIPS、CPU时间**

CPI（cycles per instruction）

已知程序总指令条数和综合CPI，求总时钟周期数
$$
程序总时钟周期数 = \sum^{n}_{i=1}(CPI_{i}\times C_{i})
$$
已知程序中有n种不同指令，第i条指令的条数和CPI，求综合CPI

其中$F_{i}$表示第i种指令在程序中所占的比例。
$$
CPI=\sum^{n}_{i=1}(CPI_{i}\times F_{i})=程序总时钟周期数\div 程序所含指令条数
$$
MIPS(Million Instuctions Per Second)，其含义是平均每秒钟执行多少百万条指令
$$
MIPS = \frac{F(CPU主频)}{综合CPI}*10^{-6}
$$
CPU时间指CPU用于程序执行的时间
$$
CPU执行时间=CPI\times 程序总指令条数\times 时钟周期
$$
（1）用户CPU时间，指真正用于运行用户程序代码的时间；

（2）系统CPU时间，指为了执行用户程序而需要CPU运行操作系统程序的时间

## 第二章 数据的机器级表示

###### • **原码、反码、补码**

###### • **补码表示有符号整数**

###### • **补码加减法原理**

###### • **符号扩展、0扩展**

◆ 符号扩展 （Sign-extend） • 将扩展后的数据的高位置为立即数的最高位
• 例：将一个字节的二进制数符号扩展为两个字节的二进制数
• 0b00001111 -> 0b0000000000001111
• 0b10001111 -> 0b1111111110001111
◆ 0扩展 (Zero-extend)
• 将扩展后的数据的高位置为0 • 例：将一个字节的二进制数0扩展为两个字节的二进制数
• 0b00001111 -> 0b0000000000001111
• 0b10001111 -> 0b0000000010001111

###### • **二进制补码表示定点小数**

![image-20220609172249961](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609172249961.png)

###### • **IEEE 754标准表示浮点小数**

阶码的表示范围：-126-127

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609220410302.png" alt="image-20220609220410302" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609220445502.png" alt="image-20220609220445502" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609220536932.png" alt="image-20220609220536932" style="zoom:50%;" />	<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609220549543.png" alt="image-20220609220549543" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609220910340.png" alt="image-20220609220910340" style="zoom:50%;" />、

###### • **BCD码**

如8421码

###### • **字和字长**

一字节是8bit，一个字是几字节要看规定

◆“字”(word)和 “字长”(word size，数字电路中对应总线的宽度width)的概念不同
• “字长”指定点运算数据通路的宽度。
（数据通路指CPU内部数据流经的路径以及路径上的部件，主要是CPU内部进行数据运算、存储和传送的部件，这些部件的宽度基本上要一致，才能相互匹配。因此，”字长”等于CPU内部总线的宽度、运算器的位数、通用寄存器的宽度等。 ） 

• “字”表示被处理信息的单位，用来度量数据类型的宽度。
• 字和字长的宽度可以一样，也可不同。

###### • **大端方式、小端方式**

![image-20220609225940786](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609225940786.png)

###### • **对齐**

**Alignment:要求数据的地址是相应的边界地址**

![image-20220609230127560](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609230127560.png)

###### • **奇偶校验**

**奇偶校验码**

![image-20220609230250017](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609230250017.png)

![image-20220609230421835](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609230421835.png)

## 第三章：运算方法和运算部件

###### • **算术运算、逻辑运算**

###### • **半加器、全加器、串行进位加法器、先行进位加法器**

半加器：

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609230638548.png" alt="image-20220609230638548" style="zoom:50%;" />

全加器：

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609230705976.png" alt="image-20220609230705976" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609231952592.png" alt="image-20220609231952592" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609232432908.png" alt="image-20220609232432908" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609232538585.png" alt="image-20220609232538585" style="zoom:50%;" />

###### • **n位整数加/减运算器（补码加减法原理）**

**[A–B]补= [A]补+ [–B] 补 ( mod $2^{n}$ )** 

– **实现减法的主要工作在于：求[–B]** **补**

###### • **n位带标志加法器**

◆CF(carry flag)进位标志
描述了最近操作是否发生了进位（可以检查无符号操作是否溢出）
◆ZF(zero flag)零标志
描述了最近操作结果是否为0（例如:逻辑操作等）
◆SF(sign flag)符号标志
描述了最近操作结果是否为负数
◆OF(overflow flag)溢出标志
描述了最近操作是否导致一个补码溢出，补码溢出通常有两种结果（正溢出或者负溢出）

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220609233527961.png" alt="image-20220609233527961" style="zoom:67%;" />

###### • **乘法器、快速乘法器**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610000347050.png" alt="image-20220610000347050" style="zoom:67%;" /><img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001153616.png" alt="image-20220610001153616" style="zoom:67%;" />

快速乘法器
◆前面介绍的乘法部件的特点
• 通过一个ALU多次做“加/减+右移”来实现
• 所需时间随位数增多而加长，由时钟和控制电路控制
◆设计快速乘法部件的必要性
• 大约1/3是乘法运算
◆快速乘法器的实现（由特定功能的组合逻辑单元构成）
• 流水线方式
• 硬件叠加方式（如：阵列乘法器）

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001347987.png" alt="image-20220610001347987" style="zoom: 50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001422017.png" alt="image-20220610001422017" style="zoom:50%;" />

###### • **除法器：恢复余数法、不恢复余数法(加减交替法)** 

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001523505.png" alt="image-20220610001523505" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001650772.png" alt="image-20220610001650772" style="zoom:50%;" />



<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610001738033.png" alt="image-20220610001738033" style="zoom:50%;" />

###### • **浮点数加减运算**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610134616886.png" alt="image-20220610134616886" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610134653754.png" alt="image-20220610134653754" style="zoom:50%;" />

​												<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610134810909.png" alt="image-20220610134810909" style="zoom:50%;" />	

###### • **浮点数乘除运算**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610134858506.png" alt="image-20220610134858506" style="zoom:50%;" />

## 第四章: 指令系统

###### • **R-Type指令、I-Type指令、J-Type指令**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610153754704.png" alt="image-20220610153754704" style="zoom:67%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610153901681.png" alt="image-20220610153901681" style="zoom:67%;" />

###### • **MIPS寄存器的功能定义**

###### • **MIPS汇编指令到机器码的手工翻译**

###### • **分支判断语句、循环语句的MIPS汇编代码实现**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610155151525.png" alt="image-20220610155151525" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610183756528.png" alt="image-20220610183756528" style="zoom: 50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610183934695.png" alt="image-20220610183934695" style="zoom:50%;" />

###### • **MIPS函数调用过程中，寄存器的分配和使用**

###### • **MIPS程序和数据的存储器分配**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610154624992.png" alt="image-20220610154624992" style="zoom:50%;" />

###### • **MIPS的寻址方式**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610154335042.png" alt="image-20220610154335042" style="zoom:50%;" />

###### • **零地址指令、一地址指令、二地址指令、三地址指令、多地址指令**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610190344468.png" alt="image-20220610190344468" style="zoom:67%;" />

###### • **寻址方式**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610190959984.png" alt="image-20220610190959984" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610191438340.png" alt="image-20220610191438340" style="zoom:50%;" />

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610191724228.png" alt="image-20220610191724228" style="zoom:50%;" />

###### • **定长操作码编码、扩展（变长)操作码编码**

![image-20220610192300830](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610192300830.png)

###### • **条件测试方式**

**Unsigned: CF=0时，大于**

**Signed：OF=SF时，大于**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610193730925.png" alt="image-20220610193730925" style="zoom:50%;" />

###### • **指令设计风格**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610194123949.png" alt="image-20220610194123949" style="zoom:50%;" />

###### • **RISC vs. CISC**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610193701080.png" alt="image-20220610193701080" style="zoom:50%;" />

CISC的缺陷
– 日趋庞大的指令系统不但使计算机的研制周期变长，而且难以保证设计的正确性，难以调试和维护，并且因指令操作复杂而增加机器周期，从而降低了系统性能。

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610194013752.png" alt="image-20220610194013752" style="zoom: 50%;" />

## 第五章: 中央处理器：数据通路和控制器

#### **• MIPS处理器：**

##### **• 数据通路、控制器**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610195626967.png" alt="image-20220610195626967" style="zoom:50%;" />

##### **• 组合逻辑元件:** 

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610215518855.png" alt="image-20220610215518855" style="zoom:50%;" />

###### **• 加法器**

###### **• 多路选择器**

###### **• ALU**

###### **• 译码器**

##### **• 时序逻辑元件：D触发器->寄存器->寄存器组(Register File)**

![image-20220610215851936](C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610215851936.png)

##### **• RTL语言**

<img src="C:\Users\86171\AppData\Roaming\Typora\typora-user-images\image-20220610194552835.png" alt="image-20220610194552835" style="zoom:50%;" />





##### **• MIPS指令的数据通路、控制通路**

##### **• 微程序(机器指令)\微指令\微命令\微操作的关系**

##### **• 中断、异常处理的概念**
