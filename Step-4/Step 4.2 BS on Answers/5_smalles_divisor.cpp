#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &nums, int k, int num)
{

    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= num)
        {
            ans += 1;
        }
        else
        {

            ans += ceil((double)nums[i] / (double)num);
        }

        if (ans > k)
            return false;
    }

    return true;
}

int findMax(vector<int> &nums)
{
    int temp = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        temp = max(temp, nums[i]);
    }

    return temp;
}


// optimal appraoch
// T.C. :- O(log(maxarr) * N);
//  S.C. :- O(1)
int smallestDivisor(vector<int> &nums, int K)
{

    int low = 1, high = findMax(nums);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, K, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> nums{1, 2, 5, 9};
    int k = 6;

    cout << smallestDivisor(nums, k);

    return 0;
}