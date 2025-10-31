/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

double calculateMedian(vector<int>& numbers) {
    int n = numbers.size();
    if (n % 2 == 0)
        return (numbers[n/2 - 1] + numbers[n/2]) / 2.0;
    else
        return numbers[n/2];
}

vector<int> calculateMode(vector<int>& numbers) {
    map<int, int> freq;
    for (int num : numbers) {
        freq[num]++;
    }
    int maxFreq = 0;
    for (const auto& pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
        }
    }
    vector<int> modes;
    for (const auto& pair : freq) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }
    return modes;
}

int main() {
    int C;
    cin >> C;
    for (int i = 1; i <= C; ++i) {
        int N;
        cin >> N;
        vector<int> numbers(N);
        for (int j = 0; j < N; ++j) {
            cin >> numbers[j];
        }

        cout << "sequencia " << i << ":\n";
        sort(numbers.begin(), numbers.end());
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << "\n" << numbers.front() << " " << numbers.back() << "\n";

        double sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        cout << fixed << setprecision(5) << sum / N << "\n";

        vector<int> modes = calculateMode(numbers);
        for (int mode : modes) {
            cout << mode << " ";
        }
        cout << "\n";

        cout << fixed << setprecision(5) << calculateMedian(numbers) << "\n";
    }
    return 0;
}
