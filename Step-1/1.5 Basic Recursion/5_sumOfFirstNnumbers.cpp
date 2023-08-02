
#include <bits/stdc++.h>
using namespace std;

// parameterized 
int sumOfSeries(int N , int sum)
{
    // code here

    if (N == 0)
    {
        return sum;
    }

    sum += N;
    return sumOfSeries(N - 1, sum);
}



// functional
int sumOfSeries2(int N)
{
    // code here

    if (N == 0)
    {
        return 0;
    }

    return N + sumOfSeries2(N - 1);
}
int main()
{
    cout<<sumOfSeries2(10);
    return 0;
}