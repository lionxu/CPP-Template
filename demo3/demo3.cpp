#include<iostream>

using namespace std;
/*
 * 此处我们为T0和T1指定了,默认类型。
 * 这里我们利用了C++11的最新特性,允许为函数模板参数赋默认值
 * 在func中，当我们为T0和T2这两个无法根据实参类型自动推导出类型的模板参数赋予默认值后,
 * 调用func模板时候的时候,模板实参列表可以完全省略。
*/
template<typename T0 = float,
	typename T1,
	typename T2 = float,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4);

/*
 * 下面的代码运行的结果为:
 * v1: 1   v3: 2   v4: 3   || sv0: 0       sv2: 0
 * v1: 4   v3: 5   v4: 6   || sv0: -1      sv2: -1
 * v1: 1   v3: 0.1 v4: 0.1 || sv0: 0       sv2: 0
 * v1: 0.1 v3: 0.1 v4: 0.1 || sv0: 0       sv2: 0
 * 因为在函数的定义中,sv0和sv2是两个静态变量.
 * 在CPP中函数的静态变量为每个函数私有,不同的函数之间,相同名称的静态变量是无法共享的。
 * 很显然,在CPP的模板函数中,静态变量仍然存在于每个根据模板实例化以后的函数中.
 * 在CPP中会编译器会根据不同的函数模板实参自动生成相应的函数实例。
 * 在下面的main函数中,总共有三组不同的模板实参,分别是
 * i: <float int, float, int, int>,此时对应的函数调用是:func(1, 2, 3)和func(4, 5, 6)
 * ii: <float int, float, double, double>,此时对应的函数调用为:func(1, 0.1, 0.1)
 * iii: <float, double, float, double, double>,此时对应的函数调用为:func(0.1, 0.1, 0.1)
 * 很显然，对于i,编译器为这两个函数调用生成了一个函数,所以sv0和sv2这两个静态变量在这两次函数调用之间发生了变化。
 * 而对于ii和iii而言,编译器分别为这两个函数调用生成了两个函数,所以这两个调用中,sv0和sv2的值均为0.
 * 即，他们没有共享。
 * 当有不同的函数调用模板形参时，编译器才会生成新的函数，否则就用已经生成的函数。
 */
int main() {
	double sv2;
	sv2 = func(1, 2, 3);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(4, 5, 6);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(1, 0.1, 0.1);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(0.1, 0.1, 0.1);
	cout << "\tsv2: " << sv2 << endl;
	return 0;
}

template<typename T0 = float,
	typename T1,
	typename T2 = float,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4) {
	T0 static sv0 = T0(0);
	T2 static sv2 = T2(0);

	cout << "\tv1: " << v1
		<< "\tv3: " << v3
		<< "\tv4: " << v4
		<< "\t|| sv0: " << sv0;
	T2 v2 = sv2;
	sv0 -= 1;
	sv2 -= 1;
	return v2;
}