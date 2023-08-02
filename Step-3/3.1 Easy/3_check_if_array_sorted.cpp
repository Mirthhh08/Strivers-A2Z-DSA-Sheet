#include <bits/stdc++.h>
using namespace std;
// T.C : O(N)

// S.C : O(1)
bool arraySortedOrNot(vector<int> arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}
int main()
{
    vector<int> arr = {10, 12, 1, 19, 89, 90, 32, 67, 23, 43, 13, 87, 9};
    int n = arr.size();
    cout << arraySortedOrNot(arr , n);
    return 0;
}