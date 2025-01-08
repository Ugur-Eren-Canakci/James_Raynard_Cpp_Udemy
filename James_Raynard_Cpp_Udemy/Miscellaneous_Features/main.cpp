#include <iostream>
#include <chrono>
#include <thread>


using namespace std::chrono;
using namespace std::literals;

long long fibonacci (long long n) {
    return (n < 2) ? n : fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    
    minutes a{3};
    seconds b{287};
    std::cout << (a+b).count() << std::endl;
    
    // time_point exercise
    auto start = steady_clock::now();
    long long n = fibonacci(13);
    std::cout << "13th fibonacci number is " << n << "." << std::endl;
    auto finish = steady_clock::now();
    
    auto elapsed = duration_cast<milliseconds>(finish - start).count();
    std::cout << "calculation time: " << elapsed << " milliseconds." << std::endl;
    
    // sleep_for() exercise on threads
    std::cout << "Waiter!" << std::endl;
    start = steady_clock::now();
    std::this_thread::sleep_for(2s);
    finish = steady_clock::now();
    std::cout << "You called, sir? (You had to wait for " << duration_cast<milliseconds>(finish - start).count() << " milliseconds.)" << std::endl;
    
    
	return 0;
}
