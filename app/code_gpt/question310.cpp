/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string encrypt(const string &s) {
    string first_pass;
    for (char c : s) {
        if (isalnum(c)) {
            first_pass += c + 3;
        } else {
            first_pass += c;
        }
    }
    
    string second_pass(first_pass.rbegin(), first_pass.rend());
    
    string final_pass;
    int mid = second_pass.size() / 2;
    for (int i = 0; i < second_pass.size(); ++i) {
        if (i >= mid) {
            final_pass += second_pass[i] - 1;
        } else {
            final_pass += second_pass[i];
        }
    }
    
    return final_pass;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    vector<string> results;
    
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        results.push_back(encrypt(line));
    }
    
    for (const string &result : results) {
        cout << result << endl;
    }
    
    return 0;
}
