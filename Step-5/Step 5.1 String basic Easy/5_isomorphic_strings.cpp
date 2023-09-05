#include <bits/stdc++.h>
using namespace std;

// T.C. :- O(N)
// S.C :-O(N + M)
bool isomorphicString(string str1, string str2)
{
    int n = str1.length();

    unordered_map<char, char> mp;
    unordered_map<char, bool> mp2;

    for (int i = 0; i < n; i++)
    {
        char x = str1[i];
        char y = str2[i];

        if (mp.find(x) != mp.end())
        {
            if (mp[x] != y)
            {
                return false;
            }
        }
        else
        {
            if (mp2.find(y) != mp2.end())
            {
                return false;
            }
            else
            {
                mp[x] = y;
                mp2[y] = true;
            }
        }
    }

    return true;
}
int main()
{
    string str1 = "aab";
    string str2 = "xxy";
    cout << isomorphicString(str1, str2);
    return 0;
}