# Resumo do Semestre 

## Teoria de Grafos

Grafos representam relações. Em software, usamos para mapas, redes sociais e fluxos de dados.

| Algoritmo | Explicação Simples | Exemplo no Mundo Real |
| :--- | :--- | :--- |
| **1.1 Busca (BFS/DFS)** | BFS explora em camadas; DFS explora caminhos até o fim. | **BFS:** Achar amigos de 1º grau no LinkedIn. |
| **1.2 Menor Caminho** | Encontrar a rota com menor custo total. | Rotas de entrega de comida. |
| **1.3 Comp. Conectados** | Identificar grupos isolados em uma rede. | Identificar "bolhas" de usuários em redes sociais. |
| **1.4 Detecção de Ciclos** | Verificar se um caminho volta ao início. | Evitar loops infinitos em chamadas de funções. |
| **1.5 Ord. Topológica** | Ordenar tarefas com dependências. | O Gradle/Maven decidindo a ordem de compilação. |
| **1.6 SCC (Fort. Conectados)** | Grupos onde todos se alcançam (direcionado). | Analisar grupos de sites que linkam entre si (SEO). |
| **1.7 Dijkstra** | Menor caminho com pesos positivos. | **Google Maps:** Caminho mais rápido para o trabalho. |
| **1.8 Algoritmo A*** | Dijkstra com uma "bússola" (heurística). | **IA de Jogos:** NPC encontrando o jogador no mapa. |
| **1.9 Árvore Geradora (MST)** | Conectar todos os nós gastando o mínimo. | Passar fibra ótica em um bairro com o menor custo. |

---

## Algoritmos Ambiciosos (Greedy)

Fazem a melhor escolha local a cada passo. São rápidos e ocupam pouca memória.

* **2.1 Mochila (Fracionária):** Pegar o máximo de valor possível dividindo itens.
    * *Exemplo:* Encher um caminhão de grãos priorizando o mais caro por quilo.
* **2.2/2.3 Interval Scheduling/Partitioning:** Organizar tarefas em horários.
    * *Exemplo:* Sistema de reserva de salas de reunião para evitar conflitos.
* **2.4 Atraso Máximo:** Minimizar o pior atraso possível.
    * *Exemplo:* Escalonar entregas para que nenhum cliente espere demais.
* **2.5 Caminhoneiro:** Parar para abastecer apenas quando necessário.
    * *Exemplo:* Logística de veículos elétricos calculando pontos de recarga.
* **2.6 Caixa (Moedas):** Dar o troco usando o menor número de moedas.
    * *Exemplo:* Um caixa eletrônico dispensando notas de 100 antes das de 20.
* **2.7 Huffman:** Reduzir o tamanho de dados sem perder informação.
    * *Exemplo:* Compressão de arquivos `.zip` ou imagens `.jpeg`.

---

## Dividir e Conquistar

Quebrar um problema grande em menores, resolver e combinar os resultados.

* **3.1 Merge/Quicksort:** Ordenação de dados.
    * *Exemplo:* Organizar uma lista de 1 milhão de usuários por nome.
* **3.2 Contagem de Inversões:** Medir o quão "fora de ordem" está algo.
    * *Exemplo:* Comparar o ranking de filmes de dois usuários para dar recomendações.
* **3.3 Mediana das Medianas:** Achar o elemento central de forma rápida.
    * *Exemplo:* Calcular estatísticas de performance de um servidor em tempo real.
* **3.4 Par de Pontos Próximos:** Achar a menor distância entre muitos pontos.
    * *Exemplo:* Sistemas de colisão em jogos ou radares aéreos.
* **3.5 Karatsuba / 3.6 Strassen:** Multiplicação ultra-veloz.
    * *Exemplo:* Criptografia pesada (RSA) ou processamento de imagens (Matrizes).

---

## Programação Dinâmica (PD)

Resolver cada subproblema uma única vez e guardar o resultado (memoization).

* **4.1 Scheduling com Pesos:** Escolher tarefas que dão mais lucro, não apenas as mais curtas.
    * *Exemplo:* Selecionar quais anúncios exibir em um site para lucrar mais.
* **4.2 Maior Subsequência:** Achar padrões em sequências.
    * *Exemplo:* Previsão de tendências em gráficos de ações.
* **4.3 Mochila (0/1):** Decidir se leva ou não um item inteiro.
    * *Exemplo:* Otimizar o espaço de um servidor para hospedar as aplicações mais rentáveis.
* **4.4 Selos/Troco:** Resolver troco para sistemas de moedas estranhas.
    * *Exemplo:* Sistemas de pagamento internacionais com regras complexas.
* **4.5 Alinhamento de Sequências:** Comparar textos ou códigos.
    * *Exemplo:* O comando `git diff` comparando suas alterações no código.
* **4.6 Bellman-Ford:** Menor caminho lidando com custos negativos.
    * *Exemplo:* Protocolos de rede que detectam links que "gastam" energia ou crédito.
