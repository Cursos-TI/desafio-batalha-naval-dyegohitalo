// Inclusão das bibliotecas padrão:
// stdio.h -> necessária para funções de entrada/saída (printf, etc.)
// stdlib.h -> biblioteca padrão de utilidades gerais (No momento ainda não usada, só para manter um padrão).
#include <stdio.h>
#include <stdlib.h>

// Faculdade Estácio de Sá.
// Aluno: Dyego Hitalo da Silva Cruz Matos.
// Desafio: Xadrez Nível Novato.
// Posicionando Navios No Tabuleiro.

#define TAM 10  // Define o tamanho do tabuleiro como 10x10 (constante).
#define NAVIO 3 // Define o tamanho do navio como 3 posições (constante).

int main()
{
    // Matriz Do Tabuleiro.
    // Declara uma matriz bidimensional de tamanho TAM x TAM (10x10).
    // Cada posição representará uma célula do tabuleiro do Batalha Naval.
    int tabuleiro[TAM][TAM];

    // Inicializa com água (0).
    // Loop externo: percorre todas as linhas do tabuleiro (0 a 9).
    for (int linha = 0; linha < TAM; linha++)
    {
        // Loop interno: percorre todas as colunas de cada linha (0 a 9).
        for (int coluna = 0; coluna < TAM; coluna++)
        {
            tabuleiro[linha][coluna] = 0; // Define cada posição como 0 (água).
        }
    }

    // Posicionando Os Navios.
    // Navio horizontal.
    // Define a linha inicial onde o navio horizontal será posicionado (linha 2, índice 2).
    int linhaH = 2;
    // Define a coluna inicial onde o navio horizontal será posicionado (coluna 3, índice 3).
    int colunaH = 3;

    // Posiciona navio horizontal.
    // Loop que se repete 3 vezes (tamanho do navio definido como 3).
    for (int i = 0; i < NAVIO; i++)
    {
        // Acessa a posição do tabuleiro na linha fixa (linhaH) e coluna variável (colunaH + i).
        // i = 0: posiciona na coluna 3.
        // i = 1: posiciona na coluna 4.
        // i = 2: posiciona na coluna 5.
        // Define o valor 3 nessa posição, representando parte do navio.
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Exibindo O Tabuleiro.
    // Imprime cabeçalho do jogo no console.
    printf("TABULEIRO BATALHA NAVAL\n\n");

    // Área de Impressão Das Letras Das Colunas.
    // Imprime dois espaços no início para alinhar com os números das linhas.
    printf("  ");

    // Loop que usa caracteres para representar as colunas de A a J.
    // 'A' é o código ASCII 65, 'J' é o código ASCII 74.
    for (char letra = 'A'; letra <= 'J'; letra++)
    {
        // Imprime a letra seguida de um espaço para formatação.
        printf("%c ", letra);
    }

    // Pula para a próxima linha após imprimir todas as letras.
    printf("\n");

    // Área de Impressão Das Linhas Do Tabuleiro.
    // Loop externo: percorre todas as linhas do tabuleiro (0 a 9).
    for (int linha = 0; linha < TAM; linha++)
    {

        // Imprime o número da linha com formatação de 2 dígitos (ex: " 1", " 2", ..., "10").
        // linha + 1 porque o usuário vê de 1 a 10, mas a matriz usa 0 a 9.
        printf("%2d ", linha + 1);

        // Loop interno: percorre todas as colunas da linha atual (0 a 9).
        for (int coluna = 0; coluna < TAM; coluna++)
        {
            // Imprime o valor contido na posição [linha][coluna] do tabuleiro.
            // 0 representa água, 3 representa parte do navio.
            printf("%d ", tabuleiro[linha][coluna]);
        }

        // Pula para a próxima linha após imprimir todas as colunas da linha atual.
        printf("\n");
    }

    // Retorna 0 indicando que o programa foi executado com sucesso.
    return 0;
}