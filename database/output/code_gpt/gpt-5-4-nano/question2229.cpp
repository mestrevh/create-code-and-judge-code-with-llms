/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> a(5);
    for (int i = 0; i < 5; i++) {
        if (!getline(cin, a[i])) return 0;
        if (!a[i].empty() && a[i][0] == ' ') {
            int p = 0;
            while (p < (int)a[i].size() && a[i][p] == ' ') p++;
            a[i] = a[i].substr(p);
        }
        if (a[i].empty()) { i--; continue; }
    }

    vector<string> even, odd;
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    vector<int> oddPos = {0,2,4};
    vector<int> evenPos = {1,3};

    string pos[5];

    for (int i = 0; i < (int)oddPos.size(); i++) pos[oddPos[i]] = odd[i];
    for (int i = 0; i < (int)evenPos.size(); i++) pos[evenPos[i]] = even[i];

    auto sideOf = [&](int seatIdx)->int{
        return (seatIdx % 2);
    };

    int marioSeat = -1;
    for (int i = 0; i < 5; i++) if (pos[i] == "Mario") marioSeat = i;

    int princesaSeat = 0;
    if (marioSeat == -1) marioSeat = 1;

    if (marioSeat != 1 && marioSeat != 2) {
        int target = (marioSeat < 2 ? 1 : 2);
        if (target == 1) {
            int idx2 = -1;
            for (int i = 0; i < 5; i++) if (pos[i] == "Mario") idx2 = i;
            if (idx2 != 1) {
                int seatToSwap = -1;
                for (int i = 0; i < 5; i++) {
                    if (pos[i] != "Princesa" && pos[i] != "Mario") {
                        if ((i % 2) == (1 % 2)) { seatToSwap = i; break; }
                    }
                }
                if (seatToSwap != -1) swap(pos[1], pos[seatToSwap]);
            }
        } else {
            int idx2 = -1;
            for (int i = 0; i < 5; i++) if (pos[i] == "Mario") idx2 = i;
            if (idx2 != 2) {
                int seatToSwap = -1;
                for (int i = 0; i < 5; i++) {
                    if (pos[i] != "Princesa" && pos[i] != "Mario") {
                        if ((i % 2) == (2 % 2)) { seatToSwap = i; break; }
                    }
                }
                if (seatToSwap != -1) swap(pos[2], pos[seatToSwap]);
            }
        }
    }

    int toadSeat = -1;
    for (int i = 0; i < 5; i++) if (pos[i] == "Toad") toadSeat = i;

    auto distanceToPrincess = [&](int seatIdx)->int{
        return abs(seatIdx - princesaSeat);
    };

    if (toadSeat != -1) {
        if (sideOf(marioSeat) == sideOf(toadSeat)) {
            vector<int> sameSideSeats;
            for (int i = 0; i < 5; i++) if (sideOf(i) == sideOf(marioSeat)) sameSideSeats.push_back(i);
            sort(sameSideSeats.begin(), sameSideSeats.end(), [&](int x, int y){
                return distanceToPrincess(x) < distanceToPrincess(y);
            });
            vector<int> candidatesToSwap;
            for (int s : sameSideSeats) {
                if (pos[s] == "Mario" || pos[s] == "Toad") continue;
                candidatesToSwap.push_back(s);
            }
            if (distanceToPrincess(marioSeat) > distanceToPrincess(toadSeat)) {
                int bestSeat = sameSideSeats[0];
                if (bestSeat == toadSeat) bestSeat = sameSideSeats[1];
                int other = -1;
                for (int s : sameSideSeats) if (pos[s] == "Mario") { other = s; break; }
                if (bestSeat != -1 && other != -1) swap(pos[bestSeat], pos[other]);
            }
        }
    }

    int luigiSeat = -1, yoshiSeat = -1;
    for (int i = 0; i < 5; i++) {
        if (pos[i] == "Luigi") luigiSeat = i;
        if (pos[i] == "Yoshi") yoshiSeat = i;
    }

    if (luigiSeat != -1 && yoshiSeat != -1) {
        if (sideOf(luigiSeat) == sideOf(yoshiSeat)) {
            if (distanceToPrincess(luigiSeat) > distanceToPrincess(yoshiSeat)) swap(luigiSeat, yoshiSeat);
            for (int i = 0; i < 5; i++) {
                if (pos[i] == "Luigi") luigiSeat = i;
                if (pos[i] == "Yoshi") yoshiSeat = i;
            }
            if (luigiSeat != -1 && yoshiSeat != -1 && sideOf(luigiSeat) == sideOf(yoshiSeat) &&
                distanceToPrincess(luigiSeat) > distanceToPrincess(yoshiSeat)) {
                swap(pos[luigiSeat], pos[yoshiSeat]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << pos[i] << "\n";
    }
    return 0;
}