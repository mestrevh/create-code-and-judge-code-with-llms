/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

const int MAX_SIZE = 51;

struct TFilha {
    char itens[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
};

void inicia(TFilha &f) {
    f.inicio = 0;
    f.fim = 0;
    f.tamanho = 0;
}

bool vazia(TFilha &f) {
    return f.tamanho == 0;
}

bool cheia(TFilha &f) {
    return f.tamanho == MAX_SIZE;
}

void enfileira(TFilha &f, char x) {
    if (!cheia(f)) {
        f.itens[f.fim] = x;
        f.fim = (f.fim + 1) % MAX_SIZE;
        f.tamanho++;
    }
}

char desenfileira(TFilha &f) {
    char x = '\0';
    if (!vazia(f)) {
        x = f.itens[f.inicio];
        f.inicio = (f.inicio + 1) % MAX_SIZE;
        f.tamanho--;
    }
    return x;
}

void removeRepetidosSeguidos(char s[]) {
    int len = strlen(s);
    if (len == 0) {
        return;
    }

    TFilha fila;
    inicia(fila);

    enfileira(fila, s[0]);

    for (int i = 1; i < len; i++) {
        if (s[i] != s[i - 1]) {
            enfileira(fila, s[i]);
        }
    }

    int i = 0;
    while (!vazia(fila)) {
        s[i] = desenfileira(fila);
        i++;
    }
    s[i] = '\0';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    char s[MAX_SIZE];
    std::cin.getline(s, MAX_SIZE);
    
    removeRepetidosSeguidos(s);
    
    std::cout << s << std::endl;
    
    return 0;
}
