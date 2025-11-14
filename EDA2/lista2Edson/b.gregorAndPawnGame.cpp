#include <bits/stdc++.h>
using namespace std;

int t, n;
string gregor, enemy;


int solve(int n){ // Linear
    int sum = 0;
    for (int i = 0; i < n; i++){
        if(gregor[i] == '1'){
            if(enemy[i] == '0'){ // Reto
                sum++;
                enemy[i] = '2';
            }
            else if(i > 0 && enemy[i-1] == '1'){ // Diagonal Esq
                sum++;
                enemy[i-1] = '2';
            }
            else if(i < n && enemy[i+1] == '1'){ // Diagonal Dir
                sum++;
                enemy[i+1] = '2';
            }
        }
    } 

    return sum;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> enemy >> gregor;
        
        cout << solve(n) << "\n";
    }
    
    

    return 0;
}