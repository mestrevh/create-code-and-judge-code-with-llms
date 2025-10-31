/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <map>

class Joia {
public:
    int id;
    std::string nome;
    std::string portador;
    std::list<std::string> envolvidos;

    Joia(int id, const std::string &nome, const std::string &portador, const std::list<std::string> &envolvidos)
        : id(id), nome(nome), portador(portador), envolvidos(envolvidos) {}
};

class Registro {
    std::map<std::string, std::list<Joia>> joias;

public:
    void registrar(int id, const std::string &nome, const std::string &portador, const std::list<std::string> &envolvidos) {
        joias[nome].emplace_back(id, nome, portador, envolvidos);
        std::cout << "Aparicao registrada com sucesso (" << joias[nome].size() << ").\n\n";
    }

    void paradeiro(const std::string &nome) {
        if (joias[nome].empty()) {
            std::cout << "Ainda nao houve nenhuma aparicao da Joia do(a) " << nome << ".\n\n";
        } else {
            const Joia &ultima = joias[nome].back();
            std::cout << "A ultima aparicao da Joia do(a) " << ultima.nome << " foi a: " << ultima.id << ".\n";
            std::cout << "Portador: " << ultima.portador << ".\n";
            if (!ultima.envolvidos.empty()) {
                std::cout << "Personagens envolvidos: ";
                for (const auto &envolvido : ultima.envolvidos) {
                    std::cout << envolvido << ", ";
                }
                std::cout.seekp(-2, std::ios_base::end);
                std::cout << ".\n\n";
            } else {
                std::cout << "\n";
            }
        }
    }

    void procurar(const std::string &nome) {
        bool encontrado = false;
        for (const auto &item : joias) {
            for (const auto &aparicao : item.second) {
                if (aparicao.portador == nome || std::find(aparicao.envolvidos.begin(), aparicao.envolvidos.end(), nome) != aparicao.envolvidos.end()) {
                    encontrado = true;
                    std::cout << nome << " participou das aparicoes:\n" << aparicao.id << " (" << item.first << ").\n";
                }
            }
        }
        if (!encontrado) {
            std::cout << "Ainda nao houve nenhum envolvimento do personagem " << nome << " em aparicoes de Joias.\n\n";
        }
    }

    void mentira(int id) {
        for (auto &item : joias) {
            item.second.remove_if([id](const Joia &j) { return j.id == id; });
            if (!item.second.empty() && item.second.back().id == id) {
                item.second.pop_back();
                std::cout << "Aparicao removida com sucesso.\n\n";
                return;
            }
        }
        std::cout << "Aparicao removida com sucesso.\n\n";
    }
};

void processar_comandos(Registro &registro) {
    std::string comando;
    while (std::getline(std::cin, comando)) {
        if (comando.empty()) continue;

        if (comando == "REGISTRAR") {
            int id, quantidade;
            std::string nome, portador;
            std::list<std::string> envolvidos;
            std::cin >> id >> nome >> portador >> quantidade;
            std::cin.ignore();
            for (int i = 0; i < quantidade; ++i) {
                std::string envolvido;
                std::getline(std::cin, envolvido);
                envolvidos.push_back(envolvido);
            }
            registro.registrar(id, nome, portador, envolvidos);
        } else if (comando == "PARADEIRO") {
            std::string nome;
            std::getline(std::cin, nome);
            registro.paradeiro(nome);
        } else if (comando == "PROCURAR") {
            std::string nome;
            std::getline(std::cin, nome);
            registro.procurar(nome);
        } else if (comando == "MENTIRA") {
            int id;
            std::cin >> id;
            std::cin.ignore();
            registro.mentira(id);
        } else {
            std::cout << "Comando invalido.\n\n";
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();  // Ignora a nova linha após N

    Registro registro;
    processar_comandos(registro);

    return 0;
}
