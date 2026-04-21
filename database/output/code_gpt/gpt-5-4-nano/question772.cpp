/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0){init(n);}
    void init(int n_) {
        n=n_;
        p.resize(n);
        r.assign(n,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        while(p[x]!=x){ p[x]=p[p[x]]; x=p[x]; }
        return x;
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if(!(cin >> K)) return 0;

    for(int tc=0; tc<K; tc++){
        int N;
        cin >> N;
        char S;
        cin >> S;

        vector<vector<int>> board(N, vector<int>(N, 0));
        int M = N*N;
        vector<pair<int,int>> moves;
        moves.reserve(M);
        int r,c;
        while (cin >> r >> c) {
            moves.push_back({r,c});
            int remaining = M - (int)moves.size();
            if(remaining < 0) break;
            if((int)moves.size() >= M) break;
            if(cin.peek()=='\n') {
                string line;
                streampos pos = cin.tellg();
                getline(cin, line);
                if(line.size()==0) break;
                else {
                    cin.seekg(pos);
                }
            }
            if((int)moves.size() % 2 == 0) {
                int nextR;
                streampos pos = cin.tellg();
                if(!(cin >> nextR)) break;
                if(nextR < 0 || nextR >= N) {
                    cin.seekg(pos);
                    break;
                }
                int nextC;
                cin >> nextC;
                moves.push_back({nextR,nextC});
            }
            if((int)moves.size() >= M) break;
        }

        if((int)moves.size() == 0) {
            cout << "caso " << tc << ": B 0\n\n";
            continue;
        }

        DSU dsuB(N*N+2), dsuW(N*N+2);
        auto idx = [&](int i,int j){ return i*N + j; };
        auto leftTop = N*N;
        auto rightBottom = N*N+1;

        int turn = (S=='B') ? 0 : 1;

        auto neighbors = [&](int i,int j){
            array<pair<int,int>,6> arr;
            int cnt=0;
            if(i-1>=0) { if(j>=0 && j<N) arr[cnt++]={i-1,j}; }
            if(i+1<N) { if(j>=0 && j<N) arr[cnt++]={i+1,j}; }
            if(j-1>=0) arr[cnt++]={i,j-1};
            if(j+1<N) arr[cnt++]={i,j+1};
            if(i-1>=0 && j+1<N) arr[cnt++]={i-1,j+1};
            if(i+1<N && j-1>=0) arr[cnt++]={i+1,j-1};
            arr[cnt++] = {-1,-1};
            vector<pair<int,int>> res;
            res.reserve(cnt);
            for(int k=0;k<cnt;k++){
                int x=arr[k].first, y=arr[k].second;
                if(x>=0 && x<N && y>=0 && y<N) res.push_back({x,y});
            }
            return res;
        };

        char winner = (turn==0 ? 'B' : 'W');

        auto checkWinner = [&]()->char{
            for(int i=0;i<N;i++){
                if(board[i][0]=='B' || board[i][N-1]=='B'){
                }
            }
            for(int side=0; side<2; side++){
            }
            return '?';
        };

        auto areaOfWinner = [&](char win)->int{
            vector<vector<int>> vis(N, vector<int>(N, 0));
            queue<pair<int,int>> q;
            int count = 0;
            if(win=='B'){
                for(int i=0;i<N;i++){
                    if(board[i][0]==win && !vis[i][0]){
                        vis[i][0]=1;
                        q.push({i,0});
                        count++;
                    }
                }
                while(!q.empty()){
                    auto [x,y]=q.front(); q.pop();
                    for(auto [nx,ny]: neighbors(x,y)){
                        if(board[nx][ny]==win && !vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                            count++;
                        }
                    }
                }
            } else {
                for(int j=0;j<N;j++){
                    if(board[0][j]==win && !vis[0][j]){
                        vis[0][j]=1;
                        q.push({0,j});
                        count++;
                    }
                }
                while(!q.empty()){
                    auto [x,y]=q.front(); q.pop();
                    for(auto [nx,ny]: neighbors(x,y)){
                        if(board[nx][ny]==win && !vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                            count++;
                        }
                    }
                }
            }
            return count;
        };

        bool isSolved = false;
        int winnerMoveIndex = -1;
        char win = '?';

        for(int mi=0; mi<(int)moves.size(); mi++){
            int i=moves[mi].first, j=moves[mi].second;
            char player = (mi%2==0)?S: (S=='B'?'W':'B');
            board[i][j]=player;

            int id = idx(i,j);
            if(player=='B'){
                if(j==0) dsuB.unite(id, leftTop);
                if(j==N-1) dsuB.unite(id, rightBottom);
                for(auto [nx,ny]: neighbors(i,j)){
                    if(board[nx][ny]=='B'){
                        dsuB.unite(id, idx(nx,ny));
                    }
                }
                if(!isSolved && dsuB.find(leftTop)==dsuB.find(rightBottom)){
                    isSolved=true;
                    winnerMoveIndex=mi;
                    win='B';
                    break;
                }
            } else {
                if(i==0) dsuW.unite(id, leftTop);
                if(i==N-1) dsuW.unite(id, rightBottom);
                for(auto [nx,ny]: neighbors(i,j)){
                    if(board[nx][ny]=='W'){
                        dsuW.unite(id, idx(nx,ny));
                    }
                }
                if(!isSolved && dsuW.find(leftTop)==dsuW.find(rightBottom)){
                    isSolved=true;
                    winnerMoveIndex=mi;
                    win='W';
                    break;
                }
            }
        }

        if(!isSolved){
            for(int mi=0; mi<(int)moves.size(); mi++){
                int i=moves[mi].first, j=moves[mi].second;
                char player = (mi%2==0)?S: (S=='B'?'W':'B');
                board[i][j]=player;
            }
            int winB=0, winW=0;
            DSU dsuB2(N*N+2), dsuW2(N*N+2);
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    int id=idx(i,j);
                    if(board[i][j]=='B'){
                        if(j==0) dsuB2.unite(id,leftTop);
                        if(j==N-1) dsuB2.unite(id,rightBottom);
                        for(auto [nx,ny]: neighbors(i,j)){
                            if(board[nx][ny]=='B') dsuB2.unite(id, idx(nx,ny));
                        }
                    } else if(board[i][j]=='W'){
                        if(i==0) dsuW2.unite(id,leftTop);
                        if(i==N-1) dsuW2.unite(id,rightBottom);
                        for(auto [nx,ny]: neighbors(i,j)){
                            if(board[nx][ny]=='W') dsuW2.unite(id, idx(nx,ny));
                        }
                    }
                }
            }
            if(dsuB2.find(leftTop)==dsuB2.find(rightBottom)) win='B';
            else if(dsuW2.find(leftTop)==dsuW2.find(rightBottom)) win='W';
            else win='B';
        }

        int area = 0;
        {
            vector<vector<int>> vis(N, vector<int>(N, 0));
            queue<pair<int,int>> q;
            vector<pair<int,int>> start;
            if(win=='B'){
                for(int i=0;i<N;i++) if(board[i][0]=='B') start.push_back({i,0});
                for(auto &p:start) if(!vis[p.first][p.second]){ vis[p.first][p.second]=1; q.push(p); }
                int visitedCount=0;
                while(!q.empty()){
                    auto [x,y]=q.front(); q.pop();
                    visitedCount++;
                    for(auto [nx,ny]: neighbors(x,y)){
                        if(board[nx][ny]=='B' && !vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                area = visitedCount;
            } else {
                for(int j=0;j<N;j++) if(board[0][j]=='W') start.push_back({0,j});
                for(auto &p:start) if(!vis[p.first][p.second]){ vis[p.first][p.second]=1; q.push(p); }
                int visitedCount=0;
                while(!q.empty()){
                    auto [x,y]=q.front(); q.pop();
                    visitedCount++;
                    for(auto [nx,ny]: neighbors(x,y)){
                        if(board[nx][ny]=='W' && !vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                area = visitedCount;
            }
        }

        cout << "caso " << tc << ": " << win << " " << area << "\n\n";
    }
    return 0;
}