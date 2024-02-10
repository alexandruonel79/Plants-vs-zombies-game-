#ifndef STAR_H
#define STAR_H

class Star {
private:
    float x;
    float y;
    int type;
    float rotationAngle;
public:
    Star(float x, int y);

    float getX() {
        return x;
    }
    float getRotationAngle() {
        return rotationAngle;
    }
    int getType() {
        return type;
    }
    float getY() {
        return y;
    }
    void setX(float tx) {
        x = tx;
    }
    void setRotationAngle(float rot) {
        rotationAngle = rot;
    }
    void setY(float txy) {
        y = txy;
    }
    void setType(int txxy) {
        type = txxy;
    }
};

#endif
