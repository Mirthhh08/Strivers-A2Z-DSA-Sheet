#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C. :- O(N^3)
// S.C. :- O(1)
vector<vector<int>> three_sum_brute(int n, int x, int arr[])
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (k != i && k != j)
                {
                    if (arr[i] + arr[j] + arr[k] == x)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// better approach
// using hashing
// T.C. :- O(N^2 logM)
// S.C. :- O(N)
vector<vector<int>> three_sum_better(int n, int x, int arr[])
{

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = x - (arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// optimal approach
// using hashing
// T.C. :- O(N^2 logM)
// S.C. :- O(N)
vector<vector<int>> three_sum_optimal(int n, int x, int arr[])
{
    vector<vector<int>> ans;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] == x)
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;

                while (j < k && arr[k] == arr[k + 1])
                    k++;
            }

            else if (arr[i] + arr[j] + arr[k] < x)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return ans;
}

int main()
{
    int n = 5, x = 10;
    int arr[n] = {1, 2, 4, 3, 6};

    // vector<vector<int>> ans = three_sum_brute(n, x, arr);

    // vector<vector<int>> ans = three_sum_better(n, x, arr);

    vector<vector<int>> ans = three_sum_optimal(n, x, arr);
    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
    }

    
    return 0;
}