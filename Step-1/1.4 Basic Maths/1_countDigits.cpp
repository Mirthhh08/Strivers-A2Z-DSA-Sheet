#include <bits/stdc++.h>
using namespace std;
// approach 1
int countDigit1(int n){
    
    int cnt = 0;
    while(n > 0)
    {
        n = n/10;
        cnt++;
    }
    return cnt;
}

// approach 2

int countDigit2(int n)
{
    string x = to_string(n);
    return x.length();
}


// approach 3


int countDigit3(int n){
    
    return floor(log10(n) + 1);

}
int main()
{
    cout<<countDigit1(12345)<<endl;
    cout<<countDigit2(12345)<<endl;
    cout<<countDigit3(12345)<<endl;

    return 0;
}