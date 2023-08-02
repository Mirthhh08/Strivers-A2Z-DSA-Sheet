#include <bits/stdc++.h>
using namespace std;
int isPalindrome(string &s, int i)
{
    if (i >= s.size() / 2)
    {
        return 1;
    }


    if(s[i]!=s[s.size() - i - 1])return 0;

    isPalindrome(s , i+1);
}
int main()
{
    string s = "madsdfam";
    cout<<isPalindrome(s, 0);
    return 0;
}