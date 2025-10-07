/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> queue(size, -1);
    int head = 0;
    int tail = 0;
    int count = 0;

    char command;
    while (cin >> command && command != 'F') {
        if (command == 'E') {
            int value;
            cin >> value;
            if (count < size - 1) {
                queue[tail] = value;
                tail = (tail + 1) % size;
                count++;
                for (int i = 0; i < size; ++i) {
                    if (queue[i] == -1) {
                        cout << "- ";
                    } else {
                        cout << queue[i] << " ";
                    }
                }
                cout << endl;
            } else {
                cout << "Fila cheia" << endl;
            }
        } else if (command == 'D') {
            if (count > 0) {
                int removed = queue[head];
                queue[head] = -1;
                head = (head + 1) % size;
                count--;
                cout << removed << endl;
                for (int i = 0; i < size; ++i) {
                    if (queue[i] == -1) {
                        cout << "- ";
                    } else {
                        cout << queue[i] << " ";
                    }
                }
                cout << endl;
            } else {
                cout << "Fila vazia" << endl;
            }
        }
    }
    cout << "Saindo..." << endl;

    return 0;
}
