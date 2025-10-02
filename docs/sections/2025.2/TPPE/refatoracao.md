# Refatoração: uma introdução

- O projeto representa os aspectos estrtuturais do nosso programa, como as classes se organizam, os aspectos comportamentais e os estados desses objetos.

Existe uma ligação entre o que foi projetado pelo que foi construido. Portanto modificações em alguns artefaos de projeto devem refletir nos demais artefatos.

- Alterações em código devem refletir nos artefatos de projeto
- Alterações em artefatos de projeto deme refletir no código.

A refatoração é o processo de modificar um sistema de software de modo que não altere o comportamento externamente observável e ainda melhorando sua estrutura interna.

- Em um desenvolvimento tradicional, inicialmente é feito o projeto e posteriormente a codificação.

## Ideias premiliminares

Em projetos pequenos as alterações e evoluções podem ser simple, quando o trecho a ser alterado pertence a um contexto maior, as dificuldades começam a aparecer.

- Ao refatorar sempre é necessário validar as alterações, um bom conjunto de teste lhe dá segurança necessária para alterar o programa posteriormente.
- Portanto um conjunto sólido de testes é necessario para analisar o trecho de código em questão
    - O comportamento variou?
    - Bugs foram introduzidos?
- Antes de iniciar a refatoração verifique se você possui um conjunto sólido de testes.
- Refatoração altera o programa em pequenos passos.
- Quando você refatora um código tornando-o mais legível, você está introduzindo no código o seu entendimento.

Melhorar o proejto de software nem sempre significa otimizar o projeto (seria o ideal):
- Minimizar o tamanho do código
- Melhorar a performance em tempo de execução

- Durante a atividade de refatoração não se preocupe com estes fatores. Refatore apenas.

## Conclusão

Refatoração é uma maneira controlada de melhorar o projeto sem alterar seu comportamento observável. Conhecimentos sólidos de princípios de um bom projeto são fundamentais para aplicação das operações de refatoração.

## Princípios de Refatoração

- Refactoring: Uma mudança feita na estrutura interna de um software. Pequenas mudanças no software.

Refatoração é uma maneira mais eficiente e controlada de limpar código.

- Quanto mais você refatorar, melhor você vai refatorar. Menores são as chances de introduzir falhas no software
- Cada oportunidade de refatoraça2o é feita

- Usuários que usam o sistema, não devem perceber a mudança ocorrida apos a refatoração.

Metáfora dos dois chapéus(Kent beck):

- Ao desenvolver software usando refatoração o tempo é dividido em duas atividades: evoluir e refatorar.
- Chapéu do programador: ao adicionar funcionalidades, não altere o código existente
    - Meça o progresso através de testes: crie-os e coloque-os para funcionar.

## Por que Refatorar?

Sem refatoração o código tende a degradar ao longo do tempo. Essa degradação tem efeito cumulativo. Busque sempre um projeto de software.

- Refatorar torna o software mais fácil de ser entendido:
    - Um bom projeto eé mais fácil de ser entendido por todos os membros da equipe.
    - Refatorar um projeto de software é uma forma de validar o seu entendimento
    - "Retirar a poeira da janela"
- Refatorar ajuda a encontrar bugs.


## Quando refatorar?

- Não tem um momento específico para refatorar, independentemente do desenvolvimento. Entretanto apresenta melhores resultados se realizado continuamente.

- Regra dos três:
    - 1 vez: Você simplesmente implementa.
    - 2 vez: Você duplica a implementação, ainda que você saibda que o código duplicado deve ser evitado a todo custo.
    - 3 vez: Você refatora.

- Refatore quando adicionar uma funcionalidade
- Refatore quando precisar eliminar um bug
- Refatore ao realizar revisões de código

## Problemas com refatoração

- Banco de dados:
    - Aplicações geralmente são fortemente acopladas aos esquemas de banco de dados.

- Mudanças de interfaces
    - Uma grande vantagem de objetos: altere sua implementação separadamente de sua interface
    - No entanto, algumas refatorações impactam elementos da interface.

- Quando não refatorar?
    - Há casos, em que o código está extremamente complexo e confuso.
    - Quando o **deadline** está próximo

## Oportunidades de Refatoração

### Código duplicado

Se o mesmo trecho de código aparece em diversos pontos do projeto. Será melhor unifica-los

### Método longo

Operações e extrair métodos, diminuir o tamanho de um método. 

### Classe grande

### Lista longa de parâmetros

Preservar o objeto inteiro

### Mudanças divergentes

Idealemnte mudanças em uma classe devem ser realizadas de modo pontual.

### Cirurgia com rifle

É o oposto da mudança com rifle: ao realizar uma mudança várias classes devem sofrer modificações.

### Inveja de recursos

Quando uma classe está mais interessado nos recursos de outras classes

### Aglomerado de dados

É comum que alguns itens de dados apareçam em conjunto em alguns pedaços de código

### Obsessões primitivas

Tipos de dados primiticos são oferecidos por todas as linguagens, a partir desse dados, sa2o formados estruturaas maiores, tais como registos e classes

### Instruções Switch

Condicional longa, solução mais elegante, é o uso de polimorfismo

### Hierarquias de heranças paralelas

### Classe preguiçosa

Classes que não poaauem 

### Generalidade especulativa

Projetos que são genéricos demais.

### Campo temporário

### Cadeia de mensagens

Ocorre quando um objeto chama outro que chama outro, que chama outro, e assim segue.

### Homem do meio

Caso em que a indireção e indesejável. Os métodos de uma classe simplesmente.

### Intimidade inapropriada

Algumas vezes uma classe tona muito íntima das demais

### Classes alternativas com interfaces diferentes

### Biblioteca de classes incompleta

Comum encontrar bibliotecas de classes que não oferecem todos os recursos dos quais precisamos

### Classe de dados

### Herança negada



