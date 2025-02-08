#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, x, y;
    string directions;
    int cont = 0;
    vector<pair<int, int> > passadas;
    cin >> h >> w >> x >> y;

    char grid[h+3][w+3];

    for (int i = 1; i < h+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            cin >> grid[i][j];
        }       
    }
    cin >> directions;

    for (int i = 0; i < directions.size(); i++)
    {
        if(grid[x][y] == '@'){
            for (int i = 0; i < passadas.size(); i++)
            {
                if(x != passadas[i].first && y != passadas[i].second){
                    cont++;
                }
            }
            passadas.push_back(make_pair(x,y));
        }
        if (directions[i] == 'U' && grid[x-1][y] != '#')
        {
            x--;
        }else if (directions[i] == 'D' && grid[x+1][y] != '#')
        {
            x++;
        }else if (directions[i] == 'L' && grid[x][y-1] != '#')
        {
            y--;
        }else if (directions[i] == 'R' && grid[x][y+1] != '#')
        {
            y++;
        }

    }
    cout << x << ' ' << y << ' ' << cont << endl;
    
    return 0;
}