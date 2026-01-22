/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <limits>
#include <string>

long long sum_digits(long long n) {
    long long sum = 0;
    n = std::abs(n);
    if (n == 0) return 0;
    std::string s = std::to_string(n);
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long xupenio_num;
    int n_channels;
    
    std::cin >> xupenio_num >> n_channels;
    
    int best_channel = -1;
    int best_minute = -1;
    long long best_term = -1;
    long long min_diff = std::numeric_limits<long long>::max();

    for (int current_channel = 1; current_channel <= n_channels; ++current_channel) {
        long long f1, f2;
        std::cin >> f1 >> f2;
        
        int channel_best_minute = 0;
        long long channel_best_term = 0;
        long long channel_min_diff = std::numeric_limits<long long>::max();
        
        long long diff1 = std::abs(xupenio_num - f1);
        if (diff1 < channel_min_diff) {
            channel_min_diff = diff1;
            channel_best_minute = 1;
            channel_best_term = f1;
        }

        long long diff2 = std::abs(xupenio_num - f2);
        if (diff2 < channel_min_diff) {
            channel_min_diff = diff2;
            channel_best_minute = 2;
            channel_best_term = f2;
        }

        long long term_prev = f1;
        long long term_curr = f2;
        
        for (int i = 3; i < 100; ++i) {
            long long next_term = term_prev + term_curr;
            
            if (next_term < term_curr) {
                break;
            }
            
            long long current_diff = std::abs(xupenio_num - next_term);
            
            if (current_diff < channel_min_diff) {
                channel_min_diff = current_diff;
                channel_best_minute = i;
                channel_best_term = next_term;
            }
            
            if (next_term > xupenio_num && current_diff > std::abs(xupenio_num - term_curr)) {
                break;
            }

            term_prev = term_curr;
            term_curr = next_term;
        }
        
        if (channel_min_diff <= min_diff) {
            min_diff = channel_min_diff;
            best_channel = current_channel;
            best_minute = channel_best_minute;
            best_term = channel_best_term;
        }
    }
    
    if (sum_digits(best_term) > 10) {
        std::cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << best_channel
                  << " e sera chamado mais ou menos no minuto " << best_minute
                  << " e com o VIP garantido!!!" << std::endl;
    } else {
        std::cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << best_channel
                  << " e sera chamado mais ou menos no minuto " << best_minute
                  << ", mas o ingresso VIP não vai rolar :(" << std::endl;
    }
    
    return 0;
}
