#include<iostream>

/*
 * ͨ������ָ���������ʵ�ֻص������Ĺ���
 * ���ɺ����ĵ��÷�������Ҫִ�еĲ�����װ�ɺ���f0,
 * ����ָ��˺�����ָ��&f0,�Բ�������ʽ���ݸ�����f1,
 * ����f1������ʱ�ص���ָ����f0,�Ӷ�ʵ�ֵ��÷����ڴ��Ĺ���.
 * ����f0����һ���ص�����
 * ���ص�������ָ���Բ�������ʽ���ݸ����ú���,ʵ�ֵ��Ƕ�̬�ص�
 * ��Ϊֻ��������ʱ����ȷ�����õ����ĸ�����
 * �������Ҫ��̬�ص�,ֻΪ����,�������㷨�����Ƕ���������,��̬�ص�������ţ��ɱ��
 * ��ʱ,���ǽ��ص�����ָ��Ӻ��������Ƶ�ģ�����,�ͺ�����ʵ�־�̬�ص�
 */

/*
 * ����һ��foreach����ģ��,�������е�ÿһ��Ԫ�ؽ���ĳ�ֲ���
 * ���������ģ��ĺ���ָ�����ָ��
 * �˴�ʹ�õ��Ƿ�����ģ���β�,����ָ��ģ�����
 */
template<typename T, void (*f)(T &v)>
void foreach(T array[], unsigned size) {
	for (unsigned i = 0; i < size; i++) f(array[i]);
}

/*
 * ��������ģ���������������Ԫ�صĲ���
 */
template<typename T>
void inc(T &v) { ++v; }

template<typename T>
void dec(T &v) { --v; }

template<typename T>
void print(T &v) { std::cout << " " << v; }

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

	foreach<int, print<int> >(array, 8);
	std::cout << std::endl;

	foreach<int, inc<int> >(array, 8);
	foreach<int, print<int> >(array, 8);
	std::cout << std::endl;

	foreach<int, dec<int> >(array, 8);
	foreach<int, print<int> >(array, 8);
	std::cout << std::endl;
	return 0;
}