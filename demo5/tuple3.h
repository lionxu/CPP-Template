#pragma once
/*
 * 在这里我们定义了一个可以存储任意元素类型的三元组.
 * 避免了异质链表的额外存储空间和构造重复复制的问题.
 * 但是,这个元组只可以存储三个元素
 * 如果存储四个元素或者更多,我们就需要重新定义更多的元组.
 * 而且如果为类模板添加一些其他的功能,代码的改动量就会很大.
 */
template<typename T0, typename T1, typename T2>
struct tuple3 {
	T0 v0;
	T1 v1;
	T2 v2;

	tuple3(T0 const &_v0, T1 const &_v1, T2 const &_v2) :
		v0(_v0), v1(_v1), v2(_v2) {}
};