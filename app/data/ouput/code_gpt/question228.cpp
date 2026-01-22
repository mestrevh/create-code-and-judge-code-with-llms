/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BlockWorld {
    vector<vector<int>> stacks;
    vector<int> positions;

public:
    BlockWorld(int n) {
        stacks.resize(n);
        for (int i = 0; i < n; ++i) {
            stacks[i].push_back(i);
            positions.push_back(i);
        }
    }

    void clearAbove(int a) {
        while (stacks[a].size() > 1) {
            int top = stacks[a].back();
            stacks[a].pop_back();
            stacks[top].push_back(top);
            positions[top] = top;
        }
    }

    void moveOnto(int a, int b) {
        clearAbove(a);
        clearAbove(b);
        stacks[b].push_back(a);
        positions[a] = b;
    }

    void moveOver(int a, int b) {
        clearAbove(a);
        stacks[b].push_back(a);
        positions[a] = positions[b];
    }

    void pileOnto(int a, int b) {
        clearAbove(b);
        int posA = positions[a];
        vector<int> pile;
        while (stacks[posA].back() != a) {
            pile.push_back(stacks[posA].back());
            stacks[posA].pop_back();
        }
        pile.push_back(stacks[posA].back());
        stacks[posA].pop_back();
        for (int i = pile.size() - 1; i >= 0; --i) {
            stacks[b].push_back(pile[i]);
            positions[pile[i]] = b;
        }
    }

    void pileOver(int a, int b) {
        int posA = positions[a];
        vector<int> pile;
        while (stacks[posA].back() != a) {
            pile.push_back(stacks[posA].back());
            stacks[posA].pop_back();
        }
        pile.push_back(stacks[posA].back());
        stacks[posA].pop_back();
        for (int i = 0; i < pile.size(); ++i) {
            stacks[b].push_back(pile[i]);
            positions[pile[i]] = positions[b];
        }
    }

    void executeCommand(const string& command) {
        istringstream iss(command);
        string action1, action2, type;
        int a, b;
        iss >> action1 >> a >> type >> b;

        if (a == b || positions[a] == positions[b]) return;

        if (action1 == "mover") {
            if (type == "sobre") {
                moveOnto(a, b);
            } else {
                moveOver(a, b);
            }
        } else {
            if (type == "sobre") {
                pileOnto(a, b);
            } else {
                pileOver(a, b);
            }
        }
    }

    void print() {
        for (int i = 0; i < stacks.size(); ++i) {
            cout << i << ":";
            for (int block : stacks[i]) {
                cout << " " << block;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    BlockWorld world(n);
    string command;
    while (getline(cin, command)) {
        if (command == "final") break;
        world.executeCommand(command);
    }
    world.print();
    return 0;
}
