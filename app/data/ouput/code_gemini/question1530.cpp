/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Envolvido {
    string nome;
    Envolvido* proximo = nullptr;
};

struct Aparicao {
    int id;
    string joia;
    string portador;
    Envolvido* listaEnvolvidos = nullptr;
    Aparicao* proximo = nullptr;
};

void adicionarEnvolvido(Envolvido*& head, const string& nome) {
    if (head == nullptr) {
        head = new Envolvido{nome, nullptr};
    } else {
        adicionarEnvolvido(head->proximo, nome);
    }
}

void destruirEnvolvidos(Envolvido*& head) {
    if (head != nullptr) {
        destruirEnvolvidos(head->proximo);
        delete head;
        head = nullptr;
    }
}

bool buscarEnvolvido(Envolvido* head, const string& nome) {
    if (head == nullptr) {
        return false;
    }
    if (head->nome == nome) {
        return true;
    }
    return buscarEnvolvido(head->proximo, nome);
}

void registrarAparicao(Aparicao*& head, Aparicao* novaAparicao) {
    if (head == nullptr) {
        head = novaAparicao;
    } else {
        registrarAparicao(head->proximo, novaAparicao);
    }
}

int contarAparicoesJoia(Aparicao* head, const string& joia) {
    if (head == nullptr) {
        return 0;
    }
    int count = (head->joia == joia) ? 1 : 0;
    return count + contarAparicoesJoia(head->proximo, joia);
}

Aparicao* buscarUltimaAparicaoRec(Aparicao* head, const string& joia, Aparicao* ultimaEncontrada) {
    if (head == nullptr) {
        return ultimaEncontrada;
    }
    Aparicao* proximaUltima = ultimaEncontrada;
    if (head->joia == joia) {
        proximaUltima = head;
    }
    return buscarUltimaAparicaoRec(head->proximo, joia, proximaUltima);
}

Aparicao* buscarUltimaAparicao(Aparicao* head, const string& joia) {
    return buscarUltimaAparicaoRec(head, joia, nullptr);
}

void removerAparicao(Aparicao*& head, int id) {
    if (head == nullptr) {
        return;
    }
    if (head->id == id) {
        Aparicao* temp = head;
        head = head->proximo;
        destruirEnvolvidos(temp->listaEnvolvidos);
        delete temp;
    } else {
        removerAparicao(head->proximo, id);
    }
}

void procurarEnvolvimentos(Aparicao* head, const string& nome, Aparicao*& resultadoHead) {
    if (head == nullptr) {
        return;
    }
    if (head->portador == nome || buscarEnvolvido(head->listaEnvolvidos, nome)) {
        Aparicao* resultadoNode = new Aparicao{head->id, head->joia, "", nullptr, nullptr};
        registrarAparicao(resultadoHead, resultadoNode);
    }
    procurarEnvolvimentos(head->proximo, nome, resultadoHead);
}

void destruirAparicoes(Aparicao*& head) {
    if (head != nullptr) {
        destruirAparicoes(head->proximo);
        destruirEnvolvidos(head->listaEnvolvidos);
        delete head;
        head = nullptr;
    }
}

void destruirListaResultados(Aparicao*& head) {
    if (head != nullptr) {
        destruirListaResultados(head->proximo);
        delete head;
        head = nullptr;
    }
}

void imprimirEnvolvidos(Envolvido* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->nome;
    if (head->proximo != nullptr) {
        cout << ", ";
        imprimirEnvolvidos(head->proximo);
    }
}

void imprimirResultadosProcurar(Aparicao* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->id << " (" << head->joia << ")." << endl;
    imprimirResultadosProcurar(head->proximo);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Aparicao* listaAparicoes = nullptr;

    for (int i = 0; i < n; ++i) {
        string comando;
        cin >> comando;

        if (comando == "REGISTRAR") {
            Aparicao* novaAparicao = new Aparicao;
            int quantidadeEnvolvidos;
            
            cin >> novaAparicao->id;
            cin >> novaAparicao->joia;
            cin.ignore(); 
            getline(cin, novaAparicao->portador);
            cin >> quantidadeEnvolvidos;
            
            if (quantidadeEnvolvidos > 0) {
                cin.ignore(); 
            }
            
            for (int j = 0; j < quantidadeEnvolvidos; ++j) {
                string nomeEnvolvido;
                getline(cin, nomeEnvolvido);
                adicionarEnvolvido(novaAparicao->listaEnvolvidos, nomeEnvolvido);
            }
            
            registrarAparicao(listaAparicoes, novaAparicao);
            
            int total = contarAparicoesJoia(listaAparicoes, novaAparicao->joia);
            cout << "Aparicao registrada com sucesso (" << total << ")." << endl;

        } else if (comando == "PARADEIRO") {
            string joia;
            cin >> joia;
            
            Aparicao* ultima = buscarUltimaAparicao(listaAparicoes, joia);
            
            if (ultima == nullptr) {
                cout << "Ainda nao houve nenhuma aparicao da Joia do(a) " << joia << "." << endl;
            } else {
                cout << "A ultima aparicao da Joia do(a) " << joia << " foi a: " << ultima->id << "." << endl;
                cout << "Portador: " << ultima->portador << "." << endl;
                if (ultima->listaEnvolvidos != nullptr) {
                    cout << "Personagens envolvidos: ";
                    imprimirEnvolvidos(ultima->listaEnvolvidos);
                    cout << "." << endl;
                }
            }

        } else if (comando == "PROCURAR") {
            string nome;
            cin.ignore();
            getline(cin, nome);
            
            Aparicao* resultados = nullptr;
            procurarEnvolvimentos(listaAparicoes, nome, resultados);
            
            if (resultados == nullptr) {
                cout << "Ainda nao houve nenhum envolvimento do personagem " << nome << " em aparicoes de Joias." << endl;
            } else {
                cout << nome << " participou das aparicoes:" << endl;
                imprimirResultadosProcurar(resultados);
                destruirListaResultados(resultados);
            }
            
        } else if (comando == "MENTIRA") {
            int id;
            cin >> id;
            removerAparicao(listaAparicoes, id);
            cout << "Aparicao removida com sucesso." << endl;
            
        } else {
            cout << "Comando invalido." << endl;
        }

        if (i < n - 1) {
            cout << endl;
        }
    }
    
    destruirAparicoes(listaAparicoes);

    return 0;
}
