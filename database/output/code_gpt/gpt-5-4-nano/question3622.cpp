/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void calcular_media(int *A, int *B) {
    int a = *A, b = *B;
    if (a <= b) {
        long long sum = (long long)a + b;
        long long media = sum / 2;
        long long resto = sum % 2;
        *A = (int)media;
        *B = (int)resto;
    } else {
        long long sum = (long long)a + b;
        long long media = sum / 2;
        long long resto = sum % 2;
        *B = (int)media;
        *A = (int)resto;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    if (!(cin >> A >> B)) return 0;
    calcular_media(&A, &B);
    cout << "A = " << A << "\nB = " << B;
    return 0;
}