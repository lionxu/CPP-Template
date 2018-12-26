#include<iostream>

/*
 * ���������ǰ�һ��ģ�嵱��ģ��Ĳ���ʹ��
 * �������е�class�ؼ����Ǳ����,˵��ֻ����ģ�������Ϊģ��Ĳ���
 * ���Ҳ�����struct�滻class
 */

// Func��һ��ģ����ģ�庯��,��װforeachҪ��ÿ��Ԫ�ؽ��еĲ���
template<template<typename TT> class Func, typename T>
void foreach(T array[], unsigned size) {
	Func<T> func;
	for (unsigned i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

// ���ֲ�������װ�ɺ�����ģ��,����ͨ�����Ų���������
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

	// foreach���Զ�����print����ģ�����ʵ��
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