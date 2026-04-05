/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    
    string item;
    if (N == 1) item = "Life Mushroom";
    else if (N == 2) item = "Fire Flower";
    else if (N == 3) item = "Boost Star";
    else if (N == 4) item = "Mega Mushroom";
    
    cout << item;
    return 0;
}