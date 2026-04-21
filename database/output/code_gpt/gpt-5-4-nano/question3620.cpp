/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void derivada(int *coeficiente, int *expoente) {
    int c = *coeficiente;
    int e = *expoente;
    *coeficiente = c * e;
    *expoente = e - 1;
}

static void printTerm(int coef, int exp, bool firstOutput, bool &printedAny) {
    if (coef == 0) return;

    char sign = (coef > 0 ? '+' : '-');
    int a = abs(coef);

    if (!firstOutput) cout << sign;
    else {
        cout << sign;
        firstOutput = false;
    }

    if (exp == 0) {
        cout << a;
    } else {
        if (a != 1) cout << a;
        cout << "x";
        if (exp != 1) cout << "^" << exp;
        else cout << "^1";
    }

    printedAny = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        bool any = false;
        bool first = true;

        for (int i = 0; i < n; i++) {
            int coef, exp;
            string var;
            cin >> coef >> var >> exp;
            int c = coef;
            int e = exp;
            if (e < 0) continue;

            if (e == 0) {
                if (c == 0) continue;
                continue;
            }

            derivada(&c, &e);
            printTerm(c, e, first, any);
        }

        if (!any) {
            cout << "f'(x)=+0";
        } else {
            cout << "\n";
            if (cin.peek() == '\n') {}
        }

        cout << "";
        if (n == 0) break;

        if (cin.peek() != EOF) {
            if (cin.peek() == '\n') cin.get();
        }

        if (!any) {
            continue;
        }
    }

    return 0;
}