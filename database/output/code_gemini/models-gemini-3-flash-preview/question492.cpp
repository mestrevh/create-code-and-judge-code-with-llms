/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_capsules = 0;
    int n;
    char size;

    for (int i = 0; i < 7; ++i) {
        if (!(cin >> n >> size)) break;
        if (size == 'p' || size == 'P') {
            total_capsules += n * 10;
        } else if (size == 'g' || size == 'G') {
            total_capsules += n * 16;
        }
    }

    int total_cups = total_capsules * 2;
    int cups_per_professor = total_cups / 7;

    cout << total_capsules << "\n";
    cout << cups_per_professor << "\n";

    return 0;
}