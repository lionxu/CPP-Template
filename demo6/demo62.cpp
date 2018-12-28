#include<stdexcept>
#include<iostream>

/* 
 * 为了解决数组长度定义为类常量所带来的问题,
 * 我们在类模板的形参列表中引入了类型为整形的模板形参
 * 此处我们使用了非类型模板形参
 * 非类型模板参数,在本质上相当于为函数模板或者类模板定义常量
 * 而且在生成模板实例的时候,也需要以常量来为非类型模板参数赋值
 */

template<typename T, unsigned size>
class array
{
	T elements[size];

public:
	T& operator[](unsigned i) throw (std::out_of_range) {
		if (i >= size)
		{
			throw std::out_of_range("array access out of range");
		}
		else
		{
			return elements[i];
		}
	}
};

int main2() {

	//生成多个长度不同的数组类型

	array<char, 20> array0;
	array<char, 10> array1;

	array0[10] = 'b';

	try
	{
		array1[10] = 'c';
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Access out of range." << std::endl;
	}
	return 0;
}