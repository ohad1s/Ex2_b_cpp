#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using ariel::Direction;
using namespace std;
int const LIMIT_100 = 100;

void ariel::Notebook::init_row(char[LIMIT_100] row) {
    for (int i = 0; i < LIMIT_100; i++) {
        row[LIMIT_100] = '_';
    }
}

void ariel::Notebook::write(int page, int row, int col, ariel::Direction direction, string const &sentence) {
    if (page < 0) {
        throw invalid_argument("negative page error");
    }
    if (row < 0) {
        throw invalid_argument("negative page error");
    }
    if (col < 0) {
        throw invalid_argument("negative page error");
    }
    if (col > LIMIT_100) {
        throw invalid_argument("index out of range error");
    }
    if (sentence.length() > (LIMIT_100 - col)) {
        throw invalid_argument("index out of range error");
    }
    if (direction == ariel::Direction::Horizontal) {
        init_row(my_notebook[page][row]);
    } else {

    }

}

void ariel::Notebook::erase(int page, int row, int col, ariel::Direction direction, int num_of_chars_to_clear) {}

std::string ariel::Notebook::read(int page, int row, int col, ariel::Direction direction, int len_to_read) {
    return "a";
}

std::string ariel::Notebook::show(int page) {
    return "a";
}


