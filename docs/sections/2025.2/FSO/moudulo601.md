# Pthreads

Microprocessadores baseados em uma unidade central de processamento (CPU) apresentam um grande avanço durante mais de duas décadas. A evolução começou a diminuir em 2003, devido ao crescente consumo de energia e dissipação de calor que limitaram o crescimento do clock e o número de instruções que podem ser executados em um período de clocl em uma única CPU. 
Os usuários e programados estão acostuamdos a ver seu programa rodando mais rápido a cada nova geração de CPU, isso não é mais verdade nos dias de hoje, um programa sequencial irá rodar em apenas um dos cores de um processador. Tradicionalmente, os software são escritos como programas sequenciais.
Praticamente, todos os fabricantes mudaram de paradigma de evolução, onde começaram a aumentar o número de núcleos de um processador para poder aumentar a capacidade de processamento. Uma forma de aproveitas esses diferentes núcleos é com a utilização de threads. Bem antes dos fabricantes mudarem o paradigma, um padrão já havia sido definido, a grande diversidade das possibilidades e implementação motivou a padronizaçãol, por exemplo, alguns pacotes divergem até mesmo como criar uma thread (alguns não usam o nome de função). 

- Pthreads ("P" de "POSIX") é uma padronização criada pelo IEEE e define um conjunto de tipos e chamadas na linguagem de programação C. 

## Criação de uma Thread

Pthread define funções para cirar e terminar uma thread:
- *attr e *arg podem ser nulos.

```c
#include <pthread.h>

int pthread_create(pthread_t *threadm const pthread_attr_t * attr,
                   void *(*start_routine) (coid *), void *arg);

void pthread_exit(void *reveal);

#define NUM_THREADS 5

void *thread_func(void *arg){
    printf("Hello, world!\n");
    pthread_exit(NULL);
}

int main(){
    int ret, i;
    pthread_t threads(NUM_THREADS);

    for(int i = 0; i < NUM_THREADS; i++){
        printf("Creating %d\n", i);
        ret = pthread create(&threads[i], NULL, &thread_func, NULL);
        if(ret){
            printf("Error %d on thread %d\n", ret, i);
            perror("pthread_create");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

```

## Término de Threads

Uma thread pode terminar nas seguintes situações:

- Quando a thread invoca pthread_exit();
- Quando a função passada por argumentos para pthread_create retorna;
- Ela é cancelada
- Alguma thread chama a função exit() ou a thread principal retorna na função main()

Exemplos de thread terminando a execução:

```c
void *thread_func(void *arg){
    printf("Hello, world!\n");
    pthread_exit(NULL);
}
```

## Argumento para Threads

Muitas vezes é necessário para argumentos para threads, assim como ;e possível passar argumentos para funções.

- O argumento "arg", da função pthread_create, é utilizado para isso.

```c
struct thread_arg {
    int num;
};

int main() {
    int ret, i;
    struct thread_arg args(NUM_THREAD);
    pthread_t threads(NUM_THREADS);

    for(i = 0; i < NUM_THREADS; i++){
        args[i].num = i;    
    }
    for(i = 0; i < NUM_THREADS; i++){
        pritnf("Creating %d\n", i);
        ret = pthread_create(&threads[i], NULL, &thread_func, &args[i]);
        if(ret){
            printf("Error %d on threads %d\n", ret, i);
            perror("pthread_create");
            ecxit(-1);
        }   
    }

    pthread_exit(NULL);
}

```

## Pthreads_Join

```c
#include <pthread.h>

int pthread_join(pthread_t thread, coid **retval);
```

Função que aguarda o término da thread (ou retorna imediatamente se a thread já terminou). Se retval != NULL, recebe o valor retornando pela thread.

```c
int main(void){
    (...)

    for(i = 0; i < NUM_THREADS; i++){
        pritnf("Creating %d\n", i);
        ret = pthread_create(&threads[i], NULL, &thread_func, &args[i]);
        (...)
    }

    for (i = 0; i < NUM_THREADS; i++){
        ret = pthread_join(threads[i], NULL);
        if(ret){
            printf("Error waiting thread %d\n", i);
            perror("pthread_join");
            ecxit(-1);
        }
    }

    return 0;
}
```

Após a saída com sucesso de um pthread_join é garantido que a thread termninou, múltiplas threads aguradando a mesma thread possuem comportamento indefinido. Qualquer thread pode aguarda qualquer thread, não existe função "aguarde qualquer thread"

## Pthread_mutex

```c
#include <pthread.h>

int pthread_mute_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
pthread_mutex_detroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

```

- Inicialização
- Lock, unlock, try_lock
- Atributos de mutex: veja pthread_mutexattr(3)

```c
#define NUM_THREADS 2
#define THREADS_LOOPS 1000 * 1000

static int count = 0;
static pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    int i;

    for(i = 0; i < THREAD_LOOPS; i++){
        pthread_mutex_lock(&my_mutex);
        count++;
        pthread_mutex_unlock(&my_mutex);
    }
    return NULL;
}

int main(void){
    for(i = 0; i < NUM_THREADS; i++){
        ret = pthread_create(&threads[i], NULL, &thread_func, NULL);
        (...)     
    }
    while(count < NUM_THREADS * THREADS_LOOPS
        printf("count %d/%d\n", count, NUM_THREADS * THREADS_LOOPS);
    
    return 0;
}
```

Se um sinal chega em uma função que está aguardando um mutex, depois de retornar do sighandler ela volta a bloquar no mutex como se não tivesse sido interrompida, mutex foram cirados como para serem primitivas baixo nível, que outras rotinas de sincronização se baseiam. Implementações de mutex tentam ser o mais eficiente possível

## Pthread_Cond_Wait

Função que bloqueia aguardando uma condição, é necessário obter o mutex antes de bloquear, a thread libera o mutex e aguarda a condição "atomicamente"

```c
pthread_mutex_lock(&coint_mutex);
while (count < 0){
    pthread_cond_wait(&cont_cond, &count_mutex);
    printf("%d!\n", count);
}
printf("%d!\n", count);
pthread_mutex_unlock(&count_mutex);

#include <pthread.h>

int pthread_cond_timewait(pthread_cond_t,*restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);

int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
```

Comportamento indefinido se não tiver o lock do mutex, deve-se utilizar apenas um mutex por condição (nunca mais de uma mutex). Pode-se utilizar mais de uma condição por mutex, comportamento desejado em muitos casos. Timed wait comporta-se como o wait, mas retorna erro depois de um certo tempo.

```c
int main(void){
    int aux = countl
    (...)

    for(i = 0; i < NUM_THREADS; i++){
        (...)
    }
    pthread_mutex_lock(&count_mutex);
    printf("main: beginnign: %d\n", count);
    pthread_mutex_unlock(&coint_mutex);

    while(aux > 0){
        pthread_mutex_lock(&count mutex){
            if(aux == count){
                pthread_cond_wait(&count_cond, &count_mutex);
            }
            aux = count;
            printf("main: count is %d\n", count);
            pthread_mutex_unlock(&count_mutex);

            long_func(aux);
        }
    }
    printf("main: bye %d\n", count);

    pthread_exit(NULL);
}
```


## Pthread_cond_init

```c
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
pthread_cond_t cond - PTHREAD_COND_INITIALIZER;
```

- Macro que permite inicialização estática;
- Função para (re)inicialização dinâmica;
- Função que destrói, resultado é que para todos os efeitos, o
objeto permanece não-inicializado;
- Comportamento não definido para: destruir condição quando
outras threads estão aguardando, utilizar objeto não inicializados,
iniciar mais de uma vez ou destruir mais de uma vez.

## Pthread_Cond_Wait

```c 
#include <pthreads/h>

int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_signal(pthread_cond_t *cond);
```

- Signal desbloqueia pelo menos uma thread que esteja
bloqueada em uma condição.
- Se nenhuma estiver aguardando, nada acontece.
- Broadcast desbloqueia todas as threads que estejam
aguardando. Nesse caso, uma thread é desbloqueada e
as outras ficam aguardando o mutex ser liberado.


## Multiprogramação Segura

Nem toda função pode ser executada em paralelo, tipicamente, variáveris globais, locks de arquivos não são seguras de ser chamadas, funções que são seguras para serem chamadas em paralelo são chamadas de thread-safe.

### Dados Static

```c
int *func(void){
    static int i;
    (...);
    return &i;
}
```

Funções que usam ou retornam ponteiros para dados estáticos não podem ser executados em paralelo, exemplo disto é a inet_ntoa, vastamente utilizada par aconverter 32 bits em um endereço IP que possa ser lido como "10.0.0.1". Por retornar um ponteiro para um buffer estático, não pode ser usada em múltiplas threads.

- Funções que usam dados estáticos foram recriadas para retornar dados em um buffer passado pelo usuário.

### Global

Às vezes, o uso de variáveis globais sem proteção leva a leitura de dados incorretos que podem levar a segmentation fault, alguns mecanismos de sincronia entre as threads deve ser utilizado para proteção dos dados, o uso de variáveis globais de sistema deve ser feito de forma que apenas uma thread precise acessá-las.

### ERRNO

Chamdas de sistemas tradicionais UNIX e POSIX usam a variável errno para indicar o erro das mais diversas funções, comportamento complestos de programas podem depender do valor dessa variável. O padrão Pthreads receba seu errno.

- Errno é definido como uma macro a cada thread tem o seu "errno local"

### File Locks

Chamdas de sistema podem sincronizar threads com outros processos dos sistema operacional apenas um processo obtém o lock, o sistema não reconhece chamadas de lock de diferentes threads do programa e por isso não pode ser utilizada para sincronizar.

- Lock per-thread foram cirados para resolver esse problema (Flockfile, Ftrylockfile, Funlockfile)

### Thread Safe

Funções de bibliotecas e manuais de programação vastamente definem as suas funções como "thread safe" e "thread unsafe", pode parecer óbvio, mas procure sempre utilizar as funções thread safe. Por exemplo:

- Função signal() possuem comportamento INDEFINIDO para programas multithread.

## Conclusão 

Apesar de toda a dificuldade, diversos casos são conhecidos na literatura. Lembre-se: a tentência é que o número de cores apenas AUMENTEM! Dominar o bom uso de threads é saber usar melhor os processadores do **FUTURO**.
