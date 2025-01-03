#include <iostream>

class invalid_student_grade : public std::out_of_range {
public:
    // string-arg constructors
    invalid_student_grade(const std::string& s) noexcept : std::out_of_range(s) {}
    invalid_student_grade(const char* s) noexcept : std::out_of_range(s) {}
    // no arg constructor
    invalid_student_grade() noexcept : std::out_of_range("Invalid grade") {}
    // copy constructor
    invalid_student_grade(const invalid_student_grade& e) noexcept = default;
};

class StudentGrade {
private:
    int grade;
public:
    StudentGrade(int x) {
        if (x > 100) {
            throw invalid_student_grade("Student grade entered is greater than 100");
        }
        else if (x < 0) {
            throw invalid_student_grade("Student grade entered is less than 0");
        }
        else {
            this->grade = x;
            std::cout << "Student grade construction successful" << std::endl;
        }
    }
};


int main() {
    
    //When we write our own exception class, why is it better to derive
    //from a subclass of std::exception hierarchy than to write a completely
    //new class?
    // std::exception only has a default constructor and no data members
    // some of the subclasses have useful override-possible members

    //When we write our own exception class, which member functions
    //should we consider implementing?
    // Default constructor, especially if we're deriving from a "string-argument constructor" base class
    // copy constructor for copying of the exception object outside the function body it was created in
    // override of the what() function
    
    //In the invalid_student_grade class, why did we not provide any data members?
    // std::out_of_range already has enough members to execute the exception code fully
    
    //Why did we not implement a copy constructor or destructor for the class?
    // no special processing needed, no member is managed further when copying
    // so what the compiler will synthesise is enough for the work
    
    //Implement a suitable invalid_student_grade exception class
    //Write a program which reads a number from standard input and stores it in a StudentGrade object
    std::cout << "Enter a grade between 0 and 100: ";
    std::string user_input;
    std::cin >> user_input;
    try {
        StudentGrade(stoi(user_input));
    }
    catch (const invalid_student_grade& e) {
        std::cout << "The grade you entered is invalid. Please try again." << std::endl;
    }
    
    
    
	return 0;
}
