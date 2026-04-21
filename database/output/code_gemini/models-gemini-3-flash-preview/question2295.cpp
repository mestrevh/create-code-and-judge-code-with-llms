/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

#define MAX 100

struct TPilhaDupla {
    int v[MAX];
    int topoE;
    int topoD;
};

void inicializar(TPilhaDupla *p) {
    p->topoE = -1;
    p->topoD = MAX;
}

void empilhar(TPilhaDupla *p, char lado, int item) {
    if (p->topoE + 1 < p->topoD) {
        if (lado == 'e') {
            p->v[++(p->topoE)] = item;
        } else if (lado == 'd') {
            p->v[--(p->topoD)] = item;
        }
    }
}

int desempilhar(TPilhaDupla *p, char lado) {
    if (lado == 'e') {
        if (p->topoE >= 0) {
            return p->v[(p->topoE)--];
        }
    } else if (lado == 'd') {
        if (p->topoD < MAX) {
            return p->v[(p->topoD)++];
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    TPilhaDupla p;
    inicializar(&p);

    char op, lado;
    int item;

    for (int i = 0; i < n; ++i) {
        if (!(cin >> op)) break;
        if (op == 'E') {
            if (cin >> lado >> item) {
                empilhar(&p, lado, item);
            }
        } else if (op == 'D') {
            if (cin >> lado) {
                int res = desempilhar(&p, lado);
                cout << res << "\n";
            }
        }
    }

    return 0;
}