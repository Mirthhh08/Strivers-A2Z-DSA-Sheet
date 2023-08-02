#include <bits/stdc++.h>
using namespace std;
string armstrongNumber(int n)
{

    int val = n;
    int res = 0;

    while (val != 0)
    {
        int temp = val % 10;
        res += temp * temp * temp;
        val /= 10;
    }

    if (res == n)
        return "Yes";
    else
        return "No";
}
int main()
{
    cout << armstrongNumber(153);
    return 0;
}