#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

template <typename T>
void vector_print(const std::vector<T>& vec) {
    std::cout << "vector elements: " << std::endl;
    for (const auto& el : vec) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}

int main() {
    
    //find_first_of()
    
    // uses operator== by default
    
    std::string str{"Hello"};
    std::string vowels{"aeiou"};
    
    auto vowel = find_first_of(str.cbegin(), str.cend(), vowels.cbegin(), vowels.cend());
    if (vowel != str.cend()) {
        std::cout << "The first vowel is " << *vowel << " at index " << distance(str.cbegin(), vowel) << std::endl;
    }
    else {
        std::cout << "No vowel found." << std::endl;
    }
    
    // to find the next vowel, start a search from next(vowel)
	auto second_vowel = find_first_of(next(vowel), str.cend(), vowels.cbegin(), vowels.cend());
    if (second_vowel != str.cend()) {
        std::cout << "The second vowel is " << *second_vowel << " at index " << distance(str.cbegin(), second_vowel) << std::endl;
    }
    else {
        std::cout << "No vowel found after " << *vowel << std::endl;
    }
    
    
    
    // adjacent_find() looks for two neighbouring elements that have the same value
    // by default uses operator==
    
    auto adj_pos = std::adjacent_find(str.cbegin(), str.cend());
    if (adj_pos != str.cend()) std::cout << "adjacents found at position " << distance(str.cbegin(), adj_pos) << std::endl;
    else std::cout << "no adjacent elements found" << std::endl;
    
    
    //search_n() looks for a seq. of n successive elements which have the same value
    
    // search() takes two iterator ranges. Looks in the first range to find if the second range appears there
    
    //mismatch() takes in two iterator ranges. Returns a pair to the first elements that has a different value on both containers
    // ->first is the element from the first container, ->second is the other one
    // 1 2 1 2
    // 1 3 1 2
    // mismatch(...)->first == 2,mismatch(...)->second == 3

    //some_of algorithms
    // all_of, any_of, none_of
    // all take two half-ranges and a functor/lambda expression to check if all of, any of, or none of return true from the functor
    
    //binary_search()
    // assumes that the container to be searched is sorted, which makes the search much much much faster
    // takes in a half-range and an element to be searched in the container, and returns bool
    
    //includes()
    // takes in two half ranges, looks for if the second container is completely in the first one. returns bool




    // Numeric arguments
    // requires <numeric>
    
    //iota()
    // populates an iterator range with values successively increasing by one
    // takes in an iterator range and a starting number
    // std::vector<int> vec(10); 10 element vector
    // iota(vec.begin(), vec.end(), 1) -> fills in the vector with elements from 1 to 10 sequentially
    
    // accumulate()
    // cumulative sum, takes in a half-range and a starting number
    // can take in a fourth lambda argument as a different operation from addition
    // Ex: conditional summation
    // doesn't allow for parallel processing, addition is done from left to right
    
    // reduce()
    // accumulate's alternative for random access summation, so compatible with parallel processing
    
    
    // Write-only algorithms
    
    //fill() takes in a half range and an element to populate the range with that element
    
    //fill_n() takes in a start point, number of fills, and the element to fill the given number of fills
    // returns an iterator pointing to the element after the last filled one
    
    //************IMPORTANT*************
    // .swap() is very useful for cases where you erase elements from the original one but don't need the space initiated when those
    // elements are created. create an empty vector and fill it in with the remaining elements, and then swap the old vector with the new one
    
    
    
    
    // for_each()
    // takes in a half-range, and a functor/function ptr/lambda expr to apply that function over the whole range
    // the lambda can take the arguments by reference
    
    
    
    // copy()
    // takes in a half-range, and a target iterator to copy elements from the given range into the target container
    // if the target container is empty, we can use back_inserter(target_container) as the third argument
    
    // copy_n() will copy the first n elements, starting from the first element
    // takes three args: 
    // first is the iterator to the first element to copy
    // second is how many elements to be copied
    // third is the target container
    
    // copy_if() checks with a predicate on each copying attempt
    
    
    
    
    // replace()
    // takes in a half-range, a value to be replaced, and the value that will replace the third argument
    
    // replace_if()
    // takes in a half-range, a predicate, and a value to replace whichever pre-existing element returns true from the predicate
    
    // both have _copy versions
    // take in an extra iterator as the third arg. that shows where a new object with the replaced items is going to be placed to
    // first two arguments are the bounds of the containers, and the last two are the elements that will be replaced and will replace
    
    
    
    
    // removing algorithms
    // "removes" elements from a range
    // elements are "logically removed", i.e. they're still present in the range
    
    // remove()
    // each element which has a given value is moved to the back of the range
    // the values of the removed elements are no longer defined
    // accessing those will cause undefined behaviour
    // the elements which were behind the removed element are moved forwards
    // calling size() will return the same values before and after a remove operation
    // returns an iterator to the first removed element
    
    std::vector<int> remove_vec {3,1,4,1,5,9};
    auto defunct = std::remove(remove_vec.begin(), remove_vec.end(), 1); // points to the (re)moved elements
    std::cout << remove_vec.size() << std::endl;
    vector_print(remove_vec); //3,4,5,9,5,9
    
    
    // erase()
    // physically removes elements from the called container 
    remove_vec.erase(defunct, remove_vec.end()); // will erase the "removed" elements from the vector
    vector_print(remove_vec);
    
    // remove_if, remove_copy, remove_copy_if ...
    // _if versions take in a predicate to use instead of operator==
    // _copy versions take in an extra iterator to place the new version of the vector into
    
    
    // unique()
    // removes duplicate adjacent elements
    // the elements in the given range must be ordered
    // behaves similarly to remove(), doesn't erase elements from the container
    // returns an iterator to the first non-unique element => forward it to erase() to erase the non-unique elements
    // takes in a half-range, and if needed, a binary predicate as a third argument, which will be used to compare adjacent elements
    // if an adjacent pair returns true from the predicate, then the RIGHT one is REMOVED
    
    // unique_copy() works similar to other _copy versions
    
    
    // transform() 
    // will call a given function on each element between the half-range iterators
    // result is copied to a destination, could be copied onto the original container as well
    
    std::vector<int> transform_vec{1,2,3,4,5,6};
    // square each element and store the results in their original places
    transform(transform_vec.begin(), transform_vec.end(), transform_vec.begin(), [] (int x) { return x*x; } );
    vector_print(transform_vec);
    
    // there's an overload of transform() which takes a third iterator pointing to another container
    // requires a binary function/lambda expr 
    // takes one element from both containers and forwards both into the binary function, and
    // pastes the outcome onto the container who's pointed by a fourth iterator
    
    
    
    
    // merge()
    // combines two sorted ranges into a destination
    // the destination will contain all the elements from both containers, sorted
    // sorting is done by operator<
    
    // set_intersection()
    // takes in two ranges (i.e. four iterators) and a destination
    // destination contains only the common elements of both containers, sorted
    // sorting is done by operator<
    
    // set_union()
    // takes in two ranges (i.e. four iterators) and a destination
    // destination contains elements that are in at least one of the containers, sorted
    // sorting is done by operator<
    // if one set contains duplicates, then the union also contains duplicates
    
    
    
    // Reordering algorithms
    // rearranges elements inside a range
    // doesn't change their values
    
    // reverse()
    // takes in a range, and reverses the order of the elements
    // reverse_copy() puts the new order into a new container pointed by a third iterator
    
    // rotate()
    // takes in an iterator to a certain element
    // every element before the pointed one is taken to the end of the container
    // takes in three args: beginning, pivot point, and the end of the container
    
    std::vector<int> rotate_vec{1,2,3,4,5};
    auto pivot = rotate_vec.begin() + 2;
    std::rotate(rotate_vec.begin(), pivot, rotate_vec.end());
    vector_print(rotate_vec);
    
    // rotate_copy() takes in a fourth arg. to point to where the resulting container will be copied to
    
    
    // partitioning 
    // elements with a property is pushed to the front, and others are pushed to the back
    // very useful in interactive applications
    // Ex: unread messages pushed to the front
    // Ex: selected items pushed to the front
    
    // partition()
    // takes in a half-range and a unary predicate
    // elements that return true from the predicate is pushed to the front
    
    // stable_partition()
    // same with partition, but elements within their partitions preserve their respective order 
    
    // is_partitioned()
    // takes in a half-range and a predicate
    // returns a bool depending on whether the range of elements is already partitioned by that predicate function
    
    // partition_point()
    // takes the same arguments with is_partitioned()
    // returns an iterator to the first element in the container that returns false from the predicate
    
    
    // sorting algs
    // they use operator< by default to order elements 

    // sort()
    // takes in a half-range and sorts the elements in ascending order
    // usually implements "quicksort"
    // you can supply a predicate to be used instead of operator<
    
    //is_sorted()
    // takes in a half-range, and returns true if the elements are sorted
    
    // is_sorted_until()
    // takes in a half-range, and returns an iterator to the first element which is not in order
    
    // partial_sort()
    // takes in an extra iterator, and sorts elements so that 
    // the smaller interval is filled with the smallest elements, and the rest is disregarded
    std::vector<int> sort_vec {6,7,8,3,2,1};
    std::partial_sort(sort_vec.begin(), sort_vec.begin()+3, sort_vec.end());
    vector_print(sort_vec);
    
    // partial_sort_copy()
    // copies the outcome to a new destination
    
    // nth_element()
    // takes an iterator to an element in the range
    // rearranges the elements so that the iterator points to the element that would be in that position if the range was sorted
    // it then does a partition with this element as the partition point
    
    
    // permutations
    
    // next_permutation()
    // takes a half-range, reorders elements to give the next permutation in ascending order
    // Ex: abc becomes acb
    // returns true if there's a permutation that's obtainable by applying next_permutation again
    // uses operator< by default, we can supply our own binary predicate instead of it
    
    // prev_permutation()
    
    // is_permutation()
    // takes two half-ranges
    // returns true if both ranges contain the same elements
    // uses operator== by default, we can supply our own binary predicate instead of it
    

    // min and max algorithms
    // can take two arguments, or initializer lists(c++11), or iterator half-ranges
    // by default they use operator<
    
    // minmax()
    // returns a std::pair that's the minimum and the maximum elements of a container
    
    
    
    // other numeric algorithms
    
    // <numeric> contains some other algorithms useful for numerical computing
    // Ex: partial_sum, adjacent_difference, inner_product, etc.
    
    // C++17 also provides a number of special functions in <cmath>
    // Bessel functions, Legendre polynomials, elliptic integral, etc.
    
    // partial_sum()
    // given a container with items a, b, c, ...
    // partial_sum writes the partial sums to another container
    // the resulting container will contain a, a+b, a+b+c, ...
    // by default+ operator+ is used
    
    // adjacent_difference()
    // given a container with items a, b, c, ...
    // the resulting container will contain a, b-a, c-b, d-c, ...
    // by default, operator- is used 
    
    // inner_product()
    // given two containers, returns the sum of the corresponding elements' multiplication result
    // similar to accumulate, an argument has to be the starting value 
    // by default, operator+ and operator* are used
    
    
    
    // Random numbers
    
    // rand()
    // inherited from C, comes from <cstdlib>
    // calling rand() returns the next number in a sequence of pseudo-random numbers
    // returns an integer between 0 and RAND_MAX inclusive
    
    // use srand() to seed the RNG that's used by rand()
    // traditionally, programmers use the current time to provide a "random" seed
    // the value returned by time() only changes per second
    
    // typical rand() implementations generate numbers which are not very random, especially in the last few digits
    // if we don't want to get numbers between 0 and RAND_MAX, you have to scale the outcome or the range. this introduces bias to the results
    // rand() has poor cryptographic security since
    // 1) the sequence it takes numbers from is short and repeats frequently
    // 2) guessing the next number is not difficult enough
    
    
    // C++11 introduced a number of classes for working with random numbers
    // these are defined in <random>
    
    // A random number engine is implemented as a functor
    // the constructor generates the sequence of pseudo-random numbers
    // when we call operator(), we get the next number from the sequence
    
    // distributions are also implemented as functors
    // read the docs for the distributions
    
    // two main random number engines are:
    // 1) default_random_engine
    // - implementation-defined
    // - may be a wrapper around rand()

    // 2) mt19937 
    // - Mersenne Twister with period (2^19937 - 1)
    // very fast at generating numbers
    // Almost crypto-secure
    // has a lot of state => slow to initialize
    // usually the best choice for most requirements
    
    // random_device
    // produces a hardware-generated random number from system entropy data
    // however, it will produce a pseudo-random number if
    // 1) the system doesn't provide entropy data
    // 2) the compiler is GNU C++, which doesn't support entropy data
    // if all the entropy data has been used, it will stop and wait until new entropy data is available
    // random_device is much slower than mt19937
    // implemented as a functor
    
    // => use random_device for seed generation, and mt19937 for rng
    // also, make the engine and distribution objects static
    
    
    
    // shuffle()
    // rearranges an iterator range in a random order
    // takes in a number engine object as its third argument
    // calls uniform_int_distribution internally
    std::vector<int> shuffle_vec {3,1,4,1,5,9};
    static std::mt19937 mt;
    shuffle(shuffle_vec.begin(), shuffle_vec.end(), mt);
    vector_print(shuffle_vec);
    
    //std::bernoulli_distribution
    // rescales a sequence of numbers into boolean values
    // useful for making one-off decisions with random outcomes
    
    static std::bernoulli_distribution bd;
    std::cout << "returned " << (bd(mt) ? " true " : " false ") << "from bernoulli distribution." << std::endl;
    
    
    
    return 0;
}
