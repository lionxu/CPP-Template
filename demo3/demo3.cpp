#include<iostream>

using namespace std;
/*
 * �˴�����ΪT0��T1ָ����,Ĭ�����͡�
 * ��������������C++11����������,����Ϊ����ģ�������Ĭ��ֵ
 * ��func�У�������ΪT0��T2�������޷�����ʵ�������Զ��Ƶ������͵�ģ���������Ĭ��ֵ��,
 * ����funcģ��ʱ���ʱ��,ģ��ʵ���б������ȫʡ�ԡ�
*/
template<typename T0 = float,
	typename T1,
	typename T2 = float,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4);

/*
 * ����Ĵ������еĽ��Ϊ:
 * v1: 1   v3: 2   v4: 3   || sv0: 0       sv2: 0
 * v1: 4   v3: 5   v4: 6   || sv0: -1      sv2: -1
 * v1: 1   v3: 0.1 v4: 0.1 || sv0: 0       sv2: 0
 * v1: 0.1 v3: 0.1 v4: 0.1 || sv0: 0       sv2: 0
 * ��Ϊ�ں����Ķ�����,sv0��sv2��������̬����.
 * ��CPP�к����ľ�̬����Ϊÿ������˽��,��ͬ�ĺ���֮��,��ͬ���Ƶľ�̬�������޷�����ġ�
 * ����Ȼ,��CPP��ģ�庯����,��̬������Ȼ������ÿ������ģ��ʵ�����Ժ�ĺ�����.
 * ��CPP�л����������ݲ�ͬ�ĺ���ģ��ʵ���Զ�������Ӧ�ĺ���ʵ����
 * �������main������,�ܹ������鲻ͬ��ģ��ʵ��,�ֱ���
 * i: <float int, float, int, int>,��ʱ��Ӧ�ĺ���������:func(1, 2, 3)��func(4, 5, 6)
 * ii: <float int, float, double, double>,��ʱ��Ӧ�ĺ�������Ϊ:func(1, 0.1, 0.1)
 * iii: <float, double, float, double, double>,��ʱ��Ӧ�ĺ�������Ϊ:func(0.1, 0.1, 0.1)
 * ����Ȼ������i,������Ϊ��������������������һ������,����sv0��sv2��������̬�����������κ�������֮�䷢���˱仯��
 * ������ii��iii����,�������ֱ�Ϊ����������������������������,����������������,sv0��sv2��ֵ��Ϊ0.
 * ��������û�й���
 * ���в�ͬ�ĺ�������ģ���β�ʱ���������Ż������µĺ�������������Ѿ����ɵĺ�����
 */
int main() {
	double sv2;
	sv2 = func(1, 2, 3);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(4, 5, 6);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(1, 0.1, 0.1);
	cout << "\tsv2: " << sv2 << endl;

	sv2 = func(0.1, 0.1, 0.1);
	cout << "\tsv2: " << sv2 << endl;
	return 0;
}

template<typename T0 = float,
	typename T1,
	typename T2 = float,
	typename T3,
	typename T4>
	T2 func(T1 v1, T3 v3, T4 v4) {
	T0 static sv0 = T0(0);
	T2 static sv2 = T2(0);

	cout << "\tv1: " << v1
		<< "\tv3: " << v3
		<< "\tv4: " << v4
		<< "\t|| sv0: " << sv0;
	T2 v2 = sv2;
	sv0 -= 1;
	sv2 -= 1;
	return v2;
}