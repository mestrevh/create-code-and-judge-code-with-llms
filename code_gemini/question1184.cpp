/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Q, P;
deque<pair<ll, ll>> buffer;
deque<pair<ll, ll>> aux_memory;
ll buffer_size = 0;
ll next_packet_id = 0;
ll op_counter = 0;

void recover() {
    while (buffer_size < Q && !aux_memory.empty()) {
        auto& range = aux_memory.back();
        ll range_size = range.second - range.first + 1;
        ll space_in_buffer = Q - buffer_size;
        ll can_move = min(range_size, space_in_buffer);

        if (can_move > 0) {
            buffer.push_back({range.second, range.second - can_move + 1});
            buffer_size += can_move;
            range.second -= can_move;
        }

        if (range.second < range.first) {
            aux_memory.pop_back();
        }
    }
}

void handle_recv(ll k) {
    if (k == 0) return;

    ll to_add = k;
    
    ll space = Q - buffer_size;
    ll add_to_buffer = min(to_add, space);
    if (add_to_buffer > 0) {
        buffer.push_back({next_packet_id, next_packet_id + add_to_buffer - 1});
        buffer_size += add_to_buffer;
        next_packet_id += add_to_buffer;
        to_add -= add_to_buffer;
    }

    if (to_add > 0) {
        aux_memory.push_back({next_packet_id, next_packet_id + to_add - 1});
        next_packet_id += to_add;
    }
}

void handle_send(ll k) {
    if (k == 0) {
        return;
    }
    
    bool first_print = true;
    ll to_send = k;

    while (to_send > 0 && !buffer.empty()) {
        auto& range = buffer.front();
        ll start = range.first;
        ll end = range.second;
        ll range_size = abs(start - end) + 1;
        ll can_send = min(to_send, range_size);

        if (start <= end) {
            for (ll i = 0; i < can_send; ++i) {
                if (!first_print) cout << " ";
                cout << start + i;
                first_print = false;
            }
            range.first += can_send;
        } else {
            for (ll i = 0; i < can_send; ++i) {
                if (!first_print) cout << " ";
                cout << start - i;
                first_print = false;
            }
            range.first -= can_send;
        }

        to_send -= can_send;
        buffer_size -= can_send;

        if (can_send == range_size) {
            buffer.pop_front();
        }
    }
    cout << "\n";
}

void final_print() {
    bool first_print = true;
    for (const auto& range : buffer) {
        ll start = range.first;
        ll end = range.second;
        if (start <= end) {
            for (ll i = start; i <= end; ++i) {
                if (!first_print) cout << " ";
                cout << i;
                first_print = false;
            }
        } else {
            for (ll i = start; i >= end; --i) {
                if (!first_print) cout << " ";
                cout << i;
                first_print = false;
            }
        }
    }
    cout << "\n";

    first_print = true;
    for (auto it = aux_memory.rbegin(); it != aux_memory.rend(); ++it) {
        const auto& range = *it;
        ll start = range.first;
        ll end = range.second;
        for (ll i = end; i >= start; --i) {
            if (!first_print) cout << " ";
            cout << i;
            first_print = false;
        }
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q >> P;

    string command;
    ll k;
    while (cin >> command >> k) {
        if (P > 0 && op_counter == P) {
            recover();
            op_counter = 0;
        }
        op_counter++;

        if (command == "RECV") {
            handle_recv(k);
        } else {
            handle_send(k);
        }
    }

    final_print();

    return 0;
}
