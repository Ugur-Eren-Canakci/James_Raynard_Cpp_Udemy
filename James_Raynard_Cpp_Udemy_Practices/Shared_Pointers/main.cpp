#include <iostream>
#include <memory>
#include <vector>

int main() {
    
    //• Briefly describe std::shared_ptr
    //• Briefly describe the structure of the shared_ptr class
    // contains two raw pointer data members, where one of them points to an object and the other one points to a control block
    // control block contains an integer used for counting how many shared_ptr's point to the same object with the 
    // previously mentioned data member
    
    //Give two ways to create an initialized std::shared_ptr object
    // 1) auto p1 { std::make_shared<typename>{object_value} };
    // 2) std::shared_ptr<typename> p2 { new Object{object_value} }; 
    // • Is there any reason to prefer one approach over the other?
    // second way of initialization requires a separate call for a heap allocation of the control block

    //Describe what happens when a shared_ptr object is created as a copy of another object
    // since we talk about a creation, copy constructor is called
    // the counter in the control block of the copied object is incremented by one
    // then the pointers of the created object is assigned the copied object's pointers
    
    //Describe what happens when a shared_ptr object is assigned to another shared_ptr object
    // if the assigned object is pointing to a different object than the copied one, 
    // the assigned object's counter is decremented by one, assuming there are other shared_ptr's pointing to the same object.
    // if the assigned object is the only shared_ptr for its old object, then the old object and the control block that
    // contained the counter for this old object are destroyed
    // then the copied object's counter is incremented by one, and pointers are shallow-copied onto the assigned object
    
    //Write a simple program which creates and initializes shared_ptr object and performs some operations on it
    
    std::vector<std::shared_ptr<int>> vec;
    
    vec.push_back({ std::make_shared<int>(5) });
    auto p = vec.at(0);
    //vec.push_back(std::make_shared<int>(p));
    vec.push_back(std::make_shared<int>(int(3)));
    vec.push_back(std::move(std::make_shared<int>(int{6})));
    
    std::cout << "use counts: ";
    for (const auto& el : vec) {
         std::cout << el.use_count() << ", ";
    }
    std::cout << std::endl;
	return 0;
}
