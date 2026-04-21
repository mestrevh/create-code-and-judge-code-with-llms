/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float r;
    while (cin >> r) {
        float pi = 3.1415f;
        float area = pi * r * r;
        cout << fixed << setprecision(6) << area << "\n";
    }

    return 0;
}