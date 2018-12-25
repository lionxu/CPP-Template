#include<iostream>

/*
 * ��ָ�����������Ϊģ�������ʱ��,�����ú�������ģ���������,
 * �൱��Ϊ������������һ��������ָ���������
 * ��Ҫע�����,ֻ��ָ��ȫ�ֱ��������ⲿ����(ʹ��extern����)�Լ��ྲ̬������ָ�뼰���òſ���Ϊģ�����.
 * �����ľֲ������Լ���ĳ�Ա�����Ⱦ�������Ϊģ�����
 * ������Ϊģ�����ֵ�����Ǳ���ʱ��֪��
 * ����ָ�뼰���ã���Ҫ�ڱ���ʱȷ������ָ��������õı������ڴ��еĵ�ַ��
 * ���ֲ������п��ܱ����������䵽�������ö�ջ�ϣ��ڴ��ַ���̶�,�ʶ��޷���Ϊģ�����ʹ��
 */

// ��ָ����Ϊģ�����
template<int *p>
struct wrapper1 {
	int get() { return *p; }
	void set(int v) { *p = v; }
};

// ��������Ϊģ�����
template<int &p>
struct wrapper2 {
	int get() { return p; }
	void set(int v) { p = v; }
};

int global_variable = 0;

int main1() {
	wrapper1<&global_variable> gwrapper1;
	gwrapper1.set(1);
	std::cout << gwrapper1.get() << std::endl;

	wrapper2<global_variable> gwrapper2;
	gwrapper2.set(2);
	std::cout << gwrapper2.get() << std::endl;

	return 0;
}