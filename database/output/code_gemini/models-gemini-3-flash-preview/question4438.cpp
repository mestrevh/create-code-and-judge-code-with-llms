/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << "NAO HA CELEBRIDADE" << endl;
        return 0;
    }

    vector<int> matrix(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> matrix[i];
    }

    int celebrity = -1;
    for (int i = 0; i < n; i++) {
        bool is_celeb = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (matrix[i * n + j] == 1 || matrix[j * n + i] == 0) {
                is_celeb = false;
                break;
            }
        }
        if (is_celeb) {
            celebrity = i;
            break;
        }
    }

    if (celebrity != -1) {
        cout << celebrity << endl;
    } else {
        cout << "NAO HA CELEBRIDADE" << endl;
    }

    return 0;
}