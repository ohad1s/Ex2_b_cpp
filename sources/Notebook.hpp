//
// Created by shira on 06/03/2022.
//
#include <unordered_map>
#ifndef EX1CPP_MAT_H
#define EX1CPP_MAT_H

#endif //EX1CPP_MAT_H
#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Notebook {
    private:
        unordered_map<int,unordered_map<int,char[100]>> my_notebook;
    public:
//        void init_row(char row[100]);
        void write(int page, int row, int col, ariel::Direction direction ,  string sentence);
        void erase(int page, int row, int col, ariel::Direction direction, int num_of_chars_to_clear );
        std::string read(int page, int row, int col, ariel::Direction direction, int len_to_read );
        void show(int page);
        Notebook() {
        }
    };
}
