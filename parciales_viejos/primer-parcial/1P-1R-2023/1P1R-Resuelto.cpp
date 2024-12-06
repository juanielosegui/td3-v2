#include <iostream>
#include <vector>
using namespace std;

int sumar_picos_aux(const vector<int>& v, int desde) {
    if (desde >= v.size()) {
        return 0;
    }

    int suma = 0;
    if (desde == 0 || v[desde] >= v[desde+1]) {
        suma += v[desde];
    }

    return suma + sumar_picos_aux(v, desde+1);
}

// Problema 4
int sumar_picos(const vector<int> & v)
{
    // call aux func
    return sumar_picos_aux(v, 0);
}