/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    string gen = "MGTCKQWAEILORUY BDFHJNPSVXZ";
    int n = (int)gen.size();

    struct Node {
        int left = -1, right = -1;
        int val = -1;
    };

    vector<Node> nodes;
    nodes.push_back(Node{});
    for (char c : gen) {
        if (!nodes.empty()) {
            vector<int> path;
        }
    }

    int idxLetter = 0;
    function<void(int)> build = [&](int u) {
        if (idxLetter >= n) return;
        if (idxLetter >= n) return;

        char ch = gen[idxLetter++];
        nodes[u].val = (unsigned char)ch;

        if (idxLetter >= n) return;

        nodes[u].left = (int)nodes.size();
        nodes.push_back(Node{});
        build(nodes[u].left);

        if (idxLetter >= n) return;

        nodes[u].right = (int)nodes.size();
        nodes.push_back(Node{});
        build(nodes[u].right);
    };

    build(0);

    auto nextChar = [&](int u, char bit) -> int {
        if (bit == '-') return nodes[u].left;
        if (bit == '|') return nodes[u].right;
        return -1;
    };

    string out;
    int cur = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch == '-' || ch == '|') {
            int nxt = nextChar(cur, ch);
            cur = nxt;
        } else if (ch == '@') {
            out.push_back((char)nodes[0].val);
            cur = 0;
        } else if (ch == '*') {
            out.push_back((char)nodes[cur].val);
            cur = 0;
        }
    }

    cout << out << "\n";
    return 0;
}