#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <stdexcept>
#define hor Direction::Horizontal
#define ver Direction::Vertical
using namespace ariel;
TEST_CASE("full read (hor)"){
    Board board;
    board.post(0,0,hor,"abcd");
    CHECK(board.read(0,0,hor,4)=="abcd");//1
}

TEST_CASE("part read (hor)"){
    Board board;
    board.post(0,3,hor,"abcd");
    // 2 - 7
    CHECK(board.read(0,0,hor,4)=="___a");
    CHECK(board.read(0,1,hor,4)=="__ab");
    CHECK(board.read(0,2,hor,4)=="_abc");
    CHECK(board.read(0,4,hor,4)=="bcd_");
    CHECK(board.read(0,5,hor,4)=="cd__");
    CHECK(board.read(0,6,hor,4)=="d___");
}

TEST_CASE("middle read (hor)"){
    Board board;
    board.post(0,3,hor,"ab");
    CHECK(board.read(0,2,hor,5)=="_ab_");//8
}

TEST_CASE("empty"){
     Board board;
     CHECK(board.read(0,0,hor,3) =="___");//9
     CHECK(board.read(0,0,ver,3) =="___");//10
}

TEST_CASE("hor - ver"){
    Board board;
    board.post(1,5,hor,"abc");
    CHECK(board.read(0,6,ver,3) == "_b_");//11
    board.post(0,5,ver,"abc");
    CHECK(board.read(1,4,hor,3) == "_b_");//12
}

TEST_CASE("overwrite"){
    Board board;
    board.post(1,5,hor,"abc");
    CHECK(board.read(0,7,ver,3) == "_c_");//13
    board.post(0,7,ver,"check");
    CHECK(board.read(0,7,ver,3) == "che");//14
    CHECK(board.read(1,5,hor,3) == "abh");//15
}


TEST_CASE("full read (ver)"){
    Board board;
    board.post(0,0,ver,"abcd");
    CHECK(board.read(0,0,ver,4)=="abcd");//16
}

TEST_CASE("part read (ver)"){
    Board board;
    board.post(3,0,ver,"abcd");
    // 17-22
    CHECK(board.read(0,0,hor,4)=="___a");
    CHECK(board.read(1,0,hor,4)=="__ab");
    CHECK(board.read(2,0,hor,4)=="_abc");
    CHECK(board.read(4,0,hor,4)=="bcd_");
    CHECK(board.read(5,0,hor,4)=="cd__");
    CHECK(board.read(6,0,hor,4)=="d___");
}

TEST_CASE("middle read (ver)"){
    Board board;
    board.post(3,0,ver,"ab");
    CHECK(board.read(2,0,hor,5)=="_ab_");//23
}