#include <bits/stdc++.h>
using namespace std;
// using unordered-map
// T.C. : O(N *logN)
// S.C. : O(N)
void highestFrequency(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    vector<pair<int, int>> v;

    for (auto it : mp)
    {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (auto it : v)
    {
        cout << it.second << " -> " << it.first << endl;
    }
}

// using max-Heap
// T.C. -> O(K log(N))   (avg and best case) -- in most caseses
// In worst case K == N then T.C. -> O(N log(N)) -- in very rare case
// Auxilary space -> O(N)
struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;

        return p1.second < p2.second;
    }
};
void highestFrequency2(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap(mp.begin(), mp.end());

    for (int i = 1; i <= k; i++)
    {
        cout << heap.top().first << " -> " << heap.top().second << endl;
        heap.pop();
    }
}
int main()
{
    vector<int> arr{1, 1, 1, 2, 2, 3};
    highestFrequency2(arr, 2);
    return 0;
}