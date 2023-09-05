#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(NlogN)
// S.C. :- O(N)
string frequencySort(string s)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    priority_queue<pair<int, char>> q;

    for (auto it : mp)
    {
        q.push({it.second, it.first});
    }

    string res = "";

    while (!q.empty())
    {
        int freq = q.top().first;

        while (freq--)
        {
            res += q.top().second;
        }
        q.pop();
    }

    return res;
}

string frequencySort_another_approach(string s)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    vector<vector<char>> bucket(mp.size() + 1);

    for (auto it : mp)
    {
        char key = it.first;
        int freq = it.second;

        bucket[freq].push_back(key);
    }

    string res = "";

    for (int i = bucket.size() - 1; i >= 0; i--)
    {
        if (!bucket[i].empty())
        {
            for (char c : bucket[i])
            {
                int freq = i;
                while (freq--)
                {
                    res += c;
                }
            }
        }
    }

    return res;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s);
    return 0;
}