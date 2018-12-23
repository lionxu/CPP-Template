/*
 * CPP的类模板中的静态成员变量
 * 遵循CPP的标准把模板类的声明和模板类的实现都放在一个头文件中,
 * 以便编译器可以当场生成类模板的实例,同时避免了产生夸目标文件的链接.
 * 但是,对于类模板的静态成员变量而言情况有些不同.
 * 对于类模板的静态成员变量而言,他为同一类型的类模板实例所共享.
 * 由于类模板的静态成员变量的声明和实现都放在同一个头文件中,
 * 那么在每一个包含了该头文件的代码文件中,编译器都会生成该类模板实例的若干个副本.
 * 同样,类模板的静态成员变量也会有多个副本.
 * 为了实现静态成员变量在同类型类模板实例中间的共享,
 * CPP编译器必然选择某一个该实例的静态变量的副本来进行链接.
 */

#pragma once
template<typename T>
struct the_class {
	static int id;
	the_class() { id++; }
};

template<typename T> int the_class<T>::id = 0;