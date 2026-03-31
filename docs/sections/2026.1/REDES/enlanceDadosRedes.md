# Camada de enlance de Dados e Rede - 30/05

## OSI - 7 Camadas

- **1 - Camada Física:** Taxa de bits.
- **2 - Data Link:** Taxa de bits confiável (Geralmente, através de uma cópia das informações na origem). No fim, juntamos bits, virando quadros. Portanto, taxa de quadros.
- **3 - Camada de Rede:** Trabalha com pacotes (1 pacote está dentro de 1 ou mais quadros). Roteamento (melhor caminho para chegar no outro lado).
- **4 - Camada de Trasnporte:** Primeira camada Fim-a-Fim de fato (Momento em que o dispositivo A se comunica com o dispositivo B).
- **5 - Camada de Sessão:** Gerência de diálogos (Quem vai falar, quem vai escutar, pode sempre alternar).
- **6 - Camada de Apresentação:** Apresenta o formato das Máquinas (Arquiterturas diferentes, alocações diferentes, etc).
- **7 - Camada de Aplicação:** Camada do usuário em sí.

## TCP/IP - 4 camadas

- **1 - Host-to-Network**
- **2 - Internet:**
- **3 - Transporte:**
- **4 - Aplicação:**

## Criação de Quadro (Frame)

Camada de Rede -> Camada de Enlance de Dados. Para esse enlance, existem técnicas para a delimitação, para indicar onde um frame começa e onde termina.

- Contador de caracteres no cabeçalho
- Delimitadores explícitos (DLE-STX e DLE-ETX com Caracter-Stuffing) ou (Bits e com bit-stuffing).

> DLE-STX A DLE *DLE* B DLX-ETX. Neste exemplo, o transmissor quando avista um "DLE" adiciona outro, isto, porque eles sempre devem estar em pares e se existem "DLE-DLE" ele sabe que não é o fim.

> Nos bits funciona mais ou menos da mesma forma, mas com "01111110" para início e fim, confome avista 5 "1s" o transmissor adiciona um '0'.

## Transmissão com Erros e Perdas de Quadro

Sempre o cabeçalho possui informações cruciais para o envio e o recebimento conforme, como, numeração do quadro, tipo de quadro (Se é de informação ou de reconhcimento).

## Controle de fluxo

- Assegura que uma entidade trasnmissora não afogue uma entidade receptora com dados.
- Protocolos falam quando se pode transmitir quadros.

## Controle de Erro

Um quadro é inútil se teve bits alterados. Portanto, existem:

- **Checagem de paridade:** Detecção de erro, com 1 bit, 1 bit para cada byte.
- **Código Polinomiais:** CRC (Cyclic Redundancy Click) efetuam operações matemáticas para detectar erros em rajadas (MAIS EFICIENTE).

Se já foi perdido, temos mecanismos de controle:

- ARQ (Automatic Repeat Request)
    - Confirmação positiva (ACK)
    - Retransmissão depois de Timeout
    - Retransmissão depois da confirmação negativa (NACK)

### CRC

Polinómios padrão G de ordem r, cálculo de m bits de informação M se insere r bits zero ao final:

- Transmite $T = x^r M - n$
- Na recepção, divide-se o T por G. O **resultado deve ter resto 0.**
- Possui fácil implementação via hardware.

## Stop-and-Wait

Ineficiente, principalmente em logas distâncias e taxas altas de transmissão.

## Protocolos de Janela Deslizante

Utilização do recurso piggyback (Poucos bits a mais no cabeçalho).

- Melhor utilização da banda, consiste em manter números de sequência que indicarão quais quadros poderão ser evitados e quais ainda não.

Aqui irei especificar um pouco melhor alguns conceitos importantes:

- **Número de sequência:** Cada quadro possui um número sequencial que é incrementado a cada novo.
- **Janela de Transmissão:** Mantem os números em sequência de quadros já enviados (porem, ainda não confirmado).
- **Janela de Recepção:** Mantem os números de sequência para quadros.
- **Tamanho da Janela de Transmissão:** Número máximo de quadros sem a confimação do receptor.
- **Tamanho da Janela de Recepção:** Número máximo de quadros antes de enviar a confirmação.

### Controle de Erro

- **Go-Back-N:** Pede-se a retransmissão de todos quadros desde o número N.
- **Selective-Repeat:** Pede somente a retransmissão dos quadros que não chegaram: aproveita o que foi recebido, mesmo que fora de ordem.

