#include<stdexcept>
#include<cstdlib>
#include<iostream>

template<typename T>
class my_vector{
    T *array;
    unsigned size;
    unsigned block_size;
    public:
    // 构造函数通过malloc申请内存空间
    my_vector(unsigned bsz): array((T*)malloc(sizeof(T) * bsz)), size(0), block_size(bsz){}

    ~my_vector(){if(array) free(array);}

    void push_back(T const &elem){
        if(size == block_size){
            // 空间已经用完,需要申请更大空间
            block_size *= 2;
            T *new_array = (T *)realloc(array, block_size * sizeof(T));
            if(new_array != NULL) array = new_array;
            else{
                // 申请空间失败,内存耗尽
                free(array);
                array = NULL;
                throw std::runtime_error("Out of memory");
            }
        }
        array[size++] = elem;
    }

    T& operator[] (unsigned i){return array[i];}

    const T& operator[] (unsigned i)const {return array[i];}

    //告诉我们占用了多少内存
    unsigned get_mem_size() const {return block_size * sizeof(T);}
};

/*
 * 在通常的计算机平台上,sizeof(bool)返回1,即1字节
 * 但是,布尔型只有两个值,真或者假,只需要一个1bit
 * 1个字节完全可以用来存储8个布尔型变量.
 * 然而,如果我们用上述我们定义的模板来存储布尔型变量,
 * 则一个布尔值占用1个字节,显然太浪费存储空间.
 * 存储布尔型数据的动态数组,需要一种更加紧凑的保存方法.
 * 上面我们定义了通用型向量模板,下面我们声明专门用于存储布尔型向量.
 * 即相当于my_vector模板的特例,当我们定义my_vector<bool>类型变量时,
 * 编译器会自动识别为该模板特例.
 * 在声明模板特例之前,必须先声明模板通例.
 * 我们把my_vector<bool>设计成用一系列整数值来保存压缩后的布尔值.
 */
template<>
class my_vector<bool>{
    int *array;
    unsigned size;
    unsigned block_size;
    // 一个段即一个整数值,段大小即为一个整数值所能容纳的最多布尔值数
    const static unsigned seg_size;
    public:
    my_vector(unsigned bsz = 1): array((int *)malloc(sizeof(int) * bsz)), size(0), block_size(bsz){}
    ~my_vector(){if (array) free(array);}
    void push_back(bool elem){
        if(size == block_size * seg_size){
            block_size *= 2;
            int *new_array = (int *)realloc(array, block_size * sizeof(int));
            if(new_array != NULL){
                array = new_array;
            }
            else{
                free(array);
                array = NULL;
                throw std::runtime_error("Out of memory");
            }
        }
        set(size++, elem);
    }

    void set(unsigned i, bool elem){
        if(elem){
            array[i / seg_size] |= (0x1 << (i % seg_size));
        }
        else{
            array[i / seg_size] &= ~(0x1 << (i % seg_size));
        }
    }

    bool operator[] (unsigned i) const{
        return (array[i / seg_size] & (0x1 << (i % seg_size))) != 0;
    }

    unsigned get_mem_size() const { return block_size * sizeof(int); }
};

const unsigned my_vector<bool>::seg_size = sizeof(int) * 8;

int main(){
    my_vector<char> vi(2);
    my_vector<bool> vb(2);
    for (unsigned i = 0; i < 20; i++){
        vi.push_back('a' + i);
        vb.push_back((i % 4) == 0);
    }

    std::cout << "MemSize of my_vector<char> is " << vi.get_mem_size() << std::endl;
    std::cout << "MemSize of my_vector<bool> is " << vb.get_mem_size() << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    for (unsigned i = 0; i < 20; ++i){
        std::cout << " " << vi[i];
    }

    std::cout << std::endl;

    for (unsigned i = 0; i < 20; ++i){
        std::cout << " " << vb[i];
    }

    std::cout << std::endl;
}

/*
 * my_vector<char>的长度是32
 * my_vector<bool>的长度是8
 * 显然,模板特例my_vector<bool>对布尔值使用压缩存储,节省了内存
 * 与通例的模板相比,特例模板少了一个对[]操作符函数的重载
 * C++中对通例与特例并无任何约束,理论上完全可以把特例设计成一个与通例毫无完全共同点的类.
 * 在面对某一问题时,我们可以首先为绝大多数情况设计模板,然后再针对几种特殊情况单独设计模板特例,
 * 从而尽量用最小的代码量得到尽量最优的解法.
 */