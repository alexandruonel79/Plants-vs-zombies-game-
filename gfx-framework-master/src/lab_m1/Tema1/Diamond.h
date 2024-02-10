#ifndef Diamond_H
#define Diamond_H

namespace m1
{
    class Diamond {
    private:
        float x;
        float y;
        float initialX;
        float initialY;
        int type;
        int matrixXPozition;
        int matrixYPozition;
        bool isAlive;
        float scalingFactor;
        float projectileLastSpawnTime;
    public:
        Diamond() {
        }

        Diamond(int type, int row);

        float getX() {
            return x;
        }

        void setIsAlive(bool txx) {
            isAlive = txx;
        }

        bool getIsAlive() {
            return isAlive;
        }

        void setX(float tx) {
            x = tx;
        }

        float getY() {
            return y;
        }

        void setY(float ty) {
            y = ty;
        }

        float getScalingFactor() {
            return scalingFactor;
        }

        void setScalingFactor(float txy) {
            scalingFactor = txy;
        }


        void setInitialX(float itx) {
            initialX = itx;
        }

        void setInitialY(float ity) {
            initialY = ity;
        }

        float getInitialY() {
            return initialY;
        }
        float getInitialX() {
            return initialX;
        }
        int getType() {
            return type;
        }

        void setType(int ty) {
            type = ty;
        }

        int getMatrixXPosition() {
            return matrixXPozition;
        }
        int getMatrixYPosition() {
            return matrixYPozition;
        }

        void setMatrixXPosition(int paramx) {
            matrixXPozition = paramx;
        }
        void setMatrixYPosition(int paramy) {
            matrixYPozition = paramy;
        }
        float getProjectileLastSpawnTime() {
            return projectileLastSpawnTime;
        }
        void setProjectileLastSpawnTime(float sett) {
            projectileLastSpawnTime = sett;
        }

    };
}

#endif
