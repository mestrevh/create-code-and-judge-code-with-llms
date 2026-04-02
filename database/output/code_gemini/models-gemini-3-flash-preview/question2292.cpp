/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct TPilha {
    int topo;
    int elementos[100];
};

void inicializar(TPilha &p) {
    p.topo = -1;
}

void empilhar(TPilha &p, int x) {
    p.elementos[++p.topo] = x;
}

int desempilhar(TPilha &p) {
    return p.elementos[p.topo--];
}

bool vazia(TPilha &p) {
    return p.topo == -1;
}

char* hexadecimal(int n) {
    static char res[20];
    TPilha p;
    inicializar(p);

    if (n == 0) {
        empilhar(p, 0);
    } else {
        while (n > 0) {
            empilhar(p, n % 16);
            n /= 16;
        }
    }

    int i = 0;
    const char* digitos = "0123456789ABCDEF";
    while (!vazia(p)) {
        res[i++] = digitos[desempilhar(p)];
    }
    res[i] = '\0';
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        cout << hexadecimal(n) << endl;
    }

    return 0;
}