#include <bits/stdc++.h>
using namespace std;

//  brute force appraoch
// T.C. :- O(N^2)
// S.C. :- O(1)
bool linearSearch(vector<int> arr, int val)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == val)
            return true;
    }
    return false;
}
int longestSubseq(vector<int> arr)
{
    int maxlen = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 1;
        int val = arr[i];

        while (linearSearch(arr, val + 1) == true)
        {
            val = val + 1;
            cnt = cnt + 1;
        }

        maxlen = max(cnt, maxlen);
    }

    return maxlen;
}

// better approach
// T.C. :- O(Nlog(N)
// S.C. :- O(1)
int longestSubseq_better(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    int maxlen = 1;
    int lastsml = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (lastsml + 1 == arr[i])
        {
            lastsml = arr[i];
            cnt++;
        }
        else if (arr[i] != lastsml)
        {
            cnt = 1;
            lastsml = arr[i];
        }

        maxlen = max(maxlen, cnt);
    }

    return maxlen;
}

// optimal appraoch
// using set
// T.C. :- O(N)
// S.C. :- O(N)

void longestSubseq_optimal(vector<int> arr)
{
    unordered_set<int> st;
    int maxlen = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }

            maxlen = max(maxlen, cnt);
        }
    }


    
    cout<< maxlen;
}
int main()
{
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    // cout << longestSubseq(arr);
    longestSubseq_optimal(arr);
    return 0;
}