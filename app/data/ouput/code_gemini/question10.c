
#include <stdio.h>
#include <stdlib.h> // Para qsort
#include <string.h> // Para strcmp, strcspn, strcpy

#define MAX_NAMES 300
#define MAX_NAME_LEN 51 // Máximo de 50 caracteres para o nome + terminador nulo

// Função de comparação para qsort. Compara duas strings.
int compareStrings(const void *a, const void *b) {
    // Os ponteiros 'a' e 'b' apontam para elementos do array 'names'.
    // Como 'names' é um array 2D de caracteres (char names[MAX_NAMES][MAX_NAME_LEN]),
    // 'a' e 'b' são ponteiros para linhas do array (char[MAX_NAME_LEN]).
    // Podemos fazer um cast direto para 'const char *' porque o nome de um array
    // decai para um ponteiro para seu primeiro elemento.
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n;
    char names[MAX_NAMES][MAX_NAME_LEN];
    char buffer[MAX_NAME_LEN]; // Buffer temporário para ler nomes com fgets

    // Loop principal para processar múltiplas listas de convidados
    while (scanf("%d", &n) == 1 && n != 0) {
        // Consome o caractere de nova linha deixado por scanf após ler 'n'.
        // Isso é importante para que fgets leia a primeira linha de nome corretamente.
        getchar(); 

        // Lê os 'n' nomes
        for (int i = 0; i < n; i++) {
            // Usa fgets para ler o nome. É mais seguro que scanf("%s", ...)
            // pois permite nomes com espaços e previne overflow de buffer.
            if (fgets(buffer, MAX_NAME_LEN, stdin) != NULL) {
                // Remove o caractere de nova linha que fgets inclui, se presente.
                // strcspn retorna o índice da primeira ocorrência do caractere '\n'.
                // Se '\n' não for encontrado, retorna o comprimento da string.
                buffer[strcspn(buffer, "\n")] = 0;
                // Copia o nome do buffer temporário para o array de nomes
                strcpy(names[i], buffer);
            }
        }

        // Ordena o array de nomes usando qsort
        // - names: ponteiro para o primeiro elemento do array a ser ordenado
        // - n: número de elementos no array
        // - sizeof(names[0]): tamanho de cada elemento (uma string de MAX_NAME_LEN caracteres)
        // - compareStrings: função de comparação personalizada
        qsort(names, n, sizeof(names[0]), compareStrings);

        // Imprime os nomes ordenados, cada um em uma nova linha
        for (int i = 0; i < n; i++) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
