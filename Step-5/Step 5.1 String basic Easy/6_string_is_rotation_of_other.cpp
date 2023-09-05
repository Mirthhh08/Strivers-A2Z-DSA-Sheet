#include <bits/stdc++.h>

using namespace std;
// brute force approach
// T.C. :- O(N * (M - 1))
// S.C. :- O(1)
void rotate(string &s)
{
    int n = s.length();

    char temp = s[0];

    for (int i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    }

    s[n - 1] = temp;
}
bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    if (s1 == s2)
        return true;

    int n = s1.length();

    for (int i = 0; i < n; i++)
    {
        rotate(s2);
        if (s1 == s2)
            return true;
    }
    return false;
}
// optimal approach
// T.C. :- o(N)
// Auxiliary space : O(N + N)
bool areRotations_optimal(string s1, string s2){
    string temp = s1 + s1;

    if(temp.find(s2)!=string::npos)
    {
        return true;
    }

    return false;
}
int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "forgeeksgeeks";

    // cout << areRotations(s1, s2);
    cout << areRotations_optimal(s1, s2);
    return 0;
}