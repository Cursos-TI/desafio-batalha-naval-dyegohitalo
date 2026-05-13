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
// Define o tamanho fixo do tabuleiro (10x10).
#define TAM 10

// Função principal do programa, ponto de entrada da execução em C.

int main() {

    // Matriz Do Tabuleiro.
    // Cria uma matriz bidimensional chamada tabuleiro.
    // Cada posição representa uma célula do jogo.
    int tabuleiro[TAM][TAM];

    // Inicialização Do Tabuleiro.

    // Percorre todas as linhas do tabuleiro.
    for (int linha = 0; linha < TAM; linha++) {

        // Percorre todas as colunas do tabuleiro.
        for (int coluna = 0; coluna < TAM; coluna++) {

            // Inicializa todas as posições com 0.
            // 0 representa água.
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Navio Em Formato De Cruz.
    // Valor Utilizado: 3.

    // Parte vertical da cruz.
    // Preenche a coluna 3 da linha 0 até a linha 4.
    for (int linha = 0; linha < 5; linha++) {

        tabuleiro[linha][3] = 3;
    }

    // Parte horizontal da cruz.
    // Preenche a linha 2 da coluna 1 até a coluna 5.
    for (int coluna = 1; coluna <= 5; coluna++) {

        tabuleiro[2][coluna] = 3;
    }

    // Habilidade Em Formato De Losango.
    // Valor Utilizado: 2.

    // Coordenadas centrais da habilidade.
    int centroLinha = 5;
    int centroColuna = 7;

    // Percorre todo o tabuleiro.
    for (int linha = 0; linha < TAM; linha++) {

        for (int coluna = 0; coluna < TAM; coluna++) {

            // Calcula a distância da posição atual
            // até o centro do losango.
            int distancia =
                abs(linha - centroLinha) +
                abs(coluna - centroColuna);

            // Se a distância for menor ou igual a 2,
            // a posição faz parte do losango.
            if (distancia <= 2) {

                // Evita sobrescrever partes do navio.
                if (tabuleiro[linha][coluna] == 0) {

                    // Marca a área da habilidade com valor 2.
                    tabuleiro[linha][coluna] = 2;
                }
            }
        }
    }

    // Habilidade Em Formato De Triângulo/Cone.
    // Valor Utilizado: 1.

    // Coordenadas de origem da habilidade.
    int origemLinha = 5;
    int origemColuna = 2;

    // Cria o formato triangular.
    // O triângulo cresce para baixo.
    for (int linha = 0; linha < 3; linha++) {

        // Controla a expansão lateral da habilidade.
        for (int coluna = -linha; coluna <= linha; coluna++) {

            // Calcula posição final no tabuleiro.
            int posLinha = origemLinha + linha;
            int posColuna = origemColuna + coluna;

            // Validação Dos Limites Do Tabuleiro.
            // Verifica se a posição calculada existe
            // dentro do tabuleiro.
            if (posLinha >= 0 && posLinha < TAM &&
                posColuna >= 0 && posColuna < TAM) {

                // Evita sobrescrever navios já existentes.
                if (tabuleiro[posLinha][posColuna] == 0) {

                    // Marca a área da habilidade com valor 1.
                    tabuleiro[posLinha][posColuna] = 1;
                }
            }
        }
    }

    // Exibindo O Tabuleiro.

    // Título do jogo.
    printf("TABULEIRO BATALHA NAVAL\n\n");

    // Espaçamento para alinhar o cabeçalho.
    printf("  ");

    // Mostrando As Colunas.

    // Mostra os números das colunas de 0 até 9.
    for (int coluna = 0; coluna < TAM; coluna++) {

        printf("%d ", coluna);
    }

    // Quebra de linha após o cabeçalho.
    printf("\n");

    // Área De Exibição Das Linhas e Do Conteúdo.

    // Percorre todas as linhas do tabuleiro.
    for (int linha = 0; linha < TAM; linha++) {

        // Exibe o número da linha.
        printf("%d ", linha);

        // Percorre as colunas da linha atual.
        for (int coluna = 0; coluna < TAM; coluna++) {

            // Exibe o valor armazenado na posição.
            // 0 = água.
            // 1 = habilidade cone.
            // 2 = habilidade losango.
            // 3 = navio.
            printf("%d ", tabuleiro[linha][coluna]);
        }

        // Quebra de linha após imprimir a linha completa.
        printf("\n");
    }

    // // Encerramento Do Programa.

    // Retorna 0 indicando execução bem-sucedida
    return 0;
}