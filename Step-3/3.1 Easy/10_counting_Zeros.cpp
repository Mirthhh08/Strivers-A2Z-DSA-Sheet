#include <bits/stdc++.h>
using namespace std;
int longestOnes(int n, int arr[], int k)
{
    int prevCnt = 0;
    int currCnt = 0;
    int kcnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 || kcnt < k)
        {
            currCnt++;
            if (arr[i] == 0)
                kcnt++;
        }
        else
        {

            prevCnt = max(currCnt, prevCnt);
            currCnt = 0;
            kcnt = 0;
        }
    }
    prevCnt = max(currCnt, prevCnt);
    return prevCnt;
}
int main()
{

    int n, k;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    cout<<longestOnes(n, arr, k);

    return 0;
}