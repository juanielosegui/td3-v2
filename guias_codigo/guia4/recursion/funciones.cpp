#include "funciones.h"

//  -----------------------------------------------------------------------------------------------------------
//  1)

// fibonacci: each term consist of the sum of the previous two  
int fibonacci(int n)
{
    // base cases
    if(n == 0) return 0;
    if(n == 1) return 1;

    // recursion
    return fibonacci(n-1) + fibonacci(n-2);
}

// if you keep substracting two to a number and you get to zero, then that number is even, otherwise is odd
bool is_even(int n)
{
    // base cases
    if(n == 0) return true;
    if(n == 1) return false;

    // recursion
    return is_even(n-2);
}

//  -----------------------------------------------------------------------------------------------------------
//  2)

// multiplies all numbers in v
int prod(const vector<int> & v, const int from)
{
    // base case
    if(from == v.size()-1) return v[from];

    return v[from] * prod(v, from+1); 
}

// counts how many times s shows up in v
int amt_occurrencies(string s, const vector<string> & v, const int from)
{
    // base case
    bool is_S_OK = v[from] == s;
    
    if(from == v.size()) return 0;

    if(is_S_OK)
    {
        return 1 + amt_occurrencies(s, v, from+1);
    } else {
        return 0 + amt_occurrencies(s, v, from+1);
    }
}

// how many times i = v[i]
int count_coincidences(const vector<int> & v, const int from)
{
    // base case
    if(v.size() == 0) return -1; // empty vector
    if(from == v.size()) return 0; // we got to the end
    
    // recursive case
    // we're treating 'from' like an index
    if(from == v[from])
    {
        return 1 + count_coincidences(v, from+1);
    } else {
        return 0 + count_coincidences(v, from+1);
    }
}

// gets every positive number
vector<int> onlypositives(const vector<int> & v, const int from)
{
    // base case
    if(from == v.size()) return {}; // empty vector

    // recursive case
    vector<int> res = onlypositives(v, from+1);
    if(v[from] > 0)
    {
        res.push_back(v[from]);
    }
    return res;
}

// multiplies every element by n
void multiplyAll(vector<int> & v, int n, const int from)
{
    // base case
    if(from == v.size()) return;

    // recursive case
    v[from] *= n;
    multiplyAll(v, n, from+1);
}

//  -----------------------------------------------------------------------------------------------------------
//  3)

int amt_occurrenciesDC(string s, const vector<string> & v, const int from, const int to)
{
    // base case
    bool no_elems_OK = from >= to;
    bool one_elem_OK = to - from == 1;
    bool is_S_OK = v[from] == s;
    
    if(no_elems_OK) return 0;   // no elements
    
    if(one_elem_OK && is_S_OK) return 1;
    if(one_elem_OK && !is_S_OK) return 0; 

    // divide
    int mid = from+(to-from)/2;

    // conquer
    int left = amt_occurrenciesDC(s, v, from, mid);
    int right = amt_occurrenciesDC(s, v, mid, to);
    
    // combine
    return left + right;
}

void multiplyAllDC(vector<int> & v, int n, const int from, const int to)
{
    // base case
    bool no_elems_OK = from >= to;  // empty vec
    bool one_elem_OK = to - from == 1; // one elem

    if(no_elems_OK) return;
    
    if(one_elem_OK)
    {
        v[from] = v[from] * n;
        return;
    }

    // divide
    int mid = from+(to-from)/2;

    // conquer
    multiplyAllDC(v, n, from, mid);
    multiplyAllDC(v, n, mid, to);
}

//  -----------------------------------------------------------------------------------------------------------
//  4)

int n_to_the_m_power(const int & n, const int & m)
{
    // base case
    if(m == 0) return 1; // since n^0 is 1
    if(m == 1) return n; // since n^1 is n

    // divide
    int mid = m/2;
    
    // conquer
    int half1 = n_to_the_m_power(n, mid);
    int half2 = n_to_the_m_power(n, mid); // n^(m/2) * n^(m/2) = n^m

    // combine
    return half1 * half2;
}

bool mountain_vector(const vector<int> & v, const int & from, const int & to)
{
    // base case
    if(from >= to) return false;
    if((to-from) == 1) return true;

    // divide
    int mid = from+(from-to)/2;
    bool left = mountain_vector(v, from, mid);
    bool right = mountain_vector(v, mid, to);

    return true;
}

//  -----------------------------------------------------------------------------------------------------------
//  5)

bool is_to_the_left(const vector<int> & v, const int & from, const int & to)
{
    // base case
    if((to-from) == 1) return true; // vec has one element

    // divide
    int mid = from+(to-from)/2;

    // conquer
    int resLeft = accumulate(v.begin() + from, v.begin() + mid, 0);
    int resRight = accumulate(v.begin() + mid, v.begin() + to, 0);
    
    // check the sum of the left and right part
    if(resLeft > resRight)
    {
        return is_to_the_left(v, from, mid) && is_to_the_left(v, mid, to);
    } else {
        return false;
    }
}

//  -----------------------------------------------------------------------------------------------------------
//  7)

int productorial(const vector<int> & v, const int & from, const int & to)
{
    // base cases
    if(from >= to) return 1; // empty range
    if(from+1 == to) return v[from]; // one element

    // divide
    int one_third_stamp = from+(to-from)/3;
    int two_third_stamp = from+2*one_third_stamp;

    // conquer
    int first_third = productorial(v, from, one_third_stamp);
    int second_third = productorial(v, one_third_stamp, two_third_stamp);
    int third_third = productorial(v, two_third_stamp, to);

    // combine
    return first_third * second_third * third_third;   
}

int sum(const vector<int> & v, const int & from, const int & to)
{
    // base cases
    if(from>=to) return 0; // empty range
    if(from+1==to) return v[from]; // one element

    // divide
    int one_third_stamp = from+(to-from)/3;
    int two_third_stamp = from+2*one_third_stamp;

    // conquer
    int first_third = sum(v, from, one_third_stamp);
    int second_third = sum(v, one_third_stamp, two_third_stamp);
    int third_third = sum(v, two_third_stamp, to);

    // combine
    return first_third + second_third + third_third;
}