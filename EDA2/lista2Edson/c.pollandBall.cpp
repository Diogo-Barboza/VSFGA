#include <bits/stdc++.h>
#define MAX 100
using namespace std;

bool isPrime(int num){
    int teto = sqrt(num);
    for (int i = 2; i <= teto; i++)
        if(num % i == 0 && num != i){
            return false;
        }
            
    return true;
}

int solve(int n){
    int res = 129038901;
    for (int i = 1; i <= MAX; i++){
        if(!isPrime((n * i) + 1)){
            res =  i;
            return res;
        } 
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    int n;

    cin >> n;

    cout << solve(n) << "\n";

    return 0;
}