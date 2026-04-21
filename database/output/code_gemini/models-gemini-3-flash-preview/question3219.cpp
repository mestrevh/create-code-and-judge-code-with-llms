/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

/**
 * Função iterativa para contar as ocorrências de um caractere em uma string.
 * @param sequencia A string onde a busca será realizada.
 * @param buscado O caractere a ser contado.
 * @return O número de ocorrências do caractere na string.
 */
int contarOcorrencias(const std::string& sequencia, char buscado) {
    int contador = 0;
    for (size_t i = 0; i < sequencia.length(); ++i) {
        if (sequencia[i] == buscado) {
            contador++;
        }
    }
    return contador;
}

int main() {
    // Otimização de I/O padrão para C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string sequencia;
    char caractereBuscado;

    // Leitura das duas entradas fornecidas
    // cin >> string lê até o primeiro espaço em branco ou quebra de linha
    if (std::cin >> sequencia >> caractereBuscado) {
        // Chamada da função iterativa
        int total = contarOcorrencias(sequencia, caractereBuscado);

        // Verificação do resultado para formatação da saída conforme especificado
        if (total > 0) {
            std::cout << "O caractere buscado ocorre " << total << " vezes na sequencia." << std::endl;
        } else {
            std::cout << "Caractere nao encontrado." << std::endl;
        }
    }

    return 0;
}