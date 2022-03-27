#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using ariel::Direction;
using namespace std;
int const LIMIT_100 = 99;
int const MIN_CHAR = 32;
int const MAX_CHAR = 125;

void ariel::Notebook::write(int page, int row, int col, ariel::Direction direction, string sentence) {
    int LEN = sentence.length();
    for (int i = 0; i < LEN; i++) {
        if (sentence[(unsigned int) i] < MIN_CHAR || sentence[(unsigned int) i] > MAX_CHAR) {
            throw invalid_argument("Invalid char");
        }
    }
    if (page < 0 || row < 0 || col < 0) {
        throw invalid_argument("negative error");
    }
    if (col > LIMIT_100) {
        throw invalid_argument("index out of range error");
    }
    if (LEN + col > LIMIT_100 && direction == ariel::Direction::Horizontal) {
        throw invalid_argument("index out of range error");
    }
//    if (LEN > LIMIT_100) {
//        && direction == ariel::Direction::Horizontal
//        throw invalid_argument("index out of range error");
//    }
    if (direction == ariel::Direction::Horizontal) {
        for (int j = 0, i = col; i < LEN + col; j++, i++) {
            if (sentence[(unsigned int) j] == '~' || my_notebook[page][row][i] == '~') {
                throw invalid_argument("Position error");
            }
            if (MIN_CHAR <= my_notebook[page][row][i] && my_notebook[page][row][i] <= MAX_CHAR) {
                if (my_notebook[page][row][i] == '_') {
                    my_notebook[page][row][i] = sentence[(unsigned int) j];
                } else {
                    throw invalid_argument("Position error");
                }
            } else {
                my_notebook[page][row][i] = sentence[(unsigned int) j];
//                throw invalid_argument("Position error");
            }
        }
    } else {
        for (int j = 0, i = row; i < LEN + row; j++, i++) {
            if (sentence[(unsigned int) j] == '~' || my_notebook[page][i][col] == '~') {
                throw invalid_argument("Position error");
            }
            if (MIN_CHAR <= my_notebook[page][i][col] && my_notebook[page][i][col] <= MAX_CHAR) {
                if (my_notebook[page][i][col] == '_') {
                    my_notebook[page][i][col] = sentence[(unsigned int) j];
                } else {
                    throw invalid_argument("Position error");
                }
            } else {
//                throw invalid_argument("Position error");
                my_notebook[page][i][col] = sentence[(unsigned int) j];
            }
        }
    }
}

void ariel::Notebook::erase(int page, int row, int col, ariel::Direction direction, int num_of_chars_to_clear) {

    if (num_of_chars_to_clear < 0) {
        throw invalid_argument("negative error");
    }
    if (page < 0 || row < 0 || col < 0) {
        throw invalid_argument("negative error");
    }
    if (col > LIMIT_100) {
        throw invalid_argument("index out of range error");
    }
    if (num_of_chars_to_clear + col > LIMIT_100 && direction == ariel::Direction::Horizontal) {
        throw invalid_argument("index out of range error");
    }
    if (num_of_chars_to_clear > LIMIT_100 && direction == ariel::Direction::Horizontal) {
        throw invalid_argument("index out of range error");
    }
    if (direction == ariel::Direction::Horizontal) {
        for (int j = 0, i = col; i < num_of_chars_to_clear + col; j++, i++) {
            my_notebook[page][row][i] = '~';
        }
    } else {
        for (int j = 0, i = row; i < num_of_chars_to_clear + row; j++, i++) {
            my_notebook[page][i][col] = '~';
        }
    }
}

std::string ariel::Notebook::read(int page, int row, int col, ariel::Direction direction, int len_to_read) {
    if (len_to_read < 0) {
        throw invalid_argument("negative error");
    }
    if (page < 0 || row < 0 || col < 0) {
        throw invalid_argument("negative error");
    }
    if (col > LIMIT_100) {
        throw invalid_argument("index out of range error");
    }
    if (len_to_read + col > LIMIT_100 + 1 && direction == ariel::Direction::Horizontal) {
        throw invalid_argument("index out of range error");
    }
    string str_read;
    if (direction == ariel::Direction::Horizontal) {
        for (int j = 0, i = col; i < len_to_read + col; j++, i++) {
            if (MIN_CHAR <= my_notebook[page][row][i] && my_notebook[page][row][i] <= MAX_CHAR + 1) {
                str_read += my_notebook[page][row][i];
            } else {
                str_read += '_';
            }

        }
    } else {
        for (int j = 0, i = row; i < len_to_read + row; j++, i++) {
            if (MIN_CHAR <= my_notebook[page][i][col] && my_notebook[page][i][col] <= MAX_CHAR + 1) {
                str_read += my_notebook[page][i][col];
            } else {
                str_read += '_';
            }
        }
    }
    return str_read;
}

void ariel::Notebook::show(int page) {
    if (page < 0) {
        throw invalid_argument("index out of range error");
    }
        std::cout << my_notebook[page][0][0] << std::endl;
}


