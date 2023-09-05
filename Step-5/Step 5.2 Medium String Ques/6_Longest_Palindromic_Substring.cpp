#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    string temp = s;

    reverse(temp.begin(), temp.end());

    return temp == s;
}
string longest_Palindromic_Substring(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];

            if (isPalindrome(temp))
            {
                if (temp.length() > ans.length())
                {
                    ans = temp;
                }
            }
        }
    }

    return ans;
}

int main()
{
    string S = "aaaabbaa";
    cout << longest_Palindromic_Substring(S);

    return 0;
}