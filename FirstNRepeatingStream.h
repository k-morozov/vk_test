//
// Created by focus on 15.05.22.
//

#pragma once

#include <optional>
#include <queue>


class FirstNRepeatingStream {
public:
    explicit FirstNRepeatingStream(int N) : max_count_(N) {}
    std::optional<char> next(char c) {
        push_new_sym(c);
        clear_queue();
        return get_first_sym();
    }

private:
    const int max_count_;
    std::unordered_map<char, int> data_counter_;
    std::queue<char> data_chars_;

    void push_new_sym(char c) {
        data_counter_[c]++;
        data_chars_.push(c);
    }

    void clear_queue() {
        while (!data_chars_.empty()) {
            const char sym = data_chars_.front();
            if (const auto it = data_counter_.find(sym);
                it!=std::end(data_counter_) && it->second > max_count_) {
                data_chars_.pop();
            } else {
                // maybe need to check that it != std::end.
                // I believe that it is useless for class with current interface.
                break;
            }
        }
    }

    std::optional<char> get_first_sym() {
        if (data_chars_.empty()) {
            return std::nullopt;
        }

        return data_chars_.front();
    }
};
