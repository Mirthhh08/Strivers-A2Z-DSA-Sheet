#include <bits/stdc++.h>
using namespace std;
void printNos(int N)
{
    if (N == 0)
    {
        return;
    }
    cout << N << " ";
    printNos(N - 1);
    
}
int main()
{
    printNos(5);
    return 0;
}