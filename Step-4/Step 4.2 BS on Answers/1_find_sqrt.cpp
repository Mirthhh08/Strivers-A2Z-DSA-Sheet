#include <bits/stdc++.h>
using namespace std;
int findSqrt(int n)
{
    int low = 0, high = n;

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid == (n / mid))
            return mid;

        else if (mid < (n / mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}
int main()
{
    int n = 12;
    cout << findSqrt(n);
    return 0;
}