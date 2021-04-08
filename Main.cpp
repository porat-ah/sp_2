#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
using namespace std;

#define print(x) cout << x ;
#define println(x) cout << x << endl;

const Direction hor = Direction::Horizontal;
const Direction ver = Direction::Vertical;

int main(){
    println("hello and welcome to the shape creator.")
    println("here you can ask for a shape and we create it. ")
    println("the shapes are : \n line - 1  \n circle - 2  \n triangle - 3  \n square - 4  \n pentagon - 5  \n star - 6 \n star of david - 7")
    int shape;
    cin >> shape;
    Board b;
     
    switch (shape)
    {
        // line
    case 1:
        b.post(0,4,ver,"*****");
        for (size_t i = 0; i < 5; i++)
        {
            println(b.read(i,2,hor,5));
        }
        break;

        // circle
    case 2:
        b.post(0,3,hor,"*");
        b.post(1,2,hor,"* *");
        b.post(2,1,hor,"*   *");
        b.post(3,2,hor,"* *");
        b.post(4,3,hor,"*");
        for (size_t i = 0; i < 5; i++)
        {
            println(b.read(i,0,hor,7));
        }
        break;


        // triangle 
    case 3:
        b.post(0,3,hor,"*");
        b.post(1,2,hor,"* *");
        b.post(2,1,hor,"*   *");
        b.post(3,0,hor,"*******");
        for (size_t i = 0; i < 4; i++)
        {
            println(b.read(i,0,hor,7));
        }
        break;

        // square
    case 4:
        b.post(0,3,hor,"****");
        b.post(0,2,ver,"******");
        b.post(5,3,hor,"****");
        b.post(0,7,ver,"******");
        for (size_t i = 0; i < 6; i++)
        {
            println(b.read(i,1,hor,8));
        }
        break;

        // pentagon
    case 5:
        b.post(0,4,hor,"*");
        b.post(1,3,hor,"*_*");
        b.post(2,2,ver,"****");
        b.post(2,6,ver,"****");
        b.post(5,3,hor,"***");
        for (size_t i = 0; i < 6; i++)
        {
            println(b.read(i,1,hor,7));
        }
        break;

        //star
    case 6:
        b.post(0,8,hor,"*");
        b.post(1,7,hor,"* *");
        b.post(2,6,hor,"*   *");
        b.post(3,2,hor,"****     ****");
        b.post(4,3,hor,"*         *");
        b.post(5,4,hor,"*       *");
        b.post(6,5,hor,"*  *  *");
        b.post(7,4,hor,"* *___* *");
        b.post(8,3,hor,"**_______**");
        b.post(9,2,hor,"*___________*");
        for (size_t i = 0; i < 10; i++)
        {
            println(b.read(i,1,hor,15));
        }
        break;

        // david
    case 7:
        b.post(0,8,hor,"*");
        b.post(1,7,hor,"* *");
        b.post(2,6,hor,"*   *");
        b.post(3,2,hor,"****     ****");
        b.post(4,3,hor,"*         *");
        b.post(5,4,hor,"*       *");
        b.post(6,5,hor,"*     *");
        b.post(7,4,hor,"*       *");
        b.post(8,3,hor,"*         *");
        b.post(9,2,hor,"****     ****");
        b.post(10,6,hor,"*   *");
        b.post(11,7,hor,"* *");
       b.post(12,8,hor,"*");
        for (size_t i = 0; i < 13; i++)
        {
            println(b.read(i,1,hor,15));
        }
        break;
    }








}