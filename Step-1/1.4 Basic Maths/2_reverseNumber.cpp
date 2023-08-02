#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n)
{
    int res = 0;
    while (n > 0)
    {
        int temp = n % 10;
        
        res = (res * 10) + temp;
        n = n / 10;
    }

    return res;
}
int main()
{
    cout<<reverseNumber(123);
    return 0;
}