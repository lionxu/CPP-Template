#include<iostream>

/*
 * 在这里我们把一个模板当做模板的参数使用
 * 在声明中的class关键字是必须的,说明只有类模板可以作为模板的参数
 * 而且不能用struct替换class
 */

// Func是一个模板型模板函数,包装foreach要对每个元素进行的操作
template<template<typename TT> class Func, typename T>
void foreach(T array[], unsigned size) {
	Func<T> func;
	for (unsigned i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

// 三种操作都包装成函数类模板,可以通过括号操作符调用
template<typename T>
struct inc {
	void operator()(T &v) const { ++v; }
};

template<typename T>
struct dec {
	void operator()(T &v) const { --v; }
};

template<typename T>
struct print {
	void operator()(T &v) const { std::cout << v << ' '; }
};

int main1() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	// foreach会自动生成print函数模板类的实例
	foreach<print>(array, 9);
	std::cout << std::endl;

	foreach<inc>(array, 9);
	foreach<print>(array, 9);
	std::cout << std::endl;

	foreach<dec>(array, 9);
	foreach<print>(array, 9);
	std::cout << std::endl;
	return 0;
}