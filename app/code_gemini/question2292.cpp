/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct No {
    int valor;
    No* proximo;
};

struct TPilha {
    No* topo;
    int tamanho;
};

void inicializa(TPilha &p) {
    p.topo = NULL;
    p.tamanho = 0;
}

bool estaVazia(TPilha &p) {
    return p.topo == NULL;
}

void empilha(TPilha &p, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = p.topo;
    p.topo = novo;
    p.tamanho++;
}

int desempilha(TPilha &p) {
    if (estaVazia(p)) {
        return -1; // Indicador de erro
    }
    int valor = p.topo->valor;
    No* temp = p.topo;
    p.topo = p.topo->proximo;
    delete temp;
    p.tamanho--;
    return valor;
}

char* hexadecimal(int n) {
    TPilha p;
    inicializa(p);

    if (n == 0) {
        empilha(p, 0);
    } else {
        while (n > 0) {
            empilha(p, n % 16);
            n = n / 16;
        }
    }

    int len = p.tamanho;
    char* hexStr = new char[len + 1];
    
    for (int i = 0; i < len; ++i) {
        int val = desempilha(p);
        if (val < 10) {
            hexStr[i] = val + '0';
        } else {
            hexStr[i] = val - 10 + 'A';
        }
    }
    
    hexStr[len] = '\0';
    
    return hexStr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    char* resultado = hexadecimal(n);
    std::cout << resultado << std::endl;
    delete[] resultado;
    return 0;
}
