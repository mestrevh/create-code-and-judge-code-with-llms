/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int cost(char a, char b){
    return a==b ? 0 : 1;
}

vector<int> nwScoreLinear(const string& X, const string& Y){
    int n = (int)X.size();
    int m = (int)Y.size();
    vector<int> prev(m+1), cur(m+1);
    prev[0]=0;
    for(int j=1;j<=m;j++) prev[j]=prev[j-1]+2;
    for(int i=1;i<=n;i++){
        cur[0]=prev[0]+2;
        for(int j=1;j<=m;j++){
            int diag = prev[j-1] + cost(X[i-1], Y[j-1]);
            int up = prev[j] + 2;
            int left = cur[j-1] + 2;
            cur[j] = min({diag, up, left});
        }
        swap(prev, cur);
    }
    return prev;
}

vector<int> nwScoreLinearPairs(const string& X, const string& Y, bool rev){
    string a=X, b=Y;
    if(rev){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    }
    return nwScoreLinear(a,b);
}

pair<int,int> chooseMinSplit(const vector<int>& L, const vector<int>& R){
    int n = (int)L.size()-1;
    int bestI = 0;
    int best = L[0] + R[n];
    for(int i=0;i<=n;i++){
        int s = L[i] + R[n-i];
        if(s < best){
            best = s;
            bestI = i;
        }
    }
    return {best, bestI};
}

void hirschberg(const string& X, const string& Y, string& outX, string& outY, int baseLimit){
    int n = (int)X.size();
    int m = (int)Y.size();
    if(n==0){
        outX.append(m, '-');
        outY.append(Y);
        return;
    }
    if(m==0){
        outX.append(n, X);
        outY.append(n, '-');
        return;
    }
    if(n==1 || m==1 || (long long)n*m <= baseLimit){
        if(n==1 && m==1){
            char x=X[0], y=Y[0];
            int diag = cost(x,y);
            int up = 2;
            int left = 2;
            int best = min({diag, up, left});
            if(diag==best){
                outX.push_back(x); outY.push_back(y);
            }else if(up==best){
                outX.push_back(x); outY.push_back('-');
                outX.push_back('-'); outY.push_back(y);
            }else{
                outX.push_back('-'); outY.push_back(y);
                outX.push_back(x); outY.push_back('-');
            }
            return;
        }
        if(n==1){
            int i=0;
            char x=X[0];
            int bestCost = INF;
            string bx, by;
            for(int j=0;j<=m;j++){
                int c = j*2 + (m-j)*2 + (j<m ? cost(x,Y[j-1]) : 0);
            }
            int curCostDiag = INF;
            for(int j=0;j<m;j++){
                int c = (j)*2 + cost(x, Y[j]) + (m-j-1)*2;
                if(c < bestCost){
                    bestCost = c;
                    int pos=j;
                    bx.clear(); by.clear();
                    bx.push_back(x); by.push_back(Y[pos]);
                    for(int k=0;k<pos;k++){ bx.insert(bx.begin(), '-'); by.insert(by.begin(), Y[k]); }
                    for(int k=pos+1;k<m;k++){ bx.push_back('-'); by.push_back(Y[k]); }
                }
            }
            int cAllGaps = m*2;
            if(cAllGaps < bestCost){
                bestCost = cAllGaps;
                bx.assign(m, '-'); by=Y;
            }else if(cAllGaps==bestCost){
                int j=0;
                bx.assign(m, '-'); by=Y;
            }
            outX += bx;
            outY += by;
            return;
        }
        if(m==1){
            char y=Y[0];
            int bestCost = INF;
            string bx, by;
            for(int i=0;i<n;i++){
                int c = i*2 + cost(X[i], y) + (n-i-1)*2;
                if(c < bestCost){
                    bestCost = c;
                    bx.clear(); by.clear();
                    bx.push_back(X[i]); by.push_back(y);
                    for(int k=0;k<i;k++){ bx.insert(bx.begin(), X[k]); by.insert(by.begin(), '-'); }
                    for(int k=i+1;k<n;k++){ bx.push_back(X[k]); by.push_back('-'); }
                }
            }
            int cAllGaps = n*2;
            if(cAllGaps < bestCost){
                bestCost = cAllGaps;
                bx=X; by.assign(n, '-');
            }else if(cAllGaps==bestCost){
                bx=X; by.assign(n, '-');
            }
            outX += bx;
            outY += by;
            return;
        }

        int N = n, M = m;
        vector<vector<short>> dp(N+1, vector<short>(M+1));
        vector<vector<char>> par(N+1, vector<char>(M+1));
        dp[0][0]=0;
        par[0][0]=0;
        for(int i=1;i<=N;i++){ dp[i][0]=dp[i-1][0]+2; par[i][0]='U'; }
        for(int j=1;j<=M;j++){ dp[0][j]=dp[0][j-1]+2; par[0][j]='L'; }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                int diag = dp[i-1][j-1] + cost(X[i-1], Y[j-1]);
                int up = dp[i-1][j] + 2;
                int left = dp[i][j-1] + 2;
                int best = min({diag, up, left});
                dp[i][j]=best;
                if(diag==best) par[i][j]='D';
                else if(up==best) par[i][j]='U';
                else par[i][j]='L';
            }
        }
        string ax, ay;
        int i=N,j=M;
        while(i>0 || j>0){
            if(i>0 && j>0 && par[i][j]=='D'){
                ax.push_back(X[i-1]);
                ay.push_back(Y[j-1]);
                i--; j--;
            }else if(i>0 && (j==0 || par[i][j]=='U')){
                ax.push_back(X[i-1]);
                ay.push_back('-');
                i--;
            }else{
                ax.push_back('-');
                ay.push_back(Y[j-1]);
                j--;
            }
        }
        reverse(ax.begin(), ax.end());
        reverse(ay.begin(), ay.end());
        outX += ax;
        outY += ay;
        return;
    }

    int mid = n/2;
    string XL = X.substr(0, mid);
    string XR = X.substr(mid);

    vector<int> L = nwScoreLinear(XL, Y);
    vector<int> RR;
    {
        string XRrev = XR;
        reverse(XRrev.begin(), XRrev.end());
        string Yrev = Y;
        reverse(Yrev.begin(), Yrev.end());
        RR = nwScoreLinear(XRrev, Yrev);
    }

    int mlen = m;
    int bestSum = INF;
    int bestI = 0;
    for(int i=0;i<=mlen;i++){
        int s = L[i] + RR[mlen - i];
        if(s < bestSum){
            bestSum = s;
            bestI = i;
        }
    }

    string Y1 = Y.substr(0, bestI);
    string Y2 = Y.substr(bestI);

    hirschberg(XL, Y1, outX, outY, baseLimit);
    hirschberg(XR, Y2, outX, outY, baseLimit);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y;
    if(!(cin >> X)) return 0;
    cin >> Y;

    string outX, outY;
    outX.reserve(X.size() + Y.size());
    outY.reserve(X.size() + Y.size());

    int baseLimit = 4000;

    hirschberg(X, Y, outX, outY, baseLimit);

    long long score = 0;
    int L = (int)outX.size();
    for(int i=0;i<L;i++){
        char a = outX[i];
        char b = outY[i];
        if(a=='-' || b=='-'){
            score += 2;
        }else{
            score += cost(a,b);
        }
    }

    cout << score << "\n" << outX << "\n" << outY << "\n";
    return 0;
}