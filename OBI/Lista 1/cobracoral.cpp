#include <bits/stdc++.h>
using namespace std;

int main(){
    char a, b, c, d;

    cin >> a >> b >> c >> d;

    if((a == c && b != d) || (a != c && b == d)){
        cout << "V" << endl;
    }else{
        cout << "F" << endl;
    }
    
    return 0;
}