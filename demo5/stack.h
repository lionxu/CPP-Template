#pragma once
/*
 * ���Ƕ���һ��ջģ����,����װ���ݵ���ջ�ͳ�ջ,�Լ��ж�ջ�Ƿ�Ϊ�յĲ���
 */
#include<stdexcept>

/*
 * ջ��ģ���ǰ������
 * Ϊ���ñ������ں���list_node������������my_stack<T>ʱ,
 * ֪��my_stack��һ����ģ�������Ҫģ�����
 * ���ǽ�list_node�����г�Ա�����ȫ˽��,��my_stack����Ϊlist_node����Ԫ��
 * my_stack����Է���list_node�����г�Ա,�������֯��list_node��ɵĵ�����ĳ�Ա
 */
template<typename T> class my_stack;

template<typename T>
class list_node {
	T value;
	list_node *next;

	// ˽�й��캯��,ֻ��������Ԫ��������.
	list_node(T const &v, list_node *n) : value(v), next(n) {}

	// ������Ԫ��,������my_stack��ģ���ʵ��
	friend class my_stack<T>;
};

template<typename T>
class my_stack {

	/* Ϊlist_node<T>��һ������,ʹ�ú��������list_node<T>��ʹ����,
	 * ��ʹ�ñ�����ʱ�������Ӽ��
	 */
	typedef list_node<T> node_type;
	node_type *head;

	// ����my_stack�Ŀ������캯���͸�ֵ������
	my_stack operator=(my_stack const &) {}
	my_stack(my_stack const &) {}

public:
	// ���幹�캯������������
	my_stack() : head(0) {}
	~my_stack() {}

	// ����ģ����ʵ�ֵĳ�Ա����ģ��
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

	// ģ���Ա����������,������ģ������ʵ��
	void pop();
};

// ����ģ������ʵ�ֵĳ�Ա����
template<typename T>
void my_stack<T>::pop() {
	if (head)
	{
		node_type *tmp = head;
		head = head->next;
		delete tmp;
	}
}