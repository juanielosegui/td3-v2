#include "funciones.h"

// ----------------------------------------------------
// 3)

bool todos_positivos(const vector<int> & vec)
{
    // assuming vec is not empty
    int i = 0;
    while (i < vec.size())
    {
        if(vec[i] < 0)
        {
            // only one negative element is enough to return false
            return false;
        }
        i++;
    }
    return true; 
}

bool no_contiene_equis(const vector<char> & str)
{
    // assuming str is not empty
    int i = 0;
    while(i < str.size())
    {
        if(str[i] == 'x')
        {
            // soon as one 'x' shows up it is false
            return false;
        }
        i++;
    }
    return true;
}

// ----------------------------------------------------
// 6)

void sumar_n(vector<int> & ls, const int & n)
{
    // init iteration var
    int i = 0;

    // iterate over ls
    while(i < ls.size())
    {
        // modify
        ls[i] = ls[i] + n;
        i++;
    }
}

int suma_y_reset(vector<int> & v)
{
    // init res and iteration var
    int res, i = 0;

    // iterate over v
    while(i < v.size())
    {
        // add to res
        res += v[i];
        // reset
        v[i] = 0;
        i++;
    }

    return res;
}

// ----------------------------------------------------
// 8)

int sumar_hasta_mitad(const vector<int> & v)
{
    int i, res = 0;
    while(i < v.size()/2)
    {
        res = res + v[2*i] + v[(2*i)+1];
        i++; 
    }
    res = res + 100;
    return res;
}

// ----------------------------------------------------
// 12)

bool es_palindromo(const vector<char> & s)
{
    int j = 0;
    while(j < s.size())
    {
        if(s[j] != s[s.size()-j-1])
        {
            return false;
        }
        j++;
    }
    return true;
}

bool es_palindromo2(const vector<char> & s)
{
    int j = 0;
    while(j < s.size()/2)
    {
        if(s[j] != s[s.size()-j-1])
        {
            return false;
        }
        j++;
    }
    return true;
}

// ----------------------------------------------------
// 13)

void invertir_rango(vector<int> & v, const int & i, const int & j)
{
    // iteration var
    int k = i;
    while(k <= j)
    {
        int aux = v[k];
        v[k] = v[j];
        v[j] = aux;

        // inc
        k++;
    }
}

// ----------------------------------------------------
// 14)

int contar_iguales(const vector<int> & v1, const vector<int> & v2)
{
    // init vars
    int res = 0;
    int i = v1.size() - 1;

    while (i >= 0)
    {
        // coincidence
        if(v1[i] == v2[i])
        {
            // inc res
            res = res + 1;
        }
        // inc it
        i = i - 1;
}
    return res;
}

// ----------------------------------------------------
// 15)

void sumar_vector_a(vector<int> & v, vector<int> w, const int & k)
{
    // pre-conditions
    int i = 0;
    int res = 0;
    // res?

    // (0 <= i <= |v|)
    while(i < v.size())
    {
        // beta(v[i] > k)
        if(v[i] > k)
        {
            res += v[i];
            // i mean, Qc talks about some res, wtf?
        }
        i++;
    }
}

void sumar_vector_b(vector<int> & v, vector<int> w)
{
    // pre-conditions
    int i = v.size();
    bool res = false;
    
    // (0 <= i <= |v|)
    while (i > 0)
    {
        if(v[i] % 2 == 0)
        {
            res = true;
            break;
        }
        i--;
    }
}

void sumar_vector_c(vector<int> & v, vector<int> w)
{
    int i = 0;
    while (i < v.size())
    {
        if (v[i] = v[i+1])
        {
            continue;
        } else {
            break;
        }
        i++;
    }
}

void sumar_vector_d(vector<int> & v, vector<int> w)
{
    int i = 0;
    while (i < v.size())
    {
        if(v[i] != w[i])
        {
            break;
        }
        i++;
    }
    
}