#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

int t, n;
string enemy, gregor;


void solve(int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        // Da ponta esq
        if(gregor[i] == '1' && i == 0){
            if(enemy[i] == 0){
                sum++;
                enemy[i] = '2';
            }
            else if(enemy[i+1] == '1'){
                sum++;
                enemy[i+1] = '2';
            }
        }
        // Da ponta Dir
        else if(gregor[i] == '1' && i == n){
            if(enemy[i] == 0){
                sum++;
                enemy[i] = '2';
            }
            else if(enemy[i-1] == '1'){
                sum++;
                enemy[i-1] = '2';
            }
        }

        // Do meio
        if(gregor[i] == '1' && enemy[i] == '0'){
            sum++;
            enemy[i] = '2';
        }
        else if (gregor[i] == '1' && enemy[i-1] == '1'){
            sum++;
            enemy[i-1] = '2';
        }
        else if(gregor[i] == '1' && enemy[i+1] == '1'){
            sum++;
            enemy[i+1] = '2';
        }
    }

    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> enemy >> gregor;

        solve(n);
    }
    
    

    return 0;
}