/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long px, py;
    if (scanf(" ( %lld , %lld ) ", &px, &py) == 2) {
        long long A, a, B, b;
        if (scanf(" %lld * x ^ %lld - %lld * y ^ %lld ", &A, &a, &B, &b) == 4) {
            long double v1 = (long double)A * pow((long double)px, (long double)a);
            long double v2 = (long double)B * pow((long double)py, (long double)b);

            if (v1 == v2) {
                printf("a função não está definida em (%lld,%lld) .-.\n", px, py);
            } else {
                printf("a função está definida em (%lld,%lld)\n", px, py);
            }
        }
    }

    return 0;
}