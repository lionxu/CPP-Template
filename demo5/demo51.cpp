/*
 * 利用CPP语言的类模板特性,我们可以实现如下目标
 * 对于某一个数据结构的描述可以脱离具体的类型,
 * 我们只需要专注于数据的存取以及数据之间的逻辑关系的描述。
 * 我们以常见的数据结构栈为例,来作为说明的示例.
 * 栈是一种后进先出的数据结构,而且其数据元素的数量是不确定的.
 * 一般我们采用链表的实现方式,而且由于我们只需要知道链表的头节点,就可以对栈实现操作.
 * 最简单的方式就是使用单链表来实现.
 * 我们来定义一下链表的节点,如果不使用类模板,每种类型都需要单独给出节点的定义.
 */

/*
 * 保存整数值的单链表节点
 */

struct int_node
{
	int value;
	int_node *next;
};

/*
 * 保存浮点数值的单链表节点
 */
struct float_node
{
	float value;
	float_node *next;
};

/*
 * 使用类模板统一上述两种单链表节点的定义
 * 此处模板形参T表示要存储的数据类型,
 * next是一个指向链表下一个节点的指针
 * list_node只是一个类模板的名称,无法表示一个具体的类型.
 * 应该写为:list_node<T>
 * 此处利用了CPP的一个特性:在类模板中出现的自身模板名,等价于该模板被调用时所生成的实例.
 * 而且,此处我们还为类的模板形参设置的默认值
 */
template<typename T=int>
struct list_node
{
	T value;
	list_node *next;
};

// 调用类模板,生成保存整形数据的模板实例,相当于int_node
list_node<int> inode;
// 调用类模板,生成保存浮点形数据的模板实例,相当于float_node
list_node<float> fnode;
// 利用模板形参的默认值来生成保存整形数据的模板实例
/*
 * 类模板是没有实参推导机制的,所以我们在调用类模板的时候必须指定模板形参
 * 而我们可以省略的是,类模板的模板形参列表中,最后有默认值的几个相邻的模板形参
 */