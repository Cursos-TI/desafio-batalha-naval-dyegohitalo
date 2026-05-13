// Inclusão das bibliotecas padrão:
// stdio.h -> necessária para funções de entrada/saída (printf, etc.)
// stdlib.h -> biblioteca padrão de utilidades gerais (No momento ainda não usada, só para manter um padrão).
#include <stdio.h>
#include <stdlib.h>

// Faculdade Estácio de Sá.
// Aluno: Dyego Hitalo da Silva Cruz Matos.
// Desafio: Xadrez Nível Novato.
// Posicionando Navios No Tabuleiro.

// Definição De Constantes.

// Define o tamanho do tabuleiro como 10x10.
#define TAM 10

// Função principal do programa, ponto de entrada da execução em C.

int main() {

    // Matriz Do Tabuleiro.
    // Cria uma matriz bidimensional chamada tabuleiro.
    // Cada posição representa uma célula do jogo.
    // 0 = água.
    // 3 = parte do navio.
    int tabuleiro[TAM][TAM];

    // Inicialização Do Tabuleiro.

    // Percorre todas as linhas do tabuleiro.
    for (int linha = 0; linha < TAM; linha++) {

        // Percorre todas as colunas do tabuleiro.
        for (int coluna = 0; coluna < TAM; coluna++) {

            // Preenche cada posição com 0.
            // Isso representa água em todo o mapa.
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Posicionamento do Navio em Diagonal Principal.

    // Este loop posiciona o navio na diagonal principal.
    // Exemplo:
    // tabuleiro[0][0]
    // tabuleiro[1][1]
    // tabuleiro[2][2]
    // ...
    for (int i = 0; i < TAM; i++) {

        // Marca a posição da diagonal com o valor 3.
        tabuleiro[i][i] = 3;
    }

    // Exibindo O Tabuleiro.

    // Exibe o título do jogo
    printf("TABULEIRO BATALHA NAVAL\n\n");

    // Espaçamento inicial para alinhar as letras.
    printf("   ");

    // Área de Impressão Das Letras Das Colunas.

    // Percorre as letras de A até J.
    for (char letra = 'A'; letra <= 'J'; letra++) {

        // Exibe cada letra seguida de espaço.
        printf("%c ", letra);
    }

    // Quebra de linha após as letras.
    printf("\n");

    // Área de Impressão Das Linhas Do Tabuleiro.

    // Percorre todas as linhas da matriz.
    for (int linha = 0; linha < TAM; linha++) {

        // Exibe o número da linha.
        // %2d mantém alinhamento para números de 1 a 10.
        printf("%2d ", linha + 1);

        // Mostrando As Colunas.

        // Percorre todas as colunas da linha atual.
        for (int coluna = 0; coluna < TAM; coluna++) {

            // Mostra o conteúdo da posição atual.
            // 0 = água.
            // 3 = navio.
            printf("%d ", tabuleiro[linha][coluna]);
        }

        // Quebra de linha após imprimir uma linha completa.
        printf("\n");
    }

    // Encerramento Do Programa.

    // Retorna 0 indicando execução bem-sucedida
    return 0;
}