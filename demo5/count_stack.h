#pragma once
#include"stack.h"
/*
 * count_stack��stack��ģ���һ������ģ��
 * ��ģ��Ļ��������ĳ������,�ʶ�count_stack�Ļ���д��my_stack<T>
 * ������T�������ݵ�my_stack��ģ���ʵ������
 * �����ﶨ���ʱ��,����ʹ��count_stack��ģ�����T,������my_stack��ģ�����ֵ.
 * �����������ͨ�����̳���ģ��,������ҪΪ����ģ��ָ��ģ���βε�ֵ.
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

