/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        if (!(cin >> s)) break;
        if (!s.empty() && s.back() == ',') s.pop_back();
        arr[i] = stoi(s);
    }

    int shifts = 0;
    int comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (true) {
            comparisons++;
            if (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }

    cout << "Array ordenado: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Quantidade de trocas: " << shifts << endl;
    cout << "Quantidade de comparacoes: " << comparisons << endl;

    return 0;
}