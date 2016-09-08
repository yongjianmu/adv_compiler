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
 * 
 * @Description         This is the transfer function
 * @param domain        Domain of 4-bit abstract values
 *                      domain.first is the low bit
 *                      domain.second is the high bit
 *
 * @return              The data set of the substraction
 *********************************************************************/
set<unsigned int> transferFunc(pair<unsigned int, unsigned int> domain)
{
    unsigned int start = domain.first, end = domain.second;
    set<unsigned int> st;

    for(unsigned int i = start; i <= end; ++i)
    {
        for(unsigned int j = start; j <= end; ++j)
        {
            st.insert(sub(i, j));
        }
    }

    return st;
}

/* Test case */
int main()
{
    set<unsigned int> result = transferFunc(make_pair<unsigned int, unsigned int>(0, 15));
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;
    // Data set (result) value: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

    return 0;
}
