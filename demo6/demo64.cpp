#include<iostream>

/*
 * 以指针或者引用作为模板参数的时候,其作用和整数型模板参数类似,
 * 相当于为函数或类声明一个常量的指针或者引用
 * 需要注意的是,只有指向全局变量或者外部变量(使用extern修饰)以及类静态变量的指针及引用才可作为模板参数.
 * 函数的局部变量以及类的成员变量等均不能作为模板参数
 * 这是因为模板参数值必须是编译时已知的
 * 对于指针及引用，需要在编译时确定其所指向或所引用的变量在内存中的地址。
 * 而局部变量有可能被编译器分配到函数调用堆栈上，内存地址不固定,故而无法作为模板参数使用
 */

// 以指针作为模板参数
template<int *p>
struct wrapper1 {
	int get() { return *p; }
	void set(int v) { *p = v; }
};

// 以引用作为模板参数
template<int &p>
struct wrapper2 {
	int get() { return p; }
	void set(int v) { p = v; }
};

int global_variable = 0;

int main1() {
	wrapper1<&global_variable> gwrapper1;
	gwrapper1.set(1);
	std::cout << gwrapper1.get() << std::endl;

	wrapper2<global_variable> gwrapper2;
	gwrapper2.set(2);
	std::cout << gwrapper2.get() << std::endl;

	return 0;
}