#include <bits/stdc++.h>
using namespace std;

void hashing(int arr[], int n)
{
    int hash_map[n] = {0};

    for (int i = 0; i < n; i++)
    {
        hash_map[arr[i]]++;
    }

    for (auto it : hash_map)
    {
        cout << it << endl;
    }
}

// chracter hashing

void character_hashing(string s, char c)
{

    int n = s.length();

    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    cout << endl;
    cout << hash[c];
}

//  hashing for numbers greater than 10^9
//  using map

void hashing_map(int arr[], int n, int num)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << "->" << it.second << endl;
    }
}


//  hashing for characters
//  using map
void character_hashing_using_map(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// using unordered_map
void hashingUsingUnorderedMap(int arr[], int n, int num)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << "->" << it.second << endl;
    }
}


int main()
{
    int arr[10] = {1, 2, 1, 3, 1, 1, 4, 2, 5};

    // hashing(arr, 10);
    // character_hashing("mirtthhHhh", 'h');

    hashing_map(arr, 10, 1);

    character_hashing_using_map("mirthdffaeqqrrrdfgmmnn");
    return 0;
}