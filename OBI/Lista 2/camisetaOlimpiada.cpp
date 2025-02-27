#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, m, contp = 0, contm = 0;

    cin >> n;

    int t[n];

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        if (t[i] == 1)
        {
            contp++;
        }else{
            contm++;
        }
    }
    cin >> p >> m;

    if (contp == p && contm == m)
    {
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
    

    return 0;
}