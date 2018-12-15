#include<iostream>

/*
 * �˴�����ĺ���ʾ����Ϊ��˵��CPP����ģ���βε��Զ��Ƶ�����
 * 1��CPP������ֻ���ݺ�������ʱ������ʵ���б����Ƶ�ģ�����ֵ,�뺯�����������޹ص�ģ�������ֵ�޷��Ƶ�
 * ���ݹ���1������Ȼ�����ڵ��ú���func��ʱ��,����ָ��T1��T3��T4��ģ���β�����
 * ��Ϊ���Ը��ݺ������õ�ʵ���б��Զ��Ƶ�����
 * ���,������Ҫָ����ģ���βε�������T0��T2�����͡�
 * 2���뺯������ֵ��ص�ģ�������ֵҲ�޷��Ƶ���
 * ���ݹ���2,���Ǻ����T2�������޷��Զ��Ƶ�������
 * ���Ǵ���һ��,��ĳЩ������ƺ��ǿ����Ƶ������ġ�
 * ����,�Ժ���func���õ�α��������:
 * double d = func<...>(...);
 * �ƺ�������d�����ͣ�����Ӧ����ΪT2����һ��double�ء�
 * ��ʵ��Ȼ,��ΪCPP�д������������Զ�ת�͵Ļ��ơ�
 * double���͵ı����������Խ�������double�ͱ��������ĸ�ֵ,
 * Ҳ���Խ�������int�͡�char�͵ȶ������ͱ����Լ�������ֵ��
 * �������Խ����û��Զ������ͱ����Լ������ĸ�ֵ��
 * ���ԣ��������ģ������б�����ʾָ��������������ֵ����,
 * ������ʾ��α����,�ڱ������ػ�������ʱ��,��������塣
 * ��������,���ǿ��ܲ��ᶨ��һ������ȥ���溯���ķ���ֵ��
 * �����������ķ���ֵ���;͸��޴�ȥ�ƶ���,
 * ��ˣ�T2���������޷��ƶϵģ���Ҫ�ں������õ�ʱ�򷵻�.
 * 3�����п��Ƶ�ģ���������������λ��ģ������б���β��,�м䲻���п��Ƶ���ģ�������
 * ���ݹ���3�����ǵ�T1���ͱ���ָ��,���������õ�����д��������ʽ��:
 * sv0 = func<double, , int>(1, 2, 3),�����Ƶ�ģ�����T1λ��ģ������б����м��ˡ�
 * �ʶ��������ڵ���func������ʱ��,����ʡ�Ե�ģ�����ΪT3��T4.
 * ���Ǳ���ָ��T0��T1��T2�����͡�
 */
template<typename T0,
	typename T1,
	typename T2,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4) {
	T0 static sv0 = T0(0);
	T2 static sv2 = T2(0);
	std::cout << "\tv1: " << v1
		<< "\tv3: " << v3
		<< "\tv4: " << v4
		<< "\t|| sv0: " << sv0;
	T2 v2 = sv2;
	sv0 -= 1;
	sv2 -= 1;
	return v2;
}

int main() {
	double sv2;
	sv2 = func<double, int, int>(1, 2, 3);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<double, int, int>(1, 2, 3);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<double, int, int>(1, 0.1, 0.1);
	std::cout << "\tsv2: " << sv2 << std::endl;

	sv2 = func<int, double, double>(0.1, 0.1, 0.1);
	std::cout << "\tsv2: " << sv2 << std::endl;
}