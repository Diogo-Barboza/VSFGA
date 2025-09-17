# Problemas Clássicos de IPC e Deadlock

- IPC - Inter-Process Communication
- Mecanismo que permite os processos se ocmunicarem entre sí

## Problema do Jantar dos Filósofos

Dijkstra formulou e resolveu o problema do jantar dos filósofos. Pra comer tem a ideia de paralelismo. 

- Cinco filósofos estão sentados em torno de uma mesa circular cada filósofo tem um prato de espaguete o espaguete é escorregadio e cada filósofo precisa utilizar dois garfos para comer existe um par de pratos entre os garfos.

```c
void philosofer(int i){
    int esq = i;
    int dir = (i + 1) % N; // Modular
    while(True){
        think(); // pensar qual garfo pego
        take_fork(dir);
        take_fork(esq);
        eat();
        release_fork(esq);
        release_fork(dir);
    }
}
```

- **Problema**: Se todos os filósofos resolverem pegar os garfos ao mesmo tempo, e ao obter um garfo, o escalonador troca de
contexto para outro filósofo, neste caso, todos os filósofos terão um garfo e ficarão bloquados tentando obter outro, **esse problema é conhecido como deadlock**

- Imagina que nós tentamos uma nova versão do algoritmo, de forma que um filósofo largue o garfo esquerdo, se não conseguiu obter o direito. Com isso, o problema é **minimizado**, porém não **corrigido**.
- Se o escalonador sempre trocar de context oao obter ou liberar um garfo:
    - F1 obtem garfo, F2, ..., F5 obtem garfo.
    - F1 libera garfo, F2, ..., F5 libera garfo.
    - F1 obtem garfo, F2, ..., F5 obtem garfo.
    - (...)
- Neste caso, dos filósofos estão processando, porém eles fracassam em realizar qualquer progresso, esse problema é chamdo **starvation**.
- Uma terceira tentativa seria:
    - Se o filósofo fracassar em obter o outro garfo, ele espera um tempo aleatório até tentar obter novamente.
    - Do ponto de vista prático, essa solução funciona muito bem, pacotes que trafegam em cabo de rede do padrão Ethernet, funcionam desta forma.

- A solução usando semáforos binários:
    - Inicialmente usamos um semáforo binário para proteger uma seção crítica, antes de começão a pegar garfos, um filósofo realiza down em mutex, após substituir os garfos, ele realiza um up em um mutex.
    - Duas funções, um pra pegar o garfo e outra pra liberar
    - As funções são protegidas por um semárofo binário (mutex)
    - Existe um array com um semáforo por filósofo
    - O filósofo aumenta seu semáforo, se obter os dois garfos, ou bloqueia nele, aguardando que um vizinho libere o garfo necessário

## Deadlock

Podemos definir, como, quando os programas/threads aguardam um recurso que não é liberado. e **Starvation** quando os mecanismos de sincronização não permitem que o programa avance.

- Podem acontecer em qualquer situação.
- Os S.O estão cheio de recursos que devem ser compartilhados e protegidos
- Dois processos acessando a mesma entrada de arquivos, pode causa problema
- É responsabilidade do S.O não corromper todos os arquivos do sistema, no entanto ao garantir a exclusão mútua desses recursos, é possível causar um deadlock
- Podem acontecer não só e softwware, mas também em hardware
- Em software, com mutexes e outros mecanismos de sincronização de processos
- Em hardware, quando, múltiplos programas tentam acessar/usar dispositivos, por exemplo, uma impressora e scanner
- O exemplo mais simples de um deadlock, quando os recursos só podem ser usados por um processo de cada vez, os processos P1 e P2 podem chegar a uma situação de bloqueio eterno, esperando por recursos que nunca são liberados

Definição formal de deadlock:

> “Um conjunto de processos estará em situação de deadlock se cada processo no conjunto estiver esperando por um evento que apenas outro processo no conjunto pode causar”

- Na mioria dos casos, o evento que cada processo aguarda é a liberação de um recursos obtido por outro processo, o número de processos e o número de recursos solicitados devem ser maior ou igual a 2.

## Recursos

São objetos que um processo pode adquirir de maneira exclusiva, ou não, na obtenção de recursos de maneira exclusiva, apenas um processo pode estar usando ao mesmo tempo (exclusão mútua é implícita), um recursos é qualquer coisa que pode ser adquirida, usada e liberada.

- Em geral, deadlocks ocorrem em recursos não-preemptíveis.
- Em recursos preemptíveis a simples transferência de recursos os resolve

### Preemptíveis

- Pode ser retirado do proprietário por uma entidade externa sem causa-lhe prejuizo:
    - Ex.: Memória não utilizada
    - Se dois programas, precisam utilizar um esoaço de memória e usar a impressora. Imagine a situação que P1 obteve a impressora, P2 obteve a memória e não há mais memória disponível. Aparente impasse, mas neste caso, é possível transferir a memória para P1 de forma que termine sua execução


### Não-Preemptíveis

- Um recurso não pode ser tomado à força
- O processo que o possui deve libera-ló de espontaneamente
- Por exemplo, se um programa começou a escrever um arquivo, ou começar a imprimir uma página, não é possível interromper esse processo sem prejuízos
- Maior parte dos nossos recursos são, não-preemptíveis

## Modelagen de Deadlocks

> Próxima aula.