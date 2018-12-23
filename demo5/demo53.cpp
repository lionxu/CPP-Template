#include<iostream>
#include<string>

// 用于构建元组的类模板

/*
 * 把next类型由指针换成换成普通的成员变量
 * 这样可以避免异质链表在存储时的额外的指针开销
 * 但是这种写法存在一个缺陷
 * 即,在调用模板函数push构造元组的时候,存在重复复制元素的问题.
 * 如果所存元素数据类型过于复杂,无疑这种重复复制会存在性能问题.
 */
template<typename T, typename N>
struct tuple{
	T value1;
	N next1;
	tuple(T const &v, N const &n): value1(v), next1(n){}
};

// 向元组中增加元素的函数模板
template<typename T, typename N>
tuple<T, N> push(T const &v, N const &n) {
	return tuple<T, N>(v, n);
}

int main2() {
	// 通过typedef构造四个元素的元组类型
	typedef tuple<int, char> tuple2;
	typedef tuple<float, tuple2> tuple3;
	typedef tuple<std::string, tuple3> tuple4;

	// 通过嵌套调用push函数模板构造一个4元素的元组类
	tuple4 tup4 = push(std::string("awesome!"), push(.1f, push(1, 'a')));

	// 通过元组类的next成员访问到元组中的任何一个元素
	std::cout << tup4.value1 << ", "
		<< tup4.next1.value1 << ", "
		<< tup4.next1.next1.value1 << ", "
		<< tup4.next1.next1.next1 << ", "
		<< std::endl;
	return 0;
}