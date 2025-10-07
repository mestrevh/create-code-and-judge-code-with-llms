/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void print_array(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == -1) {
            std::cout << "-";
        } else {
            std::cout << arr[i];
        }
        if (i < arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int SIZE;
    std::cin >> SIZE;

    std::vector<int> queue(SIZE, -1);
    int front = 0;
    int rear = 0;

    char command;
    while (std::cin >> command && command != 'F') {
        if (command == 'E') {
            int value;
            std::cin >> value;

            if ((rear + 1) % SIZE == front) {
                std::cout << "Fila cheia" << std::endl;
            } else {
                queue[rear] = value;
                rear = (rear + 1) % SIZE;
                print_array(queue);
            }
        } else if (command == 'D') {
            if (front == rear) {
                std::cout << "Fila vazia" << std::endl;
            } else {
                int removed_value = queue[front];
                std::cout << removed_value << std::endl;
                queue[front] = -1;
                front = (front + 1) % SIZE;
                print_array(queue);
            }
        }
    }

    std::cout << "Saindo..." << std::endl;

    return 0;
}
