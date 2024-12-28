#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <fstream>
#include <iterator>

// Not finished
// I just gave up on file read questions due to being frustrated at times
// Might come back and attempt the questions again

void print_vector(const std::vector<int>& vec) {
    
    std::cout << "[";
    for (const auto& el : vec) {
        std::cout << el << ",";
    }
    std::cout << "]" << std::endl;
}

void print_vector(const std::vector<double>& vec) {
    
    std::cout << "[";
    for (const auto& el : vec) {
        std::cout << el << ",";
    }
    std::cout << "]" << std::endl;
}

void print_vector(const std::vector<std::string>& vec) {
    
    std::cout << "[";
    for (const auto& el : vec) {
        std::cout << el << ",";
    }
    std::cout << "]" << std::endl;
}


int main() {

    // 1) Fill a vector with 10 random integers between 0 and 1000
    std::vector<int> vec(10);
    
    // RNG
    static std::mt19937 mt;
    std::uniform_int_distribution<> rng(0,1000);
    // mt is the engine, and rng is a distribution
    // when mt is called, it creates a number, and then the distribution object scales the number so that it fits within the range 
    // that was forwarded into the distribution's constructor
    
    // mt is callable because it's a functor
    // operator() generates a random number between 0 and 2^19937 - 1
    
    //std::generates expects a half-range to fill, and a generator
    // basically the function call expects a callable object that returns a value
    
    // the lambda expression I wrote takes the engine and the distribution objects, and 
    // uses rng.operator()(mt) to return a random number from the lambda expression 
    std::generate(vec.begin(), vec.end(), [&mt, &rng](){ return rng(mt); });
        
    // 2) (For each exercise, display the result)
    print_vector(vec);    
    
    
    // 3) Find the maximum element in this vector
    auto max_it = std::max_element(vec.begin(), vec.end());
    std::cout << "\nMaximum element: " << *max_it << std::endl;
    
    // 4) Find the index of this maximum element
    std::cout << "Positioned at: " << std::distance(vec.begin(),max_it) + 1 << std::endl;
    
    
    // 5) Sum the elements of the vector
    std::cout << "\nSum of the elements: " << std::accumulate(vec.cbegin(), vec.cend(), 0) << std::endl;
    
    // 6) Count the number of odd numbers in the vector
    std::cout << "Number of odd numbers: " << std::count_if(vec.cbegin(), vec.cend(), [](int n) { return n%2 == 1; } ) << std::endl;
    
    // 7) Normalize the vector (divide all the elements by the largest.) 
    // Put the normalized elements into a vector of doubles, without setting
    // the size of the output vector first
    std::vector<double> norm_vec;
    std::transform(vec.begin(), vec.end(), back_inserter(norm_vec), [max_it] (int n) { return 1.0*n/(*max_it); });
    std::cout << "\nNormalized vector: ";
    print_vector(norm_vec);
    
    // 8) Make a sorted copy of the vector. Without using a functor or a
    // lambda (or equivalent), find the first element greater than 455 and
    // the number of elements > 455
    
    std::vector<int> sorted_vec(vec);
    std::sort(sorted_vec.begin(), sorted_vec.end());
    std::cout << "\nSorted vector: ";
    print_vector(sorted_vec);
    
    
    // Couldn't figure out how to find elements without predicate functors/lambdas
    std::cout << "\nFirst number larger than 455: ";
    auto it_gt455 = std::find_if(sorted_vec.cbegin(), sorted_vec.cend(), [] (int x) { return (x > 455) ; });
    std::cout << *it_gt455 << std::endl;
    
    // 9) Copy all the odd numbers to a vector of doubles, without setting the size of the output vector first
    std::vector<double> odd_vec;
    std::copy_if(sorted_vec.cbegin(), sorted_vec.cend(), back_inserter(odd_vec), [] (int x) { return x%2 == 1; } );
    std::cout << "\nOdd numbers: ";
    print_vector(odd_vec);
    
    // 10) Sort the vector in descending order
    std::sort(odd_vec.begin(), odd_vec.end(), [] (double x, double y) { return x>y; } );
    std::cout << "\nOdd numbers in descending order: ";
    print_vector(odd_vec);
    
    
    // 11) Randomly shuffle all but the first and the last element of the vector
    auto first_it = odd_vec.begin();
    first_it++;
    auto last_it = odd_vec.end();
    last_it--;
    
    std::shuffle(first_it, last_it, mt );
    std::cout << "\nOdd numbers shuffled except the front and the back: ";
    print_vector(odd_vec);
    
    // 12) Remove all the odd numbers from the vector
    // removing from the original vector
    std::remove_if(vec.begin(), vec.end(), [] (int x) { return x%2==1; });
    std::cout << "\nOdd elements removed: ";
    print_vector(vec);
    
    // 13) Write the remaining elements to a text file on a single line as a comma separated list, without a trailing comma
    std::string file_location{"C:\\Users\\ugur_\\Desktop\\Self Studies\\Cpp\\James_Raynard_Cpp_Udemy\\James_Raynard_Cpp_Udemy_Practices\\Algorithms_and_Iterators_Assignment\\output_file.txt"};
    std::ofstream out_file(file_location,std::ios::trunc);
    std::ostream_iterator<int> output_it(out_file, ",");
    std::copy(vec.begin(), --(vec.end()), output_it);
    std::ostream_iterator<int> temp(out_file, "");
    std::copy(--(vec.end()),vec.end(), temp);
    out_file.close();
    
    std::ifstream in_file(file_location, std::ios::in);
    std::string line;
    getline(in_file, line);
    std::cout << "file content: " << line << std::endl << std::flush;
    in_file.close();
    
    // 14)Read the file "words.txt". Display each distinct word once. Ignore punctuation and capitalization
    // Hint: look into std::istreambuf_iterator
    std::string words_location{"C:\\Users\\ugur_\\Desktop\\Self Studies\\Cpp\\James_Raynard_Cpp_Udemy\\James_Raynard_Cpp_Udemy_Practices\\Algorithms_and_Iterators_Assignment\\words.txt"};
    std::ifstream words_file(words_location, std::ios::in);
    std::istreambuf_iterator<char> words_it(words_file), end;
    std::count_if(words_it, end, [](char c) {
        
        char d = std::tolower(c);
        if (isalpha(c)) std::cout << d;
        else std::cout << " ";
        return true;
    } );
    
    // 15) Count the total number of words in the file
    int word_count{0};
    std::istreambuf_iterator<char> word_it(words_file);
    std::count_if(word_it, end, [&word_count](char c) { 
        if (c == ' ')word_count++;
        return true;
    } );
    std::cout << "Word count in words.txt: " << word_count << std::endl << std::flush;
    
    // 16) Count the number of lines in the file
    std::istreambuf_iterator<char> lines_it(words_file);
    line = "";
    int num_lines = 0;
    std::count_if(lines_it, end, 
        [&words_file, &num_lines, &line] (char c) { 
            if (!words_file.eof()) {
                getline(words_file, line);
                num_lines++;
            }
            return true; 
        } ) ;
    std::cout << "\nNumber of lines: " << num_lines << std::endl << std::flush;
    
    // 17) Count the number of characters in the file
    std::istreambuf_iterator<char> chars_it(words_file);
    std::cout << "\nNumber of characters: " << std::count_if(chars_it, end, [](char c){ return true;} ) << std::endl << std::flush;
    words_file.close();
    
    // 18)Read "words.txt" and "words2.txt". Display the words which are common to both files
    std::string temp1{"C:\\Users\\ugur_\\Desktop\\Self Studies\\Cpp\\James_Raynard_Cpp_Udemy\\James_Raynard_Cpp_Udemy_Practices\\Algorithms_and_Iterators_Assignment\\words.txt"};
    std::string temp2{"C:\\Users\\ugur_\\Desktop\\Self Studies\\Cpp\\James_Raynard_Cpp_Udemy\\James_Raynard_Cpp_Udemy_Practices\\Algorithms_and_Iterators_Assignment\\words2.txt"};
    
    std::ifstream words1(temp1, std::ios::in);
    std::ifstream words2(temp2);
    
    if (!words1 || !words2) {
        std::cout << "files couldn't read." << std::endl;
        return 1;
    }
    
    std::istreambuf_iterator<char> it1(words1);
    std::istreambuf_iterator<char> it2(words2);
    
    std::vector<std::string> words1_vec, words2_vec, words_intersection_vec;
    // read words and place into the first two vectors
    
    
    // put the intersection of vectors into words_intersection_vec
    std::set_intersection(words1_vec.begin(), words1_vec.end(), words2_vec.begin(), words2_vec.end(), back_inserter(words_intersection_vec));
    
    // 19) Calculate the factorial of 6 (6 x 5 x 4 x ... x 1)
    std::vector<int> fact_vec(6);
    std::iota(fact_vec.begin(), fact_vec.end(), 1);
    std::cout << "6 factorial is " << std::accumulate(fact_vec.begin(), fact_vec.end(), 1, [] (int x, int y) { return x*y; } );
    
    return 0;
}
