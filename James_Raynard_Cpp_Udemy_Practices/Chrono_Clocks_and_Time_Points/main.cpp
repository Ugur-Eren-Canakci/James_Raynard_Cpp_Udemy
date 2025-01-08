#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals;

void func() {
    std::cout << "function call" << std::endl;
}

int main() {
    
    //What are the main differences between system_clock and steady_clock?
    // system_clock interacts with "real" time, moving back and forth with time changes such as daylight savings and leap years
    // steady_clock goes only forward, one tick at a time
    
    //Give an example of where each one should be used
    // steady_clock for pure temporal distance measurements
    // system_clock for reporting how much time has "passed" wr. to the world time
    auto start = std::chrono::steady_clock::now();
    func();
    auto finish = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << " microseconds for func call" << std::endl;
    
    //Write a program which prints out a message, pauses for a certain duration, then prints out another message
    std::cout << "sleep_for call" << std::endl;
    start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(1s);
    finish = std::chrono::steady_clock::now();
    std::cout << "slept for " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << " milliseconds" << std::endl;
    
	return 0;
}
