#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &arr, int n)
{
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i > idx; i--)
    {
        if (arr[i] > arr[idx])
        {
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());
    return arr;
}
int main()
{
    int n = 6;
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextPermutation(arr, n);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}