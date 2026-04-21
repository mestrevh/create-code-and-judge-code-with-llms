/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int h;
    Node *l, *r;
    Node(int k): key(k), h(1), l(nullptr), r(nullptr) {}
};

static int heightOf(Node* t){ return t ? t->h : 0; }

static Node* rotateRight(Node* y){
    Node* x = y->l;
    Node* T2 = x->r;
    x->r = y;
    y->l = T2;
    y->h = 1 + max(heightOf(y->l), heightOf(y->r));
    x->h = 1 + max(heightOf(x->l), heightOf(x->r));
    return x;
}

static Node* rotateLeft(Node* x){
    Node* y = x->r;
    Node* T2 = y->l;
    y->l = x;
    x->r = T2;
    x->h = 1 + max(heightOf(x->l), heightOf(x->r));
    y->h = 1 + max(heightOf(y->l), heightOf(y->r));
    return y;
}

static int balanceFactor(Node* t){
    return heightOf(t->l) - heightOf(t->r);
}

static Node* rebalance(Node* t){
    if(!t) return t;
    t->h = 1 + max(heightOf(t->l), heightOf(t->r));
    int bf = balanceFactor(t);
    if(bf > 1){
        if(balanceFactor(t->l) < 0) t->l = rotateLeft(t->l);
        return rotateRight(t);
    }else if(bf < -1){
        if(balanceFactor(t->r) > 0) t->r = rotateRight(t->r);
        return rotateLeft(t);
    }
    return t;
}

static Node* insertNode(Node* t, int key, int &retH, bool &inserted){
    if(!t){
        inserted = true;
        Node* n = new Node(key);
        retH = n->h;
        return n;
    }
    if(key == t->key){
        inserted = false;
        retH = t->h;
        return t;
    }
    if(key < t->key) t->l = insertNode(t->l, key, retH, inserted);
    else t->r = insertNode(t->r, key, retH, inserted);
    if(inserted) t->h = 1 + max(heightOf(t->l), heightOf(t->r));
    return rebalance(t);
}

static Node* minNode(Node* t){
    while(t && t->l) t = t->l;
    return t;
}

static Node* eraseNode(Node* t, int key, int &retH, bool &found){
    if(!t){
        retH = 0;
        found = false;
        return nullptr;
    }
    if(key == t->key){
        found = true;
        retH = t->h;
        if(!t->l){
            Node* r = t->r;
            delete t;
            return r;
        }
        if(!t->r){
            Node* l = t->l;
            delete t;
            return l;
        }
        Node* succ = minNode(t->r);
        t->key = succ->key;
        bool dummyFound=false;
        int dummyH=0;
        t->r = eraseNode(t->r, succ->key, dummyH, dummyFound);
    }else if(key < t->key){
        t->l = eraseNode(t->l, key, retH, found);
    }else{
        t->r = eraseNode(t->r, key, retH, found);
    }
    if(!found) return t;
    return rebalance(t);
}

static int queryHeight(Node* t, int key){
    while(t){
        if(key == t->key) return t->h;
        if(key < t->key) t = t->l;
        else t = t->r;
    }
    return 0;
}

static void rangeMinMax(Node* t, int l, int r, bool &has, int &mn, int &mx){
    if(!t) return;
    if(t->key < l){
        rangeMinMax(t->r, l, r, has, mn, mx);
        return;
    }
    if(t->key > r){
        rangeMinMax(t->l, l, r, has, mn, mx);
        return;
    }
    if(t->key >= l && t->key <= r){
        has = true;
        mn = min(mn, t->key);
        mx = max(mx, t->key);
        rangeMinMax(t->l, l, r, has, mn, mx);
        rangeMinMax(t->r, l, r, has, mn, mx);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    int seedX;
    int A;
    int C;
    if(!(cin >> N >> M >> seedX >> A >> C)) return 0;

    Node* root = nullptr;
    int retH = 0;
    bool inserted = false;

    long long x = seedX;
    for(int i=0;i<N;i++){
        int k = (int)x;
        int tmpH=0; bool tmpIns=false;
        root = insertNode(root, k, tmpH, tmpIns);
        x = ( (long long)A * x + C ) % M;
    }

    int opIndex = 0;
    string cmd;
    while(cin >> cmd){
        if(cmd=="ADD"){
            int k; cin >> k;
            inserted = false;
            retH = 0;
            bool insFlag=false;
            root = insertNode(root, k, retH, insFlag);
            cout << opIndex << ' ' << retH << "\n";
            opIndex++;
        }else if(cmd=="DEL"){
            int k; cin >> k;
            bool found=false;
            retH = 0;
            root = eraseNode(root, k, retH, found);
            cout << opIndex << ' ' << retH << "\n";
            opIndex++;
        }else if(cmd=="QRY"){
            int k; cin >> k;
            retH = queryHeight(root, k);
            cout << opIndex << ' ' << retH << "\n";
            opIndex++;
        }else if(cmd=="INT"){
            int l, r; cin >> l >> r;
            if(l > r) swap(l, r);
            bool has=false;
            int mn = INT_MAX, mx = INT_MIN;
            rangeMinMax(root, l, r, has, mn, mx);
            if(has){
                cout << opIndex << ' ' << mn << ' ' << mx << "\n";
            }
            opIndex++;
        }
    }
    return 0;
}