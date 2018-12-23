#pragma once
/*
 * 我们定义一个栈模板类,来封装数据的入栈和出栈,以及判断栈是否为空的操作
 */
#include<stdexcept>

/*
 * 栈类模板的前置声明
 * 为了让编译器在后续list_node的声明中遇到my_stack<T>时,
 * 知道my_stack是一个类模板而且需要模板参数
 * 我们将list_node的所有成员变成完全私有,把my_stack声明为list_node的友元类
 * my_stack便可以访问list_node的所有成员,便可以组织由list_node组成的单链表的成员
 */
template<typename T> class my_stack;

template<typename T>
class list_node {
	T value;
	list_node *next;

	// 私有构造函数,只能由其友元类来访问.
	list_node(T const &v, list_node *n) : value(v), next(n) {}

	// 定义友元类,必须是my_stack类模板的实例
	friend class my_stack<T>;
};

template<typename T>
class my_stack {

	/* 为list_node<T>赋一个别名,使得后续代码对list_node<T>的使用中,
	 * 在使用别名的时候代码更加简洁
	 */
	typedef list_node<T> node_type;
	node_type *head;

	// 禁用my_stack的拷贝构造函数和赋值操作符
	my_stack operator=(my_stack const &) {}
	my_stack(my_stack const &) {}

public:
	// 定义构造函数与析构函数
	my_stack() : head(0) {}
	~my_stack() {}

	// 在类模板内实现的成员函数模板
	bool empty() const { return head == 0; }

	T const& top() throw (std::runtime_error){
		if (empty())
		{
			throw std::runtime_error("stack is empty");
		}
		return head->value;
	}

	void push(T const &v) {
		head = new node_type(v, head);
	}

	// 模板成员函数的声明,将在类模板外面实现
	void pop();
};

// 在类模板外面实现的成员函数
template<typename T>
void my_stack<T>::pop() {
	if (head)
	{
		node_type *tmp = head;
		head = head->next;
		delete tmp;
	}
}