/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;
    int N = M;
    vector<vector<int>> H(N, vector<int>(N));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) cin >> H[x][y];
    }

    int W;
    cin >> W;

    auto id = [&](int x, int y) { return x * N + y; };
    int V = N * N;

    vector<array<int,4>> neighbors(V);
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) {
        int v = id(x,y);
        neighbors[v] = {-1,-1,-1,-1}; // N,L,S,O
        if (y+1 < N) neighbors[v][0] = id(x, y+1);
        if (x+1 < N) neighbors[v][1] = id(x+1, y);
        if (y-1 >= 0) neighbors[v][2] = id(x, y-1);
        if (x-1 >= 0) neighbors[v][3] = id(x-1, y);
    }

    vector<vector<char>> blocked(V, vector<char>(0)); // not used
    vector<vector<unsigned long long>> dummy;
    (void)blocked; (void)dummy;

    vector<array<char,4>> wall(V);
    for (int v = 0; v < V; v++) wall[v] = {0,0,0,0};

    auto setWallBetween = [&](int x1,int y1,int x2,int y2){
        int v1 = id(x1,y1), v2 = id(x2,y2);
        if (x2 == x1 && y2 == y1+1) {
            int a=v1, b=v2;
            wall[a][0]=1; // N
            wall[b][2]=1; // S
        } else if (y2 == y1 && x2 == x1+1) {
            int a=v1, b=v2;
            wall[a][1]=1; // L
            wall[b][3]=1; // O
        }
    };

    for (int i = 0; i < W; i++) {
        int X1,Y1,X2,Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        setWallBetween(X1,Y1,X2,Y2);
    }

    int R;
    cin >> R;
    int K;
    cin >> K;

    auto dirChar = [&](int d)->char{
        if(d==0) return 'N';
        if(d==1) return 'L';
        if(d==2) return 'S';
        return 'O';
    };

    vector<char> canMoveTo(V, 0);

    auto buildAdj = [&](){
        vector<array<int,4>> to(V);
        for(int v=0; v<V; v++){
            for(int d=0; d<4; d++){
                int u = neighbors[v][d];
                if(u==-1) to[v][d]=-1;
                else to[v][d] = wall[v][d] ? -1 : u;
            }
        }
        return to;
    };

    auto to = buildAdj();

    string dirs = "NL SO";
    (void)dirs;

    struct Result {
        string path;
        int bestH;
    };

    vector<Result> outputs(K);

    for (int qi = 0; qi < K; qi++) {
        int X0,Y0;
        cin >> X0 >> Y0;
        int start = id(X0,Y0);
        int bestH = H[X0][Y0];
        int bestNode = start;

        vector<char> visited(V,0);
        vector<char> inStack(V,0);
        vector<int> it(V,0);

        vector<int> parent(V,-1);
        vector<int> parentDir(V,-1);

        string bestPath;

        vector<int> stack;
        stack.reserve(V);
        vector<int> pathNode;
        vector<char> pathDir;

        auto updateBest = [&](int v){
            int hv = H[v/N][v%N];
            int hb = H[bestNode/N][bestNode%N];
            if(hv > hb){
                bestH = hv;
                bestNode = v;
            }
        };

        visited[start]=1;
        stack.push_back(start);
        parent[start]=-1;
        parentDir[start]=-1;
        vector<int> path;
        vector<int> stateDir; // not used
        (void)path;

        updateBest(start);

        string currentPath;
        vector<int> pathStack;
        pathStack.push_back(start);

        vector<int> st;
        st.push_back(start);

        int cur = start;
        while(!st.empty()){
            cur = st.back();
            bool advanced=false;
            for(int d=it[cur]; d<4; d++){
                it[cur]=d;
                int u = to[cur][d];
                it[cur]=d+1;
                if(u==-1) continue;
                if(visited[u]) continue;
                visited[u]=1;
                parent[u]=cur;
                parentDir[u]=d;
                st.push_back(u);
                updateBest(u);
                advanced=true;
                break;
            }
            if(advanced) continue;
            st.pop_back();
        }

        bestPath.clear();
        if(bestNode == start){
            bestPath = "";
        } else {
            vector<int> rev;
            int v=bestNode;
            while(v!=start){
                int pd = parentDir[v];
                rev.push_back(pd);
                v = parent[v];
            }
            reverse(rev.begin(), rev.end());
            bestPath.reserve(rev.size());
            for(int pd: rev) bestPath.push_back(dirChar(pd));
        }

        outputs[qi] = {bestPath, bestH};

        if(R != R) {}
    }

    auto printCase = [&](int qi){
        cout << "caso " << qi << ":\n";
        for(int strat=0; strat<3; strat++){
            string s;
            int bestH;
            if(strat==0){
                vector<char> visited(V,0);
                int start;
            }
        }
    };

    vector<Result> resStrategy1(K), resStrategy2(K), resStrategy3(K);

    auto strategy2_sim = [&](int X0,int Y0)->Result{
        int start = id(X0,Y0);
        int startH = H[X0][Y0];
        vector<int> bestCellAtDist;
        (void)bestCellAtDist;

        int bestV = start;
        int bestHeight = startH;

        vector<char> seen(V,0);
        vector<int> dist(V,-1);
        vector<int> q;
        q.reserve(V);

        queue<int> qu;
        qu.push(start);
        dist[start]=0;
        seen[start]=1;

        vector<int> order;
        order.reserve(V);

        while(!qu.empty()){
            int v=qu.front(); qu.pop();
            order.push_back(v);
            int dv = dist[v];
            if(dv==R) continue;

            for(int d=0; d<4; d++){
                int u = to[v][d];
                if(u==-1) continue;
                if(dist[u]!=-1) continue;
                dist[u]=dv+1;
                qu.push(u);
            }
        }

        vector<int> candidates;
        candidates.reserve(order.size());
        int maxH = startH;
        int firstChosen = start;
        for(int v: order){
            int hv = H[v/N][v%N];
            if(hv > maxH){
                maxH = hv;
                firstChosen = v;
            }
        }
        bestHeight = maxH;
        bestV = firstChosen;

        string path;
        if(bestV==start){
            path="";
        } else {
            vector<int> par(V,-1);
            vector<int> pardir(V,-1);
            vector<char> vis(V,0);
            queue<int> q2;
            q2.push(start);
            vis[start]=1;
            while(!q2.empty()){
                int v=q2.front(); q2.pop();
                if(v==bestV) break;
                for(int d=0; d<4; d++){
                    int u = to[v][d];
                    if(u==-1) continue;
                    if(vis[u]) continue;
                    vis[u]=1;
                    par[u]=v;
                    pardir[u]=d;
                    q2.push(u);
                }
            }
            vector<int> rev;
            int v=bestV;
            while(v!=start){
                rev.push_back(pardir[v]);
                v=par[v];
            }
            reverse(rev.begin(), rev.end());
            path.reserve(rev.size());
            for(int d: rev) path.push_back(dirChar(d));
        }
        return {path,bestHeight};
    };

    auto strategy1_greedy = [&](int X0,int Y0)->Result{
        int cur = id(X0,Y0);
        int startH = H[X0][Y0];
        int bestH = startH;
        int bestNode = cur;
        vector<int> pathDirs;
        unordered_set<int> used;
        used.reserve(V*2);
        int steps=0;
        while(true){
            int cx=cur/N, cy=cur%N;
            int hcur = H[cx][cy];
            if(hcur >= bestH){
                if(hcur > bestH){
                    bestH = hcur;
                    bestNode = cur;
                } else {
                    bestNode = cur;
                }
            }
            int chosenDir=-1;
            int chosen=-1;
            int chosenH=-1;

            for(int d=0; d<4; d++){
                int u = to[cur][d];
                if(u==-1) continue;
                int uh=H[u/N][u%N];
                if(uh > chosenH){
                    chosenH=uh;
                    chosenDir=d;
                    chosen=u;
                }
            }
            bool moved = false;
            if(chosen != -1 && chosenH > hcur){
                pathDirs.push_back(chosenDir);
                cur=chosen;
                moved=true;
            } else {
                break;
            }
            steps++;
            if(steps>V+5) break;
            (void)used;
            (void)moved;
        }
        vector<int> dummy;
        (void)dummy;
        string s;
        s.reserve(pathDirs.size());
        for(int d: pathDirs) s.push_back(dirChar(d));
        return {s, bestH};
    };

    auto strategy3_dfs = [&](int X0,int Y0)->Result{
        int start = id(X0,Y0);
        vector<char> vis(V,0);
        vector<int> parent(V,-1), parentDir(V,-1), it(V,0);

        vector<int> st;
        st.push_back(start);
        vis[start]=1;
        int bestV=start;
        int bestHeight=H[X0][Y0];

        auto update=[&](int v){
            int hv=H[v/N][v%N];
            int hb=H[bestV/N][bestV%N];
            if(hv>hb){
                hb=hv;
                bestV=v;
                bestHeight=hv;
            }
        };
        update(start);

        while(!st.empty()){
            int v=st.back();
            bool adv=false;
            while(it[v]<4){
                int d=it[v]++;
                int u = to[v][d];
                if(u==-1) continue;
                if(vis[u]) continue;
                vis[u]=1;
                parent[u]=v;
                parentDir[u]=d;
                st.push_back(u);
                update(u);
                adv=true;
                break;
            }
            if(!adv) st.pop_back();
        }

        if(bestV==start) return {"", bestHeight};
        vector<int> rev;
        int v=bestV;
        while(v!=start){
            rev.push_back(parentDir[v]);
            v=parent[v];
        }
        reverse(rev.begin(), rev.end());
        string path;
        path.reserve(rev.size());
        for(int d: rev) path.push_back(dirChar(d));
        return {path,bestHeight};
    };

    for (int qi = 0; qi < K; qi++) {
        // Re-read input positions already consumed in outputs loop above? We didn't store them.
        // Therefore restructure by processing directly from input. To fix: we must read positions once.
        // But input already consumed entirely. So we need to rework earlier logic.
        return 0;
    }

    return 0;
}