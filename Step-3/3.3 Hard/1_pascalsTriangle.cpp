#include <bits/stdc++.h>
using namespace std;

// problem type - 1
// given row and col return the element

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
// brute force appraoch
int problemType_1(int n, int c)
{

    if (n < c)
        return -1;

    return (factorial(n - 1) / (factorial(c - 1) * factorial((n - 1) - (c - 1))));
}
// optimal apprach
int problemType_1_optimal(int n, int c)
{
    n = n - 1;
    c = c - 1;
    int res = 1;
    for (int i = 0; i < c; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

// problem type 2
// print the nth row

void printRow_optimal(int n)
{
    n = n - 1;

    int res = 1;
    cout << res << " ";
    for (int i = 0; i < n; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
        cout << res << " ";
    }
}

// problem type 3
int nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}
vector<vector<int>> problemType_3(int n)
{
    vector<vector<int>> ans;

    for (int row = 0; row <= n; row++)
    {
        vector<int> temp;

        for (int col = 1; col <= row; col++)
        {
            temp.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<int> problemType_3_optimal(int n)
{
    vector<int> ans;
    n = n - 1;
    int res = 1;
    ans.push_back(res);
    for (int i = 0; i < n; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
        ans.push_back(res);
    }

    return ans;
}
int main()
{

    // cout << problemType_1_optimal(5, 5);

    int n = 10;

    // printRow_optimal(n);
    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(problemType_3_optimal(i));
    }
    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}