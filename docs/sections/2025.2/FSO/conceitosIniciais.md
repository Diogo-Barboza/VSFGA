# Conceitos iniciais para FSO

![Conceito de Computador](../../../images/FSOconceitos.png)

Portanto a definição de Sistema Operacional mais correta, seria aquele que roda somente em modo protegido. Esse modo protegido é onde somente o sistema consegue executar comandos por exemplo de gravação em disco.

## Maquina Estendida ou Abstrada

![Discos](../../../images/maquinaAbstrata.png)

Programar, gravar em diferentes tipos de discos é MUITO complicado. Portanto, os sistema cria essa máquina abstrata de forma que facilita bastante, por exemplo, tranforma o disco em arquivos, memoria ram em endereço etc.

## Gerenciador de Recursos (RAM)

- Alocação -> `malloc`

- Liberação -> `free`

- Proteção -> Estudaremos a fundo posteriormente.