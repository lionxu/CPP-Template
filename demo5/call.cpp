#include<iostream>
#include"the_class.h"

/*
* ��������ģ��ʵ��the_class<int>
* �������ڱ����Ŀ������ļ�,Ϊ��̬��Ա����the_class<int>::id�����ڴ��ַ�ռ�
*/

void call() {
	the_class<int> c;
	std::cout << c.id << std::endl;
}