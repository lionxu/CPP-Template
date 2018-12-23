#pragma once
template<typename T>
struct the_class1 {
	static int id;
	the_class1() { id++; }
};

template<typename T> int the_class1<T>::id = 1;