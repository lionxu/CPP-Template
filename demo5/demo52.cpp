#include<string>
#include<iostream>
/*
 * hetero_node:��һ����������Ľڵ���ģ��
 * �ýڵ��ָ����һ���ڵ��ָ���������һ��ģ���β�.
 * ����ζ��,����������һ���ڵ��Ԫ�����Ϳ��ܺ�ǰһ���ڵ��Ԫ�����Ͳ�ͬ
 * ����һ�������еĽڵ��Ԫ�������ǲ���ͬ��,�����������Ϊһ����������
 */

template<typename T, typename N>
struct hetero_node{
	T value;
	N *next;

	hetero_node(T const &v, N *n): value(v), next(n){}

};

// �������ݵ�ģ�庯��
template<typename T, typename N>
hetero_node<T, N>* push(T const &v, N *n) {
	return new hetero_node<T, N>(v, n);
}

// ��������ɾ������ͷ�ڵ������
template<typename T, typename N>
N *pop(hetero_node<T, N> *head) {
	N *next = head->next;
	delete head;
	return next;
}

/*
 * ʹ��������������Ԫ��
 */
int main1() {
	/*
	 * ���������ÿ���ڵ����Ͷ�����ͬ,��ʹ����������ݵ����Ͷ�����ͬ��
	 * ��ڵ�����Ҳ����ͬ
	 */
	typedef hetero_node<int, void> node_0;
	typedef hetero_node<char, node_0> node_1;
	typedef hetero_node<std::string, node_1> node_2;

	// Ƕ�׵���pushģ���Թ�����Ԫ��
	/*
	 * �ڵ��ú���ģ���ʱ��,����ģ�庯����ģ��������Զ��Ƶ�����,�����������T��N��ֵ
	 */
	node_2 *p2 = push(std::string("Awesome"), push('a', push(1, (void*)0)));

	// ͨ��next��Ա���Է��ʵ���Ԫ���е������Ա
	std::cout << p2->value << ", "
		<< p2->next->value << ", "
		<< p2->next->next->value << std::endl;
	return 0;

	// ͨ��Ƕ�׵���popģ���������ȷ�ͷ��ڴ�������Ԫ��
	pop(pop(pop(p2)));
}