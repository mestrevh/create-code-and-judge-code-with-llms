/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int D, P, U, N;
    cin >> D >> P >> U >> N;
    int total = D + (P - D) + (U - D) + N;
    cout << total << endl;
    return 0;
}
