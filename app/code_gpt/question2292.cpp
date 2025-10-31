/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <cstring>

char* hexadecimal(int n) {
    std::stack<char> pilha;
    if (n == 0) {
        char *result = new char[2];
        result[0] = '0'; 
        result[1] = '\0';
        return result;
    }
    
    while (n > 0) {
        int resto = n % 16;
        if (resto < 10)
            pilha.push(resto + '0');
        else
            pilha.push(resto - 10 + 'A');
        n /= 16;
    }
    
    char *result = new char[pilha.size() + 1];
    int i = 0;
    while (!pilha.empty()) {
        result[i++] = pilha.top();
        pilha.pop();
    }
    result[i] = '\0';
    
    return result;
}

int main() {
    int n;
    std::cin >> n;
    char* hex = hexadecimal(n);
    std::cout << hex << std::endl;
    delete[] hex;
    return 0;
}
