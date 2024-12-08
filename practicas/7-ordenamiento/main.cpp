#include <iostream>
#include <vector>


// ---------------------------------------
// 2)
bool deCuentas(const std::vector<int> & v)
{
    // base cases:
    // empty vec
    if(v.size() == 0) return false;

    // iterate over vec
    for (int i = 0; i < v.size(); i++)
    {
        int i_ctr = 0;
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j] == v[i]) i_ctr++;
        }
        if(v[i] != i_ctr) return false;
    }
    return true;
}

// se hace en O(|v|^2?)

int main()
{
    return 0;
}