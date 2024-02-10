#pragma once

#include "components/simple_scene.h"
#include "object2D.h"
#include "Star.h"
#include "Square.h"
#include "Hexagon.h"
#include "Diamond.h"
#include "Present.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        void displayScene();
        void displayCurrentStars();
        void displayCurrentLives();
        void spawnStars();
        void renderspawnedStars();
        void spawnHexagons();
        void renderspawnedHexagons(float deltaTimeSeconds);
        void hexagonReachRectangle();
        void renderDiamonds(float deltaTimeSeconds);
        void removeDiamondOnCollision();
        void generateProjectileStars();
        void renderProjectileStars(float deltaTimeSeconds);
        void checkCollisionsProjectileHexagons();
        void renderSquareFrames();
        void initVariables();
        void renderRedRectangleAndGreenSquares();
        void generatePresents();
        void renderspawnedPresents();

        glm::mat3 modelMatrix;

        // position variables
        int resolutionX;
        int resolutionY;
        int diamondsXPoz;
        int diamondsSpaceBetween;
        int diamondsYPoz;
        int red_squareXPoz;
        int red_squareSpaceBetween;
        int red_squareYPoz;
        int red_rectangleYPoz;
        int green_squareXPoz;
        int green_squareSpaceBetween;
        int green_squareYPoz;
        int green_squareSpaceBehind;
        int grey_starXpoz;
        int grey_starYpoz;
        int red_rectangleXPoz;

        // logic variables
        int starCount;
        int livesCount;
        double starsLastSpawnTime;
        double hexagonsLastSpawnTime;
        int timeToSpawnHexagons;
        double projectilesLastSpawnTime;
        double presentsLastSpawnTime;
        int presentSpawnType;
        float length;
        float purple_starLength;

        // drag and drop
        int isPressed;
        int typeOfDiamondPressed;
        // the on board diamonds
        std::vector<Diamond> new_diamonds;

        std::vector<Star> stars;
        std::vector<Star> projectileStars;
        std::vector<Hexagon> hexagons;
        std::vector<Present> presents;
        Square square_matrix[3][3];
        Diamond positioned_diamonds[4];
    };
}   // namespace m1
