#include<iostream>

/*
 * 定义一个求最大值的函数模板
 */
template<typename T>
T const& max_element(T const *l, unsigned sz) {
	T const *max_value(l);
	for (unsigned i = 0; i < sz; i++)
	{
		if (l[i] > *max_value)
		{
			max_value = &l[i];
		}
	}
	return *max_value;
}

int main() 
{
	int l[] = {2, 0, 1, 1, 0, 8, 2, 5};
	char cl[] = "August";
	/*
	 * 此处在调用函数的时候,我们向函数传递了模板形参的类型
	 * 这样CPP的编译器可以根据我们传递的模板形参类型来生成一个相对应的函数,
	 * 对特定类型的数据进行处理
	 */
	std::cout << max_element<int>(l, 8) << std::endl;
	std::cout << max_element<char>(cl, 6) << std::endl;
	/*
	 * 此处我们调用函数的时候,并没有指定模板形参的值
	 * 这里利用了CPP的模板形参自动推导的功能。
	 * CPP的编译器根据调用模板函数的实参的类型来推导出模板形参的类型
	 */
	std::cout << max_element(l, 8) << std::endl;
	std::cout << max_element(cl, 6) << std::endl;
	return 0;
}