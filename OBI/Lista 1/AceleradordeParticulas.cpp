#include <bits/stdc++.h>
using namespace std;

int main(){
    int d = 0;

    cin >> d;

    d = (d-3) % 8;

    if (d <= 3)
    {
        cout << "1";
    }else if (d <= 4)
    {
        cout << "2";
    }else{
        cout << "3";
    }
    
    cout << endl;
    
    return 0;
}