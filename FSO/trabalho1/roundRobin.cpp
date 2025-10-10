#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct processo {
    int pid;
    int tempoRestante;
    int turnaround;
};

processo *cria_processo(int tam){
    processo *processos = new processo[tam];
    return processos;
}

int main() {
    int n = 0, janelaTempo = 0, pid = 0, tempoTotal = 0, tempoAtual = 0;

    cin >> n;

    processo *processos = cria_processo(n);

    queue<processo> fila, processoTerminados;
    vector<processo> processosTerminados;

    cin >> janelaTempo;

    for(int i = 0; i < n; i++) {
        cin >> pid >> tempoTotal;
        processos[i].pid = pid;
        processos[i].tempoRestante = tempoTotal * 1000;
        processos[i].turnaround = 0;
        fila.push(processos[i]);
    }

    while (!fila.empty()) {
        processo processoAtual = fila.front();
        fila.pop();
    
        int tempoDeExecucao = min(processoAtual.tempoRestante, janelaTempo);

        tempoAtual += tempoDeExecucao;
        
        processoAtual.tempoRestante -= tempoDeExecucao;

        if (processoAtual.tempoRestante <= 0) {
            processoAtual.turnaround = tempoAtual;
            cout << processoAtual.pid << " (" << processoAtual.turnaround << ")" << endl;
        } else {
            fila.push(processoAtual);
        }
    }

    return 0;
}
