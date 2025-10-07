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

    std::string crime_delator, crime_delatado;
    double valor_delator = 0, valor_delatado = 0;

    std::cin >> crime_delator;

    if (crime_delator != "roubo" && crime_delator != "tráfico" && crime_delator != "homicídio") {
        std::cout << "Crime inválido." << std::endl;
        return 0;
    }

    if (crime_delator == "roubo" || crime_delator == "tráfico") {
        std::cin >> valor_delator;
    }

    std::cin >> crime_delatado;

    if (crime_delatado != "roubo" && crime_delatado != "tráfico" && crime_delatado != "homicídio") {
        std::cout << "Crime inválido." << std::endl;
        return 0;
    }
    
    if (crime_delatado == "roubo" || crime_delatado == "tráfico") {
        std::cin >> valor_delatado;
    }

    bool concedida = false;

    if (crime_delator == "roubo") {
        if (crime_delatado == "homicídio") {
            concedida = true;
        } else if (crime_delatado == "tráfico") {
            if (valor_delatado > 3 * valor_delator) {
                concedida = true;
            }
        } else if (crime_delatado == "roubo") {
            if (valor_delatado > 5 * valor_delator) {
                concedida = true;
            }
        }
    } else if (crime_delator == "tráfico") {
        if (crime_delatado == "homicídio") {
            concedida = true;
        } else if (crime_delatado == "tráfico") {
            if (valor_delatado > 5 * valor_delator) {
                concedida = true;
            }
        }
    } else if (crime_delator == "homicídio") {
        if (crime_delatado == "homicídio") {
            concedida = true;
        }
    }

    if (concedida) {
        std::cout << "Delação concedida." << std::endl;
    } else {
        std::cout << "Delação rejeitada." << std::endl;
    }

    return 0;
}
