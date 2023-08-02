#include<bits/stdc++.h>
using namespace std;
void printGfg(int N) {
        
        if(N==0)
        {
            return;
        }
    
        printGfg(N - 1);
        cout<<"GFG ";
    }

int main(){
    printGfg(5);
return 0;
}