/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, A, B;
    if (!(cin >> M >> A >> B)) return 0;

    int C = M - (A + B);

    int max_age = A;
    if (B > max_age) max_age = B;
    if (C > max_age) max_age = C;

    cout << max_age << "\n";

    return 0;
}