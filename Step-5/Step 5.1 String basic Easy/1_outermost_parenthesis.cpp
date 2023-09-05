#include <bits/stdc++.h>
using namespace std;

// brute force approach
// using stack
// T.C. :- O(N)
// S.C :- O(N)
string removeOuter(string &s)
{
    stack<char> st;
    string ans = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            if (st.size() > 0)
            {
                ans += c;
            }
            st.push(c);
        }
        else
        {
            st.pop();
            if (st.size() > 0)
            {
                ans += c;
            }
        }
    }

    return ans;
}


// optimal approach
// T.C. :- O(N)
// S.C :- O(1)
string removeOuter_optimal(string &s)
{

    string ans = "";
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == '(')
        {
            cnt++;
            if (cnt > 1)
            {
                ans += c;
            }
        }
        else
        {
            if (cnt > 1)
            {
                ans += c;
            }
            cnt--;
        }
    }

    return ans;
}
int main()
{
    string s = "(()())(())";

    // cout << removeOuter(s);
    cout << removeOuter_optimal(s);

    return 0;
}