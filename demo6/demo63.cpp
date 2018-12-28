#include<iostream>

class some_value;

/*
 * 使用some_value的前置声明定义成员函数指针,
 * 并且为成员函数指针定义类型别名
 */
typedef int(some_value::* some_value_mfc)(int);

// func是一个成员函数指针型模板参数
// .*和->*是两个优先级比较低的操作符,所以用括号括起来
template<some_value_mfc func>
int call(some_value &value, int op) { return (value.*func)(op); }

class some_value {
	int value;
public:
	some_value(int _value): value(_value){}
	int add_by(int op) { return value += op; }
	int sub_by(int op) { return value -= op; }
	int mul_by(int op) { return value *= op; }
};

int main() {
	some_value v0(0);
	/*
	 * 不可以省略成员函数前面的去地址符号
	 */
	std::cout << call<&some_value::add_by>(v0, 1) << std::endl;
	std::cout << call<&some_value::sub_by>(v0, 2) << std::endl;
	std::cout << call<&some_value::mul_by>(v0, 3) << std::endl;
	return 0;
}