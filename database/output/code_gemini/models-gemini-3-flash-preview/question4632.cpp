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
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        cout << "[]" << endl;
        return 0;
    }

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> elements[i])) break;
    }

    int last_element = elements[n - 1];
    bool first_printed = true;
    
    cout << "[";
    for (int i = 0; i < n; ++i) {
        if (elements[i] != last_element) {
            if (!first_printed) {
                cout << ", ";
            }
            cout << elements[i];
            first_printed = false;
        }
    }
    cout << "]" << endl;

    return 0;
}