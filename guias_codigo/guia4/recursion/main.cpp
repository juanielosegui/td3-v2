#include <iostream>
#include <vector>
#include <string>
#include "funciones.h"
using namespace std;

// compile running the first command:
// g++ main.cpp -o main
// ./main.exe

void printVec(const vector<int> & v)
{
    for(auto &x: v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    //  **********************************
    //  1)
        cout << "Exercise 1)" << endl;
        cout << "a) Fibonacci sequence with n = 6" << endl;
        cout << "Answer: " << fibonacci(6) << endl;
        // should print out 8

        cout << "b) Find if n = 16 is even" << endl;
        cout << "Answer: " << is_even(16) << endl;
        // should print out 1 since it is true

    //  **********************************
    //  2)
        cout << "Exercise 2)" << endl;
        cout << "a) Productorial" << endl;
        cout << "Answer: " << prod({5, 3, 10, 3}, 0) << endl;
        // should print out 450

        cout << "b) Amount of occurrencies" << endl;
        cout << "Answer: " << amt_occurrencies("hello", {"hello", "goodbye", "hello", "hi", "hello"}, 0) << endl;
        // should print out 3 since "hello" shows up three times

        cout << "c) Counts coincidences" << endl;
        cout << "Answer: " << count_coincidences({0, 100, 2, 300, 4, 500, 600, 7}, 0) << endl;
        // should print out 4

        cout << "d) Get positives" << endl;
        cout << "Answer: " << endl;
        printVec(onlypositives({1, -2, -3, 4, -5, 6}, 0));
        // should print out 6, 4, 1

        cout << "e) Multiply elements" << endl;
        cout << "Answer: " << endl;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7};
        multiplyAll(v, 10, 0);
        printVec(v);
        // should print out 10, 20, 30, 40, 50, 60, 70

    //  **********************************
    //  3)
        cout << "Exercise 3)" << endl;
        cout << "a) Amount of occurrencies with divide and conquer" << endl;
        vector<string> v1 = {"hello", "goodbye", "hello", "hi", "hello"};
        cout << "Answer: " << amt_occurrenciesDC("hello", v1, 0, v1.size()) << endl;
        // should print out 3 since "hello" shows up three times

        cout << "b) Multiply elements with divide and conquer" << endl;
        vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};
        cout << "Answer: " << endl;
        multiplyAllDC(v2, 10, 0, v2.size());
        printVec(v2);
        // should print out 10, 20, 30, 40, 50, 60, 70

    //  **********************************
    //  4)
        cout << "Exercise 4)" << endl;
        cout << "a) N to the Mth power" << endl;
        cout << "Answer: " << n_to_the_m_power(3, 4) << endl;
        // should print out 81 since 3*3*3*3 = 81
        
    return 0;
}