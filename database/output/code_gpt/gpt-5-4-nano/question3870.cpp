/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool canForm(const array<int,26>& have, const string& word) {
    array<int,26> need{};
    for(char c: word){
        if(c>='A' && c<='Z') need[c-'A']++;
        else if(c>='a' && c<='z') need[c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(need[i] > have[i]) return false;
    }
    return true;
}

static void subtractLetters(array<int,26>& have, const string& word) {
    for(char c: word){
        if(c>='A' && c<='Z') have[c-'A']--;
        else if(c>='a' && c<='z') have[c-'a']--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if(!(cin >> s)) return 0;

    int N;
    cin >> N;
    vector<string> words(N);
    for(int i=0;i<N;i++) cin >> words[i];

    array<int,26> cnt{};
    for(char c: s){
        if(c>='A' && c<='Z') cnt[c-'A']++;
        else if(c>='a' && c<='z') cnt[c-'a']++;
    }

    int best = 0;
    for(int mask=0; mask < (1<<N); mask++){
        array<int,26> cur = cnt;
        int taken = 0;
        bool ok = true;

        for(int i=0;i<N;i++){
            if(mask & (1<<i)){
                if(canForm(cur, words[i])){
                    subtractLetters(cur, words[i]);
                    taken++;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) best = max(best, taken);
    }

    cout << "E possivel formar " << best << " palavras com esse conjunto\n";
    return 0;
}