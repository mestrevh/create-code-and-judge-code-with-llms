/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void Plantar_e_Colher(int mes) {
    std::vector<std::string> plantar;
    std::vector<std::string> colher;

    switch (mes) {
        case 1: // Janeiro
            plantar.push_back("algodão");
            colher.push_back("manga");
            break;
        case 2: // Fevereiro
            colher.push_back("soja");
            colher.push_back("milho");
            colher.push_back("manga");
            break;
        case 3: // Março
            plantar.push_back("feijão");
            colher.push_back("soja");
            colher.push_back("milho");
            break;
        case 4: // Abril
            plantar.push_back("feijão");
            colher.push_back("soja");
            colher.push_back("milho");
            break;
        case 5: // Maio
            colher.push_back("soja");
            colher.push_back("milho");
            break;
        case 6: // Junho
            colher.push_back("milho");
            colher.push_back("algodão");
            colher.push_back("feijão");
            break;
        case 7: // Julho
            colher.push_back("algodão");
            colher.push_back("feijão");
            break;
        case 8: // Agosto
            colher.push_back("algodão");
            break;
        case 10: // Outubro
        case 11: // Novembro
        case 12: // Dezembro
            plantar.push_back("milho");
            plantar.push_back("soja");
            break;
        default:
            break;
    }

    bool pode_plantar = !plantar.empty();
    bool pode_colher = !colher.empty();

    if (pode_plantar) {
        std::cout << "Hora de plantar ";
        for (size_t i = 0; i < plantar.size(); ++i) {
            std::cout << plantar[i];
            if (i < plantar.size() - 1) {
                std::cout << " e ";
            }
        }
    }

    if (pode_plantar && pode_colher) {
        std::cout << " e colher ";
    } else if (pode_colher) {
        std::cout << "Hora de colher ";
    }

    if (pode_colher) {
        for (size_t i = 0; i < colher.size(); ++i) {
            std::cout << colher[i];
            if (i < colher.size() - 1) {
                std::cout << " e ";
            }
        }
    }

    if (pode_plantar || pode_colher) {
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int dia, mes;
    std::cin >> dia >> mes;
    Plantar_e_Colher(mes);
    return 0;
}
