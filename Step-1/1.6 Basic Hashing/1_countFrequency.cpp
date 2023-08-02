#include <bits/stdc++.h>
using namespace std;
// using unordered map
// T.C. : O(N)
// S.C. : O(N)
void frequencyCount1(vector<int> &arr, int N, int P)
{
    // code here
    unordered_map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > P)
        {
            continue;
        }
        else
        {
            mp[arr[i]]++;
        }
    }

    arr.clear();

    for (int i = 1; i <= N; i++)
    {
        arr.push_back(mp[i]);
    }
}

// optimized approach
// T.C. : O(N)
// S.C. : O(1)

// Implementation
/*
1.Traverse the array from start to end.

2.For each element check if the element is less than or equal to zero or not. If negative or zero skip the element as it is the frequency and if the element is greater than N or P then also, because no need to calculate its frequency according to question states.

3.If an element (e = array[i] – 1 ) is positive, then check if array[e] is positive or not. If positive then that means it is the first occurrence of e in the array and replaces array[i] with array[e], i.earray[i] = array[e] and assign array[e] = -1. If array[e] is negative, then it is not the first occurrence, the update array[e] as array[e]– and update array[i] as array[i] = 0.

4.Again, traverse the array and check if element is negative that menas it is frequency so make them positive else if element is already positive that means is it skipped element(i.e it is greater than P or N) so make them zero because no need to calculate the frequency of these elements.
*/

void frequencyCount2(vector<int> &arr, int N, int P)
{
    int i = 0;
    while (i < N)
    {
        // check if arr[i] < 0 or >N and >p then increase i and move to next iteration
        if (arr[i] <= 0 || arr[i] > N || arr[i] > P)
        {
            i++;
            continue;
        }

        int elementIdx = arr[i] - 1;

        if (arr[elementIdx] > 0)
        {
            arr[i] = arr[elementIdx];

            arr[elementIdx] = -1;
        }
        else
        {

            arr[elementIdx]--;
            arr[i] = 0;
            i++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
            arr[i] = -arr[i];
        else
            arr[i] = 0;
    }
}
int main()
{
    int N = 5;
    int P = 5;
    vector<int> arr{2, 3, 2, 3, 5};
    // frequencyCount1(arr, N, P);

    frequencyCount2(arr, N, P);
    for (auto it : arr)
    {
        cout << it << endl;
    }
    return 0;
}