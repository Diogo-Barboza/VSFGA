#include <bits/stdc++.h>
using namespace std;

bool Swap(string str, int start, int curr){
    for (int i = start; i < curr; i++)
    {
        if(str[i] == str[curr]){
            return 0;
        }
    }
    return 1;
}

int total = 0;
int achou = 0;

int findPerm(string str, string buffer,  int index, int n){
    if(index >= n){
        cout << str << " BUFF " << buffer << endl;
        if(str != buffer){
            cout << total++;
        }
    }

    for(int i = index; i < n; i++){
        bool check = Swap(str, index, i);
        if(check){
            swap(str[index], str[i]);
            findPerm(str, buffer, index + 1, n);
            swap(str[index], str[i]);
        }
    }
    return achou;
}

int main(){
    string entrada, buffer;

    cin >> entrada;
    buffer = entrada;
    sort(entrada.begin(), entrada.end());

    int tam = entrada.length();

    findPerm(entrada, buffer, 0, tam);
    cout << total << endl;

    return 0;
}

// acab