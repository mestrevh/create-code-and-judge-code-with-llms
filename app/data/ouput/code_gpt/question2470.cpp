/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

int main() {
    int I;
    cin >> I;
    cin.ignore();
    
    vector<string> cds(I);
    vector<string> capas(I);
    unordered_set<string> cdSet, capaSet;

    for (int i = 0; i < I; i++) {
        getline(cin, cds[i]);
        cdSet.insert(cds[i]);
    }

    for (int i = 0; i < I; i++) {
        getline(cin, capas[i]);
        capaSet.insert(capas[i]);
    }

    vector<string> matchedCds;
    for (const string &cd : cds) {
        if (capaSet.find(cd) != capaSet.end()) {
            matchedCds.push_back(cd);
        }
    }

    sort(matchedCds.begin(), matchedCds.end());
    for (const string &cd : matchedCds) {
        cout << cd << endl;
    }

    unordered_set<string> unmatchedCds(cds.begin(), cds.end());
    unordered_set<string> unmatchedCapas(capas.begin(), capas.end());

    for (const string &cd : matchedCds) {
        unmatchedCds.erase(cd);
        unmatchedCapas.erase(cd);
    }

    stringstream cdMissing, capaMissing;
    for (const string &cd : unmatchedCds) {
        if (!cdMissing.str().empty()) cdMissing << ", ";
        cdMissing << cd;
    }
    
    for (const string &capa : unmatchedCapas) {
        if (!capaMissing.str().empty()) capaMissing << ", ";
        capaMissing << capa;
    }

    cout << "Chandler, você vai ter que comprar a capa para os CDs: " 
         << cdMissing.str() << ". E os CDs para as capas: " 
         << capaMissing.str() << "." << endl;

    return 0;
}
