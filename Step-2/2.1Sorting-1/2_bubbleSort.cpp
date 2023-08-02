#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    bool check = false;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check = true;
            }
        }

        if (check != true)
        {
            break;
        }

        cout<<"runs\n";
    }
}
int main()
{
    int arr[10] = {1,2,3,8,5,6,7,8,9,10};

    bubbleSort(arr, 10);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}