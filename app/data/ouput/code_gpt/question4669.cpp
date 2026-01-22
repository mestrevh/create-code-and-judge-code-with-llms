/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    map<char, set<char>> relation;
    set<char> A = {'a', 'b', 'c'};
    set<char> B = {'d', 'e', 'f'};
    bool total = true, partial = false, relationExists = false;
    
    for (int i = 0; i < 3; ++i) {
        char x, y;
        cin >> x >> y;
        if (A.count(x) && B.count(y)) {
            relation[x].insert(y);
        } else if (A.count(x) || B.count(y)) {
            partial = true;
        }
    }

    for (const auto& pair : relation) {
        if (pair.second.size() > 1) {
            relationExists = true;
            break;
        }
    }

    for (char a : A) {
        if (relation.count(a) == 0) {
            total = false;
            break;
        }
    }

    if (relation.exists) {
        cout << "A <-> B" << endl;
    } else if (partial) {
        cout << "A +-> B" << endl;
    } else if (total) {
        cout << "A --> B" << endl;
    } else {
        cout << "A ^ B void" << endl;
    }

    return 0;
}
