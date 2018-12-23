#include<iostream>
#include<string>

// ���ڹ���Ԫ�����ģ��

/*
 * ��next������ָ�뻻�ɻ�����ͨ�ĳ�Ա����
 * �������Ա������������ڴ洢ʱ�Ķ����ָ�뿪��
 * ��������д������һ��ȱ��
 * ��,�ڵ���ģ�庯��push����Ԫ���ʱ��,�����ظ�����Ԫ�ص�����.
 * �������Ԫ���������͹��ڸ���,���������ظ����ƻ������������.
 */
template<typename T, typename N>
struct tuple{
	T value1;
	N next1;
	tuple(T const &v, N const &n): value1(v), next1(n){}
};

// ��Ԫ��������Ԫ�صĺ���ģ��
template<typename T, typename N>
tuple<T, N> push(T const &v, N const &n) {
	return tuple<T, N>(v, n);
}

int main2() {
	// ͨ��typedef�����ĸ�Ԫ�ص�Ԫ������
	typedef tuple<int, char> tuple2;
	typedef tuple<float, tuple2> tuple3;
	typedef tuple<std::string, tuple3> tuple4;

	// ͨ��Ƕ�׵���push����ģ�幹��һ��4Ԫ�ص�Ԫ����
	tuple4 tup4 = push(std::string("awesome!"), push(.1f, push(1, 'a')));

	// ͨ��Ԫ�����next��Ա���ʵ�Ԫ���е��κ�һ��Ԫ��
	std::cout << tup4.value1 << ", "
		<< tup4.next1.value1 << ", "
		<< tup4.next1.next1.value1 << ", "
		<< tup4.next1.next1.next1 << ", "
		<< std::endl;
	return 0;
}