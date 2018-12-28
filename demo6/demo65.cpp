#include<iostream>

/*
 * 通常函数指针的作用是实现回调函数的功能
 * 即由函数的调用方将所需要执行的操作封装成函数f0,
 * 并将指向此函数的指针&f0,以参数的形式传递给函数f1,
 * 函数f1在运行时回调所指函数f0,从而实现调用方所期待的功能.
 * 这样f0就是一个回调函数
 * 将回调函数的指针以参数的形式传递给调用函数,实现的是动态回调
 * 因为只有在运行时才能确定调用的是哪个函数
 * 如果不需要动态回调,只为方便,在已有算法框架中嵌入所需操作,则动态回调就略显牛刀杀鸡
 * 此时,我们将回调函数指针从函数参数移到模板参数,就很容易实现静态回调
 */

/*
 * 定义一个foreach函数模板,对数组中的每一个元素进行某种操作
 * 具体操作由模板的函数指针参数指定
 * 此处使用的是非类型模板形参,函数指针模板参数
 */
template<typename T, void (*f)(T &v)>
void foreach(T array[], unsigned size) {
	for (unsigned i = 0; i < size; i++) f(array[i]);
}

/*
 * 三个函数模板用来定义对数组元素的操作
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