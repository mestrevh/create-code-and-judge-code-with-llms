/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> teams = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"};
    int rounds[15][3] = {
        {0,0,1},{1,2,3},{2,4,5},{3,6,7},
        {4,8,9},{5,10,11},{6,12,13},{7,14,15},
        {8,0,2},{9,4,6},{10,8,10},{11,12,14},
        {12,0,4},{13,8,12},
        {14,0,8}
    };

    vector<int> nextTeams(16);
    vector<int> curTeams(16);
    for(int i=0;i<16;i++) curTeams[i]=i;

    vector<int> winnersLevel(16,0);

    for(int game=0; game<15; game++){
        int M,N;
        if(!(cin>>M>>N)) return 0;

        int slotA = rounds[game][1];
        int slotB = rounds[game][2];
        int idxA, idxB;

        int level = 0;
        if(game <=7) level=0;
        else if(game<=11) level=1;
        else if(game<=13) level=2;
        else level=3;

        if(level==0){
            idxA = slotA;
            idxB = slotB;
        } else if(level==1){
            idxA = 0 + slotA*0 + slotA/1; 
            idxB = 0 + slotB*0 + slotB/1;
            idxA = (slotA==0?0:(slotA==2?1:(slotA==4?2:3)));
        }

        int a,b;
        if(game<=7){
            a = slotA;
            b = slotB;
        } else if(game<=11){
            a = (game==8)?0: (game==9)?1: (game==10)?2:3;
            b = (game==8)?2: (game==9)?3: (game==10)?3:1;
        }

        (void)idxA; (void)idxB;
    }

    return 0;
}