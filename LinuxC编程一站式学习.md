## Linux C编程一站式学习



### 程序和编程语言


	程序（Program）是一个精确说明如何进行计算的指令序列。


程序由一系列指令（Instruction）组成，指令是指示计算机做某种运算的命令，通常包括以下几类：

输入（Input）

	从键盘、文件或者其它设备获取数据。

输出（Output）

	把数据显示到屏幕，或者存入一个文件，或者发送到其它设备。

基本运算

	执行最基本的数学运算（加减乘除）和数据存取，其实输入和输出也属于数据存取。

测试和分支（Branch）

	测试某个条件，然后根据不同的测试结果执行不同的后续指令。

循环（Loop）

	重复执行一系列操作。


编写程序可以说就是这样一个过程：

把复杂的任务分解成子任务，把子任务再分解成更简单的任务，层层分解，直到最后简单得可以用以上指令来完成。





### 常量、变量和表达式

常量（Constant）是程序中最基本的元素，有字符常量（Character Constant）、数字常量和枚举常量。



字符常量要用单引号括起来，注意单引号只能括一个字符而不能像双引号那样括一串字符，字符常量也可以是一个转义序列。



变量是计算机存储器中的一块命名的空间，可以在里面存储一个值（Value），存储的值是可以随时变的，正因为变量的值可以随时变所以才叫变量。

即通过变量名就可以访问这块内存空间的内容。


变量的类型决定了它所占的存储空间的大小。


C语言规定了一些单词不允许用作标识符，这些单词称为关键字（Keyword）或保留字（Reserved Word）。

C99规定的关键字有：

	auto  break  case  char  const  continue  default  do  double
	else  enum  extern  float  for  goto  if  inline  int  long
	register  restrict  return  short  signed  sizeof  static  struct  switch  typedef
	union  unsigned  void  volatile  while  _Bool  _Complex  _Imaginary



一般来说应避免使用以下划线开头的标识符，以下划线开头的标识符只要不和C语言关键字冲突的都是合法的，
但是往往被编译器用作一些功能扩展，C语言库的实现也定义了很多以下划线开头的名字，很容易造成名字冲突。




赋值

	定义了变量之后，我们要把值存到它们的存储空间里，可以用赋值（Assignment）语句实现。


** 变量一定要先定义再使用 **


定义一个变量，就是分配一块存储空间并给它命名；

给一个变量赋值，就是把一个值存到了这块存储空间中。

变量的定义和赋值也可以一步完成，这称为变量的初始化（Initialization）。

初始化是一种特殊的变量定义语句，而不是一种赋值语句。


表达式

常量和变量之间可以做加减乘除运算，例如1+1、hour-1等。

这里的+-*/称为运算符（Operator）。

参与运算的变量和常量称为操作数（Operand）。

由运算符和操作数所组成的算式称为表达式（Expression）。


对于同一优先级的运算从左到右计算。

事实上赋值语句就是一种表达式语句，因为等号也是一种运算符。


常量可以赋值给变量，也可以和变量、运算符一起组成表达式，最简单的表达式由单个常量或变量组成，任何表达式都有一个值，表达式可以加个;号构成表达式`语句`。


C语言规定了一组语法规则，只要符合它的规则，就可以写出任意复杂的组合。

所以才可以用简单的常量、变量、表达式、语句搭建出任意复杂的程序。




等号左边表示存储位置，称为左值（lvalue）。

等号右边表示要存储的值，可以是任意组合的表达式，所以通常所说的表达式的值也称为右值（rvalue）。


### 字符类型与字符编码

计算机之所以能处理符号，是因为符号在计算机内部也用数字来表示，每个字符在计算机内部都用一个整数来表示，称为字符编码（Character Encoding）。

char型本质上就是整数，只不过取值范围比int型小，可以把char型和int型统称为整数类型（Integer Type）或简称整型。




自定义函数

定义的语法：
```
返回值类型 函数名(参数列表)
{
	语句列表
}
```


函数声明、函数定义、函数原型（Prototype）:

声明了一个函数的名字、参数类型和个数、返回值类型，这称为函数原型。

在代码中可以单独写一个函数原型，后面加;号结束，而不写函数体。

只有带函数体的声明才叫定义。

只有分配存储空间的变量声明才叫变量定义，其实函数也是一样，编译器只有见到函数定义才会生成指令，而指令在程序运行时当然也是要占存储空间的。

函数原型必须出现在函数调用之前，这也是遵循“先声明后使用”的原则。


函数的隐式声明（Implicit Declaration）

隐式声明的参数类型和个数根据函数调用代码来确定，隐式声明的返回值类型总是int。

如果编译器调用了某个函数时并没有声明它，则编译器认为此处隐式声明了，但编译对比函数原型的参数或返回值不一致时，会出现执行警告。




形参和实参

基本原理：** 形参相当于函数中定义的变量，调用函数传递参数的过程相当于定义形参变量并且用实参的值来初始化。**


局部变量与全局变量

把函数中定义的变量称为局部变量（Local Variable），由于形参相当于函数中定义的变量，所以形参也相当于局部变量。

'局部'理解为：

+ 某个函数中定义的变量不能被另一个函数使用。即局限于定义函数的内部。

+ 每次调用函数时局部变量都表示不同的存储空间。局部变量是在每次函数调用时分配存储空间，每次函数返回时释放存储空间的。
 
	即临时分配一个存储空间，用后就释放空间。碰巧有可能两次分配之间是同一个临时空间，局部变量最好是初始化再用。


与局部变量的概念相对的是全局变量（Global Variable）


全局变量定义在所有的函数体之外，它们在整个程序开始之前分配存储空间，在程序结束时释放存储空间，所有函数都可以通过全局变量名访问它们。

局部变量可以用任意类型相符的表达式来初始化，而全局变量只能用常量表达式初始化。


全局变量pi这样初始化是合法的：
```
double pi = 3.14 + 0.0016;
```

但这样初始化是不合法的：
```
double pi = acos(-1.0);
```

全局变量的初始值要求保存在编译生成的目标代码中，所以必须在编译时就能计算出来。

然而上面第二种Initializer的值必须在生成了目标代码之后在运行时调用acos函数才能知道，所以不能用来初始化全局变量。



C语言从语法上规定了全局变量只能用常量表达式来初始化。



如果全局变量在定义时不初始化，则初始值是0，也就是说，整型的就是0，字符型的就是'\0'，浮点型的就是0.0。

如果局部变量在定义时不初始化，则初始值是不确定的，所以，** 局部变量在使用前一定要先赋值，不管是通过初始化还是赋值运算符。**



验证局部变量存储空间的分配和释放:
```
#include <stdio.h>

int foo(void)
{
	int i;
	printf("%d\n", i);
	i = 777;
}

int main(int argc, char *argv[])
{
	foo();
	// printf("hello\n");
	foo();
	return 0;
}
```
输出结果：

	134518128
	777

** 局部变量在定义时不初始化，则初始值是不确定的。 **



### 分支语句


除了从前到后顺序执行之外，有时候我们需要检查一个条件，然后根据检查的结果执行不同的后续代码，在C语言中可以用分支语句（Selection Statement）实现。


如果表达式所表示的比较关系成立则值为真（True），否则为假（False），在C语言中分别用1和0表示。

if语句

if语句的格式为：
```
if (控制表达式)
	语句
```

if/else语句的格式为
```
if (控制表达式)
	语句
else
	语句
```


switch语句
switch语句可以产生具有多个分支的控制流程。它的格式是：
```
switch(控制表达式) {
	case 常量表达式：语句序列
	case 常量表达式：语句序列
	default：语句序列
}
```

case后面跟的必须是常量表达式，这个值必须在编译时计算出来。


case后面跟的常量表达式的值必须是可以精确比较的整型或字符型。


通常每个case后面都要加上break语句，表示退出case检测，如果没有break打断，会继续检测下面的case是否符合执行直到退出。


### 理解函数

在有返回值的函数中，return语句的作用是提供整个函数的返回值，并结束当前函数的执行。在没有返回值的函数中也可以使用return语句。


基本原理：** 函数返回一个值相当于定义一个和函数返回值类型相同的临时变量并用return后面的表达式来初始化。**


函数的返回值不是左值，不能赋值给函数的调用。


在写带有return语句的函数时要小心检查所有的代码路径（Code Path）。

有些代码路径在任何条件下都执行不到，这称为Dead Code。


### 递归

如果定义一个概念需要用到这个概念本身，我们称它的定义是递归的（Recursive）。


数学上确实有很多概念是用它自己来定义的，比如n的阶乘（Factorial）是这样定义的：n的阶乘等于n乘以n-1的阶乘。

n-1的阶乘又是什么？是n-1乘以n-2的阶乘。那n-2的阶乘呢？这样下去永远也没完。

因此需要定义一个最关键的基础条件（Base Case）：0的阶乘等于1。


写递归函数时一定要记得写Base Case，否则即使递推关系正确，整个函数也不正确。


### 循环语句

while语句
格式：
```
while (控制条件) {
	语句
}
```

do/while语句

格式：
```
do
	语句
while(控制表达式);
```


for语句
格式为
```
for(控制表达式1;控制表达式2;控制表达式3)
	语句

// 等价下面的while语句
控制表达式1;
while(控制表达式2) {
	语句
	控制表达式3;
}

```


C99引入一种新的for循环，规定控制表达式1的位置可以有变量定义。


break和continue语句

break语句的一种用法，用来跳出switch语句块，这个语句也可以用来跳出循环体。

continue语句也用来终止当前循环，和break语句不同的是，continue语句终止当前循环后又回到循环体的开头准备再次执行循环体。



嵌套循环


goto语句


goto语句，实现无条件跳转。

唯一的限制是goto只能跳到同一个函数的某个标号处，而不能跳到别的函数里。

标号（Label），给标号起名字也遵循标识符的命名规则。

格式：
```
...
goto 标号;

...

标号:

...

```

通常goto语句只用于在函数末尾做出错处理（例如释放先前分配的资源、恢复先前改动过的全局变量等），函数中任何地方出现了错误条件都可以立即跳到函数末尾，处理完之后函数返回。



### 结构体

大多数数据类型都具有单一的值，例如整数、字符、布尔值、浮点数，这些可称为基本数据类型（Primitive Type）。


由基本类型组成的数据类型称为复合数据类型（Compound Type）。


复合数据类型一方面可以从整体上当作一个数据使用，另一方面也可以分别访问它的各组成单元，复合数据类型的这种两面性提供了一种数据抽象（Data Abstraction）的方法。



定义struct 类型：

```
struct 标识符 {
	基本类型定义
	...
}
```
struct 后面的标识符在C语言中称为Tag 。

`struct Tag { ... }` 整个可以看作一个类型名，就像int或double一样。

可以先声明一个新的类型，再声明变量；也可以在声明新类型同时声明该类型的变量。

```
struct complex_struct {
	double x, y;
} z1, z2;

//
struct complex_struct z3, z4;

```
Tag也可以定义在函数外面，就像全局变量一样，这样定义的Tag在其定义之后的各函数中都可以使用。

结构体变量也可以在定义时初始化:

```
struct complex_struct { double x, y; } z;

z.x = 1.0;
z.y = 4.0;

// 定义时初始化
struct complex_struct z = { 3.0, 4.0 };

double x = 3.0;
struct complex_struct z1 = { x, 4.0, }; /* z1.x=3.0, z1.y=4.0 */
struct complex_struct z2 = { 3.0, }; /* z2.x=3.0, z2.y=0.0 */
struct complex_struct z3 = { }; /* z3.x=0.0, z3.y=0.0 */
```


枚举类型：

enum关键字的作用和struct关键字类似。

enum Tag 表示一个枚举（Enumeration）类型。

枚举类型的成员是常量，它们的值编译器自动分配。

默认第一个常量值为0 ，后续的加1；如果不希望从0开始分配，可以指定第一个常量值。

```
enum gender { MAN, WOMAN};

// 
enum gender {MAN=1, WOMAN};

```

有一点需要注意，结构体的成员名和变量名不在同一命名空间，但枚举的成员名和变量名却在同一命名空间，所以会出现命名冲突。

```
int main(void)
{
	enum coordinate_type { RECTANGULAR = 1, POLAR };
	int RECTANGULAR; // 冲突

	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}

```



嵌套结构体

结构体也是一种递归定义：结构体由数据类型定义，因为结构体的成员具有数据类型，而数据类型由结构体定义，因为结构体本身也是一种数据类型。

换句话说，结构体也可以嵌套。

```
struct Segment {
	struct complex_struct start;
	struct complex_struct end;
};

struct Segment s = {{ 1.0, 2.0 }, { 4.0, 6.0 }};


s.start.a = 1.0;
s.start.b = 2.0;


```

### 数组

和结构体类似，数组（Array）也是一种复合数据类型，它由一系列相同类型的元素（Element）组成。


结构体的成员可以是基本数据类型，也可以是复合数据类型，数组中的元素也是如此。

根据组合规则，我们可以定义一个由4个结构体元素组成的数组：

```
struct Complex {
	double x, y;
} a[4];

```
数组类型的长度应该用一个常量表达式来指定，而且这个常量表达式的值必须是整数类型的。

如果定义数组的同时初始化它，也可以不指定数组的长度
```
int count[] = { 3, 2, 1 };
```
编译器会根据Initializer有三个元素确定数组的长度为3。

数组和结构体虽然有很多相似之处，但也有一个显著的不同：** 数组不能互相赋值 **。

a = b这个表达式，a和b都是数组类型的变量，但是b做右值使用，自动转换成指针类型，而左边仍是数组类型，

所以编译器报的错误信息是error: incompatible types in assignment。



既然不能互相赋值，也就不能用数组类型作为函数的参数或返回值。

对于数组类型有一条特殊规则：** 数组名做右值使用时，自动转换成指向数组首元素的指针。**


```
void foo(int a[5])
{
	...
}
```
此处函数调用其实是传一个指针类型的参数，而不是数组类型的参数。




`define不仅用于定义常量，也可以定义更复杂的语法结构，称为宏（Macro）定义。define定义是在预处理阶段处理的，而枚举是在编译阶段处理的。`


字符串

字符串可以看作一个数组，它的元素是字符型的。

字符串末尾有一个字符'\0'表示字符串结束。
这里的\0是ASCII码的八进制表示，也就是ASCII码为0的那个字符。

在本书中字符串这个概念指的是以'\0'结尾的一串字符，可能是像str这种数组，也可能是像"Hello"这种字符串字面值。

字符串字面值是只读的，不允许修改。

字符串字面值还有一点和数组名类似，做右值使用时自动转换成指向首元素的指针。

数组可以像结构体一样初始化，如果是字符数组，也可以用一个字符串字面值来初始化：
```
char str[10] = "Hello";

// 相当于
char str[10] = { 'H', 'e', 'l', 'l', 'o', '\0' };

```
str的后四个元素没有指定，自动初始化为0，即'\0'字符。


如果要用一个字符串字面值准确地初始化一个字符数组，最好的办法是不指定数组的长度，而让编译器自动计算。
```
char str[] = "Hello, world.\n";
```
字符串字面值的长度包括'\0'在内一共15个字符，编译器会确定数组str的长度为15。

字符串易错的地方

字符串可以保存在一个数组里面，用%s来打印就很有必要了：
```
printf("string: %s\n", str);
```

printf会从数组str的开头一直打印到'\0'字符为止（'\0'本身不打印）。

如果数组str中没有'\0'，那么printf就会打印出界，后果和前面讲的数组访问越界一样诡异。

有时候打印出乱码，有时候看起来没错误，有时候引起程序崩溃。


多维数组

数组也可以嵌套，一个数组的元素可以是另外一个数组，这样就构成了多维数组（Multi-dimensional Array）。

```
int a[3][2] = { 1, 2, 3, 4, 5 };

```

数组a有3个元素，a[0]、a[1]、a[2]。每个元素也是一个数组，

例如a[0]是一个数组，它有两个元素a[0][0]、a[0][1]，这两个元素的类型是int，值分别是1、2。


从物理模型上看，这六个元素在存储器中仍然是连续存储的，就像一维数组一样，

相当于把概念模型的表格一行一行接起来拼成一串，C语言的这种存储方式称为Row-major方式；

而有些编程语言（例如FORTRAN）是把概念模型的表格一列一列接起来拼起一串存储的，称为Column-major方式。

多维数组也可以像嵌套结构体一样，用嵌套Initializer初始化，例如上面的二维数组也可以这样初始化：
```
int a[][2] = { { 1, 2 },
		{ 3, 4 },
		{ 5, } };

```
** 除了第一维的长度可以由编译器自动计算而不需要指定，其余各维都必须明确指定长度。**


如果是字符数组，也可以嵌套使用字符串字面值做Initializer:
```
char days[8][10] = { "", "Monday", "Tuesday",
			     "Wednesday", "Thursday", "Friday",
			     "Saturday", "Sunday" };
```



### 编码风格

C语言的语法对编码风格并没有要求，空格、Tab和换行都可以自己随意写，实现同样功能的代码可以写得很好看，也可以写得很难看。


1. 较长的字符串可以断成多个字符串然后分行书写
```
// 第一行结束不能有空白符
printf("This is such a long sentence that "
       "it cannot be held within a line\n");
```
C编译器会自动把相邻的多个字符串接在一起。
以上两个字符串相当于一个字符串"This is such a long sentence that it cannot be held within a line\n"。





### 数据类型详解

整型

计算机存储的最小单位是字节（Byte），一个字节通常是8个bit。

C语言规定char型占一个字节的存储空间。

如果这8个bit按无符号整数来解释，则取值范围是0~255，如果按有符号整数来解释，则取值范围是-128~127。



C语言规定了signed和unsigned两个关键字，unsigned char型表示无符号数，signed char型表示有符号数。

C标准的Rationale之一: **优先考虑效率，而可移植性尚在其次。**



C标准规定这是Implementation Defined，编译器可以定义char型是无符号的，也可以定义char型是有符号的。



	Implementation-defined、Unspecified和Undefined

	在C标准中没有做明确规定的地方会用Implementation-defined、Unspecified或Undefined来表述，在本书中有时把这三种情况统称为“未明确定义”的。

	Implementation-defined的情况，C标准没有明确规定char是有符号的还是无符号的，但是要求编译器必须对此做出明确规定，并写在编译器的文档中。

	对于Unspecified的情况，往往有几种可选的处理方式，C标准没有明确规定按哪种方式处理，编译器可以自己决定，并且也不必写在编译器的文档中，这样即使用同一个编译器的不同版本来编译也可能得到不同的结果。

	Undefined的情况则是完全不确定的，C标准没规定怎么处理，编译器很可能也没规定，甚至也没做出错处理，有很多Undefined的情况是编译器是检查不出来的，最终会导致运行时错误，比如数组访问越界就是Undefined的。




char型之外，整数类型还有short int（或者简写为short）、int、long int（或者简写为long）、long long int（或者简写为long long）几种，

这些类型都可以加上signed或unsigned关键字表示有符号或无符号数。


除了char型在C标准中明确规定占一个字节之外，其它整数类型占几个字节都是Implementation Defined。

通常的编译器实现遵守ILP32或LP64规范。


	类型		ILP32（位数）	LP64（位数）
	char		8	8
	short		16	16
	int		32	32
	long		32	64
	long long	64	64
	指针		32	64




ILP32这个缩写的意思是int（I）、long（L）和指针（P）类型都占32位，通常32位计算机的C编译器采用这种规范，x86平台的gcc也是如此。

整数常量还可以在末尾在加u或U表示“unsigned”，加l或L表示“long”，加ll或LL表示“long long”，例如0x1234U，98765ULL等。

但事实上u、l、ll这几种后缀和上面讲的unsigned、long、long long关键字并不是一一对应的。

具体由编译器决定，但最终都会满足程序定义的数据宽度。


浮点型

C标准规定的浮点型有float、double、long double，和整数类型一样，既没有规定每种类型占多少字节，也没有规定采用哪种表示形式。

x86处理器通常是有浮点运算单元的，遵循IEEE 754，float型通常是32位，double型通常是64位。



类型转换

Integer Promotion（整型提升）

如果原始类型的取值范围都能用int型表示，则其值被提升为int型。如果表示不了就提升为unsigned int型，这称为Integer Promotion。

凡是可以使用int或unsigned int类型做右值的地方，也都可以使用有符号或无符号的char型、short型和Bit-field，其值被提升为int类型。

C99规定Integer Promotion适用于以下几种情况：

1. 如果一个函数的形参类型未知，或者函数的参数列表中有...，那么调用函数时要对相应的实参做Integer Promotion，

	此外，相应的实参如果是float型的也要被提升为double型，这条规则称为Default Argument Promotion。


2. 算术运算中的类型转换。

	两个算术类型的操作数做算术运算，比如a * b，如果两边操作数的类型不同，编译器会自动做类型转换，使两边类型相同之后才做运算，
	这称为Usual Arithmetic Conversion，转换过程中有一步就是Integer Promotion

```
unsigned char c1 = 255, c2 = 2;
int n = c1 + c2;

// 整个表达式的值也是int型，最后的结果是257。假如没有这个提升的过程，c1 + c2就溢出了，最后的结果应该是1。
```


	显然，+-*/%这些算术运算以及> < >= <= == !=这些比较运算都需要做Usual Arithmetic Conversion，因为都要求两边操作数的类型一致。

3. 单目运算符+、-、~只有一个操作数，移位运算符<<、>>两边的操作数类型不要求一致，因此这些运算不需要做Usual Arithmetic Conversion，但也需要做Integer Promotion。




Usual Arithmetic Conversion

规则：
	
	1 如果有一边的类型是long double，则把另一边也转成long double。
	2 否则，如果有一边的类型是double，则把另一边也转成double。
	3 否则，如果有一边的类型是float，则把另一边也转成float。
	4 否则，两边应该都是整数类型，首先按上一小节讲过的规则对a和b做Integer Promotion，然后如果类型仍不相同，则需要继续转换。
		首先规定char、short、int、long、long long的转换级别（Integer Conversion Rank）一个比一个高，同一类型的有符号和无符号数具有相同的Rank，
		然后有如下转换规则：
		
		（先相同符号数比较，再优先无符号的Rank，类型范围是否覆盖其他的）

		a. 如果两边都是有符号数，或者都是无符号数，那么较低Rank的类型转换成较高Rank的类型。

		b. 否则，如果一边是无符号数另一边是有符号数，无符号数的Rank不低于有符号数的Rank，则把有符号数转成另一边的无符号类型。

		c. 剩下的情况就是：一边是无符号数另一边是有符号数，并且无符号数的Rank低于有符号数的Rank。

			这时又分为两种情况，如果这个有符号数类型能够覆盖这个无符号数类型的取值范围，则把无符号数转成另一边的有符号类型。
			例如遵循LP64的平台上unsigned int和long在做算术运算时都转成long。

		d. 否则，也就是这个符号数类型不足以覆盖这个无符号数类型的取值范围，则把两边都转成两者之中较高Rank的无符号类型。
		例如遵循ILP32的平台上unsigned int和long在做算术运算时都转成unsigned long。




由赋值产生的类型转换

赋值或初始化时等号两边的类型不相同，则编译器会把等号右边的类型转换成等号左边的类型再做赋值。

例如int c = 3.14;，编译器会把右边的double型转成int型再赋给变量c。


函数调用传参的过程相当于定义形参并且用实参对其做初始化，函数返回的过程相当于定义一个临时变量并且用return的表达式对其做初始化，
所以由赋值产生的类型转换也适用于这两种情况。

如果这个函数定义中有返回语句return 1.2;，则返回值1.2会自动转成int型再返回。


以上三种情况通称为隐式类型转换（Implicit Conversion，或者叫Coercion），编译器根据它自己的一套规则将一种类型自动转换为另一种类型。



强制类型转换

程序员也可以通过类型转换运算符（Cast Operator）自己规定某个值要转换成何种类型，这称为显式类型转换（Explicit Conversion）或强制类型转换（Type Cast）。






### 运算符详解

整数在计算机中用二进制的位来表示，C语言提供一些运算符可以直接操作整数中的位，称为位运算，这些运算符的操作数都必须是整型的。




移位运算符（Bitwise Shift）包括左移<<和右移>>。

左移将一个整数的各二进制位全部左移若干位。

在一定的取值范围内，将一个整数左移1位相当于乘以2。



在一定的取值范围内，将一个整数右移1位相当于除以2，小数部分截掉。


当操作数是有符号数时，右移运算的规则比较复杂：

	如果是正数，那么高位移入0
	如果是负数，那么高位移入1还是0不一定，这是Implementation-defined的。对于x86平台的gcc编译器，最高位移入1，也就是仍保持负数的符号位。

由于类型转换和移位等问题，使用有符号数做位运算是很不方便的，所以，建议只对无符号数做位运算，以减少出错的可能。



异或运算的一些特性

1. 一个数和自己做异或的结果是0。如果需要一个常数0，x86平台的编译器可能会生成这样的指令：xorl %eax, %eax。

2.从异或的真值表可以看出，不管是0还是1，和0做异或值不变，和1做异或得到原值的相反值。

3. x ^ x ^ y == y，因为x ^ x == 0，0 ^ y == y。
	
	利用位运算可以这样做交换：
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;




复合赋值运算符

复合赋值运算符（Compound Assignment Operator）包括*= /= %= += -= <<= >>= &= ^= |=，在赋值的同时做一个运算。


例如a += 1相当于a = a + 1。但有一点细微的区别，前者对表达式a只求值一次，而后者求值两次。


对于有Side Effect的表达式则两者结果是不一样的。

例如a[foo()] += 1和a[foo()] = a[foo()] + 1，
如果foo()函数调用有Side Effect，比如会打印一条消息，那么前者只打印一次，而后者打印两次。




条件运算符

条件运算符（Conditional Operator）是C语言中唯一一个三目运算符（Ternary Operator），带三个操作数，它的形式是表达式1 ? 表达式2 : 表达式3。
```
if (表达式1)
	return 表达式2;
else
	return 表达式3;
```


逗号运算符

逗号运算符（Comma Operator）也是一种双目运算符，它的形式是`表达式1, 表达式2`。

两个表达式不要求类型一致，左边的表达式1先求值，求完了直接把值丢掉，再求右边表达式2的值作为整个表达式的值。



逗号运算符是左结合的，类似于+-*/运算符。

根据组合规则可以写出`表达式1, 表达式2, 表达式3, ..., 表达式n` 这种形式，
先求表达式1的值，然后求表达式2的值，依此类推，整个计算过程就是从左到右依次求值，最后一个表达式的值成为整个表达式的值。

函数调用时各实参也是用逗号隔开，那个逗号不能看作逗号运算符。但可以这样：
```
f(a, (t=3, t+2), c)

// 第二个参数的值是表达式t+2的值。
```



sizeof运算符与typedef类型声明

sizeof是一个很特殊的运算符，它有两种形式：`sizeof 表达式` 和 `sizeof(类型名)`。

`sizeof 表达式` 中的表达式并不求值，只是根据类型转换规则求得该`表达式的类型`，

然后把这种类型所占的字节数作为`sizeof 表达式`这整个表达式的值。


由于sizeof 表达式中的表达式不需要求值，所以不需要到运行时才计算。

```
int a[12];
printf("%d\n", sizeof a/sizeof a[0]);
```

在编译时就知道sizeof a的值是48，sizeof a[0]的值是4，所以在编译时就已经把sizeof a/sizeof a[0]替换成常量12了，这是一个常量表达式。


准确地说，sizeof表达式的值是size_t类型的，这个类型定义在stddef.h头文件中，不过你的代码中只要不出现size_t这个类型名就不用包含这个头文件。


typedef这个关键字用于给一个类型起个新的名字。

```
typedef unsigned long size_t;
```

去掉typedef就成了一个变量声明unsigned long size_t;，

size_t是一个变量名，类型是unsigned long，那么加上typedef之后，size_t就是一个类型名，就代表unsigned long类型。




Side Effect与Sequence Point


C 语言中副作用（side effect）：是指对数据对象或者文件的修改。

调用一个函数可能产生Side Effect，
使用某些运算符（++、--、=、复合赋值）也会产生Side Effect，

如果一个表达式中隐含着多个Side Effect，究竟哪个先发生哪个后发生呢？


C标准规定代码执行过程中的某些时刻是Sequence Point，

当到达一个Sequence Point时，在此之前的Side Effect必须全部作用完毕，在此之后的Side Effect必须一个都没发生。

至于两个Sequence Point之间的多个Side Effect哪个先发生哪个后发生则没有规定，编译器可以任意选择各Side Effect的作用顺序。

C 语句结束标志——分号（;）是序列点。

标准规定，在两个序列点之间，一个对象所保存的值最多只能被修改一次。


写表达式应遵循的原则一：**在两个Sequence Point之间，同一个变量的值只允许被改变一次**。

写表达式应遵循的原则二：**如果在两个Sequence Point之间既要读一个变量的值又要改它的值，只有在读写顺序确定的情况下才可以这么写**。

```
a[i++] = i;
```

因为等号左边改i的值，等号右边读i的值，到底是先改还是先读？这个读写顺序是不确定的。



运算符总结

	1、标识符、常量、字符串和用()括号套起来的表达式是组成表达式的最基本单元，在运算中做操作数，优先级最高。

	2、后缀运算符，包括数组取下标[]、函数调用()、结构体取成员.、指向结构体的指针取成员->、后缀自增++、后缀自减--。

		如果一个操作数后面有多个后缀，按照离操作数从近到远的顺序（也就是从左到右）依次运算，
		比如a.name++，先算a.name，再++，这里的.name应该看成a的一个后缀，而不是把.看成双目运算符。

	3、单目运算符，包括前缀自增++、前缀自减--、sizeof、类型转换()、取地址运算&、指针间接寻址*、正号+、负号-、按位取反~、逻辑非! 。

		如果一个操作数前面有多个前缀，按照离操作数从近到远的顺序（也就是从右到左）依次运算，
		比如!~a，先算~a，再求!。

	4、乘*、除/、模%运算符。这三个运算符是右结合的。

	5、加+、减-运算符。右结合。

	6、移位运算符<<和>>。右结合。

	7、关系运算符< > <= >=。右结合。

	8、相等性运算符==和!=。右结合。

	9、按位与&。右结合。

	10、按位异或^。右结合。

	11、按位或|。右结合。

	12、逻辑与&&。右结合。

	13、逻辑或||。右结合。

	14、条件运算符:?。例如a ? b : c ? d : e是看成(a ? b : c) ? d : e还是a ? b : (c ? d : e)？C语言规定是后者。

	15、赋值=和各种复合赋值（*= /= %= += -= <<= >>= &= ^= |=）。左结合。

	16、逗号运算符。右结合。












### 计算机体系结构基础


每个存储单元有一个地址（Address），CPU通过地址找到相应的存储单元，取其中的指令，或者读写其中的数据。

一个地址所对应的存储单元不能存很多东西，只能存一个字节，
所以以前讲过的int、float等多字节的数据类型保存在内存中要占用多个地址，

这种情况下把起始地址当作这个数据的地址。

内存地址是从0开始编号的整数，最大编到多少取决于CPU的地址空间（Address Space）有多大。




CPU

CPU总是周而复始地做同一件事：从内存取指令，然后解释执行它，然后再取下一条指令，再解释执行。


CPU包含以下功能单元：

+ 寄存器（Register），是CPU内部的高速存储器，像内存一样可以存取数据，但比访问内存快得多。

	x86的寄存器如eax、ebp、eip等等，有些寄存器保存的数据只能用于某种特定的用途

+ 程序计数器（PC，Program Counter），保存着CPU取指令的地址，每次CPU读出程序计数器中保存的地址，然后按这个地址去内存中取指令。

	这时程序计数器保存的地址会自动加上该指令的长度，指向内存中的下一条指令。
	程序计数器通常是CPU的一个特殊寄存器，x86的程序计数器是特殊寄存器eip，由于地址是32位的，所以这个寄存器也是32位的。

+ 指令解码器（Instruction Decoder）。CPU取上来的指令由若干个字节组成，这些字节中有些位表示内存地址，有些位表示寄存器编号，有些位表示这种指令做什么操作。

+ 算术逻辑单元（ALU，Arithmetic and Logic Unit）。如果解码器将一条指令解释为运算指令，就调动算术逻辑单元去做运算，比如加减乘除、位运算、判断一个条件是否成立等。

+ 地址和数据总线（Bus）。CPU和内存之间用地址总线、数据总线和控制线连接起来，32位处理器有32条地址线和32条数据线，每条线上有1和0两种状态，32条线的状态就可以表示一个32位的数。






### 变量的存储布局

作用域（Scope）这个概念适用于所有标识符，而不仅仅是变量，C语言的作用域分为以下几类：

+ 函数作用域（Function Scope），标识符在整个函数中都有效。只有语句标号属于函数作用域。标号在函数中不需要先声明后使用，在前面用一个goto语句也可以跳转到后面的某个标号，但仅限于同一个函数之中。

+ 文件作用域（File Scope），标识符从它声明的位置开始直到这个程序文件[28]的末尾都有效。例如上例中main函数外面的A、a、b、c，还有main也算，printf其实是在stdio.h中声明的，被包含到这个程序文件中了，所以也算文件作用域的。

+ 块作用域（Block Scope），标识符位于一对{}括号中（函数体或语句块），从它声明的位置开始到右}括号之间有效。例如上例中main函数里的a、b、c。此外，函数定义中的形参也算块作用域的，从声明的位置开始到函数末尾之间有效。

+ 函数原型作用域（Function Prototype Scope），标识符出现在函数原型中，这个函数原型只是一个声明而不是定义（没有函数体），那么标识符从声明的位置开始到在这个原型末尾之间有效。例如int foo(int a, int b);中的a和b。


对属于同一命名空间（Name Space）的重名标识符，内层作用域的标识符将覆盖外层作用域的标识符，例如局部变量名在它的函数中将覆盖重名的全局变量。命名空间可分为以下几类：

+ 语句标号单独属于一个命名空间。例如在函数中局部变量和语句标号可以重名，互不影响。由于使用标号的语法和使用其它标识符的语法都不一样，编译器不会把它和别的标识符弄混。

+ struct，enum和union（下一节介绍union）的类型Tag属于一个命名空间。由于Tag前面总是带struct，enum或union关键字，所以编译器不会把它和别的标识符弄混。

+ struct和union的成员名属于一个命名空间。由于成员名总是通过.或->运算符来访问而不会单独使用，所以编译器不会把它和别的标识符弄混。

+ 所有其它标识符，例如变量名、函数名、宏定义、typedef的类型名、enum成员等等都属于同一个命名空间。如果有重名的话，宏定义覆盖所有其它标识符，因为它在预处理阶段而不是编译阶段处理，除了宏定义之外其它几类标识符按上面所说的规则处理，内层作用域覆盖外层作用域。
 

标识符的链接属性（Linkage）有三种：

+ 外部链接（External Linkage），如果最终的可执行文件由多个程序文件链接而成，一个标识符在任意程序文件中即使声明多次也都代表同一个变量或函数，则这个标识符具有External Linkage。具有External Linkage的标识符编译后在符号表中是GLOBAL的符号。例如上例中main函数外面的a和c，main和printf也算。

+ 内部链接（Internal Linkage），如果一个标识符在某个程序文件中即使声明多次也都代表同一个变量或函数，则这个标识符具有Internal Linkage。例如上例中main函数外面的b。如果有另一个foo.c程序和main.c链接在一起，在foo.c中也声明一个static int b;，则那个b和这个b不代表同一个变量。具有Internal Linkage的标识符编译后在符号表中是LOCAL的符号，但main函数里面那个a不能算Internal Linkage的，因为即使在同一个程序文件中，在不同的函数中声明多次，也不代表同一个变量。

+ 无链接（No Linkage）。除以上情况之外的标识符都属于No Linkage的，例如函数的局部变量，以及不表示变量和函数的其它标识符。


存储类修饰符（Storage Class Specifier）有以下几种关键字，可以修饰变量或函数声明：

+ static，用它修饰的变量的存储空间是静态分配的，用它修饰的文件作用域的变量或函数具有Internal Linkage。

+ auto，用它修饰的变量在函数调用时自动在栈上分配存储空间，函数返回时自动释放，例如上例中main函数里的b其实就是用auto修饰的，只不过auto可以省略不写，auto不能修饰文件作用域的变量。

+ register，编译器对于用register修饰的变量会尽可能分配一个专门的寄存器来存储，但如果实在分配不开寄存器，编译器就把它当auto变量处理了，register不能修饰文件作用域的变量。现在一般编译器的优化都做得很好了，它自己会想办法有效地利用CPU的寄存器，所以现在register关键字也用得比较少了。

+ extern，上面讲过，链接属性是根据一个标识符多次声明时是不是代表同一个变量或函数来分类的，extern关键字就用于多次声明同一个标识符，下一章再详细介绍它的用法。

+ typedef，在“sizeof运算符与typedef类型声明”一节讲过这个关键字，它并不是用来修饰变量的，而是定义一个类型名。在那一节也讲过，看typedef声明怎么看呢，首先去掉typedef把它看成变量声明，看这个变量是什么类型的，那么typedef就定义了一个什么类型，也就是说，typedef在语法结构中出现的位置和是面几个关键字一样，也是修饰变量定义的，所以从语法（而不是语义）的角度把它和前面几个关键字归类到一起。


变量的生存期（Storage Duration，或者Lifetime）分为以下几类：

+ 静态生存期（Static Storage Duration），具有外部或内部链接属性，或者被static修饰的变量，在程序开始执行时分配和初始化一次，此后便一直存在直到程序结束。这种变量通常位于.rodata，.data或.bss段，例如上例中main函数外的A，a，b，c，以及main函数里的a。

+ 自动生存期（Automatic Storage Duration），链接属性为无链接并且没有被static修饰的变量，这种变量在进入块作用域时在栈上或寄存器中分配，在退出块作用域时释放。例如上例中main函数里的b和c。

+ 动态分配生存期（Allocated Storage Duration），以后会讲到调用malloc函数在进程的堆空间中分配内存，调用free函数可以释放这种存储空间。





### 结构体和联合体

结构体的各成员并不是一个紧挨一个排列的，中间有空隙，称为填充（Padding）

大多数计算机体系统结构对于访问内存的指令是有限制的，在32位平台上，访问4字节的指令（比如上面的movl）所访问的内存地址应该是4的整数倍，访问两字节的指令（比如上面的movw）所访问的内存地址应该是两字节的整数倍，这称为对齐（Alignment）。

合理设计结构体各成员的排列顺序可以节省存储空间，例如上例中的结构体改成这样就可以避免产生填充字节：
```
struct {
	char a;
	char d;
	short b;
	int c;
} s;
```
此外，gcc提供了一种扩展语法可以消除结构体中的填充字节：

```
struct {
	char a;
	short b;
	int c;
	char d;
} __attribute__((packed)) s;
```
这样就不能保证结构体成员的对齐了，在访问b和c的时候可能会有效率问题，所以除非有特别的理由，一般不要使用这种语法。


以前我们使用的数据类型都是占几个字节，最小的类型也要占一个字节，而在结构体中还可以使用Bit Field语法定义只占几个Bit的成员。
```
#include <stdio.h>

typedef struct {
	unsigned int one:1;
	unsigned int two:3;
	unsigned int three:10;
	unsigned int four:5;
	unsigned int :2;
	unsigned int five:8;
	unsigned int six:8;
} demo_type;

int main(void)
{
	demo_type s = { 1, 5, 513, 17, 129, 0x81 };
	printf("sizeof demo_type = %u\n", sizeof(demo_type));
	printf("values: s=%u,%u,%u,%u,%u,%u\n",
	       s.one, s.two, s.three, s.four, s.five, s.six);

	return 0;
}

```
Bit Field成员的类型可以是int或unsigned int，表示有符号数或无符号数，但不表示它像普通的int型一样占4个字节，它后面的数字是几就表示它占多少个Bit，也可以像unsigned int :2;

这样定义一个未命名的Bit Field，即使不写未命名的Bit Field，编译器也有可能在两个成员之间插入填充位，


C语言还有一种类型叫联合体，用关键字union定义，其语法类似于结构体。
```
#include <stdio.h>

typedef union {
	struct {
		unsigned int one:1;
		unsigned int two:3;
		unsigned int three:10;
		unsigned int four:5;
		unsigned int :2;
		unsigned int five:8;
		unsigned int six:8;
	} bitfield;
	unsigned char byte[8];
} demo_type;

int main(void)
{
	demo_type u = {{ 1, 5, 513, 17, 129, 0x81 }};
	printf("sizeof demo_type = %u\n", sizeof(demo_type));
	printf("values: u=%u,%u,%u,%u,%u,%u\n",
	       u.bitfield.one, u.bitfield.two, u.bitfield.three,
	       u.bitfield.four, u.bitfield.five, u.bitfield.six);
	printf("hex dump of u: %x %x %x %x %x %x %x %x \n",
	       u.byte[0], u.byte[1], u.byte[2], u.byte[3],
	       u.byte[4], u.byte[5], u.byte[6], u.byte[7]);

	return 0;
}
```
一个联合体的各个成员占用相同的内存空间，联合体的长度等于其中最长成员的长度。

比如u这个联合体占8个字节，如果访问成员u.bitfield，则把这8个字节看成一个由Bit Field组成的结构体，如果访问成员u.byte，则把这8个字节看成一个数组。

联合体如果用Initializer初始化，则只初始化它的第一个成员，
例如demo_type u = {{ 1, 5, 513, 17, 129, 0x81 }};初始化的是u.bitfield，但是通过u.bitfield的成员看不出这8个字节的内存布局，

而通过u.byte数组就可以看出每个字节分别是多少了。








### 链接详解

** extern和static关键字 **

凡是被多次声明的变量或函数，必须有且只有一个声明是定义，如果有多个定义，或者一个定义都没有，链接器就无法完成链接。

变量声明和函数声明有一点不同，函数声明的extern可写可不写，而变量声明如果不写extern意思就完全变了。


文件include 


gcc -I 告诉gcc头文件在那查找。
则需要用gcc -c main.c -Istack编译。用-I选项告诉gcc头文件要到子目录stack里找。

在#include预处理指示中可以使用相对路径，例如把上面的代码改成#include "stack/stack.h"，那么编译时就不需要加-Istack选项了


重复包含头文件有以下问题：

1. 一是使预处理的速度变慢了，要处理很多本来不需要处理的头文件。

2. 二是如果有foo.h包含bar.h，bar.h又包含foo.h的情况，预处理器就陷入死循环了（其实编译器都会规定一个包含层数的上限）。

3. 三是头文件里有些代码不允许重复出现，虽然变量和函数允许多次声明（只要不是多次定义就行），但头文件里有些代码是不允许多次出现的，比如typedef类型定义和结构体Tag定义等，在一个程序文件中只允许出现一次。



函数声明的规则

	Storage Class	File Scope Declaration	        Block Scope Declaration

	none		previous linkage/can define	previous linkage/cannot define

	extern		previous linkage/can define	previous linkage/cannot define

	static		internal linkage/can define	N/A 




Previous Linkage的定义是：

这次声明的标识符具有什么样的Linkage取决于前一次声明，这前一次声明具有相同的标识符名，而且必须是文件作用域的声明，

如果在程序文件中找不到前一次声明（这次声明是第一次声明），那么这个标识符具有External Linkage。


```
static int f(void); /* internal linkage */
extern int f(void); /* previous linkage */
```

则这里的extern修饰的标识符具有Interanl Linkage而不是External Linkage。
在文件作用域允许定义函数，在块作用域不允许定义函数，或者说函数定义不能嵌套。
在块作用域中不允许用static关键字声明函数。


变量声明的规则要复杂一些：

	Storage Class	File Scope Declaration			Block Scope Declaration

	none		external linkage / static duration		no linkage / automatic duration
			static initializer / tentative definition		dynamic initializer / definition


	extern		previous linkage / static duration		previous linkage / static duration
			no initializer[*] / not a definition		no initializer / not a definition


	static		internal linkage / static duration		no linkage / static duration
			static initializer / tentative definition		static initializer / definition




注意上表中标有[*]的单元格，对于文件作用域的extern变量声明，C99是允许带Initializer的，并且认为它是一个定义，但是gcc对于这种写法会报警告，为了兼容性应避免这种写法。



分别描述变量的链接属性、生存期，以及这种变量如何初始化，是否算变量定义。

链接属性有External Linkage、Internal Linkage、No Linkage和Previous Linkage四种情况。

生存期有Static Duration和Automatic Duration两种情况。


初始化有Static Initializer和Dynamic Initializer两种情况，

前者表示Initializer中只能使用常量表达式，表达式的值必须在编译时就能确定，

后者表示Initializer中可以使用任意的右值表达式，表达式的值可以在运行时计算。


是否算变量定义有三种情况，Definition（算变量定义）、Not a Definition（不算变量定义）和Tentative Definition（暂定的变量定义）。


什么叫“暂定的变量定义”呢？

一个变量声明具有文件作用域，没有Storage Class关键字修饰，或者用static关键字修饰，

那么如果它有Initializer则编译器认为它就是一个变量定义，
如果它没有Initializer则编译器暂定它是变量定义，

如果程序文件中有这个变量的明确定义就用明确定义，
如果程序文件没有这个变量的明确定义，就用这个暂定的变量定义，这种情况下变量以0初始化。


```

```



### 预处理


宏定义

函数式宏定义


用过的#define N 20或#define STR "hello, world"这种宏定义可以称为变量式宏定义（Object-like Macro），宏定义名可以像变量一样在代码中使用

另外一种宏定义可以像函数调用一样在代码中使用，称为函数式宏定义（Function-like Macro）。

```
#define MAX(a, b) ((a)>(b)?(a):(b))
```

1. 函数式宏定义的参数没有类型，预处理器只负责做形式上的替换，而不做参数类型检查，所以传参时要格外小心。

2. 使用函数式宏定义也往往会导致较低的代码执行效率。


函数式宏定义经常写成这样的形式
```
#define device_init_wakeup(dev,val) \
        do { \
                device_can_wakeup(dev) = !!(val); \
                device_set_wakeup_enable(dev,val); \
        } while(0)
```

为什么要用do { ... } while(0)括起来呢？不括起来会有什么问题呢？

```
#define device_init_wakeup(dev,val) \
                device_can_wakeup(dev) = !!(val); \
                device_set_wakeup_enable(dev,val);

if (n > 0)
	device_init_wakeup(d, v);

```
这样宏展开之后，函数体的第二条语句不在if条件中。那么简单地用{ ... }括起来组成一个语句块不行吗？

问题出在device_init_wakeup(d, v);末尾的;号，如果不允许写这个;号，看起来不像个函数调用，
可如果写了这个;号，宏展开之后就有语法错误，if语句被这个;号结束掉了，没法跟else配对。

因此，do { ... } while(0)是一种比较好的解决办法。



如果在一个程序文件中重复定义一个宏，C语言规定这些重复的宏定义必须一模一样。



在定义的前后多些空白（空格、Tab、注释）没有关系，在定义之中多些空白或少些空白也没有关系，但在定义之中有空白和没有空白被认为是不同的。

所以这样的重复定义是不允许的：
```
#define OBJ_LIKE (1 - 1)
#define OBJ_LIKE (1-1)
```

如果需要重新定义一个宏，和原来的定义不同，可以先用#undef取消原来的定义，再重新定义。



内联函数

C99引入一个新关键字inline，用于定义内联函数（inline function）。

inline关键字告诉编译器，这个函数的调用要尽可能快，可以当普通的函数调用实现，也可以用宏展开的办法实现。


** #、##运算符和可变参数 **

在函数式宏定义中，#运算符用于创建字符串，#运算符后面应该跟一个形参（中间可以有空格或Tab）
```
#define STR(s) # s
STR(hello 	world)
```
用cpp命令预处理之后是"hello world"，自动用双引号号把实参括起来成为一个字符串，并且实参中的连续多个空白字符被替换成一个空格。

即不需使用双引号创建字符串，调用宏定义就可以，宏展开之后字符串的界定符"要替换成\"，字符常量或字符串中的\和"字符要替换成\\和\"。



在宏定义中可以用##运算符把前后两个预处理Token连接成一个预处理Token，和#运算符不同，##运算符不仅限于函数式宏定义，变量式宏定义也可以用。


















