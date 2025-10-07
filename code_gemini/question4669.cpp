/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<char, char> relations;
    int a_count = 0;
    bool multiple_mappings = false;

    for (int i = 0; i < 3; ++i) {
        char x, y;
        cin >> x >> y;
        if (x >= 'a' && x <= 'c' && y >= 'd' && y <= 'f') {
            a_count++;
            if (relations.count(x)) {
                multiple_mappings = true;
            }
            relations[x] = y;
        }
    }

    if (relations.empty()) {
        cout << "A ^ B void" << endl;
    } else if (multiple_mappings) {
        cout << "A <-> B" << endl;
    } else if (a_count == 3) {
        cout << "A --> B" << endl;
    } else {
        cout << "A +-> B" << endl;
    }

    return 0;
}
