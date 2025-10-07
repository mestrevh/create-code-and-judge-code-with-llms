/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string wires;
    getline(cin, wires);
    vector<char> connected;
    
    for (int i = 0; i < 6; i++) {
        if (wires[i] != 'x') {
            connected.push_back(wires[i]);
        }
    }
    
    int count = connected.size();
    char cut;
    
    if (count == 4) {
        if (find(connected.begin(), connected.end(), 'r') == connected.end()) {
            cut = connected[1];
        } else if (connected[count - 1] == 'b') {
            cut = connected[count - 1];
        } else {
            cut = connected[0];
        }
    } else if (count == 5) {
        if (connected[0] == 'y' && connected[1] == 'y') {
            cut = connected[0];
        } else {
            cut = connected[1];
        }
    } else if (count == 6) {
        if (count(connected.begin(), connected.end(), 'g') == 1) {
            cut = connected[count - 1];
        } else {
            cut = connected[4];
        }
    }
    
    char wire = 'a' + (find(wires.begin(), wires.end(), cut) - wires.begin());
    cout << "corta " << wire << endl;
    return 0;
}
