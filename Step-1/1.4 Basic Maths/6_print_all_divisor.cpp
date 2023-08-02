#include <bits/stdc++.h>
using namespace std;
void printAllDivisor(int n)
{
    vector<int>ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            ans.push_back(i);


            if(n/i != i)
            {
                ans.push_back(n/i);
            }
        }
    }

    sort(ans.begin() , ans.end());


    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
int main()
{
    printAllDivisor(36);

    return 0;
}