/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

typedef long long ll;

string treeStr;
ll target;
int ansDepth = -1;
bool foundNode = false;

void parse(int &pos, int depth) {
    if (pos >= (int)treeStr.size()) return;

    // consume '('
    pos++;
    
    // Check for empty node
    if (pos < (int)treeStr.size() && treeStr[pos] == ')') {
        pos++;
        return;
    }

    // Parse value
    string numStr = "";
    while (pos < (int)treeStr.size() && (isdigit(treeStr[pos]) || treeStr[pos] == '-')) {
        numStr += treeStr[pos++];
    }

    if (!numStr.empty() && numStr != "-") {
        try {
            ll val = stoll(numStr);
            if (val == target && !foundNode) {
                ansDepth = depth;
                foundNode = true;
            }
        } catch (...) {}
    }

    // Binary trees in this format have two children, parse both if not empty
    // First child (Left)
    while (pos < (int)treeStr.size() && treeStr[pos] != '(' && treeStr[pos] != ')') pos++;
    if (pos < (int)treeStr.size() && treeStr[pos] == '(') {
        parse(pos, depth + 1);
    }

    // Second child (Right)
    while (pos < (int)treeStr.size() && treeStr[pos] != '(' && treeStr[pos] != ')') pos++;
    if (pos < (int)treeStr.size() && treeStr[pos] == '(') {
        parse(pos, depth + 1);
    }

    // Finalize node
    while (pos < (int)treeStr.size() && treeStr[pos] != ')') pos++;
    if (pos < (int)treeStr.size() && treeStr[pos] == ')') {
        pos++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tree = "";
    char c;
    int balance = 0;
    bool started = false;

    // Read the tree until parentheses are balanced
    while (cin >> c) {
        if (c == '(') {
            balance++;
            started = true;
        } else if (c == ')') {
            balance--;
        }
        if (started) tree += c;
        if (started && balance == 0) break;
    }

    // Read the target integer N
    if (!(cin >> target)) {
        // Handle cases where the target might be missing or input is empty
    }

    treeStr = tree;
    int pos = 0;
    // An empty tree is represented as "()"
    if (!treeStr.empty() && treeStr != "()") {
        parse(pos, 0);
    }

    if (foundNode) {
        cout << "ESTA NA ARVORE" << endl;
        cout << ansDepth << endl;
    } else {
        cout << "NAO ESTA NA ARVORE" << endl;
        cout << -1 << endl;
    }

    return 0;
}