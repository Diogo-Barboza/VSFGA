#include <bits/stdc++.h>
using namespace std;

int fibb(int n){
    if(n == 0)
        return 0;
    if(n == 1){
        return 1;
    }
    return (fibb(n-1) + fibb(n));
}

int main() {
    // int ent = 0;

    // for (int i = 0; i < ent; i++)
    // {
        
    // }

    cout << fibb(4) << endl;
    


    return 0;
}