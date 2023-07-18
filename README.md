# Yank'kis vs Chini
## Cancelado


![aaea0b275da6b47f3c7516bbbda473e7](https://github.com/Geroldor/Trabalho-ed-baloes/assets/114019959/feabf438-8e25-4f48-88a0-e0dc7c6b30d0)

  O mundo de Pandora vive momentos de tensão entre os povos Ya’nki e Chi’ni. O povo
Chi’ni enviou secretamente balões para espionar o território dos Ya’nki. Estes descobriram objetos
voadores e enviam caças para derrubá-los via bombas de detonação por afastamento. Entretanto, os
balões tiram fotos e enviam-nas para sua base de observação.

  As fotos podem retratar desde instalações militares ou logísticas de grande importância até
regiões vazias ou pouco relevantes. Por isso, a base avalia cada foto e atribui a ela um número que
denota seu grau de importância: quanto maior o número, maior a importância.
O sensor fotográfico do balão possui uma certa capacidade de observação: o raio de
abrangência e a faixa de foco. Observe Ilustração 1. O texto v_O_v representa um balão. A sua
câmera fotográfica está posicionada na metade da parte inferior (você pode supor que está sob a
letra O). O raio de abrangência está representado pela segmento rotulado com a letra r. A
profundidade (representado pela letra p) é a distância abaixo do balão em que o foco da câmera
começa a ficar nítido. A profundidade h representa a faixa em que o foco continua nítido. Desta
forma, a câmera capturará apenas os elementos que estiverem dentro da região pontilhada em
vermelho.2

No exemplo abaixo, os elementos capturados estão coloridos e os não capturados estão
em cinza.

![image](https://github.com/Geroldor/Trabalho-ed-baloes/assets/114019959/63f7bc33-595b-4615-8aea-27fd12553477)

Um caça tenta derrubar um balão disparando uma bomba de detonação por afastamento.
Existem bombas de diferentes capacidades: A, B e C. Antes do lançamento o piloto define a
capacidade da bomba e a distância que a bomba deve percorrer antes de explodir.. Quando a bomba
atinge tal distância, ela detona-se e atinge qualquer elemento que estiver no raio de 10 unidades
(para bombas do tipo A), 15 unidades (tipo B) ou 30 unidades (tipo C) do ponto da explosão,
destruindo-o.

![image](https://github.com/Geroldor/Trabalho-ed-baloes/assets/114019959/ac2332bd-5665-4044-8982-85ca65445a28)

A Ilustração 2 mostra dois caças (representados por |-T-| ) disparando bombas de
capacidades diferentes e a dLorem ipsum ..istâncias diferentes. Note que uma das bombas atinge um balão e um
círculo. A outra não acerta nenhum alvo.
A fim de direcionar o tiro, o caça pode ser rotacionado. Note a Ilustração 3. O caça da
esquerda não está rotacionado (ou seja, giro de 00), enquanto que o caça da direita está rotacionado
de um certo ângulo α.

![image](https://github.com/Geroldor/Trabalho-ed-baloes/assets/114019959/0c0002ad-8efa-4a17-a9c6-7ed26027a9ae)

## Entrada

A entrada é constituída, basicamente, um conjunto de formas geométricas básicas
(retângulos, círculos, etc) dispostos numa região do plano cartesiano .
Considere a Ilustração 4. Cada forma geométrica é definida por uma coordenada âncora
(marcada, na figura, por um pequeno ponto vermelho) e por suas dimensões. A coordenada âncora
do círculo é o seu centro e sua dimensão é definida por seu raio (r, na figura). A coordenada âncora
do retângulo é seu canto inferior esquerdo e suas dimensões são sua largura (w) e sua altura (h). A
coordenada âncora de um texto, normalmente, é o início do texto, porém, pode ser definida como o
meio ou o fim do texto. Por fim, uma linha é determinada por duas âncoras em suas extremidades.
As coordenadas que posicionam as formas geométricas são valores reais.
Cada forma geométrica é identificada por um número inteiro.

![image](https://github.com/Geroldor/Trabalho-ed-baloes/assets/114019959/f6e0bff4-c8b8-4c10-b093-1777b3a9e84a)

## Saida

Ao final do processamento do arquivo .qry é produzido o svg representando a situação final
do “banco de dados”, com as anotações descritas nas especificações.
Caso o arquivo .qry contenha um ou mais comandos df, outros arquivos svg devem ser
produzidos.

## Implementação

O “banco de dados” deve ser armazenado numa lista (deve ser conforme .h disponibilizado
no AVA). A implementação da lista deve ser dinâmica e duplamente encadeada. O iterador e as
funções map, filter, fold devem ser implementadas e utilizadas.
Cada balão deve armazenar 10 filas de fotos. A implementação da fila deve ser circular,
estática. Cada fila terá no máximo 15 elementos.
Usar o modelo de makefile disponibilizado no AVA da disciplina.
É terminantemente proibido declarar structs nos arquivos de cabeçalho (.h).
O programa deve estar bem modularizado (arquivos .h e .c). Cada estrutura de dados deve
estar em um módulo separado. O arquivo .h deve estar muito bem documentado (lembre-se que é
um “contrato”).
