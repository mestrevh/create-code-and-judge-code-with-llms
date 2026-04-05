/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (n < 1000 || n > 9999) {
            break;
        }

        int first_part = n / 100;
        int second_part = n % 100;
        int sum = first_part + second_part;

        if (sum * sum == n) {
            cout << "propriedade do 3025!" << "\n";
        } else {
            cout << "numero comum" << "\n";
        }
    }

    return 0;
}