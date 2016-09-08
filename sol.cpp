#include <set>
#include <iostream>
using namespace std;

/**********************************
 * Compile:
 * g++ -o sol sol.cpp -std=c++11
 **********************************/


/**********************************************************************
 * @Description         Substraction of 4-bit integer, handle overflow
 * @param a             Minuend
 * @param b             Subtractor
 *
 * @return              The value of a - b
 *********************************************************************/
unsigned int sub(unsigned int a, unsigned int b)
{
    if(b > a) /* Handle overflow */
    {
        return 15 - (b - a - 1);
    }

    return a - b;
}

/**********************************************************************
 * @Description         This is the transfer function
 * @param domain1       Domain of 4-bit abstract values
 *                      domain.first is the low bit, should be 0~15
 *                      domain.second is the high bit, should be 0~15
 * @param domain2       The same data structure as domain1
 *
 * @return              The data set of domain1 - domain2
 *********************************************************************/
set<unsigned int> transferFunc(pair<unsigned int, unsigned int> domain1, pair<unsigned int, unsigned int> domain2)
{
    unsigned int start1 = domain1.first, end1 = domain1.second;
    unsigned int start2 = domain2.first, end2 = domain2.second;
    set<unsigned int> st;

    for(unsigned int i = start1; i <= end1; ++i)
    {
        for(unsigned int j = start2; j <= end2; ++j)
        {
            st.insert(sub(i, j));
        }
    }

    return st;
}

/* Test case */
int main()
{
    set<unsigned int> result = transferFunc(make_pair<unsigned int, unsigned int>(0, 15), make_pair<unsigned int, unsigned int>(0, 15));
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;
    // Data set (result) value: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

    return 0;
}
