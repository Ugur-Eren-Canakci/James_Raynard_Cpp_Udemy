#include <iostream>

int main() {
    
    /*• Write a program which
    • Initializes a two-dimensional array
    • Prints out the value of an element from the array
    • Iterates over all the elements and prints out their elements in order
    */

    int arr[2][4] { {1, 2, 3, 4} , {5, 6, 7, 8} };
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
    
    /*Repeat the previous exercise, but with the data "flattened" into a
    one-dimensional array
    • Why is this useful?*/
	int arr2[2*4] {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            std::cout << arr2[i*4 + j] << " ";
        } 
    }
    std::cout << std::endl;
    // Useful for performance due to hardware limitations
    return 0;
}
