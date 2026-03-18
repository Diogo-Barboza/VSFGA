# Memória virtual

- A Memória Virtual cria uma "ilusão" para o processo de que ele tem um espaço de endereçamento contínuo e gigante, mesmo que os dados estejam espalhados entre a RAM e o Disco.

- **Paginação (Paging)**: O espaço de memória é dividido em blocos de tamanho fixo chamados páginas (no software) e frames (no hardware/RAM).

- **MMU (Memory Management Unit)**: É o hardware que traduz o endereço "mentiroso" (lógico) que o programa usa para o endereço "verdadeiro" (físico) na RAM.

- **Page Fault**: Ocorre quando o programa tenta acessar uma página que não está na RAM, mas sim no disco. O SO interrompe tudo, busca a página no disco, coloca na RAM e avisa: "Pode continuar".

> Exemplo: É como uma biblioteca. Você não precisa de todos os livros da cidade na sua mochila (RAM), você só pega os dois que vai ler hoje. A biblioteca inteira é a sua Memória Virtual.