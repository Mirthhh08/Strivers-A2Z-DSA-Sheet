#include <bits/stdc++.h>
using namespace std;
int value(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;
    else
        return 0;
}

// T.C. : O(N)
int roman_to_number(string s)
{
    int ans = 0;
    int currVal = 0, prevVal = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        currVal = value(s[i]);

        if (prevVal > currVal)
        {
            ans -= currVal;
        }
        else
        {
            ans += currVal;
        }

        prevVal = currVal;
    }

    return ans;
}
// another approach using map
// T.C. :O(N);
int roman_to_number_using_map(string s)
{
    map<char, int> mp;

    mp.insert({'I', 1});
    mp.insert({'V', 5});
    mp.insert({'X', 10});
    mp.insert({'L', 50});
    mp.insert({'C', 100});
    mp.insert({'D', 500});
    mp.insert({'M', 1000});
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {

        if (mp[s[i]] < mp[s[i + 1]])
        {
            ans += mp[s[i + 1]] - mp[s[i]];
            i++;
        }
        else
        {
            ans += mp[s[i]];
        }
    }

    return ans;
}
int main()
{
    string s = "MCMXCIV";
    cout << roman_to_number(s)<<endl;
    cout << roman_to_number_using_map(s);

    return 0;
}