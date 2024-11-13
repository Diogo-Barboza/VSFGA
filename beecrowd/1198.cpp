#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a = 0, b = 0, dif = 0;
    
    while (cin >> a >> b)
    {
        dif = b - a;
        if(dif < 0)
            dif = dif * (-1);

        cout << dif << endl;
        
    }

    return 0;
}