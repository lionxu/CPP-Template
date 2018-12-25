#include<iostream>

class some_value;

/*
 * ʹ��some_value��ǰ�����������Ա����ָ��,
 * ����Ϊ��Ա����ָ�붨�����ͱ���
 */
typedef int(some_value::* some_value_mfc)(int);

// func��һ����Ա����ָ����ģ�����
// .*��->*���������ȼ��Ƚϵ͵Ĳ�����,����������������
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
	 * ������ʡ�Գ�Ա����ǰ���ȥ��ַ����
	 */
	std::cout << call<&some_value::add_by>(v0, 1) << std::endl;
	std::cout << call<&some_value::sub_by>(v0, 2) << std::endl;
	std::cout << call<&some_value::mul_by>(v0, 3) << std::endl;
	return 0;
}