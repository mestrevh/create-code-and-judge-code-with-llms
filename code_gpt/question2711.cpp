/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printChoices(const vector<string>& choices) {
    for (size_t i = 0; i < choices.size(); ++i) {
        cout << choices[i];
        if (i < choices.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    vector<string> choices;
    string decision;
    
    while (true) {
        getline(cin, decision);
        choices.push_back(decision);
        
        if (decision == "Sucesso") {
            printChoices(choices);
            break;
        } else if (decision == "Fracasso") {
            printChoices(choices);
            choices.pop_back();
            getline(cin, decision);
            choices.back() = decision;
        }
    }
    
    return 0;
}
