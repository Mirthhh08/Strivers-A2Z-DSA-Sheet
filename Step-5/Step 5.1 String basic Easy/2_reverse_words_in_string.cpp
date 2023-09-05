#include <bits/stdc++.h>
using namespace std;

// brute force approach
// using stack
// T.C. :- O(N)
// S.C :- O(N)
string reverse_string(string S)
{
    stack<string> st;
    string ans = "";
    int n = S.length();
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (S[i] == '.')
        {
            st.push(temp);
            temp = "";
        }
        else
        {
            temp += S[i];
        }
    }
    st.push(temp);

    while (st.size() != 1)
    {
        ans += st.top() + ".";
        st.pop();
    }
    ans += st.top();

    return ans;
}

// optimal approach
// T.C. :- O(N)
// S.C :- O(1)
void reverseStr(string &s, int i, int j)
{
    if (i > j)
    {
        return;
    }

    swap(s[i], s[j]);
    reverseStr(s, i + 1, j - 1);
}
string reverse_string_optimal(string s)
{
    int i = 0, j = s.length() - 1;

    reverseStr(s, i, j);
    int f = 0;
    for (int k = 0; k < j; k++)
    {
        if (s[k] == '.')
        {
            reverseStr(s, f, k-1);
            f = k + 1;
        }
    }

    reverseStr(s, f, j);
    return s;
}
int main()
{
    string s = "i.like.this.program.very.much";

    // cout << reverse_string(s);
    cout << reverse_string_optimal(s);

    return 0;
}