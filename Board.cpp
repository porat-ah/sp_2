#include "Board.hpp"
#include <iostream>
using namespace std;

using ariel::Direction;
const Direction hor = Direction::Horizontal;
const Direction ver = Direction::Vertical;

namespace ariel{
    Board::Board(){
        board = new std::unordered_map<int, std::unordered_map<int,char>>();
    }
    
    Board::~Board(){
        delete board;
    }
    
    void Board::post(uint32_t row , uint32_t col , Direction dir , std::string message){
        switch (dir)
        {
        case hor:
            for (size_t i = col; i < message.length() + col ; i++)
            {
                if (board->find((int)row) == board->end())
                {
                    std::unordered_map<int,char> map;
                    map.insert({ i,message.at(i-col)});
                    board->insert({row,map});
                }
                else
                {
                   if (board->at((int)row).find(i) != board->at((int)row).end())
                   {
                       auto it = board->at((int)row).find(i);
                       board->at((int)row).erase(it);
                   }
                    board->at((int)row).insert({ i,message.at(i-col)});
                }
            }
            break;
        
       case ver:
            for (size_t i = row; i < message.length() + row ; i++)
                {
                if (board->find(i) == board->end())
                {
                   std::unordered_map<int,char> map;
                    map.insert({ col,message.at(i-row)});
                    board->insert({i,map});
                }
                else
                {
                    if (board->at((int)i).find((int)col) != board->at((int)i).end())
                   {
                       auto it = board->at((int)i).find((int)col);
                       board->at((int)i).erase(it);
                   }
                    board->at(i).insert({ col,message.at(i-row)});
                }
                    
                }
                break;
        }
    }
    
    string Board::read(uint32_t row , uint32_t col , Direction dir , uint32_t len){
        string out;
        switch (dir)
        {
        case hor:
            for (size_t i = col ; i < col+len; i++)
            {
                if (board->find((int)row) == board->end())
                {
                    out += '_';
                }
                else
                {
                    if (board->at((int)row).find(i) == board->at((int)row).end())
                    {
                        out += '_';
                    }
                    else
                    {
                         out += board->at((int)row).at(i);
                    }
                }
            }
            break;
        case Direction::Vertical:
            for (size_t i = row; i < row+len; i++)
            {
                try
                {
                     out += board->at(i).at((int)col);
                }
                catch(const std::exception& e)
                {
                    out += '_';
                }
            }
            break;
        }
        return out;
    }
    
    void Board::show(){
                cout << endl<<"show " << endl;
                for (const auto & p : *board)
                {
                    for (const auto & p2 : p.second)
                    {
                        cout << p2.second;
                    }
                }
                cout << endl<<"!show " << endl;
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