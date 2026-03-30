/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string W;
    // A palavra principal W pode conter espaços, como no Teste 4.
    // std::getline é necessário para ler a linha inteira.
    std::getline(std::cin, W);

    int N;
    // Lê o número de palavras secundárias.
    // O operador >> para int ignora espaços em branco, incluindo o caractere de nova linha após W.
    std::cin >> N;

    // Depois de ler N com std::cin >> N, o caractere de nova linha restante na entrada
    // é ignorado automaticamente pelo próximo std::cin >> S (para string),
    // então um std::cin.ignore() explícito não é estritamente necessário aqui.

    int len_W = W.length();

    for (int i = 0; i < N; ++i) {
        std::string S;
        // As palavras secundárias S são fornecidas uma por linha e não contêm espaços,
        // conforme os casos de teste. std::cin >> S é apropriado.
        std::cin >> S;

        int len_S = S.length();

        // Se o tamanho da palavra secundária for maior que a principal,
        // ela não pode ser um prefixo, sufixo ou subpalavra.
        if (len_S > len_W) {
            std::cout << "PALAVRA LIVRE\n";
            continue;
        }

        // Verifica se S é um PREFIXO de W.
        // W.compare(0, len_S, S) == 0 compara a substring de W que começa em 0
        // e tem comprimento len_S com a string S.
        if (W.compare(0, len_S, S) == 0) {
            std::cout << "PREFIXO\n";
        }
        // Caso contrário, verifica se S é um SUFIXO de W.
        // W.compare(len_W - len_S, len_S, S) == 0 compara a substring de W
        // que começa em (len_W - len_S) e tem comprimento len_S com a string S.
        // A condição len_S <= len_W é garantida pelo if anterior.
        else if (W.compare(len_W - len_S, len_S, S) == 0) {
            std::cout << "SUFIXO\n";
        }
        // Caso contrário, verifica se S é uma SUBPALAVRA de W.
        // W.find(S) retorna std::string::npos se S não for encontrada.
        // Se for encontrada, e não foi classificada como prefixo/sufixo, é uma subpalavra.
        else if (W.find(S) != std::string::npos) {
            std::cout << "SUBPALAVRA\n";
        }
        // Se nenhuma das condições acima for atendida, S é uma PALAVRA LIVRE.
        else {
            std::cout << "PALAVRA LIVRE\n";
        }
    }

    return 0;
}