#include "Sudoku2.h"

int main()
{
  int caso, aux;										//Variaveis indicadoras de Caso
  int matrizSudoku[TAM][TAM] = {0};								//Matriz referente ao tabuleiro
  bool posicaoPreenchida[TAM][TAM] = {false};							//Matriz que indica posicoes Preenchidas na matriz acima
  printf("-----------------------TABULEIRO BASE--------------------------\n");
  imprimeMatriz(matrizSudoku);									//Imprime o Tabuleiro Vazio para o Usuario saber como é

  do
  {
    printf("\n\n");
    printf("\n0 - ENCERRAR PROGRAMA\n");
    printf("\n1 - RESOLVER SUDOKU\n");
    printf("\n2 - TERMINAR SUDOKU\n");
    printf("\n3 - REGRAS\n");
    printf("\nESCOLHA O QUE DESEJA FAZER: ");
    scanf("%d", &caso);										//Solicita indicacao de qual vai ser a acao do usuario
    printf("\n");
    switch (caso)										//Menu que responde a indicacao do usuario
    {
    case 0:
      printf("SAINDO ");									
      break;
    case 1:
      printf("METODOS DE INSERCAO: \n");
      printf("\n1 - ESCOLHA AS LINHAS E COLUNAS A SEREM PREENCHIDAS\n");
      printf("\n2 - PREENCHA TODA A MATRIZ\n");
      printf("\nESCOLHA O METODO DE INSERCAO: ");
      scanf("%d", &aux);									//Solicita qual o metodo de insercao que o usuario prefere
      if (aux == 1)
        preencheMatriz(matrizSudoku, posicaoPreenchida);
      else if (aux == 2)
        preencheMatriz2(matrizSudoku, posicaoPreenchida);
      else
      {
        printf("Escolha invalida!!!");
        exit(0);
      }
      computaSudoku(matrizSudoku, posicaoPreenchida, 0, 0);					//Realiza A Resolucao de acordo com o que foi preenchido
      break;

    case 2:
      preencheMatriz2(matrizSudoku, posicaoPreenchida);						//Solicita para preencher a matriz por completo
      computaSudoku(matrizSudoku, posicaoPreenchida, 0, 0);					//Realiza a Resolucao de acordo com o que foi preenchido
      break;

    case 3:
      imprimeRegras();										//Imprime as regras
      break;

    default:
      printf("OPCAO INDISPONIVEL!\n");
    }
  } while (caso != 0);										//Retornar ao Menu enquanto o programa nao ser finalizado ou o usuario indicar que quer sair

  system("pause");
  return 0;
}
