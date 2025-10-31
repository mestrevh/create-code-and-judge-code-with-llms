/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string tipo_despesa;
    std::cin >> tipo_despesa;
    if (tipo_despesa == "PPF") {
        double valor;
        std::string rubrica;
        std::cin >> valor >> rubrica;
        if (rubrica != "SERV") {
            std::cout << "Pessoa física não pode fornecer materiais para o serviço público.\n";
        } else if (valor > 8000.0) {
            std::cout << "Excesso de pagamento para pessoa física.\n";
        } else {
            std::cout << "Pagamento liberado.\n";
        }
    } else if (tipo_despesa == "PPJ") {
        double valor;
        std::string rubrica;
        std::cin >> valor >> rubrica;
        if (rubrica == "CAP" && valor > 5000000.0) {
            std::cout << "O valor para pagamento da rubrica de capital não pode exceder R$ 5M.\n";
        } else if (rubrica == "CUST" && valor > 2000000.0) {
            std::cout << "O valor para pagamento da rubrica de custeio não pode exceder R$ 2M.\n";
        } else if (rubrica == "SERV" && valor > 500000.0) {
            std::cout << "O valor para pagamento da rubrica de serviços não pode exceder R$ 500K.\n";
        } else {
            std::cout << "Pagamento liberado.\n";
        }
    } else if (tipo_despesa == "PP") {
        double valor;
        std::cin >> valor;
        if (valor > 4000.0) {
            std::cout << "Excesso de pagamento para pessoal.\n";
        } else {
            std::cout << "Pagamento liberado.\n";
        }
    } else {
        std::cout << "Despesa inválida.\n";
    }
    return 0;
}
