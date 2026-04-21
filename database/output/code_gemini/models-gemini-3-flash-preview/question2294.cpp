/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct TFilha {
    char itens[105];
    int inicio;
    int fim;
};

void inicializar(TFilha *f) {
    f->inicio = 0;
    f->fim = 0;
}

bool vazia(TFilha *f) {
    return f->inicio == f->fim;
}

void enfileirar(TFilha *f, char c) {
    f->itens[f->fim++] = c;
}

char desenfileirar(TFilha *f) {
    return f->itens[f->inicio++];
}

void removeRepetidosSeguidos(char s[]) {
    if (s[0] == '\0') return;

    TFilha f;
    inicializar(&f);

    enfileirar(&f, s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[i - 1]) {
            enfileirar(&f, s[i]);
        }
    }

    int k = 0;
    while (!vazia(&f)) {
        s[k++] = desenfileirar(&f);
    }
    s[k] = '\0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[105];
    if (cin.getline(s, 105)) {
        removeRepetidosSeguidos(s);
        cout << s << endl;
    }

    return 0;
}