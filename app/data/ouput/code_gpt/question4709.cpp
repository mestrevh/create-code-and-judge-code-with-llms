/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void amadoProfessor(int num) {
    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " =  " << num * i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    amadoProfessor(n);
    return 0;
}
