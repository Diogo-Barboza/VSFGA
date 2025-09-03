# Threads

- Threads separam conceitos de agrupamento de recursos e execução.
- Processos agrupam recusos
- Threads são escalonadas para execução
- Permitem que múltiplas execuções ocorram no mesmo ambiente
- Devido a maior simplicidade de escalonamento são chamadas de "Processos leves"
- No Multithread, a entidade processo é dividida em processo e thread
- Thread correspondeo ao estado de execução
- No modelo mutlithread existem duas entidade na tabela de processo
- Threads compartilham as mesma varáveis globais
- A proteção dos threads é de responsabilidade do programador
- A pilha é uma estrutura em memória, porem cada thread possui sua própria pilha e não compartilha esses dados com outras threads
- As threads chamam procedimentos diferentes em tempos diferentes
- Chamadas de controle de threads:
    - thread_create: Cria uma thread nova, passando uma função como argumentos para iniciar a execução
    - thread_exit: Termina a thread em execução
    - thread_yield: Permite que uma thread desista voluntariamente da CPU
 
## Por que utilizar múltiplas threads?

- Pelo mesmo motivo que processos concorrentes são melhores que sem concorrência
- Threads possuem troca de contexto mais leve que processos
- Procemos dividir o programa caso exista muitas chamadas blocantes, se as chamadas blocantes forem de diversas fontes melhora-se o tempo
- Para explorar melhor os recursos da máquina
- A intel fez uma campanha avisando que a tendência é aumentar o número de núcleos, não a velocidade deles
- Threads são mais fáceis de cirar e destruir que processos, pois só precisa de uma área alocada
- Em alguns sistemas, criar uma thread é 100 vezes mais rápido que criar um processo
- É um modelo de programação mais simples
- Quando um programa deve tratar dados de diversas fontes:

## A arte de Multiprogramar

Porem há questões que foram levantadas:

- Fork(): Quando o pai cria o processo filho, ele deve conter o mesmo tanto de threads que o pai ou apenas um? **APENAS UMA THREAD**
- Escalonamento: Uma thread estiver bloqueada esperando dados do teclado, ele deveria ser bloqueado?
- O compartilhamento de dados pode causar muitos problemas
    - O que acontece quando uma thread fecha um arquivo que outra thread está lendo? -<
- Alguns desafios são solucionados com boas práticas de programação

Multithreading Programming -> Expectation vs Reality

![Meme multiThread](../../../images/memeMulti.png)

## Implementação de Threads 

Para implementação das threads, existem diferentes formas para sua implementação. Implementar o modelo de processos e threads a nível de sistema operacional, criando abstrações de processos e de threads

- Implementar threads no sistema operacional
- O kernel do S.O deve criar as threads, organiza seu escalonamento e término
- Existência de uma tabela de threads no kernel, que contém os dados de cada thread
- É necessário uma biblioteca de threads, para evitar overhead de contexo entre as threads
- O núcleo vai ver a bibiolteca de threads em modo usuário


### Implementação em modo Kernel

![Exemplo modo Kernel](../../../images/modoKernel.png)

- Geralmente o escalonador do S.O é não-preemptivo
- Cada processo precisa de sua própria tabela de threads
- Threads manipuladas por funções
- Quando uma thread dor perder o controle, ela chama o procedimento do ambiente para selecionar outra thread
- Troca de contexto muito rápida entre as threads
- Cada processo pode ter seu próprio algoritmo de escalonamento
- Desvantagens
    - Muito cuidado ao usar chamadas bloquantes do sistema, elas rião bloquear todas as threads.
- A solução é colocar uma "capa" antes de todas as chamadas blocantes do sistema. Desta forma quando uma chamada blocante for realizada ela é mascarada pela biblioteca de threads que faz o teste de bloqueio

### Implementação de Threads em Modo Usuário

![Exemplo em modo usuário](../../../images/modoUsuario.png)

- Enquanto utilizar threads no espaço de usuário reduz o custo de troca, as operações de I/O exigem mais e podem bloquear as outras threads
- Implementar as threads em S.O continua inserindo um custo caro de troca de contexto

### Threads em Modo Híbrido

- Busca juntar as vantagens dos threads em modo kernel e modo usuário
- Um processo pode ter várias threads de kernel, por usa vez cada kernel pode conter diversar threads em modo usuário

![Modo Híbrido](../../../images/modohibrido.png)

## Comparativo de threads em Diversos S.O

![Comparativo de threads em S.O](../../../images/comparativoSO.png)

