#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 2)
void sumSign(const int & a, const int & b);

// 5)
string replaceVowelsWithA(const string & txt);
bool sumsZero(const int & a, const int & b);
int max(const int & a, const int & b);
int vowelsAmt(const string & txt);
bool isVowel(const char & c);

// 6)
void closeInBrackets(string & s);
int replaceNumber(vector<int> ls, const int & n);

// 8)
int sum(const vector<int> & numbers);
float fahrenheitToCelsius(const float & fahr);
void printFahrValues30to100();
bool isPrime(const int & n);
void printPrimesTo100();
bool isPalindrome(const string & s);
string concatenateStr(const vector<string> v);

// 9)
enum class Color{White, Black, Red, Green, Blue};
int redCounter(const vector<Color> & v);

enum class Day{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
bool isWeekend(const Day & v);

// 10)
struct user
{
    string name;
    string email;
    int amtFollowers;
};

user newUser(const string & name, const string & mail);

struct person
{
    string name;
    int age;
    string id;
};

bool tenYearsApart(const person & a, const person & b);

struct course
{
    string name;
    int id;
    int students;
    string career;
};

person eldestPerson(const vector<person> & people);

#endif