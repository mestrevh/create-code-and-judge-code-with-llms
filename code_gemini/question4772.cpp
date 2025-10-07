/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;

    if (n < 2) {
        cout << "Fica muito feio, meu senhor." << endl;
        return 0;
    }

    vector<string> x(n, string(n, ' '));
    vector<string> y(n, string(n, ' '));

    for (int i = 0; i < n; ++i) {
        x[i][i] = c;
        x[i][n - 1 - i] = c;
        y[i][i] = c;
        y[i][n - 1 - i] = c;
    }

    for (int i = 0; i < n; ++i) {
        cout << x[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (i < n/2){
            cout << y[i] << endl;
         } else if (n % 2 == 0 && i < n) {
            for (int j = 0; j < n; ++j) {
                if (j == n / 2 || j == n / 2 -1) {
                    cout << c;
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        } else if(n % 2 != 0 && i < n) {
             for (int j = 0; j < n; ++j) {
                if (j == n / 2) {
                    cout << c;
                } else {
                    cout << " ";
                }
            }
             cout << endl;
        }
    }


    return 0;
}
