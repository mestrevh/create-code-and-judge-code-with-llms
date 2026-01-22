/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int code;
    while (std::cin >> code) {
        if (code == 0) {
            break;
        }

        int quantity;
        double price = 0.0;
        std::string item_name;
        bool valid_code = true;

        switch (code) {
            case 1:
                item_name = "Misto Quente";
                price = 2.50;
                break;
            case 2:
                item_name = "X-Tudo";
                price = 4.75;
                break;
            case 3:
                item_name = "Suco";
                price = 3.25;
                break;
            case 4:
                item_name = "Refrigerante";
                price = 3.00;
                break;
            default:
                valid_code = false;
                break;
        }

        if (valid_code) {
            std::cin >> quantity;
            std::cout << "Você escolheu " << item_name << std::endl;
            std::cout << "Sua conta é de R$" << std::fixed << std::setprecision(2) << quantity * price << std::endl;
        } else {
            std::cout << "Código inválido" << std::endl;
        }
    }

    return 0;
}
