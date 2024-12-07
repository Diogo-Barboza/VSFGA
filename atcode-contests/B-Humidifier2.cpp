#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, d;
    unordered_map<int, int> cord;

    cin >> h >> w >> d;
    char tab[h][w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j])
            {
                cord.insert(make_pair(i, j));
            }
        }
    }
    
    return 0;
} // Nao consegui terminar...