#include <bits/stdc++.h>
using namespace std;

int getBeauty(string s)
{
    if (s.length() == 1)
        return 0;

    int arr[26] = {0};

    int unique = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (arr[s[i] - 'a'] == 0)
            unique++;

        arr[s[i] - 'a']++;
    }

    if (unique > 1)
    {

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                mini = min(mini, arr[i]);
            }
            maxi = max(maxi, arr[i]);
        }

        return maxi - mini;
    }
    else
    {
        return 0;
    }
}
// brute force appraoch
// T.C. : O(N^3)
void beautySum(string s)
{
    // Your code goes here
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string subStr = "";
        for (int j = i; j < s.length(); j++)
        {

            subStr += s[j];

            ans += getBeauty(subStr);

            cout << "ans at substring => " << subStr << " : " << ans << endl;
        }
    }

    cout << "overall ans => " << ans;
}

int main()
{
    string s = "aaac";
    beautySum(s);
    return 0;
}