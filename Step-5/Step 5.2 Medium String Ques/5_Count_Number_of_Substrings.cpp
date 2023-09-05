#include <bits/stdc++.h>
using namespace std;
int solve(string s, int n, int k)
{
    int arr[26] = {0};
    int unique = 0, j = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[s[i] - 'a'] == 0)
            unique++;

        arr[s[i] - 'a']++;

        while (unique > k)
        {
            arr[s[j] - 'a']--;

            if (arr[s[j] - 'a'] == 0)
                unique--;
            j++;
        }

        count += j - i + 1;
        
    }

    return count;
}

// Optimal approach
// T.C. :- O(N)
// S.C. : O(1)
int numberOfSubstring(string s, int k)
{
    int n = s.length();
    return solve(s, n, k - 1) - solve(s, n, k);
}
int main()
{
    string s = "aba";
    int k = 2;
    cout << numberOfSubstring(s, k);
    return 0;
}