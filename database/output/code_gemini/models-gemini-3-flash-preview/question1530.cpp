/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

// Estrutura para a lista encadeada de personagens envolvidos
struct StringNode {
    string name;
    StringNode* next;
};

// Estrutura para a lista encadeada de aparições de Joias
struct Appearance {
    int id;
    string stone;
    string holder;
    StringNode* involved;
    Appearance* next;
};

// Função recursiva para contar o número de aparições de uma joia específica
int countStones(Appearance* curr, const string& stone) {
    if (!curr) return 0;
    return (curr->stone == stone ? 1 : 0) + countStones(curr->next, stone);
}

// Função recursiva para adicionar uma nova aparição ao final da lista encadeada
Appearance* addEnd(Appearance* curr, Appearance* newNode) {
    if (!curr) return newNode;
    curr->next = addEnd(curr->next, newNode);
    return curr;
}

// Função recursiva para encontrar a aparição mais recente de uma joia específica
Appearance* findLatest(Appearance* curr, const string& stone, Appearance* best) {
    if (!curr) return best;
    if (curr->stone == stone) best = curr;
    return findLatest(curr->next, stone, best);
}

// Função recursiva para verificar se um personagem está presente na lista de envolvidos
bool isInvolved(StringNode* curr, const string& name) {
    if (!curr) return false;
    if (curr->name == name) return true;
    return isInvolved(curr->next, name);
}

// Função recursiva para liberar a memória de uma lista de personagens envolvidos
void deleteInvolved(StringNode* curr) {
    if (!curr) return;
    deleteInvolved(curr->next);
    delete curr;
}

// Função recursiva para remover uma aparição da lista principal com base no ID
Appearance* removeByID(Appearance* curr, int id, bool& removed) {
    if (!curr) return nullptr;
    if (curr->id == id) {
        Appearance* nextNode = curr->next;
        deleteInvolved(curr->involved);
        delete curr;
        removed = true;
        return nextNode;
    }
    curr->next = removeByID(curr->next, id, removed);
    return curr;
}

// Função recursiva para construir uma string formatada dos personagens envolvidos (separados por vírgula)
string getInvString(StringNode* curr) {
    if (!curr) return "";
    string res = curr->name;
    if (curr->next) res += ", " + getInvString(curr->next);
    return res;
}

// Função recursiva para construir a lista de aparições em que um personagem participou (PROCURAR)
void buildSearchString(Appearance* curr, const string& name, bool& found, string& res) {
    if (!curr) return;
    // Um personagem participa se for o portador ou se estiver na lista de envolvidos
    bool present = (curr->holder == name || isInvolved(curr->involved, name));
    if (present) {
        if (!found) {
            res += name + " participou das aparicoes:\n";
            found = true;
        }
        res += to_string(curr->id) + " (" + curr->stone + ").\n";
    }
    buildSearchString(curr->next, name, found, res);
}

int main() {
    // Otimização de I/O para C++ moderno
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    Appearance* head = nullptr;

    // Loop principal para processamento dos comandos (permitido conforme restrições)
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> ws; // Consome qualquer whitespace ou linha em branco anterior
        if (!(cin >> cmd)) break;

        if (cmd == "REGISTRAR") {
            int id; cin >> id;
            string stone; cin >> stone;
            string holder; cin >> ws; getline(cin, holder);
            int q; cin >> q;
            StringNode* invHead = nullptr;
            StringNode* invTail = nullptr;
            // Loop para leitura dos nomes dos envolvidos (permitido conforme restrições)
            for (int j = 0; j < q; ++j) {
                string pName; cin >> ws; getline(cin, pName);
                StringNode* newNode = new StringNode{pName, nullptr};
                if (!invHead) invHead = invTail = newNode;
                else {
                    invTail->next = newNode;
                    invTail = newNode;
                }
            }
            Appearance* newApp = new Appearance{id, stone, holder, invHead, nullptr};
            head = addEnd(head, newApp);
            cout << "Aparicao registrada com sucesso (" << countStones(head, stone) << ")." << endl;
        } else if (cmd == "PARADEIRO") {
            string stone; cin >> stone;
            Appearance* latest = findLatest(head, stone, nullptr);
            if (!latest) {
                cout << "Ainda nao houve nenhuma aparicao da Joia do(a) " << stone << "." << endl;
            } else {
                cout << "A ultima aparicao da Joia do(a) " << stone << " foi a: " << latest->id << "." << endl;
                cout << "Portador: " << latest->holder << "." << endl;
                string inv = getInvString(latest->involved);
                if (inv != "") {
                    cout << "Personagens envolvidos: " << inv << "." << endl;
                }
            }
        } else if (cmd == "PROCURAR") {
            string name; cin >> ws; getline(cin, name);
            bool found = false;
            string result = "";
            buildSearchString(head, name, found, result);
            if (!found) {
                cout << "Ainda nao houve nenhum envolvimento do personagem " << name << " em aparicoes de Joias." << endl;
            } else {
                cout << result;
            }
        } else if (cmd == "MENTIRA") {
            int id; cin >> id;
            bool removed = false;
            head = removeByID(head, id, removed);
            cout << "Aparicao removida com sucesso." << endl;
        } else {
            cout << "Comando invalido." << endl;
        }

        // Adiciona linha em branco entre saídas, conforme o formato solicitado
        if (i < N - 1) cout << endl;
    }

    return 0;
}