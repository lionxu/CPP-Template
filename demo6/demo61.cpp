#include<stdexcept>

/*
 * ������һ��������ʮ��Ԫ�ص�������ģ��,
 * ���������Խ����Ĺ���.
 * ����,�����Ԫ�������ǹ̶���,���������Ҫ��ͬ���ȵĴ�Խ���鹦�ܵ�����,
 * ���ʱ,�����鳤�ȶ���Ϊ�����Ѿ��޷��������ǵ�����.
 */
template<typename T>
class array{
	static const unsigned size = 10;
	T elements[size];

public:
	T& operator[](unsigned i) throw(std::out_of_range) {
		// ����Ԫ��ʱ���Ƚ���Խ����
		if (i >= size)
		{
			throw std::out_of_range("Access out of range");
		}
		else
		{
			return elements[i];
		}
	}
};