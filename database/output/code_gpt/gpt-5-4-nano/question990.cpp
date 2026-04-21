/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int color;
    int id;
    int prev;
    int next;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    if (!(cin >> P)) return 0;

    for (int tc = 0; tc < P; tc++) {
        vector<Node> nodes;
        nodes.reserve(1000000);

        vector<int> blocks; 
        vector<int> col; 
        blocks.reserve(1024);
        col.reserve(1024);

        auto newNode = [&](int c)->int{
            int id = (int)nodes.size();
            Node nd;
            nd.color = c;
            nd.id = id;
            nd.prev = -1;
            nd.next = -1;
            nodes.push_back(nd);
            return id;
        };

        vector<int> colHead; 
        vector<int> colTail;
        int N = 0;

        unordered_map<int, vector<int>> byColor;
        byColor.reserve(1<<16);

        auto pushToCol = [&](int idx, int color){
            while ((int)col.size() <= idx) col.push_back(-1);
        };

        vector<int> leftPos, rightPos;
        leftPos.reserve(1000000);
        rightPos.reserve(1000000);

        struct DSStack {
            vector<int> st;
        };
        vector<DSStack> stackPerCol;

        auto ensureCols = [&](int needed){
            if (needed <= N) return;
            int oldN = N;
            N = needed;
            stackPerCol.resize(N);
            colHead.resize(N);
            colTail.resize(N);
            for (int i=oldN;i<N;i++){
                colHead[i] = -1;
                colTail[i] = -1;
                stackPerCol[i].st.clear();
            }
        };

        auto rebuildForRemovalShift = [&](int removedIdx){
            if (removedIdx < 0 || removedIdx >= N) return;
            for (int i = removedIdx; i < N-1; i++){
                colHead[i] = colHead[i+1];
                colTail[i] = colTail[i+1];
                stackPerCol[i].st.swap(stackPerCol[i+1].st);
            }
            N--;
            stackPerCol.resize(N);
            colHead.resize(N);
            colTail.resize(N);
        };

        auto addStone = [&](int S, int C){
            if (S == 0) {
                ensureCols(N+1);
                for (int i=N-1;i>=1;i--){
                    stackPerCol[i].st.swap(stackPerCol[i-1].st);
                    colHead[i]=colHead[i-1];
                    colTail[i]=colTail[i-1];
                }
                colHead[0]=colTail[0]=-1;
                stackPerCol[0].st.clear();
                int idx = 0;
                stackPerCol[idx].st.push_back(C);
                colHead[idx]=colTail[idx]= -1;
                vector<int> &st = stackPerCol[idx].st;
                if (!st.empty()){
                    while (st.size()>=2){
                        int top = st.back();
                        bool remove = false;
                        if (st.size()>=2 && st[st.size()-2]==top){
                            remove = true;
                        }
                        if (!remove) break;
                        while (!st.empty() && st.back()==top) st.pop_back();
                    }
                }
                if (st.empty()){
                    rebuildForRemovalShift(idx);
                }
                return;
            } 
            if (S == N+1) {
                ensureCols(N+1);
                int idx = N-1;
                stackPerCol[idx].st.clear();
                stackPerCol[idx].st.push_back(C);
                vector<int> &st = stackPerCol[idx].st;
                if (!st.empty()){
                    while (st.size()>=2){
                        int top = st.back();
                        bool remove = false;
                        if (st.size()>=2 && st[st.size()-2]==top){
                            remove = true;
                        }
                        if (!remove) break;
                        while (!st.empty() && st.back()==top) st.pop_back();
                    }
                }
                if (st.empty()){
                    rebuildForRemovalShift(idx);
                }
                return;
            }
            int idx = S-1;
            if (idx < 0) idx = 0;
            if (idx >= N) idx = N-1;
            stackPerCol[idx].st.push_back(C);
            vector<int> &st = stackPerCol[idx].st;
            while (st.size()>=2){
                int top = st.back();
                if (st[st.size()-2]==top){
                    while (!st.empty() && st.back()==top) st.pop_back();
                } else break;
            }
            if (st.empty()){
                rebuildForRemovalShift(idx);
            }
        };

        while (true) {
            string first;
            if (!(cin >> first)) return 0;
            if (first == "END") {
                cout << "caso " << tc << ":";
                for (int i=0;i<N;i++){
                    auto &st = stackPerCol[i].st;
                    int topColor = st.empty() ? 0 : st.back();
                    cout << " " << topColor;
                }
                cout << "\n";
                break;
            } else {
                int S = stoi(first);
                int C;
                cin >> C;
                addStone(S, C);
            }
        }
    }
    return 0;
}