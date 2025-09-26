#include <iostream>
using namespace std;

struct BST {
    struct No {
        char dado;
        No *esq, *dir;
    };

    No *raiz;

    BST(): raiz(nullptr) {}

    void posOrdem(const No *no) const {
        if(no) {
            posOrdem(no -> esq);
            posOrdem(no -> dir);
            cout << no -> dado;
        }
    }

    void insere(char dado, const int rank[]){
        No **no = &raiz; // n sei o q faz

        while(*no){
            if((*no) -> dado == dado) 
                return;
            else if(rank[dado - 'A' < rank[(*no) -> dado - 'A']])
                no = &(*no) -> esq;
            else
                no = &(*no) -> dir;
        }

        *no = new No { dado, nullptr, nullptr };

    }
};



int main(){

    string preOrdem, emOrdem;

    while(cin >> preOrdem >> emOrdem){
        int rank[30], nxt = 1;

        for(const auto& c : emOrdem)
            rank[c - 'A'] = nxt++;
    
        BST arvore;

        for(const auto& c : preOrdem)
            arvore.insere(c, rank);

        arvore.posOrdem(arvore.raiz);

        cout << "\n";

    }

    return 0;

}
