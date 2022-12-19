#include <iostream>
#include <tuple>

template <class Tuple, size_t N>
struct TuplePrinter {
    static void print(std::ostream& out, const Tuple& t)
    {
        TuplePrinter<Tuple, N - 1>::print(out, t);//1
        out << ", " << std::get<N - 1>(t);//2
    }
};

template <class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print(std::ostream& out, const Tuple& t)
    {
        out << std::get<0>(t);
    }
};

template <class... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& t)
{
    out << '(';
    TuplePrinter<decltype(t), sizeof...(Args)>::print(out, t);
    return out << ')';
}

