/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Movie {
    string name;
    int r, d, a;
    int id;
};

struct Treap {
    struct Node {
        Movie* mv;
        int key; 
        uint32_t pr;
        Node *l, *r;
        Node(Movie* m, int k): mv(m), key(k), pr(((uint32_t)rand()<<16) ^ (uint32_t)rand()), l(nullptr), r(nullptr) {}
    };
    Node* root = nullptr;

    static uint32_t splitmix32(uint32_t& x){
        x += 0x9e3779b9;
        uint32_t z = x;
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
    Treap() {
        static bool inited = false;
        if(!inited){
            unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
            srand(seed);
            inited = true;
        }
    }

    static bool lessKey(const Movie* m1, const Movie* m2, int keyMode, int key1, int key2){
        if(keyMode==0){
            if(key1 != key2) return key1 < key2;
        }
        if(m1->id != m2->id) return m1->id < m2->id;
        return m1->name < m2->name;
    }

    void rotateMerge(Node*& a, Node* b) {}

    static void split(Node* t, int key, Node*& a, Node*& b){
        if(!t){ a = b = nullptr; return; }
        if(t->key < key){
            split(t->r, key, t->r, b);
            a = t;
        }else{
            split(t->l, key, a, t->l);
            b = t;
        }
    }

    static Node* merge(Node* a, Node* b){
        if(!a || !b) return a ? a : b;
        if(a->pr < b->pr){
            a->r = merge(a->r, b);
            return a;
        }else{
            b->l = merge(a, b->l);
            return b;
        }
    }

    static void insertNode(Node*& t, Node* it){
        if(!t){ t = it; return; }
        if(it->pr < t->pr){
            Node* a; Node* b;
            split(t, it->key, a, b);
            it->l = a; it->r = b;
            t = it;
        }else if(it->key < t->key){
            insertNode(t->l, it);
        }else{
            insertNode(t->r, it);
        }
    }

    static Node* eraseKey(Node* t, int key, int id){
        if(!t) return nullptr;
        if(t->key == key && t->mv->id == id){
            Node* res = merge(t->l, t->r);
            delete t;
            return res;
        }
        if(key < t->key) t->l = eraseKey(t->l, key, id);
        else t->r = eraseKey(t->r, key, id);
        return t;
    }

    static Node* findFirst(Node* t, int key){
        Node* cur = t;
        Node* ans = nullptr;
        while(cur){
            if(cur->key >= key){
                if(cur->key == key) ans = cur;
                cur = cur->l;
            }else cur = cur->r;
        }
        return ans;
    }

    static Node* findLast(Node* t, int key){
        Node* cur = t;
        Node* ans = nullptr;
        while(cur){
            if(cur->key <= key){
                if(cur->key == key) ans = cur;
                cur = cur->r;
            }else cur = cur->l;
        }
        return ans;
    }

    static Node* findMinNode(Node* t){
        Node* cur = t;
        while(cur && cur->l) cur = cur->l;
        return cur;
    }
    static Node* findMaxNode(Node* t){
        Node* cur = t;
        while(cur && cur->r) cur = cur->r;
        return cur;
    }

    void insert(Movie* m, int key){
        uint32_t seed = 0;
        (void)seed;
        Node* it = new Node(m, key);
        insertNode(root, it);
    }

    void erase(Movie* m, int key){
        root = eraseKey(root, key, m->id);
    }

    Movie* firstByKey(int key){
        Node* n = findFirst(root, key);
        if(!n) return nullptr;
        return n->mv;
    }

    Movie* lastByKey(int key){
        Node* n = findLast(root, key);
        if(!n) return nullptr;
        return n->mv;
    }
};

struct Catalog {
    vector<unique_ptr<Movie>> storage;
    unordered_map<string, Movie*> mp;
    vector<Movie*> history;

    Treap treapR, treapD, treapA;
    int nextId = 1;

    int keyFor(char L, int score){
        if(L=='R') return score * 1000000 + 0;
        if(L=='D') return score * 1000000 + 1;
        return score * 1000000 + 2;
    }

    int keyWithMovie(char L, int score, int id){
        if(L=='R') return score * 1000000 + 0;
        if(L=='D') return score * 1000000 + 1;
        return score * 1000000 + 2;
    }

    void addMovie(const string& name, int r, int d, int a){
        auto mv = make_unique<Movie>();
        mv->name = name;
        mv->r = r; mv->d = d; mv->a = a;
        mv->id = nextId++;
        Movie* p = mv.get();
        storage.push_back(std::move(mv));
        mp[name] = p;
        history.push_back(p);
        treapR.insert(p, p->r * 1000000);
        treapD.insert(p, p->d * 1000000);
        treapA.insert(p, p->a * 1000000);
    }

    void delMovie(const string& name){
        auto it = mp.find(name);
        if(it==mp.end()) return;
        Movie* p = it->second;
        treapR.erase(p, p->r * 1000000);
        treapD.erase(p, p->d * 1000000);
        treapA.erase(p, p->a * 1000000);
        mp.erase(it);
        while(!history.empty() && history.back()->id==p->id) history.pop_back();
    }

    void show(char L){
        Treap* t = nullptr;
        if(L=='R') t = &treapR;
        else if(L=='D') t = &treapD;
        else t = &treapA;

        struct ItNode { Treap::Node* n; };
        vector<Movie*> items;
        function<void(Treap::Node*)> dfs = [&](Treap::Node* node){
            if(!node) return;
            dfs(node->l);
            items.push_back(node->mv);
            dfs(node->r);
        };
        dfs(t->root);
        for(size_t i=0;i<items.size();i++){
            Movie* p = items[i];
            if(i) cout << "\n";
            cout << p->name << ": R " << p->r << ", D " << p->d << ", A " << p->a;
        }
        if(items.empty()) {
            if(!cin.fail()) {}
        }
        cout << "\n";
    }

    Movie* firstBy(char L, int N){
        if(L=='R') return treapR.firstByKey(N * 1000000);
        if(L=='D') return treapD.firstByKey(N * 1000000);
        return treapA.firstByKey(N * 1000000);
    }

    Movie* lastBy(char L, int N){
        if(L=='R') return treapR.lastByKey(N * 1000000);
        if(L=='D') return treapD.lastByKey(N * 1000000);
        return treapA.lastByKey(N * 1000000);
    }

    void handleFirstLast(char type, char L, int N){
        Movie* p = (type=='F') ? firstBy(L, N) : lastBy(L, N);
        if(!p) cout << "Nenhum\n";
        else cout << p->name << ": R " << p->r << ", D " << p->d << ", A " << p->a << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    Catalog cat;
    while(cin >> cmd){
        if(cmd=="END") break;
        if(cmd=="ADD"){
            string name; int R,D,A;
            cin >> name >> R >> D >> A;
            cat.addMovie(name, R, D, A);
        }else if(cmd=="SHOW"){
            char L; cin >> L;
            cat.show(L);
        }else if(cmd=="DEL"){
            string name; cin >> name;
            cat.delMovie(name);
        }else if(cmd=="FIRST"){
            char L; int N;
            cin >> L >> N;
            cat.handleFirstLast('F', L, N);
        }else if(cmd=="LAST"){
            char L; int N;
            cin >> L >> N;
            cat.handleFirstLast('L', L, N);
        }
    }
    return 0;
}