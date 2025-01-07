#include <iostream>

int main() {
    
    // not finished
    
    /*A weak pointer is NOT a smart pointer
    It provides a safe way of aliasing a shared_ptr
    this avoids the problems with traditional pointers which can "dangle"
    
weak_ptr is bound to a shared_ptr
    this doesn't affect the reference count in shared_ptr

the weak_ptr cannot access the shared memory directly
    it has to be converted back to the shared_ptr
        this is only allowed if the shared_ptr is still valid
Ex:
auto ptr{std::make_shared<int>(36)}; // ref. count is 1
weak_ptr<int> wptr = ptr; // ref count of shared_ptr is still 1
ptr = nullptr; //releases ptr's shared memory since its ref count is down to 0

.lock() returns the shared_ptr if it's valid, and if not, returns a nullptr

Alternatively, we can copy the weak_ptr into a shared_ptr
shared_ptr<int> sp(wptr);
    this will throw a std::bad_weak_ptr exception if invalid

to prevent data race, lock() is implemented as an atomic operation
    => thread-safe but not so efficient
    
    
Applications:
    Cache implementation in web browsers
        Data is fetched and stored in shared_ptr objects
        Cache holds weak_ptr to data
        Use lock() to retrieve data
            If not expired, returns original data
            Otherwise, data is fetched again
            
     * */
    //Briefly describe std::weak_ptr
    // not a smart pointer
    // provides a safe way of aliasing a shared_ptr
    // bound to a shared_ptr, but does not interact with the reference counts of the shared_ptr it's bound to
    
	return 0;
}
