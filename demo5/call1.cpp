#include<iostream>
#include"the_class1.h"

/*
 * ��������ģ��ʵ��the_class<int>
 * �������ڱ����Ŀ������ļ�,Ϊ��̬��Ա����the_class<int>::id�����ڴ��ַ�ռ�
 */
void call1() {
	the_class1<int> c;
	std::cout << c.id << std::endl;
}

