#ifndef Hexagon_H
#define Hexagon_H

namespace m1
{
    class Hexagon {
    private:
        int type;
        int row;
        float x;
        float y;
        bool alive = true;
        float scalingFactor;
        int lifes;
        bool killed = false;
    public:
        Hexagon() {
        }

        Hexagon(int type, int row);

        int getType() {
            return type;
        }

        int getRow() {
            return row;
        }

        float getX() {
            return x;
        }

        int getLifes() {
            return lifes;
        }

        bool getAlive() {
            return alive;
        }

        bool getKilled() {
            return killed;
        }
        void setKilled(bool tt){
            killed = tt;
        }

        void setX(float tx) {
            x = tx;
        }
        void setLifes(int life) {
            lifes = life;
        }
        void setRow(int trx) {
            row = trx;
        }

        float getY() {
            return y;
        }

        float getScalingFactor() {
            return scalingFactor;
        }

        void setY(float ty) {
            y = ty;
        }

        void setAlive(bool value) {
            alive = value;
        }
        void setScalingFactor(float scl) {
            scalingFactor = scl;
        }
    };
}

#endif
