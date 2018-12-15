#include<iostream>

/*
 * ����һ�������ֵ�ĺ���ģ��
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
	 * �˴��ڵ��ú�����ʱ��,��������������ģ���βε�����
	 * ����CPP�ı��������Ը������Ǵ��ݵ�ģ���β�����������һ�����Ӧ�ĺ���,
	 * ���ض����͵����ݽ��д���
	 */
	std::cout << max_element<int>(l, 8) << std::endl;
	std::cout << max_element<char>(cl, 6) << std::endl;
	/*
	 * �˴����ǵ��ú�����ʱ��,��û��ָ��ģ���βε�ֵ
	 * ����������CPP��ģ���β��Զ��Ƶ��Ĺ��ܡ�
	 * CPP�ı��������ݵ���ģ�庯����ʵ�ε��������Ƶ���ģ���βε�����
	 */
	std::cout << max_element(l, 8) << std::endl;
	std::cout << max_element(cl, 6) << std::endl;
	return 0;
}