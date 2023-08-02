#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C. :- O(N)
// S.C. :- O(N)
void reaarangeAleternately(int arr[], int n)
{
    vector<int> ans;
    int str = 0, end = n - 1;

    while (str < end)
    {
        ans.push_back(arr[end]);
        ans.push_back(arr[str]);

        end--;
        str++;
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};

    reaarangeAleternately(arr, n);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    return 0;
}