#ifndef Present_H
#define Present_H

namespace m1
{
    class Present {
    private:
        float x;
        float y;
        int type;
    public:
        Present() {}

        Present(float x, float y, int type);

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        int getType() {
            return type;
        }
    };
}

#endif
