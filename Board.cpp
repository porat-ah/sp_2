#include "Board.hpp"
#include <iostream>



using namespace std;

using ariel::Direction;
const Direction hor = Direction::Horizontal;
const Direction ver = Direction::Vertical;

namespace ariel{
    Board::Board():board{{{'_'}}}
    {
        for (size_t i = 0; i < row_num; i++)
                {
                    for (size_t j = 0; j < col_num; j++)
                    {
                        board.at(i).at(j) = '_';
                    }
                }
    }
     Board::~Board(){
     }

    void Board::post(uint32_t row , uint32_t col , Direction dir , std::string message){
        const size_t ROW_NORM = 98;
        const size_t COL_NORM = 198;
        if (row < ROW_NORM || col < COL_NORM)
        {
            return;
        }
        size_t start_row = (size_t)row-ROW_NORM;
        size_t start_col = (size_t)col-COL_NORM;
        switch (dir)
        {
        case hor:
            for (size_t i = start_col; i < message.length() + start_col ; i++)
            {
                board.at(start_row).at(i) = message.at(i-start_col);
            }
            cout << endl;
            break;
        
       case ver:
            for (size_t i = start_row; i < message.length() + start_row ; i++)
                {
                    board.at(i).at(start_col) = message.at(i-start_row);
                }
                break;
        }
    }
    string Board::read(uint32_t row , uint32_t col , Direction dir , uint32_t len){
        const size_t ROW_NORM = 98;
        const size_t COL_NORM = 198;
         if (row < ROW_NORM || col < COL_NORM)
        {
            return " ";
        }
        size_t start_row = (size_t)row-ROW_NORM;
        size_t start_col = (size_t)col-COL_NORM;
        string out;
        switch (dir)
        {
        case hor:
            for (size_t i = start_col ; i < start_col+(size_t)len; i++)
            {
                out +=board.at(start_row).at(i);
            }
            break;
        case Direction::Vertical:
            for (size_t i = start_row; i < start_row+(size_t)len; i++)
            {
                out += board.at(i).at(start_col);
            }
            break;
        }
        return out;
    }
    void Board::show(){
                for (size_t i = 0; i < row_num; i++)
                {
                    for (size_t j = 0; j < col_num; j++)
                    {
                        cout << board.at(i).at(j);
                    }
                    cout << endl;
                }
        }



    // Board::Board()
    // {
    //     board = new map<size_t,map<size_t,char>>;
    // }
    
    // Board::~Board()
    // {
    //     delete[] board;
    // }

    // void Board::post(size_t row , size_t col , Direction dir , string message){
    //         switch (dir)
    //         {
    //         case Direction::Horizontal:
    //             for (size_t i = row; i < row + message.length(); ++i)
    //             {
    //               board[i][col] = message.at(i-row);  
    //             }
    //             break;
            
    //         case Direction::Vertical:
    //            for (size_t i = col; i < col + message.length(); ++i)
    //             {
    //               board[row][i] = message.at(i-col);  
    //             }
    //             break;
    //         }
    //     }
    
    // string Board::read(size_t row , size_t col , Direction dir , size_t len){
    //         string out;
    //         switch (dir)
    //         {
    //         case Direction::Horizontal:
    //             for (size_t i = row ; i < row+len; i++)
    //             {
    //                 out += board[i][col];
    //             }
    //             break;
            
    //         case Direction::Vertical:
    //             for (size_t i = col; i < col+len; i++)
    //             {
    //                 out += board[row][i];
    //             }
    //             break;
    //         }
    //     return out;
    //     }

    // void Board::show(){
    //             for (size_t i = 0; i < 10; i++)
    //             {
    //                 for (size_t j = 0; j < 10; j++)
    //                 {
    //                     cout << board[i][j] << ",";
    //                 }
    //                 cout << endl;
    //             }
    //     }

    

}