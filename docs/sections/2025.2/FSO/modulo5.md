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

Holt (1972) demonstrou como deadlocks podem ser modelados com grafos dirigidos.

- Os grafos possuem dois itpos de nós, processos e recursos

Em situação operacional de computador, três processos estão na seguinte situação:

- O processo P1 tem a posse do recurso R1
- O processo P2 tem a posse do recurso R2
- O processo P3 tem a posse do recruso R3

O processo P1 solicita o recurso R2, o processo P2 solicita o recurso R3, e o processo P3 solicita o recurso R1. Sobre essa situação, é correto afirmar que:

1. Não haverá deadlock, pois o processo P1 não solicitou o recurso R3
2. Tem-se uma condição de deadlock
3. Não haverá deadlock, pois o processo P3 não solicitou o recurso R3
4. Só ocorrerá deadlock caso P1 solicite o recurso R3, P2 solicite o recurso R1 e P3 solicite o recurso R2
5. Não haverá deadlock, pois o processo P2 não solicitou o recurso R1

- No entanto, algumas questões podem cobrar apenas "um processo aguardando outro"

Vimos que é função do S.O gerenciar or recursos computacionais. Estratégias usadas para tratar deadlock:

- **Ignorar** o problema
- **Detectar** e recuperar o deadlock
- **Evitar** o deadlock
- **Prevenir** o deadlock

### Ignorar o Problema

- O "Algoritmo do avestruz"
- Enfie a sua cabeça na areia e finja que não há um problema
- Não vale a pena degradar a performance do sistema para tratar uma situação que ocorre com pouca frequência
- A maioria dos sistemas modernos são desta forma!


### Detectar e Recuperar o Deadlock

Como existe a possibildiade de ocorrência do problema, o S.O deve tratá-lo

- Técnica dividida em duas fases:
    - Detecção de deadlock
    - Recuperação do Deadlock

Aproveitando o modelo de Holt, uma grafo é construído com alocações dos recursos, neste grafo um deadlock é representado por um ciclo, desta forma todos os processos que estão nesse ciclo estão em deadlock. Para a detecção de ciclos em grafos dirigidos: diversos são conhecidos. Essa estratégia pode ser estendida para usar vetores e detectar múltiplos recursos de cada tipo.

- Quando detectar um deadlock?
    - Periodicamente 
    - A cada nova solicitação de recurso
    - Quando a utlização de CPU for baixa

Na segunda fase (recuperação) é necessário recuperar um deadlock:

- Preempção
- Rollback
- Eliminação de processos  

#### Preempção

Em alguns casos pode ser viável tomar um recursos do seu proprietário à força e devolvê-lo posteriormente. é muito dependente da natureza do recurso e pode tornar-se uma operação complexa. Escolher o processo a ser suspenso depende muito de quais processos tem recursos que podem ser devolvidos mais facilmente.

#### Roolbacks

Ao saber que a possiblidade de deadlock é grande, pode-se utilizar um arquivo de log que é atualizado periodicamente, que contém uma imagem do processo naquele momento. Esse ponto salvaguarda (checkpoint) permite que o processo seja reinicializado a partir daquele moemento, em algum instante futuro.

- Quando um deadlock é detectado, sabe-se quais recursos são necessários, para realizar a recuperaça2o, escolhe-se um processo em posse dos recursos e realiza o seu rollback até um momento anterior à aquisição dos recursos. Desta forma, os recursos podem ser entregues a outros processos e eles na2o são prejudicados.

> Voltar aqui

### Evitar o Deadlock 

Anteriormente, presumimos que a alocação de recursos, eles são obtidos e solicitados todos de uma vez, essa náo é a realidade da maioria dos S.O. Na detecção de deadlocks estamos preocupados em fazer o sistema decidir para qual processo libera o recurso, baseado em uma descisão correta.

- Os algoritmos para evitar deadlocks são baseados em estados seguros
- Diz-se que um estado é seguro se existir alguma ordem de esclonamento no qual todos os processos puderem ser executados até sua conclusão mesmo que todos solicitem seu número máximo de recursos subitamente.

- Desta forma, o processo P possui uma tabela de recursos que obteve R e o número máximo de recursos que ele pode obter M. Um exemplo, o estado é seguro, pois existe uma política de escalonamento que permite a execução. No entando, é possível que se atender o processo A, antes do B, pode-se levar a um estado inseguro. Não há sequência que garanta a conclusão.
- Um estado inseguro não é um estado de impasse, pode ser que o processo A libere um recursos e o sistema finalize, mas o sistema não tem como adivinhar o que irá ocorrer.
- A difereça é que **não pode garantir a finalização**.

Um algoritmo de escalonamento para evitar deadlocks foi desenvolvido por Dijkstra, 1965. A ideia é que o banqueiro possa garantir recursos para seus cliente. Pode ser generalizado para múltiplos recursos.

### Prevenir o Deadlock

As 4 condições precisam ocorrer para se ter um deadlock. Se uma delas na2o ocorrer, o deadlock não ocorrerá.

- Para prevenir, podemos:
    - Atacar a condição de exclusão mútua
    - Atacar a condição de posse e espera
    - Atacar a condição de não-preempção
    - Atacar a condição de espera circular

#### Impedir exclusão mútua

- Impedir a exclusão mútua, se nunca acontecer de um recursos ser alocado exclusivamente para um processo, acaba com o problema do deadlock, nenhum outro processo irá esperar pelo recurso. É possível centralizar o processo de controle do recurso, e fazer os outros processos se comunicarem com ele (troca de mensagens).

Ex.: Spool de impressão, SGBD para registro 

- Nem todos os recursos podem ser gerenciados assim, muitas vezes na prática é inviável, no entando a ideia de diminuir ao máximo o número de processos que possui acesso ao recurso pode ser uma boa prática

#### Impedir a posse e espera

Se evitarmos que os processo que possuem recursos, peçam mais recursos, o problema pode ser resolvido, uma solução é fazer os processos pedirem rodos os recursos que necessitam, antes da execução.

- Nem sempre sabe-se recursos serão necessários, é um desperdício, ficar muito tempo com o recursos se não for utilizá-lo, uma outra tática é fazer que o processo solicita o recurso deve liberar todos os recursos que adiquiriu anteriormente, para depois adiquirir todos o que precisar. **Isto pode ser muito complexo**.

#### Impedir a não-preempção

Garantir uma maneira de sempre retirar um recurso de um processo, isso pode causar sérios problemas no funcionamento e pode levar a resultados inesperados.

#### Impedir a espera Circular

Forçar que um porocesso tenha apenas um recurso por vez, porém para cenários complicados esta restrição é inviável. É possível manter uma numeração global de todos os recursos do sistema e fazer com que os processos sigam a ordem de requisição dos recursos. 

- Como a ordem de requisição é a mesma, pode-se impedir ciclos nos grafos de requisição

- Problema: Grande quantidade de recursos exige uma quantidade muito grande, que não é facilmente enumerada


### Deadlock Envolvendo 3 Processos

Neste caso, temos uma situação de deadlock que ocorre em três processos. 

- Não é obritagatório que todos os processos peçam todos os recursos ao mesmo tempo