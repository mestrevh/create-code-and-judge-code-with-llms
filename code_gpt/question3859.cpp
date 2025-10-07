/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    
    unordered_set<int> old_elements;
    for (int i = 0; i < N1; i++) {
        int x;
        cin >> x;
        old_elements.insert(x);
    }
    
    vector<int> new_elements;
    int count_new = 0;
    
    while (count_new < N2) {
        int x;
        cin >> x;
        if (old_elements.find(x) == old_elements.end()) {
            new_elements.push_back(x);
            count_new++;
        }
    }
    
    vector<int> all_elements(new_elements);
    for (const int &id : old_elements) {
        all_elements.push_back(id);
    }
    
    vector<int> processed(all_elements.size());
    for (size_t i = 0; i < all_elements.size(); i++) {
        if (i == 0) {
            processed[i] = all_elements[i];
        } else if (i == all_elements.size() - 1) {
            processed[i] = all_elements[i] * all_elements[i - 1];
        } else {
            processed[i] = abs(all_elements[i] * all_elements[i - 1] - all_elements[i + 1]);
        }
    }
    
    sort(processed.begin(), processed.end());
    
    for (size_t i = 0; i < processed.size(); i++) {
        if (old_elements.find(all_elements[i]) != old_elements.end()) {
            cout << "DELETADO";
        } else {
            cout << processed[i];
        }
        if (i < processed.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
