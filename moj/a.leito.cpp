#include <bits/stdc++.h>

using namespace std;

void solve(int t){
    // 3h
    // 5h
    // 12h
    // monotira sinais

    if(t % 3 == 0)
        cout << "Troca do soro" << "\n";
    if(t % 5 == 0)
        cout << "Injecao de antibioticos" << "\n";
    if(t % 12 == 0)
        cout << "Reavaliacao" << "\n";
    if(t % 12 != 0 && t % 5 != 0 && t % 3 != 0)
        cout << "Monitoramento dos sinais vitais" << "\n";
}


int main(){
    int t;

    cin >> t;

    cout << t << " horas de tratamento:" << "\n";

    solve(t);

    return 0;
}