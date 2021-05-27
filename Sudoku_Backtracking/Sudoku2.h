#include <stdio.h>													//Bibliotecas Padrao
#include <stdlib.h>
#include <stdbool.h>													//Biblioteca para o uso do tipo bool
#define TAM 9														//Tamanho do Tabuleiro NxN

void imprimeMatriz(int matriz[TAM][TAM]);										//Imprime Matriz como Tabuleiro
bool verificaSeTerminou(int matriz[TAM][TAM]);										//Verifica se Matriz foi toda preenchida
int verificaLinha(int valorInserido, int posicao, int matriz[TAM][TAM]);						//Verifica se ha violacao com a linha
int verificaColuna(int valorInserido, int posicao, int matriz[TAM][TAM]);						//Verifica se ha violacao com a coluna
int verificaSubMatriz(int valorInserido, int posicaoL, int posicaoC, int matriz[TAM][TAM]);				//Verifica se ha violacao com a submatriz
bool naoHaViolacao(int valorInserido, int posicaoL, int posicaoC, int matriz[TAM][TAM]);				//Indica o resultado das Verificacoes
void preencheMatriz(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM]);						//Metodo 1 de preenchimento da matriz
void preencheMatriz2(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM]);						//Metodo 2 de preenchimento da matriz
void realizaBackTracking(int matriz[TAM][TAM], int posicaoL, int posicaoC, bool posicaoPreenchida[TAM][TAM]);		//Faz funcionar o Tentativa-Erro ->Forca Bruta
void computaSudoku(int matriz[TAM][TAM], bool posicaoPreenchida[TAM][TAM], int posicaoL, int posicaoC);			//Resolve o Sudoku
void imprimeRegras(void);												//imprime as Regras do Sudoku
