#include<stdexcept>

/*
 * 定义了一个包含是十个元素的数组类模板,
 * 该数组具有越界检查的功能.
 * 由于,数组的元素数量是固定的,如果我们需要不同长度的带越界检查功能的数组,
 * 则此时,把数组长度定义为常量已经无法满足我们的需求.
 */
template<typename T>
class array{
	static const unsigned size = 10;
	T elements[size];

public:
	T& operator[](unsigned i) throw(std::out_of_range) {
		// 访问元素时首先进行越界检查
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