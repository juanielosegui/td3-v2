#include "funciones.h"

int root (const int & k)
{
    int res = 0;    // O(1)
    while(res*res <= k) // O(sqrt(n))
    {
        res = res + 1;  // O(1)
    }
    return res - 1; // O(1)
}

int countDivs (const int & d, const int & c)
{
    int count = 0;  // O(1)
    for(int i=0; i <= c; i++)   // O(n)
    {
        if(i % d == 0)  // O(n)
        {
            count = count + 1;  // O(1)
        }
    }
    return count; // O(1)
}

bool sumGreaterThan (const vector<int> & v, const int & c)
{
    return true;
}

bool repeated (const vector<int> & v)
{
    return true;
}

void fillVector (vector<int> & v)
{
    return;
}

bool inOK (const vector<int> & v, const int & e)
{
    return true;
}