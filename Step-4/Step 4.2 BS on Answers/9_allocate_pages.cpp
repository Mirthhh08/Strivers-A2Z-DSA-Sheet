#include <bits/stdc++.h>
using namespace std;

int sum(int n, int a[])
{
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        temp += a[i];
    }
    return temp;
}
bool isPossible(int n, int a[], int m, int pages)
{
    int stdCnt = 1, pgCnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (pgCnt + a[i] <= pages)
        {
            pgCnt += a[i];
        }
        else
        {
            stdCnt++;

            if (stdCnt > m || a[i] > pages)
            {
                return false;
            }

            pgCnt = a[i];
        }
    }
    return true;
}
int allocate_pages_optimal(int n, int a[], int m)
{
    if (m > n)
        return -1;
    int low = 1, high = sum(n, a);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(n, a, m, mid))
        {
            ans = mid;
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
    int n = 4;
    int a[] = {12, 34, 67, 90};
    int m = 2;
    cout << allocate_pages_optimal(n, a, m);
    return 0;
}