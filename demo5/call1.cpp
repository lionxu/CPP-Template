#include<iostream>
#include"the_class1.h"

/*
 * 定义了类模板实例the_class<int>
 * 编译器在编译的目标代码文件,为静态成员变量the_class<int>::id分配内存地址空间
 */
void call1() {
	the_class1<int> c;
	std::cout << c.id << std::endl;
}

