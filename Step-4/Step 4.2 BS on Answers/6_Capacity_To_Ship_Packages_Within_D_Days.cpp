#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int N, int D, int weight)
{
    int totalWei = 0;
    int dayCnt = 1;

    for (int i = 0; i < N; i++)
    {
        if (totalWei + arr[i] <= weight)
        {
            totalWei += arr[i];
        }
        else
        {

            dayCnt++;

            if (dayCnt > D || arr[i] > weight)
                return false;

            totalWei = arr[i];
        }
    }

    return true;
}
int findMax(int arr[], int N)
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int leastWeightCapacity(int arr[], int N, int D)
{
    // code here

    int low = 1, high = findMax(arr, N);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, N, D, mid))
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
    int N = 3;
    int arr[] = {1, 2, 1};
    int D = 2;
    cout << leastWeightCapacity(arr, N, D);
    return 0;
}