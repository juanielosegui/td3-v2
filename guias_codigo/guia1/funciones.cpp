#include "funciones.h"

// ------------------------------------------------
// 2)

void sumSign(const int & a, const int & b)
{
    if(a + b > 0) cout << "It is positive" << endl;
    if(a + b < 0) cout << "It is negative" << endl;
    if(a + b == 0) cout << "It is zero" << endl;
}

// ------------------------------------------------
// 5)

string replaceVowelsWithA(const string & txt)
{
    int i = 0;
    string res = "";
    do
    {
        if(txt[i] == 'a' || txt[i] == 'e' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'u')
        {
            res.push_back('a');
        } else 
        {
            res.push_back(txt[i]);
        }
        i++;
    } while (i < txt.size());
    return res;   
}

bool sumsZero(const int & a, const int & b)
{
    if(a + b == 0) return true;
    return false;
}

int max(const int & a, const int & b)
{
    if(a >= b) return a;
    return b;
}

int vowelsAmt(const string & txt)
{
    // result and iteration vars
    int res = 0;
    int i = 0;

    do
    {
        // inc result if it finds a vowels
        if(txt[i] == 'a' || txt[i] == 'e' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'u')
        {
            res++;
        }
        i++;
    } while (i < txt.size());

    return res;   
}

bool isVowel(const char & c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

// ------------------------------------------------
// 6)

void closeInBrackets(string & s)
{
    s = '(' + s + ')';
    cout << s << endl; 
}


int replaceNumber(vector<int> ls, const int & n)
{
    int res = 0;
    int i = 0;

    do
    {
        // resets and increases res
        if(ls[i] == n) ls[i] = 0, res++;
        i++;
    } while (i < ls.size());
    
    return res;
}

// ------------------------------------------------
// 8)

int sum(const vector<int> & numbers)
{
    int res = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        res += numbers[i];
    }
    return res;
}

float fahrenheitToCelsius(const float & fahr)
// (fahr-32)*5/9
{
    return (fahr-32)*(5.0/9.0);
}

void printFahrValues30to100()
{
    for(int fahr=30; fahr <= 100; fahr+=10)
    {
        cout << fahrenheitToCelsius(fahr) << ", ";
    }
    cout << "Done!" << endl;
}

bool isPrime(const int & n)
{
    if(n == 1) return false;
    if(n == 2) return true;

    int i = 2;
    while(i < n)
    {
        if(n % i == 0) return false;
        i++;
    }

    return true;
}

void printPrimesTo100()
{
    for (int i = 0; i <= 100; i++)
    {
        if(isPrime(i)) cout << i << ", ";
    }
    cout << "Done!" << endl;
}

bool isPalindrome(const string & s)
{
    if(s.size() <= 1) return true;

    for(int i=0; i<s.size()/2; i++)
    {
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

string concatenateStr(const vector<string> v)
{
    string res = "";
    for(int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++) res.push_back(v[i][j]);
    }
    return res;
}

// ------------------------------------------------
// 9)

int redCounter(const vector<Color> & v)
{
    int ctr = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == Color::Red) ctr++; 
    }
    return ctr;
}

bool isWeekend(const Day & d)
{
    if(d == Day::Saturday) return true;
    if(d == Day::Sunday) return true;

    return false;
}

// ------------------------------------------------
// 10)

user newUser(const string & name, const string & mail)
{
    user User = {name, mail, 0};
    return User;
}

bool tenYearsApart(const person & a, const person & b)
{
    if(a.age - b.age >= 10) return true;
    return false;
}

person eldestPerson(const vector<person> & people)
{
    person eldest = people[0];
    for(int i=0; i<people.size(); i++)
    {
        if(people[i].age >= eldest.age)
        {
            eldest = people[i];
        }
    }
    return eldest;
}