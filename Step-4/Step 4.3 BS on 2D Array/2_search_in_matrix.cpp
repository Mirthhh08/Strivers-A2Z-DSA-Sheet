#include <bits/stdc++.h>
using namespace std;

bool searchInMatrix(int n, int m, int x, vector<vector<int>> matrix)
{
    int low = 0, high = m - 1;

    while (low < n && high >= 0)
    {
        if (matrix[low][high] == x)
        {
            return true;
        }
        else if (matrix[low][high] > x)
        {
            high--;
        }
        else
        {
            low++;
        }
    }

    return false;
}
int main()
{
    int n = 3, m = 3, x = 62;
    vector<vector<int>> arr = {{3, 30, 38},
                               {36, 43, 60},
                               {40, 51, 69}};

    cout << searchInMatrix(n, m, x, arr);
    return 0;
}