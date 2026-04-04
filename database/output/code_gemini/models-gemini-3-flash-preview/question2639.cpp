/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

long long calculate_sum(const string& s, size_t index) {
    if (index >= s.length()) {
        return 0;
    }
    return (long long)((unsigned char)s[index]) + calculate_sum(s, index + 1);
}

void process_words(int n) {
    if (n <= 0) {
        return;
    }
    string word;
    if (!(cin >> word)) {
        return;
    }
    long long total_sum = calculate_sum(word, 0);
    int result = total_sum % 90;
    if (result < 65) {
        result = 65 + (result % 26);
    }
    cout << (char)result;
    process_words(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        process_words(n);
        cout << endl;
    }

    return 0;
}