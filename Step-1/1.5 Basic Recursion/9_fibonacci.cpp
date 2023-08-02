#include <bits/stdc++.h>
using namespace std;

// using iteration
vector<int> fib(int n)
{
    vector<int> ans;
    if(n>=0)
    {
        ans.push_back(0);
    }
    if (n >= 1)
    {
        ans.push_back(1);
    }

    int a = 0, b = 1;
    for (int i = 1; i < n; i++)
    {
        ans.push_back(a + b);
        int c = a + b;

        a = b;
        b = c;
    }

    return ans;
}

// using recursion
int fibonnaci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonnaci(n - 1) + fibonnaci(n - 2);
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << fibonnaci(i) << " ";
    }

    cout << endl;

    vector<int> fibo = fib(10);

    for(auto it: fibo)
    {
        cout << it << " ";
    }
    return 0;
}