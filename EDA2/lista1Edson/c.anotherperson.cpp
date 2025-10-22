#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;

    int a[n+1]; 

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    // pq 51 1 ?
    int temp[51][1];

    for(int i=0;i<51;i++)
    {
        temp[i][0]=0;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(temp[a[i]][0]==0) //
          temp[a[i]][0] = i; 
        // temp[2][0] = 1; temp[1][0] = 2; temp[1][0] = 3; temp[4][0] = 4; temp[3][0] = 5;temp[3][0] = 6; temp[1][0] = 7
        // Indice da ultima ocorrencia de cada numéro
    }

    while(q--){
       int x;
       cin>>x;
       cout<<temp[x][0]<<" ";
       
       // Coloca a ultima saida para a primeira ocorrencia e soma todos os indices que vinham antes do indice
       for(int i=1;i<51;i++)
       {
            if(temp[i][0]<temp[x][0])
                 temp[i][0]++;
       }
       temp[x][0]=1;
    }
   
    cout << "\n";

    return 0;
}