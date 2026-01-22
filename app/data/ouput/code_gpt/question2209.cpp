/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node {
    char value;
    Node *left, *right;
    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node *&root, const string &code, char letter) {
    if (root == nullptr) root = new Node(' ');
    Node *current = root;
    for (char c : code) {
        if (c == '-') {
            if (current->left == nullptr) current->left = new Node(' ');
            current = current->left;
        } else if (c == '|') {
            if (current->right == nullptr) current->right = new Node(' ');
            current = current->right;
        }
    }
    current->value = letter;
}

string decode(Node *root, const string &encoded) {
    string result;
    string code;
    for (char c : encoded) {
        if (c == '*' && !code.empty()) {
            Node *current = root;
            for (char k : code) {
                if (k == '-') current = current->left;
                else if (k == '|') current = current->right;
            }
            result += current->value;
            code.clear();
        } else {
            code += c;
        }
    }
    return result;
}

int main() {
    string generator = "MGTCKQWAEILORUY BDFHJNPSVXZ";
    string input;
    getline(cin, input);

    Node *root = nullptr;
    string code;
    for (size_t i = 0; i < generator.size(); ++i) {
        code += (i == 0 ? '@' : ' ');
        insert(root, code.substr(0, i + 1), generator[i]);
        code += (i == 0 ? '@' : ' ');
    }

    cout << decode(root, input) << endl;
    return 0;
}
