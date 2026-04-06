# Tecnologia de Rede Lan's

Tecnologias que envolvem camada física e de enlance (cada 1 e 2).

- Lan's IEEE dominam redes locais

## Grupo IEEE 802

- 802.1: Introdução e arquitetura de protocolos LAN's
- 802.2: LLC (Logcal Link Control)
- 802.3: Ethernet (CSMA/CD)
- 802.4: Token Bus (inativo)
- 802.5: Token Ring
- 802.6: Distributed (Queue Dual Bus - MAN) (inativo)
- 802.11: Wireless LAN

## 802.3 CSMA/CD

- Conhecido como ehternet, mas existe diferença
- Rede lógica 10mbps.
- É a tencologia LAN mais usada no mercado
- Na camada de enlance LLC utiliza o 802.2
- Especifica vários tipos de meio fisico (Cabos)
- Existe um cabeamento proposto (bem detalhado)
- A codificação usada 802.3 a 10mbps é a manchester
- Esta adoção se deve a facilitação dos clocks dos equipamentos por meio das transições que existem no meio de cada bit
- 01010101 e 101010111, pré-ambulo composto por 7 bytes

## Formatos do Quadro 802.3

|7 |1 |6 |6 |2 | 0-1500 |0-46|4|
|--|--|--|--|--|--------|----|-|
|Pré ambulo| Start of frame delimiter | Destination Adress | Source Adress | Length of data field | DATA | PAD | Checksum |


- O padrão define um <u>tamanho mínimo de 64 bytes</u> para um quadro.
- PAD só é necessário quando 1 quadro inteiro é menor que 64 bytes.
- Um quadro varia de $64 \leq Quadro \leq 1518$

Ex.: Se um dispositivo B quer mandar 3040 bytes será assim:

| Q0 | C | B | 1500 | ... | ... | -> PAD = 0 |
|----|---|---|------|-----|-----|------------|
|Q1 | C | B | 1500 | ... | ... | -> PAD = 0 |
|Q2 | C | B | 40 | 6 | ... | -> PAD = 6 bytes |

> $64 - 18  = 48$ bytes


## Endereços Ethernet

- 6 Bytes = 3 do fabrincante + 2 livre (MAC ADRESS)
- Multicast: Primeiro bit do endereço é igual a 1
- Broadcast: FF-FF-FF-FF-FF-FF

## Algoritmo de Backoff Exponecial

- Se uma estação deleta uma colisão, ela para na hora e envia um sinal jamming para alertar as outras estações
- Após uma colisão, o tempo é divido em slots de tamanho 51,2$\mu s$ (mircosegundo)
- Cada estação tetna trasnmitir depois de um certo numero de slots
- Limite de colisões sucessivas é 16, pós isso é considerado erro de rede
