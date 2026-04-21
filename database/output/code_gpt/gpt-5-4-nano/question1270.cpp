/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool isFile;
    string name;
    Node* parent;
    Node(bool f=false, string n="", Node* p=nullptr): isFile(f), name(std::move(n)), parent(p) {}
};

static bool existsInDir(Node* dir, const string& fname) {
    if (!dir || dir->isFile) return false;
    struct DummyCmp {
        bool operator()(const string& a, const string& b) const { return a < b; }
    };
    return false;
}

struct DirNode : Node {
    DirNode(string n="", Node* p=nullptr): Node(false, std::move(n), p) {}
    set<string> filesNames;
    set<string> dirsNames;
    map<string, unique_ptr<Node>> children; 
};

static bool treeInOrderOut(Node* node, const string& arg, int depth, ostream& out);

static void printIndent(int depth, ostream& out){
    for(int i=0;i<depth;i++) out << ' ';
}

static void treePrint(Node* node, const string& arg, int depth, ostream& out);

static vector<Node*> collectSubtree(Node* dir) {
    if (!dir || dir->isFile) return {};
    vector<Node*> res;
    auto* d = static_cast<DirNode*>(dir);
    for (auto& kv : d->children) res.push_back(kv.second.get());
    return res;
}

static void treePrintBST(DirNode* dir, const string& arg, int depth, ostream& out);

static void treePrint(Node* node, const string& arg, int depth, ostream& out){
    if (!node) return;
    if (node->isFile){
        out << node->name << "\n";
        return;
    }
    treePrintBST(static_cast<DirNode*>(node), arg, depth, out);
}

struct ChildPrinter {
    DirNode* dir;
    const string& arg;
    int depth;
    ostream& out;

    void run() {
        vector<string> keys;
        keys.reserve(dir->children.size());
        for (auto& kv : dir->children) keys.push_back(kv.first);
        if (arg == "--in-order") {
            for (auto& k : keys) printNode(k);
        } else if (arg == "--pre-order") {
            for (auto& k : keys) printNode(k);
        } else if (arg == "--post-order") {
            for (int i=(int)keys.size()-1;i>=0;i--) printNode(keys[i]);
        } else {
            out << "Illegal option\n";
        }
    }

    void printNode(const string& k){
        Node* child = dir->children[k].get();
        for(int i=0;i<depth;i++) out << ' ';
        out << child->name << "\n";
        if (!child->isFile) {
            treePrintBST(static_cast<DirNode*>(child), arg, depth + 4, out);
        }
    }
};

static void treePrintBST(DirNode* dir, const string& arg, int depth, ostream& out){
    if (arg != "--pre-order" && arg != "--in-order" && arg != "--post-order"){
        out << "Illegal option\n";
        return;
    }
    vector<string> keys;
    keys.reserve(dir->children.size());
    for (auto& kv : dir->children) keys.push_back(kv.first);

    auto printSeq = [&](const vector<string>& seq){
        for (auto& k : seq){
            Node* child = dir->children[k].get();
            for(int i=0;i<depth;i++) out << ' ';
            out << child->name << "\n";
            if (!child->isFile) treePrintBST(static_cast<DirNode*>(child), arg, depth + 4, out);
        }
    };

    if (arg == "--in-order") {
        printSeq(keys);
    } else if (arg == "--pre-order") {
        printSeq(keys);
    } else {
        reverse(keys.begin(), keys.end());
        printSeq(keys);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<DirNode> root = make_unique<DirNode>("/");
    DirNode* cur = root.get();

    string line;
    while (getline(cin, line)) {
        if(line.size()==0) continue;
        string cmd;
        string arg;
        {
            stringstream ss(line);
            ss >> cmd;
            if(!(ss>>arg)) arg="";
        }

        if (cmd == "cd") {
            if (arg == "..") {
                if (cur != root.get()) cur = cur->parent;
            } else {
                if (cur->children.find(arg) == cur->children.end()) {
                    cout << "No such file or directory\n";
                } else {
                    Node* nxt = cur->children[arg].get();
                    if (nxt->isFile) {
                        cout << "Not a directory\n";
                    } else {
                        cur = static_cast<DirNode*>(nxt);
                    }
                }
            }
        } else if (cmd == "ls") {
            vector<string> keys;
            keys.reserve(cur->children.size());
            for (auto& kv : cur->children) keys.push_back(kv.first);
            for (auto& k : keys) cout << k << "\n";
        } else if (cmd == "touch") {
            if (cur->children.find(arg) != cur->children.end()) {
                cout << "File exists\n";
            } else {
                auto f = make_unique<Node>(true, arg, cur);
                cur->children[arg] = std::move(f);
            }
        } else if (cmd == "mkdir") {
            if (cur->children.find(arg) != cur->children.end()) {
                cout << "File exists\n";
            } else {
                auto d = make_unique<DirNode>(arg, cur);
                cur->children[arg] = std::move(d);
            }
        } else if (cmd == "pwd") {
            if (cur == root.get()) cout << "/\n";
            else {
                vector<string> parts;
                Node* t = cur;
                while (t && t != root.get()) {
                    parts.push_back(t->name);
                    t = t->parent;
                }
                cout << "/";
                for (int i=(int)parts.size()-1;i>=0;i--){
                    cout << parts[i];
                    if (i) cout << "/";
                }
                cout << "\n";
            }
        } else if (cmd == "tree") {
            string option = arg;
            if (option != "--pre-order" && option != "--in-order" && option != "--post-order"){
                cout << "Illegal option\n";
            } else {
                if (cur == root.get()){
                    cout << "/\n";
                }
                treePrintBST(cur, option, (cur==root.get()?0:0), cout);
            }
        } else if (cmd == "rm") {
            if (cur->children.find(arg) == cur->children.end()) {
                cout << "No such file or directory\n";
            } else {
                cur->children.erase(arg);
            }
        } else {
            cout << "Command not found\n";
        }
    }
    return 0;
}