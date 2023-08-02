#include<bits/stdc++.h>
using namespace std;

void findpalindrome(int n){
    int res = 0;
    int ans = n;
    while(n!=0)
    {
        res = (res * 10) + (n % 10);
        n = n/10;
    }

    if(res == ans)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main(){
    findpalindrome(-121);
return 0;
}