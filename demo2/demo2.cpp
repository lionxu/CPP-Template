#include<iostream>

/*
 * 此处定义的函数示例是为了说明CPP函数模板形参的自动推到规则。
 * 1、CPP编译器只根据函数调用时给出的实参列表来推导模板参数值,与函数参数类型无关的模板参数其值无法推导
 * 根据规则1，很显然我们在调用函数func的时候,无需指定T1、T3、T4的模板形参类型
 * 因为可以根据函数调用的实参列表自动推到出来
 * 因而,我们需要指定的模板形参的类型是T0和T2的类型。
 * 2、与函数返回值相关的模板参数其值也无法推导。
 * 根据规则2,我们很清楚T2的类型无法自动推到出来。
 * 我们粗略一想,在某些情况下似乎是可以推导出来的。
 * 例如,对函数func调用的伪代码如下:
 * double d = func<...>(...);
 * 似乎，根据d的类型，我们应该认为T2就是一个double呢。
 * 其实不然,因为CPP中存在内置类型自动转型的机制。
 * double类型的变量不仅可以接受其他double型变量或常量的赋值,
 * 也可以接受诸如int型、char型等多种类型变量以及常量的值，
 * 甚至可以接受用户自定义类型变量以及常量的赋值。
 * 所以，如果不在模板参数列表中显示指定给定函数返回值类型,
 * 则以上示例伪代码,在编译器特化函数的时候,会产生歧义。
 * 更有甚者,我们可能不会定义一个变量去保存函数的返回值。
 * 这样，函数的返回值类型就更无从去推断了,
 * 因此，T2的类型是无法推断的，需要在函数调用的时候返回.
 * 3、所有可推导模板参数必须是连续位于模板参数列表的尾部,中间不能有可推导的模板参数。
 * 根据规则3，我们的T1类型必须指定,否则函数调用的语句就写成如下形式了:
 * sv0 = func<double, , int>(1, 2, 3),即可推导模板参数T1位于模板参数列表的中间了。
 * 故而，我们在调用func函数的时候,可以省略的模板参数为T3，T4.
 * 我们必须指出T0，T1，T2的类型。
 */
template<typename T0,
	typename T1,
	typename T2,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4) {
	T0 static sv0 = T0(0);
	T2 static sv2 = T2(0);
	std::cout << "\tv1: " << v1
		<< "\tv3: " << v3
		<< "\tv4: " << v4
		<< "\t|| sv0: " << sv0;
	T2 v2 = sv2;
	sv0 -= 1;
	sv2 -= 1;
	return v2;
}

int main() {
	double sv2;
	sv2 = func<double, int, int>(1, 2, 3);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<double, int, int>(1, 2, 3);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<double, int, int>(1, 0.1, 0.1);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<int, double, double>(0.1, 0.1, 0.1);
	std::cout << "\tsv2: " << sv2 << std::endl;
}