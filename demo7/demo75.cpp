#include<iostream>

template <typename T>
void func(T v) { std::cout << "#1: " << v << std::endl; }

template <>
void func(float v) { std::cout << "#2: " << v << std::endl; }

void func(float v) { std::cout << "#3: " << v << std::endl; }

void func2(float v) { std::cout << "#4: " << v << std::endl; }

int main(){
    /*
     * 匹配#4
     */
    func2(1);

    /*
     * 匹配#1
     */
    func(1);

    /* 
     * 匹配#1
     */
    func(1.);

    /*
     * 匹配#3
     */
    func(1.f);

    /*
     * 匹配#2
     */
    func<>(1.f);
    return 0;
}