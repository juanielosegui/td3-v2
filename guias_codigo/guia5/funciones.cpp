#include "funciones.h"

// ---------------------------------------
//          AUXILIARY FUNCTIONS
// ---------------------------------------

void merge1(const std::vector<int> & v1, const std::vector<int> & v2, std::vector<int> & res) {
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size())
    {
        res.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
}

std::vector<int> merge2(const std::vector<int> & v1, const std::vector<int> & v2)
{
    std::vector<int> res; int i = 0; int j = 0;

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] < v2[j])
        {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size())
    {
        res.push_back(v1[i]);
        i++;
    }

    while(j < v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
    
    return res;
}
   
std::vector<int> mergeSort(std::vector<int> & v, int d, int h)
{
    if (d >= h) return {};

    // divide
    int mid = d + (h - d) / 2;

    // conquer
    std::vector<int> izq = mergeSort(v, d, mid);
    std::vector<int> der = mergeSort(v, mid, h);
    
    return merge2(izq, der);
}

void mergeCount(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& res, int& swapCount) {
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
            // Whenever we take from v2, it means a swap has occurred with respect to v1
            swapCount += (v1.size() - i);  // Count all elements remaining in v1
        }
    }

    while (i < v1.size())
    {
        res.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
}

void printVec(const std::vector<int> & v)
{
    std::cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ", ";  // Separar los elementos con coma
        }
    }
    std::cout << "]" << std::endl;
}

int dividirMod(std::vector<int> & v, const int & d, const int & h)
{
    int pivot_p = v[h-1];
    int pivot_q = v[h-1/2];
    int i = d;

    for(int j = d; j < h - 1; j++)
    {
        if(v[j] <= pivot_p)
        {
            std::swap(v[i], v[j]);
            i = i + 1;
        }
    }
    std::swap(v[i], v[h-1]);
    return i;
}


// ---------------------------------------
// 1)
void selection_sort(std::vector<int> & v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int minIndex = i;
        
        // iterate over unsorted part
        for (int j = i+1; j < v.size(); j++)
        {
            if(v[j] < v[minIndex])
            {
                // update smallest index if necessary
                minIndex = j;
            }
        }
        
        std::swap(v[i], v[minIndex]);
    }
}

void insertion_sort(std::vector<int> & v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;

        /*
        Move elements of v[0..i-1], that are
        greater than key, to one position ahead
        of their current position
        */
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// ---------------------------------------
// 2)
// a)
void mergesortMod1(std::vector<int> & v, const int & d, const int & h)
{
    // base case: one element or no elements
    if (h - d <= 1) return;

    // divide
    int med = (d + h) / 2;
    mergesortMod1(v, d, med);
    mergesortMod1(v, med, h);

    // create temporary vectors for each half
    std::vector<int> left(v.begin() + d, v.begin() + med);
    std::vector<int> right(v.begin() + med, v.begin() + h);
    std::vector<int> temp;

    // merge the two halves
    merge1(left, right, temp);

    // copy the sorted results back to the original vector
    std::copy(temp.begin(), temp.end(), v.begin() + d);
}

// b)
int mergesortMod2(std::vector<int> & v, const int & d, const int & h)
{
    // Base case: one element or no elements
    if (h - d <= 1) return 0;

    // Divide
    int med = (d + h) / 2;
    int swapCount = 0;

    swapCount += mergesortMod2(v, d, med);   // Sort first half
    swapCount += mergesortMod2(v, med, h);   // Sort second half

    // Create temporary vectors for each half
    std::vector<int> left(v.begin() + d, v.begin() + med);
    std::vector<int> right(v.begin() + med, v.begin() + h);
    std::vector<int> temp;

    // Merge and count swaps
    mergeCount(left, right, temp, swapCount);

    // Copy sorted results back to the original vector
    std::copy(temp.begin(), temp.end(), v.begin() + d);

    return swapCount;
}

// ---------------------------------------
// 3)
std::vector<int> merge_lots(std::vector<std::vector<int>> & vs)
{
    // init answer
    std::vector<int> everyElem;

    // collect all elements of all vectors in a single one
    for (int i = 0; i < vs.size(); i++)
    {
        everyElem.insert(everyElem.end(), vs[i].begin(), vs[i].end());
    }

    // sort the combined vector
    std::sort(everyElem.begin(), everyElem.end());
    return everyElem;
}

// ---------------------------------------
// 4)

void quicksortMod(std::vector<int> & v, const int & d, const int & h)
{
    if(d < h - 1)
    {
        int pos = dividirMod(v, d, h);
        quicksortMod(v,d,pos);
        quicksortMod(v,pos+1,h);
    }
}
