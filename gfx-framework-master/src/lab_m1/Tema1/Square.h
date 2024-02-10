#ifndef Square_H
#define Square_H
#include "Hexagon.h"
namespace m1
{
    class Square {
    private:
        float x;
        float y;
        bool isFree;
    public:
        Square() {}

        Square(float x, float y);

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        bool getIsFree(){
            return isFree;
        }
        void setIsFree(bool t){
            isFree = t;
        }
    };
}

#endif
