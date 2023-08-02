#include <bits/stdc++.h>
using namespace std;
void printNos(int N)
{
    if (N == 0)
    {
        return;
    }

    printNos(N - 1);
    cout << N << " ";
}
int main()
{
    printNos(5);
    return 0;
}