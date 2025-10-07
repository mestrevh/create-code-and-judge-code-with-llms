/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int Q, R, S;
    cin >> Q >> R >> S;
    int questoes = Q + (S - 1) * R;
    cout << "Na semana " << S << " Soneca tera que fazer " << questoes << " questoes!" << endl;
    return 0;
}
