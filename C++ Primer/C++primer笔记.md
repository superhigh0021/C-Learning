箭头（->）：左边必须为指针；

点号（.）：左边必须为实体

# 顺序容器概述

1.除非你有很好的理由选择其他容器，否则应该使用vector

2.如果程序有很多小的元素，且空间的额外开销很重要，则不要用list容器

如果要求随机访问元素，应使用vector和deque

如果要求在中间插入或删除元素，应使用list

如果在头尾插入而不在中间，使用deque

当将一个容器拷贝到另一个容器中时，两个容器的类型和元素类型必须一致

array不支持普通容器的构造函数，除了指定元素类型，还要指定容器大小 array[int , 42]

assign仅支持顺序容器

emplace是构造而非insert和push的拷贝，可以避免临时变量的产生

在解引用迭代器之前，都要检是否有元素 if(!c.empty){} 

erase返回的是被删除的元素的下一个迭代器，要用一个迭代器去接受它的值

在添加和删除的操作中，保证每一次迭代器都得到更新！！！！！

insert 在给定位置之前插入一个元素，并返回该元素的位置，所以迭代器需要加2！

保存尾迭代器是个坏主意

# 泛型算法

## ***\*lambda表达式（匿名对象）\****

[ ] ( ) -> (type){ statement }

由于捕获列表的存在，可以作为条件算法函数的参数！！！！

## ***\*标准库bind函数\****

auto newCallable = bind ( callable , arg_list )

# 动态内存

## ***\*智能指针\****

会自动释放内存

\#include<memory>

shared_ptr 允许多个指针指向同一个对象 shared_ptr< 数据类型> 实例化对象

unique_ptr 独占所指向的对象

# Unit2

## 2.3复合类型

### 引用

引用必须被初始化，引用是别名。一般在初始化变量时，初始值会被拷贝到新建的对象中。定义引用是，程序把引用和她的初始值绑定(bind)在一起。无法另引用重新绑定另外一个值，所以引用必须初始化

连续声明时，必须在要声明为引用的对象前加&    int a=0;&b=a;

### 指针

指针在定义时若没有被初始化，将拥有一个不确定的值 

nullptr和NULL虽然都是0，但是nullptr可以被转换成任意其他的指针类型

建议初始化所有指针  在可能的情况下等定义了对象之后再定义指向它的指针。若实在不清楚指针应该指向何处，就初始化为nullptr

## const

#### const的引用

对常量对象的引用必须是常量  const int i=9;   必须是const int& b=i;

![image-20210610095829686](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210610095829686.png)

#### 顶层const和底层const

用顶层const表示指针本身是个常量，用底层const表示指针所指的对象是一个常量

constexpr修饰的指针是常量指指针

### 处理类型

#### 类型别名typedef

typedef double base,*p;    base是double的同义词、p是double* * 的同义词

using base = double；   同上

![image-20210610133810716](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210610133810716.png)



# Unit3

## 3.2标准库string类型

### 初始化      直接初始化、拷贝初始化

用=初始化一个变量，执行的是拷贝初始化，编译器将初始值拷贝到新创建的对象中去。

不用=初始化变量，执行的是直接初始化



### string字符串的特点

开始的时候跳过空格，然后遇到空格就结束,所以string字符串是不包含空格的



### string::size_type类型

string.size()函数返回的既不是int类型、也不是unsigned类型

而是size_type这个类型，它足以存放下任何string对象的大小，可以用auto来接受这个值



### string的加号

不能令一个string变量加一个字符串字面值，因为为了兼容C语言，C++中的字符串字面值并不是标准库类型的string对象。字符串字面值和string是不同的类型

### string到char* 的转化

string有一个库函数 c_str()，返回值是一个C风格的字符串，可以用char*接受它的返回值

![image-20210613003919308](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613003919308.png)



## 3.3 vector标准库

向量容器支持高效的随机访问，高效尾插，一般实现为一个动态分配的数组。

只能对确认已存在的元素执行下标操作，确保下标合法的手段就是尽量使用范围for

vector和string的迭代器

技巧：如果能够粗略估计出插入元素之后容器的大小，可以在插入之前用reserve函数确保空间的分配，避免插入的过程中多次重新分配空间

pop_back 删除尾部的元素

向vector容器中插入元素时，用T.push_back(i). 如果想在指定位置插入元素 v.insert(v.begin+n,value)

注意insert，掌握他！！！！！！！！

erase删除

clear()清除

迭代器的运算，没有加，只有减

总体上向量容器的插入操作效率并不高，插入位置越靠前，执行插入所需要的时间就越多



# Unit4

## 左值和右值

当一个对象被用作右值的时候，用的是对象的值(内容)，当对象被用作左值的时候，用的是对象的身份(在内存中的位置)

### 重要原则：

在需要右值的地方可以用左值代替，但是不能吧右值当成左值来使用

## 赋值运算符

赋值运算符的左侧运算对象必须是一个可修改的左值![image-20210613005125540](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613005125540.png)

赋值运算符满足右结合律![image-20210613005358707](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613005358707.png)

因为赋值运算符的优先级低于关系运算符，所以在条件语句中没复制部分通常应该加上括号。

## 递增、递减运算符

前置版本将对象本身作为左值返回，后置版本将对象原始值的副本作为右值返回![image-20210613010353075](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613010353075.png)

## 位运算符

![image-20210613011331618](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613011331618.png)

### 移位<<和>>

将左侧运算对象的内容按照右侧运算对象的要求移动指定的位数，然后将左侧运算对象的拷贝作为求值结果

如果对char等类型进行移位运算，会产生提升操作，将char提升为int

### 位与、位或、位异或

![image-20210613012128839](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613012128839.png)

## sizeof运算符

sizeof返回一条表达式或者一个类型名字占用的字节数

## 类型转换

### 隐式类型转换

while(cin>>s)如果cin读取成功，得到true，如果失败，得到false

### 显式类型转化

![image-20210613144208017](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210613144208017.png)

#### static_cast

任何具有明确定义的类型转换，只要不包含底层const，都可以用static_cast

如下：double slope= static_cast<double>(j)/i;

#### const_cast

const_cast只能改变底层const

将常量对象转换成非常量对象，即去掉const的性质



# Unit5语句

## 范围for语句

冒号后面表示的必须是一个序列，比如用花括号括起来的初始化列表、数组、或者vector等对象，这些类型的共同类型是拥有能返回迭代器begin和end成员。

## try语句块和异常处理

throw表达式：异常检测部分使用throw表达式来表示它遇到了无法处理的问题。称作throw引发了异常

try语句块：异常处理部分使用try语句块处理一场，try语句块以关键字try开始，并以一个或多个catch子句结束。try语句块中代码抛出的异常通常会被某个catch子句处理。因为catch子句“处理”异常



## throw表达式

throw表达式包含关键字throw和紧随其后的一个表达时，表达式的类型就是抛出的异常类型，抛出异常将终止当前的函数，并且将控制权转移给能处理该异常的代码

## try语句块

![image-20210614012950737](C:\Users\my little airport\AppData\Roaming\Typora\typora-user-images\image-20210614012950737.png)



# Unit6 函数

### 使用引用避免拷贝

拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型根本就不支持拷贝操作。最好使用易用形参访问该类型的对象

# 四、deque容器

双端队列支持向两端搞笑插入数据，支持随机访问

向中间插入和删除元素效率较低

# 五、list容器

物理存储单元是非连续的

不能随机访问但是可以高效的在任意位置插入和删除元素 

占用的时间和空间比数组大，因为有数据域和指针域

列表一般实现为双向链表，属于可逆容器

操作不会使原有的迭代器失效，这点和vector不同

reverse()反转函数，是链表中的元素反转过来

***\*所有不支持随机访问迭代器的容器，不可以使用标准算法（#include\*******\*<algorithm>\*******\*）\****

***\*不支持随机访问迭代器的容器，内部回提供对应的算法\****

***\*要用成员函数进行操作\****

比如list容器不能用sort，但是可以v.sort() 此时就没有迭代器的两个参数了，只有升降序的那一个参数，而且还他妈要自己 编

# 六、stack容器

stack是一种先进后出的数据结构，只有一个出口

栈中只有顶端元素可以使用，所以不可以遍历

push(elem)向栈顶添加元素

pop()从栈顶移除第一个元素 无参数

top()返回栈顶元素 无参数

# 七、queue容器

queue队列，是先进先出的数据结构，有两个出口

队头：出数据

队尾：入数据

只有队头和队尾可以被外接访问，queue不允许有遍历行为

back()返回最后一个元素

front()返回第一个元素

# 八、set（multiset）容器（关联式容器）

所有元素在插入时自动被排序 底层结构使用二叉树实现

set不允许有重复的元素，multiset允许有重复的元素

在插入数据时没有push等操作，只有insert

find(key) 查找函数，查找key这个元素，如果存在，返回该键的元素的迭代器；若不存在，返回set.end()

***\*所以使用该函数的时候，要声明并一个迭代器来接受它的值！！！！！！！\****

if( it != v.end() ) 说明找到了

count(key) 统计key这个元素的个数

# 九、函数

如果不需要更改参数的值，用常量引用。（const int &t) 至于这东西和普通形参有啥区别，我不懂(?)

然后去CSDN上找了找

引用传递可以避免截断问题

使用传值改为传引用能避免对象被截断问题 : 主要影响就在于多态的表现.

具体参照该链接https://blog.csdn.net/function_dou/article/details/86608247

常量和引用都必须初始化！！！

## ***\*数组形参\****

由于数组不能拷贝，所以无法以值传递的方式使用数组参数。所以当我们为函数传递数组的时候，实际上是传递指向数组收元素的指针。

## ***\*返回值类型和return语句\****

单一个return，不管函数还有啥东西，直接退出。

不要返回局部变量的引用或指针

# 十、类

## ***\*1.构造函数\****

初始化时，确保顺序与成员声明的顺序一致。如果可能的话，避免使用某些成员初始化其他成员

## ***\*2.const修饰成员函数\****

const在成员函数尾部，表示该成员函数不会修改类的数据

# 十一、IO类

可以使用endl来显式刷新缓冲区

cout<<"hi!"<<flush; 输出hi！然后刷新缓冲区。 flush直接刷新缓冲区，不输出字符

程序异常终止，输出缓冲区是不会被刷新的。当一个程序崩溃后，他所输出的数据很可能停留在缓冲区等待打印

当一个fstream对象被销毁，close会自动调用

getline函数的第一个参数是流对象

ofstream和ifstream后面跟的都是流对象







223.244.105.214
