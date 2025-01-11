#include <iostream>

template <int N>
int fibonacci_1() {
    return fibonacci_1<N-1>() + fibonacci_1<N-2>();
}

template <>
int fibonacci_1<1>() {
    return 1;
}

template <>
int fibonacci_1<0>() {
    return 0;
}

template <int N>
int fibonacci_2() {
    if constexpr (N>1) {
        return fibonacci_2<N-1>() + fibonacci_2<N-2>();
    }
    return N;
}


template <typename T, typename... Args>
void variadic_func(T t, Args... args) {
    std::cout << "variadic function called with " << sizeof...(args) + 1 << " arguments." << std::endl;
    std::cout << "currently investigating: " << t << std::endl;
    
    if constexpr(sizeof...(args) > 0) {
        variadic_func(args...);
    }
    
}
int main() {
    
    /*• Write a program which generates a Fibonacci number using
    • Template specialization
    • Constexpr if
    • Compare your solutions*/
    
    const int i=10;
    std::cout << fibonacci_1<i>() << std::endl;
    
    const int j = 15;
    std::cout << fibonacci_2<j>() << std::endl;
    
    /*• Rewrite the example from the Variadic Templates lecture to use
    constexpr if*/
	variadic_func(1,2,3,4,5);
    
    return 0;
}
