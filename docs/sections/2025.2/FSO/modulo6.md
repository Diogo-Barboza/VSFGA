# Fundamentos UNIX

## Unix

- Sistema projetado na Bell Labs (abandonado)
- Reescrito em uma linguaguem de alto nível
- Ritchiie cria a linguagem C e reescreve o UNIX
- Sistema em linguagem de alto nível foi amplamente aceita pela comunidade e facilitou a portabilidade do sistema para múltiplas arquiteturas

O sistema Linux foi desenvolvido em 1991 por Linus Torvalds, código do linux compartilhado no grupo de discussão do sistema do Tanenbaum Minix. É um projeto ativo e amplamente utlizado até hoje focado exclusivamente no desenvolvimento do Kernel. 

- O linux precisa de software para ser útil a um computador, utiliza o código do projeto GNU. 
- Ao se utilizar e customizar as versãoes de diversos códigos, é criada uma distribuição Linux. GNU/Linux != Linux

Hoje, UNIX é um termo utilizado para uma grande família de Sistemas Operacionais

- Família BSD: FreeBSD, OpenBS
- Família Solaris: SunOS
- Família: Mac OS X

Esses sistemas possuem estruturas de diretórios e comandos de terminal similares. 

- Comando para listar processos e verificar seu estado: `ps`

```bash
ps -ax -o pid,ppid,command
```

- Cada processo possui um identificador único chamado de "process id": pid
- Todo processo possui um processo pai, e então contém o "parent process id", ppid
- Em C (ou C++), pode usar o cabeçalho <unistd.h> para ter acesso à API do sistema operacional POSIX e usar uma série de funções para manipulação de processos
- Obter o de pid e ppid
```c
#include <stdio.h>
#include <unistd/h>

int main(){
    pid_t meupid = getpid(); //pid_t -> T de Type
    printf("Pid atual do processos: %d\n", meupid);

    pid_t pidpao = getppid();
    printf("Pid do pai do processo: %d\n", pidpai);

    return 0;
}
```

## Criação de Processos

Os processo podem ser cirados tipicamente em um terminal, onde são digitados os comandos, dentro de um código-fonte, é posível executar o comando system, essa chamda irá criar um subprocesso de shell (/bin/sh) que irá efetuar a execução do comando

- Um programa em C que lista todos os arquivos da pasta atual

```c
#include <stdlib.h>

int main(){
    return system("ls -la");
}

```

- Esse código não é portátil e funcionará exclusivamente em sistemas UNIX
- No Windows, é comum a prática de utilizar o system("pause") para parar a execução do código C ao final dele, quando se utilizar uma IDE que invoca o terminal Windows (que fecha rapidamente).

Outras linguagens (scripts Bash) são mais apropriados quando se deseja exceutar comandos (ou diversos comandos) em u m terminal, sem que seja necessário cirar um binário executável para isso.

- Para se criar novos processos em C, recomenda-se criar processo utilizando o fork()

- A se chamar, um novo processo é criado e quase todo o conteúdo da tabela de processos é copiado para o novo processo.
- Informações como pid, ppid, são únicos mas o processo filho continua a execução do mesmo potno que o processo pai. Além disso, o retorno da função é diferente para os processos e pode ser usado para diferneciá-los.

```c
int main(){ 
    pid_t id_filho;
    printf("Processo incial possui pid: %d\n", getpid());
    if_filho = fork();
    if(if_filho == 0){
        printf("Ola, sou o processo filho de pid: %d\n", getpid());
    }else{
        printf("Ola, sou o processo pai e criei o filho: %d\n", id_filho);
    }
    return 0;
}
```

## Carga de Arquivo Executável

- Desta forma, os processos criados por clonagem e executarão o mesmo programa, algun sistema permitei criar novo processo através de uma nova imagem de programa
- No UNIX, deve-se realizar uma nova chamada exec
- Existe um conjunto de funções exec, todas com o objetivo de alterar o programa em execução do processo atual
- A função retorna apenas em caso de falha: em caso de sucesso a imagem em execução é alterada e o programa é executado a partir do inicio

As famílias de função exec:
- P: (execvp, execlp ..) procuram excetucar o novo programa de diferentes diretórios do PATH, sem a letra é necessário utilizar full path do binário
- V: (execv ...) são utilizadas para criar programas com argumentos
- E: Também recebem uma lsita de variáveis de ambiente 

Normalmente, a função exec é usada e, conjunto com o forl, para não se a;terar um programa que já existe em execução a muito tempo

```c
int main(){
    char *arg[] = {"ls", "-la", NULL};
    pid_t id_filho = fork();
    if(id_filho != 0)
        printf("ola, sou o processo pai e criei o filho %d\n", id_filho);
    else{
        execvp("ls", arg);
        printf("Erro\n");
        return 1;
    }
    return 0;
}
```

## Sinais

Sinais são mecanismo para comunicar e manipular processo no UNIX, a liguagem C padrão provê a biblioteca signal.h. Quando um sinal é recebido pelo processo, a função atual é interrompida e o sinal é tradado por uma função especial chamda de "handler", no entando o sinal pode ser ingorado

- Um dos usos mais comuns de sinais é para terminar o processo em execução. Para isso são usados os sinais SIGTERM e SIGKILL. Também são definifos sinais de usuário, para que o programados possa definir um uso para eles: SIGUSR1 e SIGUSR2
- Os sinais também são usados para o sistema operacional informar erros, SIGSEGC (falha de segmentação), SIGFPE (exeção de ponto flutuante)
- A função signal é usada para alterar o comportamento, também podemos usar o sigaction, veja o manual signal 2, especialemnte a parte "Portability:"

```c
#include <signal.h>
#include <stdio.h>

int contador = 0;

void handler(int signal_number){
    contador++;
}

int main(){
    struct sigtation sa = {}; // Inicializa sem nada para evitar lixo de memória
    sa.sa_hanlder = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    printf("Pressione E para terminar a execucao: \n");
    while (getchar() != 'E')
        ;
    printf("SIGURS1 recebido %d vezes \n", cotador);
    
    return 0;
}
```

- Se testar esse código, verá qie le irá imprimir que nenhum sinal foi recebido, mas como enviar um sinal para o processo, pode ser usado o comando ou função kill.
- Quando se executa o código anterior:
    - ./programa_de_sinais
- Usamos o programa ps para determinar o pis do process (por exemplo, 2240)
- E enviamos o sinal com o comando kill
    - `[user@station ~]$ kill -SIGURS1 2240`

Desta forma, o código anterior irá imprimir quantas vezes , o sinal foi recebido. A função kill também pode ser utilizada para enviar um sinal para o processo em um código fonte C:
- int kill(pid_t pid, int sig);
- Por exemplo
- kill(pid_filho, SIGUSR1)

## Término de Processos

Por padrão, o comando kill envia o signal SIGTERM, sujo padrão é terminar a execução de um processo, Dois sinais podem ser usados para terminar:

- SIGTERM
- SIGKILL

O sinal SIGTERM pode ser ignorado, mas o SIGKILL não pode. Além disso, um processo pode terminar por vontade própria de duas formas:

- Retornando da função main
- Executando a função exit

Normalmente:

- exit(0) é utilizado para indicar sucesso
- exit(1) é usado para indicar um erro

A função wait pode receber um argumento do tipo *int, para indicar o status da saída. As macros WIFEXITED e WEXITSTATIS podem ser usadas para ler o inteiro e testar se o processo terminou e o valor de retorno.

## Aguardando o Término

Quando o processo pai evoca o processo filho, ele pode aguardar o fim do processo utilzando a função wait(), se o filho não terminou, o processo pai irá bloquar aguardando o término do processo para aguardar a chegada de um sinal, também podemos utilizar a função `pause()`

```c
#include <stdlib.h>
#include <unistd.h>
#include  <sys/wait.g>

int main(){
    pis_t id_filho;
    int status;

    printf("Processo incial possui pid: %d\n", getpid());
    id_filho = fork();
    if (id_filho == 0){
        printf("Ola, sou o processo filho de pid: %d!\n", getpid());
        exit(0);
    }

    wait(NULL);

    printf("Ola, sou o processo pai e o filho terminou!\n");
    return 0;
}
```

## Processos Zumbis

Quando um processo cria outro processo, assume-se que ele irá receber as informações de término do processo pela função wait, se ele não estiver em wait, o processo filho fica em um estado zumbi, indicando que deseja terminar, mas ainda não aguardado pelo processo pai. Só quando a função wait for chamada pelo pai, o resultado da execução é passado para o pai, o processo filho é deletado e a função wait retorna imediatamente.

```c
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t id_filho;

    filho = fork();

    if(filho > 0)
        sleep(6);
    else
        exit(0);
    wait(NULL);

    return 0;
}
```
 