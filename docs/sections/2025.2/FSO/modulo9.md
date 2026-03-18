# Sistemas de arquivos

É a camada lógica que gerencia como os bits são gravados magneticamente ou em chips flash.

- **Estrutura de Metadados**: Cada arquivo tem um "RG" (metadados) que contém: nome, tamanho, quem pode ler/escrever e, o mais importante, onde os pedaços do arquivo estão no disco.

- **Journaling**: Sistemas modernos (como NTFS ou EXT4) usam um "diário". Antes de escrever um arquivo, eles anotam o que vão fazer. Se a energia cair no meio, o sistema lê o diário e sabe exatamente onde parou para não corromper os dados.

- **Alocação**: Pode ser Contígua (tudo junto, rápido mas gera buracos/fragmentação) ou Encadeada/Indexada (espalhado pelo disco, como uma lista ligada).

> Exemplo: Pense em um armário de arquivos de aço. O Sistema de Arquivos é o método de etiquetas e gavetas que impede que todos os papéis fiquem jogados no chão.