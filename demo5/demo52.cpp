#include<string>
#include<iostream>
/*
 * hetero_node:是一个异质链表的节点类模板
 * 该节点的指向下一个节点的指针的类型是一个模板形参.
 * 这意味着,在链表中下一个节点的元素类型可能和前一个节点的元素类型不同
 * 这样一个链表中的节点的元素类型是不相同的,这样的链表称为一个异质链表
 */

template<typename T, typename N>
struct hetero_node{
	T value;
	N *next;

	hetero_node(T const &v, N *n): value(v), next(n){}

};

// 新增数据的模板函数
template<typename T, typename N>
hetero_node<T, N>* push(T const &v, N *n) {
	return new hetero_node<T, N>(v, n);
}

// 从链表中删除链表头节点的数据
template<typename T, typename N>
N *pop(hetero_node<T, N> *head) {
	N *next = head->next;
	delete head;
	return next;
}

/*
 * 使用异质链表构造三元组
 */
int main1() {
	/*
	 * 异质链表的每个节点类型都不相同,即使所保存的数据的类型都是相同的
	 * 其节点类型也不相同
	 */
	typedef hetero_node<int, void> node_0;
	typedef hetero_node<char, node_0> node_1;
	typedef hetero_node<std::string, node_1> node_2;

	// 嵌套调用push模板以构造三元组
	/*
	 * 在调用函数模板的时候,根据模板函数的模板参数的自动推导机制,我们无需给出T和N的值
	 */
	node_2 *p2 = push(std::string("Awesome"), push('a', push(1, (void*)0)));

	// 通过next成员可以访问到三元组中的任意成员
	std::cout << p2->value << ", "
		<< p2->next->value << ", "
		<< p2->next->next->value << std::endl;
	return 0;

	// 通过嵌套调用pop模板则可以正确释放内存销毁三元组
	pop(pop(pop(p2)));
}