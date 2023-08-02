#include <bits/stdc++.h>
using namespace std;
int buySellStock(int prices[], int n)
{
    int mini = prices[0];
    int profit = 0;

    for (int i = 0; i < n; i++)
    {

        int cost = prices[i] - mini;
        profit = max(profit, cost);

        mini = min(mini, prices[i]);
    }

    return profit;
}
int main()
{
    int n = 5;
    int arr[n] = {100, 180, 260, 40, 321};
    cout << buySellStock(arr, n);
    return 0;
}