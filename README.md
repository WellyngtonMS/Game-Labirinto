# Game-Labirinto
### LABIRINTO

Considere o problema de um rato apanhado em uma armadilha e que tenta encontrar o caminho para saída de um labirinto, Figura 1 (a). O rato espera escapar do labirinto, tentando sistematicamente todas as rotas. Se atinge um corredor sem saída refaz suas etapas até a última posição e começa pelo menos mais um caminho não tentado. Para cada posição, o rato pode ir em uma dentre quatro posições: direita, esquerda, para cima ou para baixo. Independentemente de quão perto está da saída, ele sempre tenta os caminhos abertos nessa ordem, o que pode levar a algumas voltas desnecessárias. Retendo a informação que permite retomar a procura depois que o corredor sem saída é atingido, o rato usa um método chamado de retrocesso ou backtracking.

O labirinto é implementado como uma matriz de caracteres bidimensional, na qual as passagens são marcadas com 0s, as paredes com 1s, as posições de saída pela letra “e” e a posição inicial do rato pela letra “m” de acordo com a Figura 1 (b). Nesse programa o problema do labirinto é levemente generalizado permitindo que a saída esteja em qualquer posição do labirinto (imagine a posição de saída como tendo um elevador que leva o rato para fora da armadilha) e permitindo que passagens estejam nas linhas-limite. Para se proteger de cair fora da matriz ao tentar continuar seu caminho quando uma célula aberta for atingida em uma das linhas limites, o rato também tem que verificar constantamente se está em uma posição de linha-limite ou não. Para evitar isso, o programa automaticamente coloca uma estrutura de 1s ao redor do labirinto dado pelo usuário.

<p align="center">
  <img src="https://user-images.githubusercontent.com/54148100/93724853-1b900e00-fb81-11ea-9182-02da56d57ca2.PNG" alt="Sublime's custom image"/>
</p>

Figura 1: (a) um rato no labirinto; (b) matriz de caracteres representando o labirinto.

O programa usa duas pilhas: uma para inicializar e outra para implementar o retrocesso. O usuário fornece o labirinto, uma linha de cada vez. O labirinto fornecido pelo usuário pode ter qualquer número de linhas e qualquer número de colunas. As únicas hipóteses que o programa considera são que todas as linhas são do mesmo comprimento e que ele usa somente estes caracteres: qualquer número de 1s, qualquer número de 0s, um “e” e um “m”. As linhas são colocadas na pilha mazeRows na ordem em que foram entradas depois de anexar um 1 no início e um 1 no fim. Depois que todas as linhas foram fornecidas, o tamanho de armazenamento da matriz pode ser determinado, e então as linhas são transferidas da pilha para a matriz.

Uma segunda matriz chamada mazeStack é usada no processo de escapar do labirinto. Para lembrar os caminhos não tentados para as tentativas subsequentes, as posições das vizinhanças não tentadas da posição corrente (se alguma) são armazenadas na pilha e sempre na mesma ordem, primeiro a vizinhança superior, então a inferior, então a esquerda e finalmente a direita. Depois de colocar na pilha as avenidas abertas, o rato toma a posição mais no topo, e tenta segui-la, primeiro armazenando as vizinhanças não tentadas e então tentando a posição mais no topo e assim por diante, até que ele atinge a saída ou esgota todas as possibilidades e se encontra preso na armadilha. Para evitar de cair dentro de um laço infinito de caminhos tentados que já tenham sido investigados, cada posição visitada do labirinto é marcada com
um ponto.

A pilha armazena as coordenadas das posições das células. Isso poderia ser feito, por exemplo, usando-se duas pilhas de inteiros para as coordenadas x e y. Outra possibilidade é usar uma pilha de inteiros com ambas as coordenadas armazenadas em uma variável de inteiro, com o auxílio da operação de transferência. No programa um TAD MazeCell é usado com dois campos de dados, x e y, de modo que uma mazeStack é usada para estocar objetos MazeCell.

<p align="center">
  <img src="https://user-images.githubusercontent.com/54148100/93724964-da4c2e00-fb81-11ea-8c2e-4ef7fb530556.PNG" alt="Sublime's custom image"/>
</p>

Figura 2: Exemplo de como se processa um labirinto.

Considere o exemplo mostrado na Figura 2. O programa imprime o labirinto depois de cada etapa realizada pelo rato. Depois que o usuário entra no labirinto:
  ````
  1100
  000e
  00m1
  ````
  O labirinto é imediatamente circundado com a estrutura de 1s entryCell e currentCell são inicializados para (3 3) e exitCell para (2 4), Figura 2 (a).
  
Como currentCell não é igual a exitCell, todas as quatro vizinhanças da célula corrente (3 3) são tentadas e somente duas delas são candidatas para o processamento: (3 2) e (2 3); em consequência, elas são colocadas na pilha. A pilha é verificada para ver se ela contém alguma posição, e como ela não está vazia, a posição mais no topo (3 2) se torna corrente (Figura 2 (b)).

CurrentCell ainda não é igual a exitCell; em consequência, as duas opções viáveis acessíveis a partir de (3 2) são colocadas na pilha: as posições (2 2) e (3 1). Note que a posição que contém o rato não está incluída na pilha. Depois que a posição corrente é marcada como visitada, a situação do labirinto fica como na Figura 2 (c). Agora a posição mais no topo (3 1) é extraída da pilha e se torna o valor de currentCell. O processo continua até que a saída seja atingida, como mostrado na etapa por etapa na Figura 2 (d)-(f).

Note que a etapa quatro Figura 2 (d), a posição (2 2) é colocada na pilha, embora ela já esteja lá. No entanto, isso não cria um risco, porque, quando a segunda instância dessa posição é retirada da pilha, todos os caminhos que se direcionam dessa posição
já foram investigados usando a primeira instância dessa posição na pilha. Note que o rato faz um desvio, embora haja um caminho mais curto a partir de sua posição inicial para a saída.

Faça adaptações para melhorar o software e utilizar alguma biblioteca gráfica 2D de maneira que a visualização do labirinto e a movimentação do rato sejam mais apropriadas. Então, utilize o conjunto de caracteres (i.e. “0”s, “1”s, “m”, e “.”)
apenas para realização de testes.
