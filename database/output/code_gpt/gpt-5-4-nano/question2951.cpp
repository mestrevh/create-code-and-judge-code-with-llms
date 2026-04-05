/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pos { int r,c; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> a(8, vector<string>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(!(cin >> a[i][j])) return 0;
        }
    }

    auto inb = [&](int r,int c){ return r>=0 && r<8 && c>=0 && c<8; };

    int kr=-1,kc=-1;
    for(int r=0;r<8;r++) for(int c=0;c<8;c++){
        string s=a[r][c];
        if(s=="K"){ kr=r; kc=c; }
    }

    auto isWhitePiece = [&](const string& s){
        return s=="K" || s=="Q" || s=="B" || s=="N" || s=="C" || s=="T" || s=="P" ;
    };

    auto enemy = [&](const string& s){
        return s=="k" || s=="q" || s=="b" || s=="n" || s=="c" || s=="t" || s=="p";
    };

    auto pieceType = [&](const string& s)->char{
        if(s.empty() || s=="-") return 0;
        char ch=s[0];
        if(ch=='.') return 0;
        return ch;
    };

    auto attackFrom = [&](int r,int c)->vector<Pos>{
        vector<Pos> res;
        string s=a[r][c];
        if(s=="-" || s.empty()) return res;
        char t = s[0];
        bool isBlack = enemy(s);
        if(!isBlack) return res;

        auto push_if = [&](int rr,int cc){
            if(!inb(rr,cc)) return;
            res.push_back({rr,cc});
        };

        if(t=='p'){
            int dir=1;
            push_if(r+dir,c-1);
            push_if(r+dir,c+1);
        } else if(t=='n'){
            static int dr[8]={-2,-2,-1,-1,1,1,2,2};
            static int dc[8]={-1,1,-2,2,-2,2,-1,1};
            for(int i=0;i<8;i++){
                int rr=r+dr[i], cc=c+dc[i];
                if(inb(rr,cc)) res.push_back({rr,cc});
            }
        } else if(t=='b' || t=='q'){
            static int dr[4]={-1,-1,1,1};
            static int dc[4]={-1,1,-1,1};
            for(int d=0;d<4;d++){
                int rr=r+dr[d], cc=c+dc[d];
                while(inb(rr,cc)){
                    res.push_back({rr,cc});
                    if(a[rr][cc] != "-") break;
                    rr+=dr[d]; cc+=dc[d];
                }
            }
        }
        if(t=='t' || t=='q'){
            static int dr[4]={-1,1,0,0};
            static int dc[4]={0,0,-1,1};
            for(int d=0;d<4;d++){
                int rr=r+dr[d], cc=c+dc[d];
                while(inb(rr,cc)){
                    res.push_back({rr,cc});
                    if(a[rr][cc] != "-") break;
                    rr+=dr[d]; cc+=dc[d];
                }
            }
        }
        if(t=='c'){
            static int dr[8]={-1,-1,-1,0,0,1,1,1};
            static int dc[8]={-1,0,1,-1,1,-1,0,1};
            for(int i=0;i<8;i++){
                int rr=r+dr[i], cc=c+dc[i];
                if(inb(rr,cc)) res.push_back({rr,cc});
            }
        }
        return res;
    };

    auto findAttackers = [&](int& attackerCount, vector<Pos>& attackers){
        attackerCount=0;
        attackers.clear();
        for(int r=0;r<8;r++) for(int c=0;c<8;c++){
            if(a[r][c]=="-" || a[r][c].empty()) continue;
            if(!enemy(a[r][c])) continue;
            auto att = attackFrom(r,c);
            for(auto &p: att){
                if(p.r==kr && p.c==kc){
                    attackerCount++;
                    attackers.push_back({r,c});
                    break;
                }
            }
        }
    };

    int attackerCount=0;
    vector<Pos> attackers;
    findAttackers(attackerCount, attackers);

    auto kingInCheck = [&](const vector<vector<string>>& b)->bool{
        vector<vector<string>> save = a;
        (void)save;
        auto inb2 = [&](int r,int c){ return r>=0 && r<8 && c>=0 && c<8; };
        int KRR=-1,KCC=-1;
        for(int r=0;r<8;r++) for(int c=0;c<8;c++) if(b[r][c]=="K"){ KRR=r; KCC=c; }
        if(KRR==-1) return false;
        auto enemy2 = [&](const string& s){
            return s=="k" || s=="q" || s=="b" || s=="n" || s=="c" || s=="t" || s=="p";
        };
        auto attackFromB = [&](int r,int c)->vector<Pos>{
            vector<Pos> res;
            string s=b[r][c];
            if(s=="-" || s.empty()) return res;
            char t=s[0];
            if(!enemy2(s)) return res;
            auto push_if = [&](int rr,int cc){
                if(inb2(rr,cc)) res.push_back({rr,cc});
            };
            if(t=='p'){
                int dir=1;
                push_if(r+dir,c-1);
                push_if(r+dir,c+1);
            } else if(t=='n'){
                static int dr[8]={-2,-2,-1,-1,1,1,2,2};
                static int dc[8]={-1,1,-2,2,-2,2,-1,1};
                for(int i=0;i<8;i++){
                    int rr=r+dr[i], cc=c+dc[i];
                    if(inb2(rr,cc)) res.push_back({rr,cc});
                }
            } else if(t=='b' || t=='q'){
                static int dr[4]={-1,-1,1,1};
                static int dc[4]={-1,1,-1,1};
                for(int d=0;d<4;d++){
                    int rr=r+dr[d], cc=c+dc[d];
                    while(inb2(rr,cc)){
                        res.push_back({rr,cc});
                        if(b[rr][cc] != "-") break;
                        rr+=dr[d]; cc+=dc[d];
                    }
                }
            }
            if(t=='t' || t=='q'){
                static int dr[4]={-1,1,0,0};
                static int dc[4]={0,0,-1,1};
                for(int d=0;d<4;d++){
                    int rr=r+dr[d], cc=c+dc[d];
                    while(inb2(rr,cc)){
                        res.push_back({rr,cc});
                        if(b[rr][cc] != "-") break;
                        rr+=dr[d]; cc+=dc[d];
                    }
                }
            }
            if(t=='c'){
                static int dr[8]={-1,-1,-1,0,0,1,1,1};
                static int dc[8]={-1,0,1,-1,1,-1,0,1};
                for(int i=0;i<8;i++){
                    int rr=r+dr[i], cc=c+dc[i];
                    if(inb2(rr,cc)) res.push_back({rr,cc});
                }
            }
            return res;
        };

        for(int r=0;r<8;r++) for(int c=0;c<8;c++){
            if(b[r][c]=="-"||b[r][c].empty()) continue;
            if(!enemy2(b[r][c])) continue;
            auto att = attackFromB(r,c);
            for(auto &p: att){
                if(p.r==KRR && p.c==KCC) return true;
            }
        }
        return false;
    };

    bool inCheck = (attackerCount>0);
    if(!inCheck){
        cout << "NAO XEQUE\n";
        return 0;
    }

    auto wouldBeLegalKingMove = [&](int nr,int nc)->bool{
        vector<vector<string>> b=a;
        b[kr][kc]="-";
        b[nr][nc]="K";
        return !kingInCheck(b);
    };

    for(int dr=-1;dr<=1;dr++) for(int dc=-1;dc<=1;dc++){
        if(dr==0 && dc==0) continue;
        int nr=kr+dr, nc=kc+dc;
        if(!inb(nr,nc)) continue;
        if(a[nr][nc] != "-" && !enemy(a[nr][nc])) continue; // cannot capture own piece
        if(wouldBeLegalKingMove(nr,nc)){
            cout << "XEQUE\n";
            return 0;
        }
    }

    auto canCaptureAttackerOrBlock = [&]()->bool{
        vector<Pos> attPos = attackers;
        for(auto &att: attPos){
            vector<vector<string>> b=a;
            string cap = b[att.r][att.c];
            if(cap=="-") continue;
            b[att.r][att.c]="-";
            int myKCount=0;
            for(int r=0;r<8;r++) for(int c=0;c<8;c++) if(b[r][c]=="K") myKCount++;
            (void)myKCount;
            if(!kingInCheck(b)) return true;
        }

        return false;
    };

    if(canCaptureAttackerOrBlock()){
        cout << "XEQUE\n";
        return 0;
    }

    cout << "XEQUE-MATE\n";
    return 0;
}