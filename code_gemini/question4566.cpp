/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> chars(n);
    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }

    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }

    vector<char> result;
    int char_idx = 0;
    int num_idx = 0;

    while (char_idx < n || num_idx < m) {
        if (char_idx < n && num_idx < m) {
            char new_char = chars[char_idx] + nums[num_idx];
            if (new_char >= 'a' && new_char <= 'z') {
                result.push_back(new_char);
            } else {
                result.push_back('.');
            }
            char_idx++;
            num_idx++;
        } else if (num_idx < m) {
            char new_char = 'a' + nums[num_idx];
            if (new_char >= 'a' && new_char <= 'z') {
                result.push_back(new_char);
            } else {
                result.push_back('.');
            }
            num_idx++;
        } else {
            result.push_back(chars[char_idx]);
            char_idx++;
        }
    }

    for (char c : result) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
