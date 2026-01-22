/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int start, end;
    
    while (true) {
        cin >> start;
        if (start < 1 || start > 9) {
            cout << "Insira um número inicial entre 1 e 9" << endl;
            continue;
        }
        break;
    }

    while (true) {
        cin >> end;
        if (end < 1 || end > 9) {
            cout << "Insira um número final entre 1 e 9" << endl;
            continue;
        }
        break;
    }

    if (start > end) {
        cout << "Nenhuma tabuada nesse intervalo" << endl;
        return 0;
    }

    for (int i = start; i <= end; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
    }

    return 0;
}
