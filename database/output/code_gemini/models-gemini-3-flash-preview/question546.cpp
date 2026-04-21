/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

struct Node {
    long long val;
    Node *left, *right;
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
};

string S;
int pos = 0;

void skip_ws() {
    while (pos < (int)S.size() && (unsigned char)S[pos] <= 32) {
        pos++;
    }
}

Node* parse() {
    skip_ws();
    if (pos >= (int)S.size() || S[pos] != '(') return nullptr;
    
    pos++; 
    skip_ws();
    
    if (pos < (int)S.size() && S[pos] == ')') {
        pos++; 
        return nullptr;
    }
    
    string val_str = "";
    if (pos < (int)S.size() && (S[pos] == '-' || S[pos] == '+')) {
        val_str += S[pos++];
    }
    while (pos < (int)S.size() && isdigit((unsigned char)S[pos])) {
        val_str += S[pos++];
    }
    
    if (val_str.empty()) return nullptr;
    
    Node* node = new Node(stoll(val_str));
    node->left = parse();
    node->right = parse();
    
    skip_ws();
    if (pos < (int)S.size() && S[pos] == ')') {
        pos++;
    }
    return node;
}

bool check(Node* root, long long* min_v, long long* max_v) {
    if (!root) return true;
    if (min_v && root->val <= *min_v) return false;
    if (max_v && root->val >= *max_v) return false;
    return check(root->left, min_v, &(root->val)) && check(root->right, &(root->val), max_v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line, full_input;
    while (getline(cin, line)) {
        full_input += line + " ";
    }
    S = full_input;
    
    if (S.find('(') == string::npos) return 0;

    Node* root = parse();
    if (root == nullptr) {
        bool has_bracket = false;
        for (char c : S) {
            if (c == '(') {
                has_bracket = true;
                break;
            }
        }
        if (has_bracket) cout << "VERDADEIRO" << endl;
    } else {
        if (check(root, nullptr, nullptr)) {
            cout << "VERDADEIRO" << endl;
        } else {
            cout << "FALSO" << endl;
        }
    }
    
    return 0;
}