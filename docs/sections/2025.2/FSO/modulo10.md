# Gerenciador de dispositivos

O SO precisa lidar com hardwares de velocidades e naturezas completamente diferentes (um teclado é lento, um SSD é ultra veloz).

- **E/S Controlada por Interrupção**: Em vez de o processador ficar perguntando toda hora "O usuário digitou algo?", ele vai fazer outra coisa. Quando o teclado recebe um clique, ele envia um sinal elétrico (interrupção) que força o processador a parar e atender aquela tecla.

- **DMA (Direct Memory Access)**: Para dispositivos rápidos (como discos), o processador autoriza que o dispositivo escreva dados direto na RAM sem passar pelo processador a cada byte. Isso libera a CPU para cálculos pesados.

- **Buffering e Spooling**: * Buffer: Um espaço de memória para guardar dados temporariamente enquanto são transferidos (ex: carregar um vídeo do YouTube).

- **Spool**: Uma fila de espera (ex: fila de impressão).

> Exemplo: Quando você move o mouse, ele dá um "toque no ombro" do processador (interrupção) dizendo: "Ei, mudei de lugar, atualiza a seta aí!"