/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    auto checkWin = [&](const array<array<char,3>,3>& b, char p)->bool{
        for(int i=0;i<3;i++){
            if(b[i][0]==p && b[i][1]==p && b[i][2]==p) return true;
            if(b[0][i]==p && b[1][i]==p && b[2][i]==p) return true;
        }
        if(b[0][0]==p && b[1][1]==p && b[2][2]==p) return true;
        if(b[0][2]==p && b[1][1]==p && b[2][0]==p) return true;
        return false;
    };

    for(int tc=0; tc<T; tc++){
        array<array<char,3>,3> b;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                string s;
                cin >> s;
                char c = s.empty() ? '_' : s[0];
                if(c!='X' && c!='O') c = '_';
                b[i][j] = c;
            }
        }

        int cntX=0, cntO=0, empty=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b[i][j]=='X') cntX++;
                else if(b[i][j]=='O') cntO++;
                else empty++;
            }
        }

        bool xWin = checkWin(b,'X');
        bool oWin = checkWin(b,'O');

        string ans;

        bool illegal = false;

        if(cntO > cntX) illegal = true;
        if(cntX - cntO > 1) illegal = true;

        if(xWin && oWin) illegal = true;

        if(!illegal){
            if(xWin){
                if(cntX != cntO + 1) illegal = true;
            }
            if(oWin){
                if(cntX != cntO) illegal = true;
            }
        }

        if(!illegal){
            if(xWin || oWin){
                char winner = xWin ? 'X' : 'O';
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(b[i][j]=='_') { }
                    }
                }
                int movesPlayed = cntX + cntO;
                int expectedMoves = winner=='X' ? (cntX + cntO) : (cntX + cntO);
                vector<pair<int,int>> cellsX, cellsO;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(b[i][j]=='X') cellsX.push_back({i,j});
                        else if(b[i][j]=='O') cellsO.push_back({i,j});
                    }
                }

                bool possible = false;
                for(int turn=0; turn<=1; turn++){
                    int firstX = 0;
                    if(turn==0){
                        firstX = 0;
                    }
                }

                int totalMoves = movesPlayed;
                if(xWin){
                    if(!(cntX==cntO+1)) illegal = true;
                } else if(oWin){
                    if(!(cntX==cntO)) illegal = true;
                }

                int winnerMoveIndex;
                if(xWin) winnerMoveIndex = 2*cntO + 1;
                else winnerMoveIndex = 2*cntX;

                if(totalMoves != winnerMoveIndex) illegal = true;
            }
        }

        if(illegal){
            ans = "ILEGAL";
        }else{
            if(xWin) ans = "X_VENCEU";
            else if(oWin) ans = "O_VENCEU";
            else ans = "EM_ANDAMENTO";
        }

        cout << ans << "\n";
    }

    return 0;
}