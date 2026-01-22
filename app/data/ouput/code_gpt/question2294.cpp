/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <cstring>

void removeRepetidosSeguidos(char s[]) {
    std::queue<char> fila;
    int n = strlen(s);
    
    if (n == 0) return;

    fila.push(s[0]);
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            fila.push(s[i]);
        }
    }
    
    int i = 0;
    while (!fila.empty()) {
        s[i++] = fila.front();
        fila.pop();
    }
    s[i] = '\0';
}

int main() {
    char s[51];
    std::cin.getline(s, 51);
    removeRepetidosSeguidos(s);
    std::cout << s << std::endl;
    return 0;
}
