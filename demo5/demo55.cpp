
/*
 * ΪCPP�е���������Ԫ��������Ԫ��ģ��
 * ��Ԫ����ģ�����Ԫ��ģ����κ�ʵ�����Ǹ������Ԫ,���Է������е�˽�г�Ա
 * ��������ΪFBI_agent��duty��ǰ������,���ǵ��κ�ʵ�������Է���citizen��˽�г�Ա
 */

class citizen {
	int id;
	double money;

	template<typename T> friend class FBI_agent;

	template<typename T> friend T duty(citizen &);

public:
	citizen(int id): id(id){}
};