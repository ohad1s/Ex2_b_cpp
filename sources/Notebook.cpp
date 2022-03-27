#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using ariel::Direction;
using namespace std;
int const LIMIT_100 = 100;

//void ariel::Notebook::init_row(char row[LIMIT_100]) {
//    for (int i = 0; i < LIMIT_100; i++) {
//        row[LIMIT_100] = '_';
//    }
//}

void ariel::Notebook::write(int page, int row, int col, ariel::Direction direction, string sentence) {
    int LEN=sentence.length();
    if (LEN<0){
        throw invalid_argument("negative error");
    }
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
    if (LEN > (LIMIT_100 - col)) {
        throw invalid_argument("index out of range error");
    }
    if (LEN>LIMIT_100 && direction==ariel::Direction::Horizontal){
        throw invalid_argument("index out of range error");
    }
    if (direction == ariel::Direction::Horizontal) {
        for (int i=col; i<LEN+col; i++){
            if (my_notebook[page][row][i]!='_') {
//                my_notebook[page][row][i]!='\0' ||
                        throw invalid_argument("Position error");
            }
        }
        for (int j=0,i=col; i<LEN+col; j++,i++){
          my_notebook[page][row][i]=sentence[(unsigned int)j];
        }
    }
    else {
        for (int i=row; i<LEN+row; i++){
            if (my_notebook[page][i][col]!='_') {
//                my_notebook[page][i][col]!='\0' ||
                        throw invalid_argument("Position error");
            }
        }
        for (int j=0,i=row; i<LEN+row; j++,i++){
            my_notebook[page][i][col]=sentence[(unsigned int)j];
        }
    }
}

void ariel::Notebook::erase(int page, int row, int col, ariel::Direction direction, int num_of_chars_to_clear) {

    if (num_of_chars_to_clear<0){
        throw invalid_argument("negative error");
    }
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
    if (num_of_chars_to_clear > (LIMIT_100 - col)) {
        throw invalid_argument("index out of range error");
    }
    if (num_of_chars_to_clear>LIMIT_100 && direction==ariel::Direction::Horizontal){
        throw invalid_argument("index out of range error");
    }
    if (direction == ariel::Direction::Horizontal) {
        for (int j=0,i=col; i<num_of_chars_to_clear+col; j++,i++){
            my_notebook[page][row][i]='~';
        }
    }
    else {
        for (int j=0,i=row; i<num_of_chars_to_clear+row; j++,i++){
            my_notebook[page][i][col]='~';
        }
    }
}

std::string ariel::Notebook::read(int page, int row, int col, ariel::Direction direction, int len_to_read) {
    if (len_to_read<0){
        throw invalid_argument("negative error");
    }
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
    if (len_to_read > (LIMIT_100 - col)) {
        throw invalid_argument("index out of range error");
    }
    string str_read;
    if (direction == ariel::Direction::Horizontal) {
        for (int j=0,i=col; i<len_to_read+col; j++,i++){
            str_read+=my_notebook[page][row][i];
        }
    }
    else {
        for (int j=0,i=row; i<len_to_read+row; j++,i++){
            str_read+=my_notebook[page][i][col];
        }
    }
    return str_read;
}

void ariel::Notebook::show(int page) {
    if (page<0){
        throw invalid_argument("index out of range error");
    }
}


