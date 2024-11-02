#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <iostream>
#include <numeric>
using namespace std;

// 1)
int fibonacci(int n);
bool is_even(int n);

// 2)
int prod(const vector<int> & v, const int from);
int amt_occurrencies(string s, const vector<string> & v, const int from);
int count_coincidences(const vector<int> & v, const int from);
vector<int> onlypositives(const vector<int> & v, const int from);
void multiplyAll(vector<int> & v, int n, const int from);

// 3)
int amt_occurrenciesDC(string s, const vector<string> & v, const int from, const int to);
void multiplyAllDC(vector<int> & v, int n, const int from, const int to);

// 4)
int n_to_the_m_power(const int & n, const int & m);
bool mountain_vector(const vector<int> & v, const int & from, const int & to);

// 5)
bool is_to_the_left(const vector<int> & v, const int & from, const int & to);

// 6)
int max_sum_sublist(const vector <int> & v, const int & from, const int & to);

// 7)
int productorial(const vector<int> & v, const int & from, const int & to);
int sum(const vector<int> & v, const int & from, const int & to);

#endif // FUNCIONES_H