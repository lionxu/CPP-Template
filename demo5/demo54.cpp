/*
 * 在普通类中我们也可以定义成员函数模板
 */

struct normal_class {
	int value;
	template<typename T>
	void set(T const &v) { value = int(v); }
	template<typename T>
	T get();
};

template<typename T>
T normal_class::get() {
	return T(value);
}

/*
 * 在模板类中定义成员函数模板
 * 而且成员函数模板可以有自己的模板形参
 * 成员函数的模板形参不能和类的模板形参名称相同,否则会造成命名冲突
 * 而不同的成员函数模板可以有相同的模板形参,因为成员函数的模板形参只在函数体内部可见
 */
template<typename T0>
struct a_class_template {
	T0 value;

	template<typename T1>
	void set(T1 const &v) { value = T0(v); }

	template<typename T1>
	T1 get();
};

// 类模板的成员函数模板在类模板外部实现
template<typename T0> template<typename T1>
T1 a_class_template<T0>::get() {
	return T1(value);
}