# Compilador HIPO

Este projeto é um compilador desenvolvido para o computador hipotético [HIPO](https://www.ime.usp.br/~jstern/miscellanea/MaterialDidatico/hipo.htm) descrito por Julio M. Stern.

## Descrição do Projeto

O compilador HIPO traduz programas escritos em uma linguagem de alto nível para a linguagem de máquina do computador HIPO.

## Sintaxe
Cada instrução é composta de um código mais um endereço relativo a esse código, da seguinte maneira:

<p align="center">+IIEE</p>

Onde II é o código de uma das instruções abaixo, e EE é o endereço ao qual ela se refere (00 <= EE M= 99). A seguir, [EE] indica o conteúdo de EE, [AC] indica o conteúdo do acumulador, AI indica o apontador de instrução e (XXX) indica o código simbólico abreviado.


```
11: (CEA) Copie o conteúdo do endereço EE no acumulador. (AC recebe [EE]).
12: (CAE) Copie o conteúdo do acumulador no endereço EE. (EE recebe [AC])
21: (SOM) Some o conteúdo do endereço EE com o conteúdo do acumulador e guarde o resultado no acumulador. (AC recebe [AC] + [EE])
22: (SUB) Subtraia o conteúdo do endereço EE do conteúdo do acumulador e guarde o resultado no acumulador. (AC recebe [AC] - [EE])
23: (MUL) Multiplique o conteúdo do endereço EE com o conteúdo do acumulador e guarde o resultado no acumulador. (AC recebe [AC] * [EE])
24: (DIV) Divide o conteúdo do acumulador pelo conteúdo do endereço EE e guarde o resultado no acumulador. (AC recebe [AC] / [EE])
25: (MOD) [AC] recebe o resto da divisão [AC] / [EE].
31: (LER) Leia um número e guarde-o no endereço EE. (EE recebe o valor lido)
41: (IMP) Imprima o conteúdo do endereço EE.
50: (NOP) Nenhuma operação é efetuada.
51: (DES) Desvie a execução para o endereço EE, i.e. AI recebe EE.
52: (DPO) Se o conteúdo do acumulador for maior do que zero, desvie a execução para o endereço EE. (Se [AC] > 0, AI recebe EE).
53: (DPZ) Se o conteúdo do acumulador for maior ou igual a zero, desvie a execução para o endereço EE. (Se [AC] >= 0, AI recebe EE).
54: (DNE) Se o conteúdo do acumulador for menor do que zero, desvie a execução para o endereço EE. (Se [AC] < 0, AI recebe EE.)
55: (DNZ) Se o conteúdo do acumulador for menor ou igual a zero, desvie a execução para o endereço EE. (Se [AC] <= 0, AI recebe EE).
56: (DDZ) Se o conteúdo do acumulador for diferente de zero, desvie a execução para o endereço EE. (Se [AC] != 0, AI recebe EE).
57: (DZZ) Se o conteúdo do acumulador for igual a zero, desvie a execução para o endereço EE. (Se [AC] = 0, AI recebe EE).
58: (DDF) Se o conteúdo do acumulador for diferente de infinito, desvie a execução para o endereço EE. (Se [AC] != INF, AI recebe EE).
59: (DFF) Se o conteúdo do acumulador for infinito, desvie a execução para o endereço EE. (Se [AC] = INF, AI recebe EE).
61: (ADE) Desloque os dígitos do acumulador uma posição à esquerda, desprezando o digito mais significativo.
62: (ADD) Desloque os dígitos do acumulador uma posição à direita, desprezando o digito menos significativo.
70: (PAR) Pare a execução do programa. OBS.: Esta instrução deve ser executada para encerrar a execução do programa.
```

## Como compilar

Para compilar, é preciso ter o SFML.
Dentro da pasta build, execute o comando

````
make all
```


