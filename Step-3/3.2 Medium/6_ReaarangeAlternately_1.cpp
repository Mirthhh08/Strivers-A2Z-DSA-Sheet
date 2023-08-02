#include <bits/stdc++.h>
using namespace std;
// bruteforce approach
// T.C. :- O(N) + O(N)
// S.C :- O(N)

int reaarangeAleternately(int arr[], int n)
{
    int pos[n / 2];
    int neg[n / 2];
    int p_idx = 0, n_idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos[p_idx++] = arr[i];
        }
        else
        {
            neg[n_idx++] = arr[i];
        }
    }

    int idx = 0;
    p_idx = 0, n_idx = 0;
    while (idx < n)
    {
        arr[idx++] = pos[p_idx++];
        arr[idx++] = neg[n_idx++];
    }
}

// optimal approach
// will try to do this in one pass
// T.C. :- O(N) + O(N)
// S.C :- O(N)

int reaarangeAleternately_optimal(int arr[], int n)
{
    int ans[n];
    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[pos] = arr[i];
            pos += 2;
        }
        else
        {
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    int idx = 0;
    for (auto it : ans)
    {
        arr[idx++] = it;
    }
}
int main()
{
    int n = 8;
    int arr[n] = {1, -2, -3, -4, 5, 6 , 7 , 8} ;

    // reaarangeAleternately(arr, n);
    reaarangeAleternately_optimal(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}