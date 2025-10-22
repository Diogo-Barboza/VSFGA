#include <iostream>

using namespace std;
using ll = long long;

ll ps(ll n){

    if(n == 1) return 1;

    ll soma = n;

    while(n != 2 && n != 3){
        soma += n/2;
        n = n/2;
    }

    return soma + 1;
}

int main() {

    int n;
    ll input;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> input;
        cout << ps(input) << "\n";
    }
    

    return 0;
}