/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(16), b(16);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) { int x; cin >> x; a[i*4+j] = x; }
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) { int x; cin >> x; b[i*4+j] = x; }

    auto idx = [](int r, int c){ return r*4 + c; };

    vector<int> targetPos;
    targetPos.reserve(16);

    vector<vector<int>> posByWeightA(1001), posByWeightB(1001);
    for (int i = 0; i < 16; i++) posByWeightA[a[i]].push_back(i);
    for (int i = 0; i < 16; i++) posByWeightB[b[i]].push_back(i);

    int minCost = INT_MAX;

    for (int w = 1; w <= 1000; w++) {
        if (posByWeightA[w].size() != posByWeightB[w].size()) return 0;
    }

    vector<int> perm(16, -1);
    for (int i = 0; i < 16; i++) perm[i] = -1;

    vector<vector<int>> occA(1001), occB(1001);
    for (int i = 0; i < 16; i++) occA[a[i]].push_back(i);
    for (int i = 0; i < 16; i++) occB[b[i]].push_back(i);

    bool ok = true;
    for (int w = 1; w <= 1000; w++) if (occA[w].size() != occB[w].size()) ok = false;
    if (!ok) return 0;

    vector<int> orderA(16);
    iota(orderA.begin(), orderA.end(), 0);

    vector<int> mapping(16, -1);
    vector<int> available(16, 0);
    for (int i = 0; i < 16; i++) available[i] = 1;

    vector<int> posOfAbyWeight[1001];
    for (int w = 1; w <= 1000; w++) posOfAbyWeight[w].clear();
    for (int i = 0; i < 16; i++) posOfAbyWeight[a[i]].push_back(i);

    for (int i = 0; i < 16; i++) mapping[i] = -1;

    // Greedy minimal matching is not necessarily optimal with costs depending on values during swaps.
    // However, the state graph cost depends only on container weights, and containers are indistinguishable by weight but distinguishable by identity.
    // To find minimal cost, we can model as minimum cost to transform with distinct containers using Dijkstra on permutations,
    // but 16! too large. We instead use the fact that costs are sums of weights of swapped adjacent containers, so each move cost depends on which two containers are swapped.
    // This corresponds to sorting via adjacent transpositions in a graph where each swap cost is sum of the two involved item weights.
    // For identical weights, any identity mapping gives same multiset, but costs might differ if identities swap around.
    // We therefore treat containers as distinct by their occurrence in initial; then compute minimal cost using min-cost flow on cycle decomposition? Not valid due to intermediate weights.
    // Given constraints small (2x4 => 8 containers), we can do full Dijkstra over 8! states by representing positions of the 8 containers.
    // We'll work with 8-container positions only.
    // Problem description says 8 positions (2x4). Our input is 4x4 with weights; but only 8 are used (as shown figure).
    // The statement omits the exact placement; for 2x4 ship, it is natural that only first two rows are used and last two rows for other? Not.
    // Actually input provides 4 lines x 4 ints for initial and final, so likely grid is 2x4 embedded in 4x4 with blank cells; but blank not given.
    // The only consistent interpretation: it's a 4x4 grid with only adjacent moves allowed on the 2x4 sub-structure? Not specified.
    // Yet examples use all 4x4 numbers.
    // Therefore the ship must be 4x4? But described "two lines and four columns" => 2x4 = 8.
    // We'll assume the ship is exactly the 2x4 within the 4x4 input: the first two rows represent the 2 lines, and remaining two rows are irrelevant.
    // Examples: initial first two rows: 1 2 3 4 / 5 10 7 8 ; final first two rows: 1 2 3 4 / 5 8 7 10 .
    // That matches output 50 with only 8 containers.
    // Similarly test1: first two rows initial: [3 1 2 1; 4 7 52 9] and final: [7 1 2 1; 3 9 52 4]. output 81 plausible.
    // We'll take positions (rows 0 and 1, cols 0..3) only.

    vector<int> init(8), fin(8);
    for (int r = 0; r < 2; r++) for (int c = 0; c < 4; c++) {
        init[r*4+c] = a[r*4+c];
        fin[r*4+c] = b[r*4+c];
    }

    vector<int> neigh[8];
    for (int r = 0; r < 2; r++) for (int c = 0; c < 4; c++) {
        int u = r*4+c;
        if (c+1 < 4) {
            int v = r*4+(c+1);
            neigh[u].push_back(v);
        }
        if (r+1 < 2) {
            int v = (r+1)*4+c;
            neigh[u].push_back(v);
        }
    }

    vector<int> initSorted = init, finSorted = fin;
    sort(initSorted.begin(), initSorted.end());
    sort(finSorted.begin(), finSorted.end());
    if (initSorted != finSorted) return 0;

    vector<int> perm0(8);
    iota(perm0.begin(), perm0.end(), 0);

    vector<int> initIds(8), finIds(8);
    // Distinguishable containers by position in initial.
    // We must map goal state to ordering of initial identities consistent with equal weights.
    // We'll enumerate possible identity assignments for duplicates by using multiset positions.
    // Then run Dijkstra for minimal cost to reach any goal assignment; take min.

    vector<vector<int>> positionsByValueInit(1001);
    for (int i = 0; i < 8; i++) positionsByValueInit[init[i]].push_back(i);

    // For each value, generate bijections between initial indices with that value and goal positions with that value.
    // Number of duplicates is small (8), so worst-case permutations could be large (up to 8!).
    // But values range wide; still implement backtracking to enumerate all goal identity permutations consistent with values.
    vector<vector<int>> goalPosByValue(1001);
    for (int p = 0; p < 8; p++) goalPosByValue[fin[p]].push_back(p);

    vector<int> goalIdentity(8, -1);

    vector<int> usedInit(8, 0);
    for (int i = 0; i < 8; i++) usedInit[i] = 0;

    vector<int> uniqueValues;
    for (int v = 1; v <= 1000; v++) if (!goalPosByValue[v].empty()) uniqueValues.push_back(v);

    vector<int> goalAssignmentsCount;
    vector<vector<int>> allGoalStates;
    allGoalStates.reserve(2000);

    function<void(int)> backtrack = [&](int idxVal) {
        if (idxVal == (int)uniqueValues.size()) {
            allGoalStates.push_back(goalIdentity);
            return;
        }
        int val = uniqueValues[idxVal];
        auto &initPos = positionsByValueInit[val];
        auto &goalPos = goalPosByValue[val];
        // Assign identities from initPos to goalPos bijectively.
        sort(initPos.begin(), initPos.end());
        vector<int> permInit = initPos;
        sort(goalPos.begin(), goalPos.end());
        // generate permutations of initPos indices mapped to goal positions in order
        sort(permInit.begin(), permInit.end());
        do {
            for (int k = 0; k < (int)goalPos.size(); k++) {
                int p = goalPos[k];
                int id = permInit[k];
                goalIdentity[p] = id;
            }
            backtrack(idxVal + 1);
        } while (next_permutation(permInit.begin(), permInit.end()));
    };

    // If there are no duplicates, backtrack generates exactly one.
    backtrack(0);

    // Dijkstra over 8! states with costs dependent on swapping two identities' weights.
    // Represent state as permutation of 8 identities (which init position's container at each current slot).
    // Use Cantor encoding for 8! = 40320.
    vector<int> idWeight(8);
    for (int i = 0; i < 8; i++) idWeight[i] = init[i];

    auto encode = [&](const array<int,8>& st)->int{
        int code = 0;
        int fact[9]; fact[0]=1; for(int i=1;i<=8;i++) fact[i]=fact[i-1]*i;
        // Lehmer code
        int used[8]={0};
        for(int i=0;i<8;i++){
            int cnt=0;
            for(int j=0;j<st[i];j++) if(!used[j]) cnt += 1;
            used[st[i]]=1;
            code += cnt * fact[7-i];
        }
        return code;
    };

    auto decode = [&](int code)->array<int,8>{
        array<int,8> st{};
        int fact[9]; fact[0]=1; for(int i=1;i<=8;i++) fact[i]=fact[i-1]*i;
        vector<int> elems(8);
        iota(elems.begin(), elems.end(), 0);
        for(int i=0;i<8;i++){
            int f = fact[7-i];
            int q = code / f;
            code %= f;
            st[i] = elems[q];
            elems.erase(elems.begin()+q);
        }
        return st;
    };

    array<int,8> start;
    for (int i = 0; i < 8; i++) start[i] = i;

    int Nstates = 40320;
    const long long INF = (1LL<<60);
    vector<long long> dist(Nstates, INF);

    int sCode = encode(start);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[sCode] = 0;
    pq.push({0, sCode});

    vector<array<int,8>> statesOfCode; statesOfCode.reserve(Nstates);

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        if (d >= minCost) continue;

        array<int,8> st = decode(u);
        // Relax swap moves between adjacent positions (edges in grid)
        for(int x=0;x<8;x++){
            for(int y: neigh[x]){
                if (x < y) { // avoid double-counting
                    array<int,8> ns = st;
                    int id1 = st[x], id2 = st[y];
                    long long nd = d + (long long)idWeight[id1] + (long long)idWeight[id2];
                    swap(ns[x], ns[y]);
                    int vCode = encode(ns);
                    if(nd < dist[vCode]){
                        dist[vCode]=nd;
                        pq.push({nd, vCode});
                    }
                }
            }
        }
    }

    for (auto &g : allGoalStates) {
        array<int,8> st;
        for(int i=0;i<8;i++) st[i]=g[i];
        int gCode = encode(st);
        minCost = min<long long>(minCost, dist[gCode]);
    }

    cout << minCost << "\n";
    return 0;
}