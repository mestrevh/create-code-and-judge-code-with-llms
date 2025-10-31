/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string periodo_historico(int ano, const std::string& referencia) {
    if (referencia == "aC") {
        if (ano > 4000) return "PRE-HISTORIA";
        if (ano >= 4001) return "ANTIGUIDADE";
    } else {
        if (ano < 477) return "ANTIGUIDADE";
        if (ano <= 1453) return "IDADE MEDIA";
        if (ano <= 1789) return "IDADE MODERNA";
        return "IDADE CONTEMPORANEA";
    }
    return "";
}

int main() {
    int ano;
    std::string referencia;
    std::cin >> ano >> referencia;
    std::cout << periodo_historico(ano, referencia) << std::endl;
    return 0;
}
