//用于模板型模板参数的模板
template <typename T, int i>
struct S1;

//模板通例,有三个模板参数,分别是类型参数、非类型参数以及模板型参数
template <typename T, int i, template <typename, int> class SP>
struct S;

//模板特例1,可匹配S<char, 任意整数, S1>
template <int i, template <typename, int> class SP>
struct S<char, i, SP>;

//模板特例2,可匹配S<任意有const修饰的类型,任意整数, S1>
template <typename T, int i, template <typename, int> class SP>
struct S<const T, i, SP>;

//模板特例3,完全特例,只能匹配S<char, 10, S1>
template <>
struct S<char, 10, S1>;

//模板特例4,以模板实例作为类型参数值.匹配S<S1<任意类型,10>, 10, S1>
/*
 * 此处S1<T, 10>是模板S1的一个实例,因而是一个合法的类型参数
*/
template <typename T>
struct S<S1<T, 10>, 10, S1>;

//模板特例5,错误的特例,匹配式项目数与通例参数个数不一致
/*
template <typename T, int i, template <typename, int> class SP, typename TT>
struct S<T, i, SP, TT>;
*/

//模板特例6,错误的特例,匹配项目的类型与通例中的参数类型不一致
//此处第三个模板参数应该是一个模板型模板参数,在特例中写的是一个类型参数
/*
template <typename T>
struct S<char, 10, T>;
*/

//模板特例7,错误的特例,模板型参数SP与通例中的SP的类型不一致
/*
template <typename T, int i, template <typename> class SP>
struct S<T, i, SP>;
*/

/*
 * 如果匹配式中没有用到任何模板参数,所有的项目都是确定的类型或值或模板,则这种特例称为完全特例
 * 相反,如果匹配式中部分用到模板参数,有不确定的项目,则这种特例称为部分特例.
 */