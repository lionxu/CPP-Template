/*
 * ����ͨ��������Ҳ���Զ����Ա����ģ��
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
 * ��ģ�����ж����Ա����ģ��
 * ���ҳ�Ա����ģ��������Լ���ģ���β�
 * ��Ա������ģ���ββ��ܺ����ģ���β�������ͬ,��������������ͻ
 * ����ͬ�ĳ�Ա����ģ���������ͬ��ģ���β�,��Ϊ��Ա������ģ���β�ֻ�ں������ڲ��ɼ�
 */
template<typename T0>
struct a_class_template {
	T0 value;

	template<typename T1>
	void set(T1 const &v) { value = T0(v); }

	template<typename T1>
	T1 get();
};

// ��ģ��ĳ�Ա����ģ������ģ���ⲿʵ��
template<typename T0> template<typename T1>
T1 a_class_template<T0>::get() {
	return T1(value);
}