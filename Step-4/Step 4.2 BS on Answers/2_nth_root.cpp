#include <bits/stdc++.h>
using namespace std;
int helper(int n, int m, int mid)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = mid * ans;

        if (ans > m)
            return 2;
    }

    if (ans == m)
        return 1;

    return 0;
}
int findNthRoot(int n, int m)
{
    int low = 0;
    int high = m;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int temp = helper(n , m , mid);

        if (temp == 1)
        {
            return mid;
        }
        else if (temp == 2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main()
{
    int n = 6, m = 4096;

    cout << findNthRoot(n, m);
    return 0;
}