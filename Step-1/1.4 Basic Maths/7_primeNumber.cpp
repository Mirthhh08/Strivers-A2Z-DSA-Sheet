#include <bits/stdc++.h>
using namespace std;
//  brute force approach
// T.C. :  O(N)
int primeNumber1(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }

    if (cnt == 2)
        return true;
    else
        return false;
}

// optimized approach
// T.C. : O(sqrt(N))
int primeNumber2(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;

            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 2)
        return true;
    else
        return false;
}

int main()
{
    cout << primeNumber1(11) << endl;
    cout << primeNumber2(11) << endl;
    return 0;
}