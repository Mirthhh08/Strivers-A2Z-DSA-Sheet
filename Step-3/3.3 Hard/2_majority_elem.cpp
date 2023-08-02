#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N^2)
// S.C. :- O(1)
vector<int> majorityElem_brute(vector<int> arr)
{
    int n = arr.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != arr[i])
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                    cnt++;
            }

            if (cnt > n / 3)
                ans.push_back(arr[i]);
        }

        if (ans.size() == 2)
            break;
    }

    if (ans.size() > 0)
        return ans;
    else
        return {-1};
}

// betterapproach
// T.C. :- O(N)(in most cases) && O(N^2) (in very rare case)
// S.C. :- O(N)
vector<int> majorityElem_better(vector<int> arr)
{

    unordered_map<int, int> mp;
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;

        if (mp[arr[i]] > n / 3 && (ans.size() == 0 || ans[0] != arr[i]))
            ans.push_back(arr[i]);

        if (ans.size() == 2)
            break;
    }

    if (ans.size() > 0)
        return ans;
    else
        return {-1};
}

// optiamal approach
// T.C. :- O(N)
// S.C. :- O(1)
// using moore's voting algorithm
vector<int> majorityElem_optimal(vector<int> arr)
{
    int ele1, ele2;
    int cnt1 = 0, cnt2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0)
        {
            ele1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            ele2 = arr[i];
            cnt2 = 1;
        }

        else if (ele1 == arr[i])
            cnt1++;

        else if (ele2 == arr[i])
            cnt2++;

        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (ele1 == arr[i])
            cnt1++;

        else if (ele2 == arr[i])
            cnt2++;
    }

    if (cnt1 > n / 3)
        ans.push_back(ele1);

    if (cnt2 > n / 3)
        ans.push_back(ele2);



    if (ans.size() > 0)
        return ans;
    else
        return {-1};
}
int main()
{
    vector<int> arr{1, 2};

    // vector<int> ans = majorityElem_brute(arr);
    // vector<int> ans = majorityElem_better(arr);

     vector<int> ans = majorityElem_optimal(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}