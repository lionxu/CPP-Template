#include<string>
#include<iostream>

/* 
 * 定义通例函数模板print
 */
template<typename T>
void print(T v){
    std::cout << v << std::endl;
}

/*
 * 定义函数模板特例,指出模板参数
 */
template<>
void print<char>(char v){
    std::cout << "\'" << v << "\'" << std::endl;
}

/* 
 * 定义函数模板特例,模板参数依赖调用实参推导
 */
template<>
void print(const char *v){
    std::cout << '"' << v << '"' << std::endl;
}

/*
 * 定义重载函数,处理string类型
 */
inline
void print(std::string const &v){
    std::cout << "\'\'\'" << v << "\'\'\'" << std::endl;
}

/*
 * 定义重载函数,处理bool类型
 */
inline
void print(bool v){
    std::cout << (v ? "true" : "false") << std::endl;
}

/* 
 * 函数模板重载
 */
template<typename T>
void print(T *v){
    std::cout << "*";
    print(*v);
}