/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long INFLL = (1LL<<62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto bfs = [&](int src, vector<int>& dist)->int{
        dist.assign(n+1, -1);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        int far=src;
        while(!q.empty()){
            int v=q.front(); q.pop();
            if(dist[v]>dist[far]) far=v;
            for(int to: g[v]){
                if(dist[to]==-1){
                    dist[to]=dist[v]+1;
                    q.push(to);
                }
            }
        }
        return far;
    };

    vector<int> dist1, distA, distB, distC;
    int A = bfs(1, dist1);
    int B = bfs(A, distA);
    int d = distA[B];

    int C = (B == A ? A : B);

    // Find all nodes whose eccentricity from A is d (i.e., on some diameter endpoint side from A).
    // We'll use distances to handle contribution with DP on depths within radius d-1.
    // But we can solve using counting for each k<d:
    // sum_{i<j} min(dist(i,j), d-1?) Actually f(i,j)=dist if dist<d else 0, and dist==d ->0.
    // So contribute dist for pairs with dist <= d-1.
    // Therefore answer = sum_{i<j, dist(i,j) <= d-1} dist(i,j).

    // Since d<=500, use centroid-like depth counting by limiting BFS depth to d-1 from each node?
    // Need O(n*d) possible.
    // Approach: For each node as root in BFS truncated to depth d-1, count distances to prior nodes and accumulate using formula.
    // But O(n^2) worst.
    // Better: Use tree DP with reroot? Still hard.
    // Use technique for sum of distances for pairs with distance <= D in tree, with D<=500:
    // Use centroid decomposition with maintaining frequency by depth up to D and accumulating contributions.
    // Complexity O(n log n * D).

    int D = d-1;
    if (D <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> sub(n+1), parent(n+1, -1);
    vector<char> dead(n+1, 0);
    function<int(int,int)> dfsSize = [&](int v,int p){
        sub[v]=1;
        for(int to: g[v]){
            if(to==p || dead[to]) continue;
            sub[v]+=dfsSize(to,v);
        }
        return sub[v];
    };
    function<int(int,int,int)> dfsCentroid = [&](int v,int p,int total){
        for(int to: g[v]){
            if(to==p || dead[to]) continue;
            if(sub[to] > total/2) return dfsCentroid(to,v,total);
        }
        return v;
    };

    long long ans = 0;

    vector<int> allDepth;
    vector<int> cnt;
    vector<long long> sumDepth;

    function<void(int,int,int,vector<int>&)> collectDepths = [&](int v,int p,int depth, vector<int>& depths){
        if(depth > D) return;
        depths.push_back(depth);
        for(int to: g[v]){
            if(to==p || dead[to]) continue;
            collectDepths(to,v,depth+1,depths);
        }
    };

    function<void(int,int,int,long long&)> accumulateFrom = [&](int v,int p,int depth,long long& localAns){
        if(depth > D) return;
        localAns += depth;
        for(int to: g[v]){
            if(to==p || dead[to]) continue;
            accumulateFrom(to,v,depth+1,localAns);
        }
    };

    function<void(int)> decompose = [&](int entry){
        int total = dfsSize(entry, -1);
        int c = dfsCentroid(entry, -1, total);
        dead[c]=1;

        cnt.assign(D+1, 0);
        sumDepth.assign(D+1, 0);

        cnt[0]=1;
        sumDepth[0]=0;

        vector<pair<int, vector<int>>> childDepths;
        for(int to: g[c]){
            if(dead[to]) continue;
            vector<int> depths;
            collectDepths(to, c, 1, depths);
            childDepths.push_back({to, depths});
        }

        // Count pairs whose path goes through centroid: sum over depths x from previous processed subtrees (including centroid node itself at depth 0)
        // For a node at depth a, and another at depth b, distance = a+b <= D => contribute a+b.
        for (auto &pr : childDepths) {
            auto &depths = pr.second;

            for(int a : depths){
                if(a > D) continue;
                int maxB = D - a;
                // Add contribution of distances with centroid as LCA:
                // For each b in [0..maxB], pairs with current node at depth a and existing nodes at depth b:
                // total add = a * cnt[b] + sumDepth[b] (where sumDepth[b] = b*cnt[b])
                long long totalCnt = 0;
                long long totalSum = 0;
                // We need prefix sums of cnt and b*cnt quickly.
                // Build prefix arrays once per centroid.
            }
            // We'll compute prefix arrays for current state.
            vector<long long> prefCnt(D+2,0), prefSum(D+2,0);
            for(int i=0;i<=D;i++){
                prefCnt[i+1]=prefCnt[i]+cnt[i];
                prefSum[i+1]=prefSum[i]+sumDepth[i];
            }

            for(int a : depths){
                if(a > D) continue;
                int maxB = D - a;
                long long ccount = prefCnt[maxB+1];
                long long csum = prefSum[maxB+1];
                ans += (long long)a * ccount + csum;
            }

            for(int b : depths){
                if(b > D) continue;
                cnt[b] += 1;
                sumDepth[b] += (long long)b;
            }
        }

        for(int to: g[c]){
            if(dead[to]) continue;
            decompose(to);
        }
        dead[c]=0;
    };

    // The above centroid decomposition counts each pair multiple times because dead reset at end.
    // Fix: do not reset dead[c]; keep decomposition tree structure.
    // We'll implement correctly with dead staying true.
    fill(dead.begin(), dead.end(), 0);

    function<void(int)> decompose2 = [&](int entry){
        int total = dfsSize(entry, -1);
        int c = dfsCentroid(entry, -1, total);
        dead[c]=1;

        vector<long long> cntArr(D+1, 0), sumArr(D+1, 0);
        cntArr[0]=1;

        // Existing nodes are centroid itself only initially.
        for(int to: g[c]){
            if(dead[to]) continue;

            vector<int> depths;
            collectDepths(to, c, 1, depths);

            vector<long long> prefCnt(D+2,0), prefSum(D+2,0);
            for(int i=0;i<=D;i++){
                prefCnt[i+1]=prefCnt[i]+cntArr[i];
                prefSum[i+1]=prefSum[i]+sumArr[i];
            }

            for(int a : depths){
                if(a > D) continue;
                int maxB = D - a;
                long long ccount = prefCnt[maxB+1];
                long long csum = prefSum[maxB+1];
                ans += (long long)a * ccount + csum;
            }

            for(int b : depths){
                if(b > D) continue;
                cntArr[b] += 1;
                sumArr[b] += (long long)b;
            }
        }

        for(int to: g[c]){
            if(dead[to]) continue;
            decompose2(to);
        }
    };

    decompose2(1);

    cout << ans << "\n";
    return 0;
}