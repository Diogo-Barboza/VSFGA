# Resumo de Estrutura de Dados 2 

## Estruturas Não-Lineares

### 🌳 Árvores (Trees)

- **O que é:** Estrutura hierárquica com um nó raiz e sub-nós.
- **Exemplo:** Organização de pastas em um sistema operacional.
- **Vantagem:** Facilita buscas rápidas e organização de dados hierárquicos.

### 🔑 Tabelas Hash

- **O que é:** Mapeia chaves para valores usando uma função hash.
- **Exemplo:** Dicionários em Python ou Mapas em Java.
- **Vantagem:** Acesso a dados em tempo constante $O(1)$.

### 🚑 Filas de Prioridade & Heaps

- **Prioridade:** Elementos são removidos com base na importância, não na ordem de chegada.
- **Heap:** A estrutura física (geralmente uma árvore binária) que permite que o elemento de maior/menor prioridade esteja sempre no topo.

---

## Algoritmos de Ordenação

| Categoria | Complexidade | Exemplos | Uso Ideal |
| :--- | :--- | :--- | :--- |
| **Logarítmicos** | $O(n \log n)$ | Quick Sort, Merge Sort | Grandes volumes de dados genéricos. |
| **Lineares** | $O(n)$ | Counting Sort, Radix Sort | Dados com intervalos conhecidos e limitados. |

---

## III. Grafos

### Representação

1. **Matriz de Adjacência:** Representação por tabela (booleana ou pesos).
2. **Lista de Adjacência:** Cada nó armazena uma lista de seus vizinhos.

### Algoritmos Principais

- **BFS (Breadth-First Search):** Busca em largura. Ideal para caminhos mínimos.
- **DFS (Depth-First Search):** Busca em profundidade. Ideal para detecção de ciclos e topologia.

### Aplicações Reais

- **Redes Sociais:** Sugestão de amizades e conexões.
- **Logística:** Cálculo de rotas e GPS (Algoritmo de Dijkstra).
- **Web Crawlers:** Como os motores de busca indexam a internet.

---