/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int v1[10], v2[10], v3[10];
    
    for (int i = 0; i < 10; i++) {
        cin >> v1[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cin >> v2[i];
    }
    
    for (int i = 0; i < 10; i++) {
        v3[i] = v1[i] + v2[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cout << v3[i] << (i < 9 ? " " : "");
    }
    
    return 0;
}
