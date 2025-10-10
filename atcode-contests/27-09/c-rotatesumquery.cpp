#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q, aux, query, c, l, r, soma = 0;
    
    //lendo tudo
    cin >> n >> q;
    
    vector<int> a(2*n + 2), pre(2*n + 2);

    int left = 1, right = n;
    a[0] = 0; 

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }



    // // soma de prefixo com um vetor 2x o tam, com todas as somas de prefixos possiveis.
    // for(int i = 1; i <= n; i++){
    //     pre[i] += pre[i-1];
    // }

    for (int i = 1; i <= q; i++)
    {
        cin >> query;
        if(query == 1){ // Rotate
            cin >> c;
            for (int j = 1; j <= c; j++)
            {
                int temp = a[left];
                left++; 
                a[right+1] = temp;
                right++;
            }
        }
        else{ //Sum Query
            cin >> l >> r;
            int start_idx = left + l - 1;
            int end_idx = left + r - 1;
            soma = 0;
            for (int i = start_idx; i <= end_idx; i++)
                soma += a[i];

            cout << soma << endl;
        }
    }

    return 0;
}
