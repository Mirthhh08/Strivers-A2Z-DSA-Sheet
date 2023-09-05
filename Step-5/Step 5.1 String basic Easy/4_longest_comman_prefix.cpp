#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. ->  O(N^2) where N is len of string
vector<int> largest_prefix(string str1, string str2)
{
    int n = str1.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = i;
        while (j < n && k < n && str1[j] == str2[k])
        {
            j++;
            k++;
        }

        maxLen = max(maxLen, j);
    }

    if (maxLen == 0)
    {
        return {-1, -1};
    }
    else
    {
        return {0, maxLen - 1};
    }
}
int main()
{
    string str1 = "geeks";
    string str2 = "dgeek";

    vector<int> ans = largest_prefix(str1, str2);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}