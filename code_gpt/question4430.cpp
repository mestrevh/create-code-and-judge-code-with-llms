/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string getSubstring(const string& phrase) {
    int len = phrase.length();
    int x = static_cast<int>(sqrt(len));
    string result = "";
    
    for (char c : phrase) {
        if (result.empty() && (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result += c;
        } else if (!result.empty() && result.length() < x) {
            result += c;
        }
    }
    
    return result.length() == x ? result : "";
}

int main() {
    int n;
    cin >> n;
    vector<string> phrases(n);
    
    for (int i = 0; i < n; i++) {
        cin >> phrases[i];
    }
    
    vector<string> substrings;
    
    for (const string& phrase : phrases) {
        string substring = getSubstring(phrase);
        if (!substring.empty()) {
            substrings.push_back(substring);
        }
    }
    
    sort(substrings.begin(), substrings.end());
    
    string result;
    for (const string& s : substrings) {
        result += s;
    }
    
    cout << result << endl;
    return 0;
}
