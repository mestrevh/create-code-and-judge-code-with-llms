/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

const int MAX = 15;

struct TPilhaDupla {
    int itens[MAX];
    int topo_e;
    int topo_d;
};

void inicializa(TPilhaDupla &p) {
    p.topo_e = -1;
    p.topo_d = MAX;
}

bool cheia(const TPilhaDupla &p) {
    return p.topo_e + 1 == p.topo_d;
}

bool vazia(const TPilhaDupla &p, char lado) {
    if (lado == 'e') {
        return p.topo_e == -1;
    } else {
        return p.topo_d == MAX;
    }
}

void empilha(TPilhaDupla &p, int item, char lado) {
    if (cheia(p)) {
        return;
    }
    if (lado == 'e') {
        p.topo_e++;
        p.itens[p.topo_e] = item;
    } else {
        p.topo_d--;
        p.itens[p.topo_d] = item;
    }
}

int desempilha(TPilhaDupla &p, char lado) {
    int item;
    if (lado == 'e') {
        item = p.itens[p.topo_e];
        p.topo_e--;
    } else {
        item = p.itens[p.topo_d];
        p.topo_d++;
    }
    return item;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    TPilhaDupla pilha;
    inicializa(pilha);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char operacao;
        std::cin >> operacao;

        if (operacao == 'E') {
            char lado;
            int item;
            std::cin >> lado >> item;
            empilha(pilha, item, lado);
        } else if (operacao == 'D') {
            char lado;
            std::cin >> lado;
            if (!vazia(pilha, lado)) {
                int item_desempilhado = desempilha(pilha, lado);
                std::cout << item_desempilhado << std::endl;
            }
        }
    }

    return 0;
}
