#include <bits/stdc++.h>
using namespace std;
int implement_atoi(string str)
{

    int ans = 0;
    int start = 0;
    bool isNegative = false;
    if (str[0] == '-')
    {
        start = 1;
        isNegative = true;
    }

    for (int i = start; i < str.length(); i++)
    {
        char c = str[i];

        if (c >= '0' && c <= '9')
        {
            ans = (ans * 10) + (c - '0');
        }
        else
        {
            return -1;
        }
    }

    if (isNegative)
        ans *= -1;

    return ans;
}


int main()
{
    string str = "-782343";
    cout << implement_atoi(str);
    return 0;
}