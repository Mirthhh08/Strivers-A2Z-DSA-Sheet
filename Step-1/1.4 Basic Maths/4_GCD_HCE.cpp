#include <bits/stdc++.h>
using namespace std;
//  brute force approach
//  T.C. : O(min(n1 , n2))
int gcd(int n1, int n2)
{
    int gcd = 1;

    for (int i = min(n1, n2); i > 0; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = max(gcd, i);
        }
    }

    return gcd;
}

// using eculidean algorithm
int gcd_optimized(int a, int b)
{

    while (a > 0 and b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;
    else
        return a;
}
int main()
{
    cout << gcd_optimized(12, 6);
    return 0;
}