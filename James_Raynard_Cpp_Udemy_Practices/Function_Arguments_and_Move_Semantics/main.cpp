#include <iostream>

int main() {
    
    /*What is the most efficient way of initializing the m_str member of this
    class, using both lvalues and rvalues?
    class Test {
    string m_str;
    public:
    ... // Public member functions
    };
    • Explain your answer
     * */
    
    // When calling with lvalues:
    // Test(const std::string& s) : m_str(str) {}
    // one copy is necessary for m_str's initialization
    // we don't want to move the value since we're still referencing the lvalue in the function
    
    // When calling with rvalues:
    // Test(std::string&& s) : m_str(std::move(s)) {}
    // only one move operation is done at the initialization of m_str, and 
    // the original rvalue is moved to m_str as it's referenced by the function argument s
    
    
    
	return 0;
}
