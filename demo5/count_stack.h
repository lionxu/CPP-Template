#pragma once
#include"stack.h"
/*
 * count_stack是stack类模板的一个子类模板
 * 类模板的基类必须是某个类型,故而count_stack的基类写成my_stack<T>
 * 即保存T类型数据的my_stack类模板的实例类型
 * 在这里定义的时候,我们使用count_stack的模板参数T,来定义my_stack的模板参数值.
 * 如果我们用普通类来继承类模板,我们需要为基类模板指定模板形参的值.
 */
template<typename T=int>
class count_stack: public my_stack<T>
{
	typedef my_stack<T> base_type;
	unsigned size;
public:
	count_stack() : base_type(), size(0) {}

	void push(T const &v) {
		base_type::push(v);
		size++;
	}

	void pop() {
		if (size > 0) {
			base_type::pop();
			size--;
		}
	}

	unsigned getSize() const { return size; }
};

