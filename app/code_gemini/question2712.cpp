/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum Era {
    PRESENTE,
    EGITO_ANTIGO,
    JAPAO_FEUDAL,
    BRASIL_FUTURISTA,
    INVALIDA
};

struct Person {
    std::string name;
    Era currentEra;
    Person* next;

    Person(std::string n, Era e) : name(n), currentEra(e), next(nullptr) {}
};

Person* head = nullptr;

Person* findPerson(const std::string& name) {
    Person* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void addPerson(const std::string& name, Era era) {
    Person* newNode = new Person(name, era);
    newNode->next = head;
    head = newNode;
}

Era getEraFromYear(int year) {
    if (year >= -3100 && year <= -30) {
        return EGITO_ANTIGO;
    }
    if (year >= 794 && year <= 1185) {
        return JAPAO_FEUDAL;
    }
    if (year >= 2235) {
        return BRASIL_FUTURISTA;
    }
    if (year == 2019) {
        return PRESENTE;
    }
    return INVALIDA;
}

std::string getEraString(Era era) {
    switch (era) {
        case PRESENTE: return "Presente";
        case EGITO_ANTIGO: return "Egito Antigo";
        case JAPAO_FEUDAL: return "Japao Feudal";
        case BRASIL_FUTURISTA: return "Brasil Futurista";
        default: return "";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name;
    int year;

    while (std::cin >> name >> year) {
        Era destEra = getEraFromYear(year);
        Person* traveler = findPerson(name);

        Era sourceEra = PRESENTE;
        if (traveler != nullptr) {
            sourceEra = traveler->currentEra;
        }

        if (destEra == INVALIDA || destEra == sourceEra) {
            std::cout << "Cuidado pra nao ficar preso no reino quantico, " << name << "." << std::endl;
        } else {
            std::cout << name << " foi de " << getEraString(sourceEra) << " para " << getEraString(destEra) << "." << std::endl;
            if (traveler == nullptr) {
                addPerson(name, destEra);
            } else {
                traveler->currentEra = destEra;
            }
        }
    }

    std::cout << std::endl;

    std::vector<std::string> egito_names;
    std::vector<std::string> japao_names;
    std::vector<std::string> brasil_names;

    Person* current = head;
    while (current != nullptr) {
        switch (current->currentEra) {
            case EGITO_ANTIGO:
                egito_names.push_back(current->name);
                break;
            case JAPAO_FEUDAL:
                japao_names.push_back(current->name);
                break;
            case BRASIL_FUTURISTA:
                brasil_names.push_back(current->name);
                break;
            default:
                break;
        }
        current = current->next;
    }

    if (!egito_names.empty()) {
        std::cout << "Egito Antigo:" << std::endl;
        std::sort(egito_names.begin(), egito_names.end());
        for (const auto& n : egito_names) {
            std::cout << n << std::endl;
        }
    }

    if (!japao_names.empty()) {
        std::cout << "Japao Feudal:" << std::endl;
        std::sort(japao_names.begin(), japao_names.end());
        for (const auto& n : japao_names) {
            std::cout << n << std::endl;
        }
    }

    if (!brasil_names.empty()) {
        std::cout << "Brasil Futurista:" << std::endl;
        std::sort(brasil_names.begin(), brasil_names.end());
        for (const auto& n : brasil_names) {
            std::cout << n << std::endl;
        }
    }

    current = head;
    while (current != nullptr) {
        Person* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    return 0;
}
