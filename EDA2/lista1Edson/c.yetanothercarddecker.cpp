#include <bits/stdc++.h>

using namespace std;
const int MAX = {51};
const int MIN = {1};
int vs[MAX][MIN];

void criaGrafo(vector<int> const &olha, int n){
    // Limpo os TODOS os indices
    for (int i = 0; i < MAX; ++i)
        vs[i][0] = 0;

    // Coloco os índices da primeira ocorrencia de cada
    for (int i = 1; i <= n; i++){
        if (vs[olha[i]][0] == 0)
            vs[olha[i]][0] = i;
    }
}

int solve(vector<int> const &olha, int q){

    int ans = vs[q][0]; 
    
    // Atualiza os indices menores q a resposta;
    for(int i = 1; i < MAX; i++){
        if(vs[i][0] < ans)
        vs[i][0]++;
    }
    
    vs[q][0] = 1;

    return ans;
}

int main()
{

    ios::sync_with_stdio(false);

    int n, q, aux;
    cin >> n >> q;

    vector<int> src(n+1);

    for (int i = 1; i <= n; i++){
        cin >> src[i];        
    }

    criaGrafo(src, n);

    for (int j = 0; j < q; j++)
    {
        cin >> aux;
        cout << solve(src, aux) << " ";
    }

    cout << "\n";

    return 0;
}