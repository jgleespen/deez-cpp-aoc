//
// Created by Joseph on 6/6/2023.
//

#ifndef DEEZ_CPP_AOC_TEST_H
#define DEEZ_CPP_AOC_TEST_H

#include <cstdint>
#include <fstream>
#include <functional>

enum class RPS { ROCK, PAPER, SCISSORS };
class One {
public:
  static std::int32_t count_all();

private:
  const std::string path_ = "input.txt";
  static int32_t count_group(std::string &line, int32_t curr_sum,
                            int32_t &curr_max);
};

class Two {
public:
  Two();
  static std::int32_t deez_higher_order(
      const std::function<int32_t(std::ifstream &istream)> &func,
      const std::string &path);
  static std::int32_t get_player_score(std::string &line);
  static std::int32_t deez(RPS plyr, RPS opnt);
};

#endif // DEEZ_CPP_AOC_TEST_H
