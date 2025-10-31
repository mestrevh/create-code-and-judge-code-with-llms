/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> parents(n);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        for (int j = 0; j < b; ++j) {
            int c;
            cin >> c;
            parents[i].insert(c);
        }
    }

    for (int i = 0; i < q; ++i) {
        int b;
        cin >> b;
        set<int> child;
        for (int j = 0; j < b; ++j) {
            int c;
            cin >> c;
            child.insert(c);
        }

        bool possible = false;
        vector<int> p(n);
        for (int j = 0; j < n; ++j) {
            p[j] = j;
        }

        do {
            set<int> current_child;
            for (int j = 0; j < n; ++j) {
                int parent_idx = p[j];
                if (parents[parent_idx].empty()) continue;
                for (int allele : parents[parent_idx]) {
                    current_child.insert(allele);
                    break;
                }

            }

            
             if (current_child == child) {
                possible = true;
                break;
            }
            
             vector<int> alleles;
            for(int j = 0; j < n; j++) {
                for(int allele : parents[p[j]]) {
                    alleles.push_back(allele);
                    break;
                }
            }


           
            if(alleles.size() == child.size()) {
                set<int> combination;
                for(int allele : alleles) {
                    combination.insert(allele);
                }

                if(combination == child) possible = true;

            }
            

        } while (next_permutation(p.begin(), p.end()));

        if (possible) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
