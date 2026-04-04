/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> elements;
    set<int> seen;
    int value;

    while (cin >> value) {
        if (value == 0) {
            if (elements.size() < 3) {
                cout << "você deve digitar pelo menos 3 números antes do 0." << endl;
            } else {
                break;
            }
        } else {
            if (seen.find(value) != seen.end()) {
                cout << "número já existe na lista, tente outro." << endl;
            } else {
                elements.push_back(value);
                seen.insert(value);
            }
        }
    }

    if (elements.empty()) return 0;

    cout << "[";
    for (size_t i = 0; i < elements.size(); ++i) {
        cout << elements[i];
        if (i < elements.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    int max_val = elements[0], max_pos = 0;
    int min_val = elements[0], min_pos = 0;

    for (int i = 1; i < (int)elements.size(); ++i) {
        if (elements[i] > max_val) {
            max_val = elements[i];
            max_pos = i;
        }
        if (elements[i] < min_val) {
            min_val = elements[i];
            min_pos = i;
        }
    }

    cout << "o maior elemento da lista é: " << max_val << " e ele se encontra na posição: " << max_pos << endl;
    cout << "o menor elemento da lista é: " << min_val << " e ele se encontra na posição: " << min_pos << endl;

    return 0;
}