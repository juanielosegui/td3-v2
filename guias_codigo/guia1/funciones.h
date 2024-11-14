#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <iostream>

// 2)
void sumSign(const int & a, const int & b);

// 5)
std::string replaceVowelsWithA(const std::string & txt);
bool sumsZero(const int & a, const int & b);
int max(const int & a, const int & b);
int vowelsAmt(const std::string & txt);
bool isVowel(const char & c);

// 6)
void closeInBrackets(std::string & s);
int replaceNumber(std::vector<int> ls, const int & n);

// 8)
int sum(const std::vector<int> & numbers);
float fahrenheitToCelsius(const float & fahr);
void printFahrValues30to100();
bool isPrime(const int & n);
void printPrimesTo100();
bool isPalindrome(const std::string & s);
std::string concatenateStr(const std::vector<std::string> v);

// 9)
enum class Color{White, Black, Red, Green, Blue};
int redCounter(const std::vector<Color> & v);

enum class Day{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
bool isWeekend(const Day & v);

// 10)
struct user
{
    std::string name;
    std::string email;
    int amtFollowers;
};

user newUser(const std::string & name, const std::string & mail);

struct person
{
    std::string name;
    int age;
    std::string id;
};

bool tenYearsApart(const person & a, const person & b);

struct course
{
    std::string name;
    int id;
    int students;
    std::string career;
};

person eldestPerson(const std::vector<person> & people);

#endif