//
// Created by Joseph on 6/6/2023.
//

#include "adventone.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

Two::Two() {
    int32_t result_two = Two::deez_higher_order(
            [](std::ifstream &istream) {
                std::int32_t total_score;
                std::string line;
                while (getline(istream, line)) {
                    total_score += Two::get_player_score(line);
                }
                return total_score;
            },
            "input_two.txt");
    std::printf("%d", result_two);
}


std::int32_t Two::deez(RPS plyr, RPS opnt) {
    if (plyr == opnt)
        return 3;
    if ((plyr == RPS::ROCK && opnt == RPS::SCISSORS)
        || (plyr == RPS::PAPER && opnt == RPS::ROCK)
        || (plyr == RPS::SCISSORS && opnt == RPS::PAPER)) {
        return 6;
    } else {
        return 0;
    }
}

std::int32_t Two::get_player_score(std::string &line) {
    RPS my_choice;
    int my_score;
    RPS their_choice;
    if (line[1] == 'X') {
        my_score = 1;
        my_choice = RPS::ROCK;
    }
    if (line[1] == 'Y') {
        my_score = 2;
        my_choice = RPS::PAPER;
    }
    if (line[1] == 'Z') {
        my_score = 3;
        my_choice = RPS::SCISSORS;
    }
    if (line[0] == 'A') {
        their_choice = RPS::ROCK;
    }
    if (line[0] == 'B') {
        their_choice = RPS::PAPER;
    }
    if (line[0] == 'C') {
        their_choice = RPS::SCISSORS;
    }
    return my_score + deez(my_choice, their_choice);
}

int32_t
Two::deez_higher_order(const std::function<int32_t(std::ifstream &)> &func,
                       const std::string &path) {
    // Open path
    std::ifstream in{path, std::ios::binary};
    if (!in) {
        return -1;
    }
    return func(in);
}

std::int32_t One::count_all() {
    std::int32_t max = std::numeric_limits<int32_t>::min();
    std::string str;
    std::ifstream input_("input.txt", std::ios::binary);
    if (!input_) {
        std::cerr << "uh oh";
        return -1;
    } else {
        int32_t curr_sum = 0;
        while (std::getline(input_, str)) {
            curr_sum = One::count_group(str, curr_sum, max);
        }
    }
    return max;
}

std::int32_t One::count_group(std::string &line, int32_t curr_sum,
                              int32_t &curr_max) {
    if (line.empty()) {
        if (curr_max < curr_sum) {
            curr_max = curr_sum;
        }
        return 0;
    } else {
        return curr_sum + std::stoi(line);
    }
}
