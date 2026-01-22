/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

double fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    double X, Z;
    int Y, K;
    cin >> X >> Y >> Z >> K;

    double troy = fib(Y);
    double gabriella = fib(K);

    if (X > troy)
        cout << "Nao foi dessa vez!! Troy nao teve coragem o suficiente." << endl;
    else
        cout << "Esse pode ser o comeco de algo novo!! Troy vai cantar!!" << endl;

    if (Z > gabriella)
        cout << "Nao foi dessa vez!! Gabriella nao teve coragem o suficiente." << endl;
    else
        cout << "Esse pode ser o comeco de algo novo!! Gabriella vai cantar!!" << endl;

    return 0;
}
