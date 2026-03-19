# Resumo do semestre

Essa matéria foi meio conturbada, plano de ensino mesmo não teve. Portanto, vou passar por tópicos que ele passou no semestre.

## Testes Unitários
Os testes unitários garantem que cada pequena parte do sistema funcione isoladamente.

### Conceitos Chave
- **FIRST:** Princípios de testes rápidos, independentes e repetíveis.
- **Suite de Testes:** Agrupamento de casos de teste relacionados.
- **Testes Parametrizados:** Execução do mesmo teste com múltiplos conjuntos de dados.
- **Assertions:** Comandos que validam se o resultado obtido é igual ao esperado.

## TDD (Test Driven Development)
Metodologia onde o desenvolvimento é guiado pelos testes.

### O Ciclo de Desenvolvimento
1. **Red:** Criar um teste que falhe para uma função que ainda não existe.
2. **Green:** Implementar o código mais simples possível para passar no teste.
3. **Refactor:** Limpar o código mantendo o teste passando.

## Refatoração e Código Limpo
A refatoração busca melhorar a qualidade do código sem alterar o que o usuário vê.

### Operações Comuns
- **Extrair Método:** Quebrar funções grandes em menores.
- **Extrair Classe:** Separar responsabilidades excessivas.
- **Encapsular Atributo:** Proteger o acesso direto aos dados da classe.

### Maus-cheiros (Code Smells)
- Código Duplicado.
- Métodos excessivamente longos.
- "Inveja de Recursos" (uma classe que usa mais dados de outra do que os seus próprios).

## Programação Defensiva e Tratamento de Erros
- **Defesa:** Validar entradas de usuário e APIs externas antes de processar.
- **Exceções:** Utilizar blocos `try-catch` para capturar falhas previstas e garantir que o sistema continue operando ou feche com segurança.

## Princípios de Design de Software
- **Simplicidade (KISS):** Keep It Simple, Stupid. Não complique o que pode ser simples.
- **Modularidade:** Dividir o sistema em partes menores e independentes.
- **Extensibilidade:** O código deve ser fácil de aumentar, mas difícil de quebrar (Princípio Aberto/Fechado).
- **DRY (Don't Repeat Yourself):** Evite duplicação de lógica.

## Componentes e Frameworks
- **Caixa-Branca:** Focado em herança; você precisa conhecer a estrutura interna.
- **Caixa-Preta:** Focado em interfaces; você usa o comportamento sem se preocupar com a implementação.