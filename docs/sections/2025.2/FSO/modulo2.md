# Processos

## Modelo de processo

- Conceito: É um programa em execução acompanhando de valores de tempo de execução

- Processo:
    - Código executável
    - Valores de variáveis locais
    - Registradores
    - Contador de programa (indica a próxima tarefa a ser executada)

- Diferença de processo e programa: Programa é receita de bolo, processo é o ato de fazer o bolo.
    - Programa é uma série de passos a ser executado
    - Processo é a execução desses passos

- Um processo pode ser dividido em: Ambiente e Execução

- Machado e Maia dividem em 3 partes, Espaço de endereçamento, contexto de software e contexto de hardware:
    - Execução: Contexto de Hardware
    - Ambiente: Espaço de endereçamento + Contexto de software

### Classificação de processo

Classificação dos modelos de processos quanto ao custo de troca de contextos e de manutenção

- Heavyweight (Processo tradicional)
- Lightwheight (threads)

#### Heavyweight (Processo Tradicional)

- Processo composto tanto pelo ambiente como pela execução
- Cada processo possui um único fluxo de controle (contador de programa) e roda de forma independente
- Em um determinado instante, há vários processos ativos ao mesmo tempo, o processador é chaveado entre diversos processos

![Visualização dos processos](../../../images/processotradicional.png)


#### Lightwheight (threads)

## Criação de processos

- Sistemas de um único propósito possuem um esquema mais simples e previsível de processos em execução
- Os processos são criados:
    - Ínicio do sistema
    - Execução de uma chamada ao sistema de criação de processo em execução
    - Requisição do usuário
    - Ínicio de um job de lote
- Alguns executam em primeiro plano e interagem com usuários
- Outros executam em segundo plano: chamados de **daemons**
- Normalmente os processos são criados por outro.
- Em alguns sistemas, é possível listar o ppid (parent pid)
- Todos os processos são filhos ou descendentes do processo init
- Windows não apresenta hierarquia de processos

### Hierarquia da árvore

![hierarquia da árvore](../../../images/hierarquiaarvore.png)

### Condiçoes de término de processo

- Sáida normal (voluntária)
- Saída por erro (voluntária)
- Erro fatal (involuntário)
- Cancelamento por outro processo (involuntário)

## Estados de processos

- Apesar de processos serem autossuficientes, muitas vezes necessitam acessar recursos ou comunicar com um processo
- Quando um processo espera um evento, dizemos que esta bloqueado
    - Leitura em disco
    - Leitura de rede
    - Esperando entrada do usuário

- Os processos podem estar:
    - Rodando
    - Bloqueado
    - Pronto

![alt text](../../../images/processosestado.png)

- (1) O processo bloqueia-se aguardando uma entrada
- (2) O evento aguardado pelo processo ocorreu, pode-se iniciar a executar.
- (3) O tempo de posse do processador esgotou-se
- (4) O processo é escolhido pelo escalonador para executar

## CPU Bound e I/O Bound

- CPU Bound possuem maior afinidade com o procesasdor, e passam a maior parte do tempo em estado rodando, já o I/O Bound possuem afinidade a entrada e saída, passam a maior parte do tempo em bloquado.

## Implementação de processos

- **TROCA DE CONTEXTO** : Operação básica da multiprogramação, é uma operação de salvamento dos registradores de um processo, para posteriormente restaurar esses regsitradroes, para que esse processo continue a execução como se não tivesse parado
-  

![alt text](../../../images/interrupcao.png)
