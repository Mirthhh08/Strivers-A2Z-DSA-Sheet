#include <bits/stdc++.h>
using namespace std;


// T.C. :- O(N)
string reverseWord(string s)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        string temp = "";

        while (s[i] != '.' && i < s.length())
        {
            temp += s[i];
            i++;
        }
        reverse(temp.begin(), temp.end());
        ans += temp;

        while (s[i] == '.')
        {
            ans += '.';
            i++;
        }
    }

    return ans;
}
int main()
{
    string s = "i.....like...thi..s.pro..gram.very...much";
    cout << reverseWord(s);

    return 0;
}