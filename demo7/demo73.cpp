#include<iostream>
template<typename T0, typename T1, typename T2>struct S{
    std::string id() { return "General"; }
};

//类模板特例1,约束第三个参数的类型必须为char
template<typename T0, typename T1>
struct S<T0, T1, char>{
    std::string id() { return "Specialization #1"; }
};

//类模板特例2,约束第二、第三参数必须为char
template<typename T0>
struct S<T0, char, char>{
    std::string id() { return "Specialization #2"; }
};

//类模板特例3,约束第一个参数必须为int,并且第二、第三参数相同
template<typename T>
struct S<int, T, T>{
    std::string id() { return "Specialization #3"; }
};

int main(){
    // 类模板实例1,匹配模板通例
    std::cout << S<float, float, float>().id() << std::endl;
    // 类模板实例2,匹配模板特例3
    std::cout << S<int, int, int>().id() << std::endl;
    // 类模板实例3,匹配模板特例1
    std::cout << S<int, int, char>().id() << std::endl;
    // 类模板实例4,虽然模板特例1和2都匹配,但是特例2更特殊,所以匹配特例2
    std::cout << S<char, char, char>().id() << std::endl;
    // 类模板实例5,同时匹配特例2和特例3,但是无法决定哪一个更特殊,故而产生歧义,是一个错误的类模板实例
    //std::cout << S<int, char, char>().id() << std::endl;
    return 0;
}