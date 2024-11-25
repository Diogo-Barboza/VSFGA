#include <bits/stdc++.h>
using namespace std;

int main(){
    float palcool = 0, pgasolia = 0, calcool = 0, cgasolina = 0;

    cin >> palcool >> pgasolia >> calcool >> cgasolina;

    if ((palcool/calcool) < (pgasolia/cgasolina)){
        cout << "A" << endl;
    }else
    {
        cout << "G" << endl;
    }
    
    return 0;
}