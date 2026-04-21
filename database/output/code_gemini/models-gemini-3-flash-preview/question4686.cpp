/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string command;
    deque<long long> queue_data;
    long long current_sum = 0;

    // Read commands until "exit" or end of input
    while (cin >> command && command != "exit") {
        if (command == "push") {
            long long value;
            if (cin >> value) {
                queue_data.push_back(value);
                current_sum += value;
            }
        } else if (command == "pop") {
            if (!queue_data.empty()) {
                current_sum -= queue_data.front();
                queue_data.pop_front();
            }
        } else if (command == "sum") {
            // Display the current sum of elements in the queue
            cout << current_sum << "\n";
        } else if (command == "print") {
            // Display elements in insertion order with a trailing space
            // as indicated in the provided test case 1.
            for (const auto& val : queue_data) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

