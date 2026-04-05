/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

class HuxleyCode {
public:
    int dado;
    HuxleyCode* proximo;

    HuxleyCode(int v) : dado(v), proximo(nullptr) {}

    static HuxleyCode* inserir(HuxleyCode* head, int v) {
        if (head == nullptr || v < head->dado) {
            HuxleyCode* novo = new HuxleyCode(v);
            novo->proximo = head;
            return novo;
        }
        head->proximo = inserir(head->proximo, v);
        return head;
    }

    static void imprimir(HuxleyCode* head) {
        if (head == nullptr) return;
        cout << head->dado << "\n";
        imprimir(head->proximo);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    HuxleyCode* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int v;
        if (cin >> v) {
            head = HuxleyCode::inserir(head, v);
        }
    }

    HuxleyCode::imprimir(head);

    return 0;
}