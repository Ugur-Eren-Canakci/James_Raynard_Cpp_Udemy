#include <iostream>

int main() {
    
    //What is meant by "template specialization"?
    // instead of executing the same code for all possible types, we specialize the code for specific types
    
    //When is template specialization useful?
    // When we need special treatment of some types
    
    //Briefly describe how to write a template specialization
    // After a generic template definition of the object, you define the specialization with putting the type
    // right after the definition's name in between arrows
    /*template <typename T>
     * class Base {
     * ...
     * };
     * 
     * template<>
     * class Base<int> {
     * ...
     * };
        
        when Base is called with an int parameter, the second definition will be used by the programme
     * 
     * 
     * */
     
     //When there is a generic template with a template specialization, how does the compiler decide which one to use?
     // The compiler decides on the most specific template to use.
     
     //What is meant by "partial specialization" of a template?
     // instead of specializing the generic definition for one type, you can specialize it for various types at the same time
     //Ex:
     
     /*template <typename T>
     *class Base {
     * ...
     * };
     * 
     * template<typename T>
     * class Base<T*> {
     * ...
     * };
     * */
     return 0;
     
}
