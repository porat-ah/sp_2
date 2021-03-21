#pragma once
#include <string>
#include "Direction.hpp"
//#include <map>
#include <array>

int const row_num = 5;
int const col_num = 9;
namespace ariel{
    class Board{
        private:
        
        std::array<std::array<char,col_num>,row_num> board;
            //map<size_t,map<size_t,char>> board(0,map<size_t,char>(0,'-'));
        public:
            Board();
            ~Board();
            void post(int row , int col , Direction dir , std::string message);
            std::string read(int row , int col , Direction dir , int len);
            void show();
    };
}