#include <bits/stdc++.h>
using namespace std;
// brute force appraoch
vector<int> leadersInArray(int arr[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                check = false;
            }
        }

        if (check == true)
        {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

vector<int> leadersInArray_optimal(int arr[], int n)
{
    int leader = INT_MIN;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        leader = max(leader, arr[i]);
        ans.push_back(leader);
    }
}
int main()
{
    int n = 5;
    int arr[n] = {16, 17, 8, 9, 1};
    // vector<int> ans = leadersInArray(arr, n);
     vector<int> ans = leadersInArray_optimal(arr, n);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}