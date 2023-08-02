#include <bits/stdc++.h>
using namespace std;
// bruteforce approach
// T.C : O(NlogN)

int second_largest_element(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    return arr[n - 2];
}


// best approach
// T.C. : O(N)
// S.C. : O(1)

int second_largest(vector<int> arr)
{
    int n = arr.size();
    
    int max1 = 0 , max2 = 0;


    for(int i = 0; i<n; i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }

        if(arr[i] > max2 && max1 != arr[i])
        {
            max2 = arr[i];
        }
    }

    return max2;
}

int main()
{
    vector<int> arr = {10, 12, 1, 19, 89, 90, 32, 67, 23, 43, 13, 87, 9};
    // cout<<second_largest_element(arr);
    cout<<second_largest(arr);
    return 0;
}