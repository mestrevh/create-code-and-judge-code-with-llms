/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, r, s;
    while (cin >> q >> r >> s) {
        int result = q + (s - 1) * r;
        cout << "Na semana " << s << " Soneca tera que fazer " << result << " questoes!\n";
    }

    return 0;
}