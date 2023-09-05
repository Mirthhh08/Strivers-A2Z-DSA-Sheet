#include <bits/stdc++.h>
using namespace std;


// T.C. :- O(N)
// S.C. :- O(1)
int maxDepth(string s)
{
    int depth = 0, cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == '(')
        {
            cnt++;
        }
        if (c == ')')
        {
            cnt--;
        }

        depth = max(depth, cnt);
    }

    return depth;
}
int main()
{
    string s = "((5+2)(3+4)((6)))";
    cout << maxDepth(s);
    return 0;
}