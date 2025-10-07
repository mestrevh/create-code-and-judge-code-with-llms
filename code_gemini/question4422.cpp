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
    cin >> n;

    long long total_cost = 0;
    vector<string> pyramid(n);

    for (int i = 0; i < n; ++i) {
        string layer = "";
        for (int j = 0; j < n - 1 - i; ++j) {
            layer += ".";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            if (j % 2 == 0) {
                layer += "&";
                total_cost += 200;
            } else {
                layer += "-";
                total_cost += 50;
            }
        }
        for (int j = 0; j < n - 1 - i; ++j) {
            layer += ".";
        }
        pyramid[i] = layer;
    }

    for (int i = 0; i < n; ++i) {
        cout << pyramid[i] << endl;
    }

    for (int i = 0; i < 2 * n - 1; ++i) {
        cout << "#";
        total_cost += 100;
    }
    cout << endl;

    cout << "O valor total foi: " << total_cost << endl;

    return 0;
}
