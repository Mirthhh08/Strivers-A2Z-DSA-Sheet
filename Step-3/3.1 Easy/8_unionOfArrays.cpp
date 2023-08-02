#include <bits/stdc++.h>
using namespace std;
// brute force appraoch
// using set

// T.C. : O(Nlog(N) + M log(M))
// log(N){ insert element in set } and N elements
// So,  T.C. : O(Nlog(N) + M log(M))

// S.C. :O(N+M)
void UnionOfArrays(int arr1[], int arr2[], int n, int m)
{
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }

    for (auto it : s)
    {
        cout << it << " ";
    }
}

// optimal approach
// two pointer appr.

// T.C. : O(N + M )

// S.C. :O(N+M) (in order to return)

void UnionOfArrays_optimal(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[3] = {1, 2, 3};
    // UnionOfArrays(arr1 , arr2 , 5 , 3);
    UnionOfArrays_optimal(arr1, arr2, 5, 3);
    return 0;
}