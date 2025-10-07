/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, n2;

    cin >> n;
    vector<int> list1(n);
    for (int i = 0; i < n; ++i) {
        cin >> list1[i];
    }

    cin >> n2;
    vector<int> list2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> list2[i];
    }

    vector<int> all_numbers;
    all_numbers.reserve(n + n2);
    all_numbers.insert(all_numbers.end(), list1.begin(), list1.end());
    all_numbers.insert(all_numbers.end(), list2.begin(), list2.end());

    vector<int> repeated_numbers;
    unordered_set<int> seen;
    unordered_set<int> repeated_set;

    for (int num : all_numbers) {
        if (seen.count(num)) {
            repeated_set.insert(num);
        } else {
            seen.insert(num);
        }
    }

    repeated_numbers.assign(repeated_set.begin(), repeated_set.end());
    sort(repeated_numbers.begin(), repeated_numbers.end());

    vector<int> all_unique_numbers;
    all_unique_numbers.assign(seen.begin(), seen.end());
    sort(all_unique_numbers.begin(), all_unique_numbers.end());
    
    vector<int> non_repeated_numbers;
    for(int num : all_unique_numbers){
        if(repeated_set.find(num) == repeated_set.end()){
            non_repeated_numbers.push_back(num);
        }
    }

    cout << "[";
    for (size_t i = 0; i < repeated_numbers.size(); ++i) {
        cout << repeated_numbers[i];
        if (i < repeated_numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "[";
    for (size_t i = 0; i < all_unique_numbers.size(); ++i) {
        cout << all_unique_numbers[i];
        if (i < all_unique_numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "[";
    for (size_t i = 0; i < non_repeated_numbers.size(); ++i) {
        cout << non_repeated_numbers[i];
        if (i < non_repeated_numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
