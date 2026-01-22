/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool canFormWord(const string &letters, const string &word) {
    unordered_map<char, int> letterCount;
    for (char c : letters) letterCount[c]++;
    for (char c : word) {
        if (letterCount[c] == 0) return false;
        letterCount[c]--;
    }
    return true;
}

int main() {
    string letters;
    cin >> letters;
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    int count = 0;
    for (const string &word : words) {
        if (canFormWord(letters, word)) count++;
        else break;
    }
    
    cout << "E possivel formar " << count << " palavras com esse conjunto" << endl;
    return 0;
}
