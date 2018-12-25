#include<stdexcept>
#include<iostream>

/* 
 * Ϊ�˽�����鳤�ȶ���Ϊ�ೣ��������������,
 * ��������ģ����β��б�������������Ϊ���ε�ģ���β�
 * �˴�����ʹ���˷�����ģ���β�
 * ������ģ�����,�ڱ������൱��Ϊ����ģ�������ģ�嶨�峣��
 * ����������ģ��ʵ����ʱ��,Ҳ��Ҫ�Գ�����Ϊ������ģ�������ֵ
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

	//���ɶ�����Ȳ�ͬ����������

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