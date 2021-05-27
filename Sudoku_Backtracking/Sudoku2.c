#include "Sudoku2.h"

void imprimeMatriz(int matriz[TAM][TAM])
{
  int i, j;
  printf("\n");
  printf("     C0   C1   C2   C3   C4   C5   C6   C7   C8  \n"); 	//Indicacao Referente as Colunas do Tabuleiro
  for (i = 0; i < TAM; i++)                                     	//Percorre Linhas da Matriz
  {
    printf("L%d ", i);						        //Indicacao Referente as Linhas do Tabuleiro
    for (j = 0; j < TAM; j++) 						//Percorre Colunas da Matriz
    {
      printf("| %d |", matriz[i][j]); 					//Imprime o valor presente em cada quadrado do Tabuleiro
    }
    printf("\n");
  }
  printf("\n");
}

bool verificaSeTerminou(int matriz[TAM][TAM])
{
  int i, j;
  for (i = 0; i < TAM; i++)						//Percorre Linhas da Matriz
    for (j = 0; j < TAM; j++)						//Percorre Colunas da Matriz
      if (matriz[i][j] == 0)						//Busca Zeros(Equivalentes a Posicoes Vazias)
        return false;

  return true;
}

int verificaLinha(int valorInserido, int posicao, int matriz[TAM][TAM])
{
  int i;
  for (i = 0; i < TAM; i++)						//Percorre Linhas da Matriz
    if (matriz[i][posicao] == valorInserido)			 	//Verifica se na linha ja ha o valor que esta se tentando inserir
      return 0;

  return 1;
}

int verificaColuna(int valorInserido, int posicao, int matriz[TAM][TAM])
{
  int j;

  for (j = 0; j < TAM; j++)						//Percorre Colunas da Matriz
    if (matriz[posicao][j] == valorInserido)				//Verifica se na coluna ja ha o valor que esta se tentando inserir
      return 0;

  return 1;
}

int verificaSubMatriz(int valorInserido, int posicaoL, int posicaoC, int matriz[TAM][TAM])
{
  int posX, posY, i, j, submatrizX, submatrizY;

  if (posicaoL < 3)							//Indica as 3 linhas inicias como parte de uma submatrizX 0
    submatrizX = 0;												
  else if (posicaoL >= 3 && posicaoL < 6)				//Indica as 3 linhas do meio como parte de uma submatrizX 1
    submatrizX = 1;
  else if (posicaoL >= 6)						//Indica as 3 linhas finais como parte de uma submatrizX 2
    submatrizX = 2;
									//Com essas Vericacoes, encontra-se a submatrizXY onde o valor esta
									//tentando ser inserido.									

  if (posicaoC < 3)							//Indica as 3 colunas inicias como parte de uma submatrizY 0
    submatrizY = 0;
  else if (posicaoC >= 3 && posicaoC < 6)				//Indica as 3 colunas do meio como parte de uma submatrizY 1
    submatrizY = 1;
  else if (posicaoC >= 6)						//Indica as 3 colunas finais como parte de uma submatrizY 2	
    submatrizY = 2;

  for (i = 0; i < 3; i++)						//Percorre linhas de uma submatriz
    for (j = 0; j < 3; j++)						//Percorre colunas de uma submatriz
    {
      posX = (i + submatrizX * 3);					//Determina conforme percorre a submatriz a linha na matriz original
      posY = (j + submatrizY * 3);					//Determina conforme percorre a submatriz a coluna na matriz original
      if (matriz[posX][posY] == valorInserido)				//verifica se o valor a ser inserido ja esta na submatriz
        return 0;
    }

  return 1;
}
bool naoHaViolacao(int valorInserido, int posicaoL, int posicaoC, int matriz[TAM][TAM])
{

  if (valorInserido == 0)						//Como 0 representa vazio, nao ha violacoes nesse caso
    return true;	
									//Chamas todas as funcoes de Verificacao
  if (!verificaLinha(valorInserido, posicaoC, matriz) || !verificaColuna(valorInserido, posicaoL, matriz) || !verificaSubMatriz(valorInserido, posicaoL, posicaoC, matriz))
    return false;						

  return true;
}

void preencheMatriz2(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM])
{
  int num, n, i, j;
  printf("\nPREENCHA O TABULEIRO PERCORRENDO DO PRIMEIRO QUADRADO AO ULTIMO, DA ESQUERDA PARA DIREITA E DE CIMA PARA BAIXO, RESPECTIVAMENTE\n");
  printf("LEMBRE-SE: NESSE PROGRAMA O NUMERO 0 REPRESENTA UM QUADRADO VAZIO!\n");	//Instrucoes de Preenchimento da Matriz
  for (i = 0; i < TAM; i++)								//Percorre Linhas da Matriz 
    for (j = 0; j < TAM; j++)								//Percorre Colunas da Matriz	
    {
      printf("L%d C%d : ", i, j);							//Indicacao de posicao atual
      scanf("%d", &num);								//Solicita o Valor a Ser preenchido
      if (num > 0)
      {
        matriz[i][j] = num;								//Preenche com o Valor
        posicaoPreenchida[i][j] = true;							//Indica que a posicao foi preenchida
      }
    }
  printf("\n!!!Completamente Preenchido!!!\n");
  imprimeMatriz(matriz);								
  printf("\nEsta correta? ");
  printf("\n1- SIM \n2- NAO \n");
  scanf("%d", &n);									//Solicita Indicacao se foi preenchida corretamente
  while (n == 2)
  {
    printf("\nDigite a Linha a ser modificada: ");
    scanf("%d", &i);
    printf("\nDigite a Coluna a ser modificada: ");
    scanf("%d", &j);
    printf("\nDigite o novo valor: ");
    scanf("%d", &num);
    matriz[i][j] = num;									//Modifica o valor na posicao indicada anteriormente
    if (num > 0)
      posicaoPreenchida[i][j] = true;
    else
      posicaoPreenchida[i][j] = false;							
    imprimeMatriz(matriz);
    printf("\nEsta correta? ");
    printf("\n1- SIM \n2- NAO\n ");
    scanf("%d", &n);									//Solicita Indicacao Novamente
  }
}

void preencheMatriz(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM])
{
  int n, l, c, num, i, j;
  printf("\n!!!ATENCAO, QUANDO TIVER TERMINADO, INDIQUE COM [-1]!!!\n");
  printf("\nLEMBRE-SE: NESSE PROGRAMA O NUMERO 0 REPRESENTA UM QUADRADO VAZIO!\n");	//Instrucoes de Preenchimento da Matriz
  while (l != -1 || c != -1)								//Verificacao se acabou o preenchimento
  {
    printf("DIGITE A LINHA ONDE QUER INSERIR: ");
    scanf("%d", &l);
    printf("DIGITE A COLUNA ONDE QUER INSERIR: ");
    scanf("%d", &c);
    printf("DIGITE O NUMERO A SER INSERIDO: ");
    scanf("%d", &num);
    if (num > 0)
    {
      matriz[l][c] = num;								//Preenche com o Valor inserido
      posicaoPreenchida[l][c] = true;							//Indica que a posicao esta preenchida
    }
    else
      posicaoPreenchida[l][c] = false;
  }

  printf("\n!!!Valores Preenchidos!!!\n");

  imprimeMatriz(matriz);
  printf("\nEsta correta? ");
  printf("\n1- SIM \n2- NAO \n");
  scanf("%d", &n);									//Solicita Indicacao se foi preenchida corretamente
  while (n == 2)
  {
    printf("\nDigite a Linha a ser modificada: ");
    scanf("%d", &i);
    printf("\nDigite a Coluna a ser modificada: ");
    scanf("%d", &j);
    printf("\nDigite o novo valor: ");
    scanf("%d", &num);
    if (num <= 0)
      posicaoPreenchida[i][j] = false;
    else
    {
      matriz[i][j] = num;								//Modifica o Valor
      posicaoPreenchida[i][j] = true;
    }
    imprimeMatriz(matriz);
    printf("\nEsta correta? ");
    printf("\n1- SIM \n2- NAO \n");
    scanf("%d", &n);									//Realiza Nova Solicitacao
  }
}

void realizaBackTracking(int matriz[TAM][TAM], int posicaoL, int posicaoC, bool posicaoPreenchida[TAM][TAM]); //Declaracao Previa da Funcao que sera usada abaixo

void computaSudoku(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM], int posicaoL, int posicaoC)
{
  while (posicaoPreenchida[posicaoL][posicaoC] == true)			//Verifica se a posicao esta preenchida
  {									//Em caso Positivo, avanca uma posicao
    if (posicaoC == TAM - 1)
    {
      posicaoL++;							
      posicaoC = 0;
    }								
    else
      posicaoC++;
  }
  int tentativa = matriz[posicaoL][posicaoC] + 1;			//Atribui uma nova tentativa, a partir do valor na matriz
  if (tentativa > 9)							//Verifica se nao esta na ultima tentativa
  {	
    realizaBackTracking(matriz, posicaoL, posicaoC, posicaoPreenchida); //Funcao Detalhada mais a frente
    tentativa = 1;							//Reset da Tentativa
  }

  while (!naoHaViolacao(tentativa, posicaoL, posicaoC, matriz))		//Verifica se a tentativa eh valida
  {
    tentativa++;							//Caso nao seja, tenta um numero a frente
    if (tentativa > 9)							//Verifica se nao esta na ultima tentativa
    {
      realizaBackTracking(matriz, posicaoL, posicaoC, posicaoPreenchida); 
      tentativa = 1;							//Reset tentativa
    }
  }

  matriz[posicaoL][posicaoC] = tentativa;				//Atribui a tentativa a matriz

  if (verificaSeTerminou(matriz))
  {
    printf("\n--------------!!!Resolucao Final!!!---------------\n");
    imprimeMatriz(matriz);
    exit(0);								//Finaliza o Programa, caso terminada a Resolucao	
  }

  if (posicaoC == TAM - 1)						//Verifica se esta na ultima coluna
    computaSudoku(matriz, posicaoPreenchida, posicaoL + 1, 0);		//Chama a propria funcao na proxima posicao
  else
    computaSudoku(matriz, posicaoPreenchida, posicaoL, posicaoC + 1);	//Chama a propria funcao na proxima posicao
}

void realizaBackTracking(int matriz[TAM][TAM], int posicaoL, int posicaoC, bool posicaoPreenchida[TAM][TAM])
{
  matriz[posicaoL][posicaoC] = 0;					//Zera a posicao atual na matriz

  if (posicaoC == 0)							//Verifica se esta na coluna 0
  {									//para decrementar a posicao
    posicaoL--;						
    posicaoC = TAM - 1;
  }
  else
    posicaoC--;

  while (posicaoPreenchida[posicaoL][posicaoC] == true) 		//Verifica se a nova posicao esta preenchida
  {									//e volta mais uma posicao
    if (posicaoC == 0)
    {
      posicaoL--;
      posicaoC = TAM - 1;
    }
    else
      posicaoC--;
  }
  computaSudoku(matriz, posicaoPreenchida, posicaoL, posicaoC); 	//Chama a funcao anterior com as novas posicoes
}

void imprimeRegras(void)
{
  printf("===========================================================REGRAS=================================================================\n");
  printf("NESSE PROGRAMA O NUMERO 0 REPRESENTA UM QUADRADO VAZIO!");
  printf("\n");
  printf("-> Sudoku e jogado numa malha de 9x9 quadrados, dividida em sub-malhas de 3x3 quadrados, chamada quadrantes.\n");
  printf("-> Sudoku inicia com alguns dos quadrados ja preenchidos com numeros\n");
  printf("-> O objetivo do Sudoku eh preencher os quadrados vazios com numeros entre 1 e 9 (apenas um numero em cada quadrado) de acordo com o seguinte:\n");
  printf("  1 - Numero pode aparecer apenas uma vez em cada linha: ");
  printf("\n");
  printf("      | 0 | 2 | 8 | 0 | 1 | 0 | 0 | 0 | 9 | = PERMITIDO");
  printf("\n");
  printf("      | 0 | 1 | 8 | 0 | 1 | 0 | 0 | 0 | 9 | = NAO PERMITIDO");
  printf("\n");
  printf("  2 - Numero pode aparecer apenas uma vez em cada coluna: ");
  printf("\n");
  printf("      PERMITIDO     NAO PERMITIDO\n        | 0 |          | 0 |\n        | 2 |          | 0 |\n        | 8 |          | 0 |\n        | 0 |          | 0 |\n        | 1 |          | 0 |\n        | 0 |          | 0 |\n        | 0 |          | 0 |\n        | 0 |          | 0 |\n        | 9 |          | 0 |");
  printf("\n");
  printf("  3 - Numero pode aparecer apenas uma vez em cada quadrante: ");
  printf("\n");
  printf("      PERMITIDO        NAO PERMITIDO\n     | 0 | 0 | 9 |      | 0 | 0 | 9 |\n     | 3 | 2 | 0 |      | 3 | 2 | 0 |\n     | 6 | 0 | 5 |      | 9 | 0 | 5 |\n");
  printf("\n");
  printf("[Resumindo: Um numero pode aparecer apenas uma vez na linha, na coluna ou no quadrante]");
  printf("\n");
  printf("===========================================================REGRAS=================================================================");
}
