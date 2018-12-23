
/*
 * 为CPP中的类声明友元函数和友元类模板
 * 友元函数模板和友元类模板的任何实例都是该类的友元,可以访问类中的私有成员
 * 我们无需为FBI_agent和duty做前置声明,他们的任何实例都可以访问citizen的私有成员
 */

class citizen {
	int id;
	double money;

	template<typename T> friend class FBI_agent;

	template<typename T> friend T duty(citizen &);

public:
	citizen(int id): id(id){}
};