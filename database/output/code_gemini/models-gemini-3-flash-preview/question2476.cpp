/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int priority;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        if (t > 1) cout << "\n";
        cout << "Situação " << t << "\n\n";

        vector<Patient> heap(N + 1);
        int sz = 0;
        string cmd;

        while (cin >> cmd && cmd != "END") {
            if (cmd == "ARR") {
                string name;
                int prio;
                cin >> name >> prio;
                if (sz < N) {
                    sz++;
                    heap[sz].name = name;
                    heap[sz].priority = prio;
                    int curr = sz;
                    while (curr > 1 && heap[curr].priority > heap[curr / 2].priority) {
                        swap(heap[curr], heap[curr / 2]);
                        curr /= 2;
                    }
                    cout << name << ", pos " << curr << "\n";
                } else {
                    cout << "Fila cheia, " << name << " encaminhado para outro hospital\n";
                }
            } else if (cmd == "CLL") {
                if (sz > 0) {
                    cout << heap[1].name << ", atendimento\n";
                    heap[1] = heap[sz];
                    sz--;
                    int curr = 1;
                    while (true) {
                        int left = 2 * curr;
                        int right = 2 * curr + 1;
                        if (left > sz) break;
                        
                        int largest = left;
                        if (right <= sz && heap[right].priority > heap[left].priority) {
                            largest = right;
                        }
                        
                        if (heap[largest].priority > heap[curr].priority) {
                            swap(heap[curr], heap[largest]);
                            curr = largest;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}