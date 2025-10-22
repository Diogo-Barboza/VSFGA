# Memória

Memória RAM é um dos principais recursos computacaionais e precisa ser cuidadosamente gerenciado, pois é um recurso finito e não existe memória rápida e não-volátil. Portanto, os SOs., modernos precisam ser projetados para lidar com essas características

- Os registradores são manipulados diretamente pelos programas ou pelo hardware
- Memória cache e completamente gerenciada pelo hardware
- O foco da gerência de memória é da RAM
- Já a memória secundária (Discos, etc) serão vistas na gerência de arquivos 

## Funcções Básicas

- Programas são armazenados em memória secundária e precisam ser transferidas para a memória principal
- O SO deve transferir programas da memória secundária para a principal antes de serem executados
- Devido a diferença de tempo, é desejável que se mantenha em memória os processos em uso e reduzir as operações e E/S para melhor performace do sistema.

Dessa forma, a gerência de memória deve manter o maior níemro de processos residentes, buscando maximizar o compartilhamentpo de recursos, mesmo na ausência de espaço livre, deve-se permitir que novos processos sejam criados.

- A memória alocada para um programa deve ser protegida.

A principal função de um gerente de memória é determinar o esquema de gerência que será utilizado e implementar eficientemente. Mas também possui funções secundárias que não dependem do esquema de gerência.


## Esquemas de Gerenciamento de Memória 

### Sem abstração de memória

- Esquema de alocação contígua simples
- Implementada nos primeiros SOs
- Cada programa vê uma memória física completa
- O usuário possui controle sobre todo o espaço de memória

Nesses sistemas, a instrução LOAD R1, 1000:

- CPU move o conteúdo da posic1ão de memória 1000 para o registrador 1
- Normalmente, cada endereço de memória possio 8 bits

Porém, observe que nesse caso dois programas iguais não podem executar ao mesmo tempo, se um programa escreve um valor em uma outra posição, o outro programa irá sobrescrever esse valor alguma hora, mas o modelo sem abstração de memória permite diferente organizações na estrutura da memória e SO.

- Nesse modelo, o SO pode estar na parte inferior da memória e o restante está disponível para o usuário.
- Erros nos programas podem causar falhas gerais no sistema. Por isso, o hardware pode ser necessário para proteger áreas do SO de programas executando, para isso, pode usar um registrador para proteção.
- O SO é armazenado em memória de leitura e escrita
- Modo utilizado pelos primeiros computadores pessoais como MS-DOR
- A porção ROM é chamada de BIOS
- Multiprogramação, faz partições de memória, porém isso não é trivial, para mudar o tamanho dessas partições é preciso reiniciar o SO.


## Algortimos de Controle de Memória

## Swapping e Overlay