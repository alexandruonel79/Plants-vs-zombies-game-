#include "Tema1.h"
#include "transform2D.h"

void m1::Tema1::initVariables() {
	// relative positions
	diamondsXPoz = resolutionX / 10;
	diamondsSpaceBetween = resolutionX / 7.5;
	diamondsYPoz = resolutionY - resolutionY / 10;

	// diamonds
	// first diamond
	positioned_diamonds[0].setInitialX(diamondsXPoz);
	positioned_diamonds[0].setInitialY(diamondsYPoz);
	positioned_diamonds[0].setX(diamondsXPoz);
	positioned_diamonds[0].setY(diamondsYPoz);
	positioned_diamonds[0].setType(0);

	grey_starXpoz = -diamondsXPoz / 3;
	grey_starYpoz = -diamondsYPoz / 7;


	// second diamond
	positioned_diamonds[1].setInitialX(diamondsXPoz + diamondsSpaceBetween);
	positioned_diamonds[1].setInitialY(diamondsYPoz);
	positioned_diamonds[1].setX(diamondsXPoz + diamondsSpaceBetween);
	positioned_diamonds[1].setY(diamondsYPoz);
	positioned_diamonds[1].setType(1);

	positioned_diamonds[2].setInitialX(diamondsXPoz + diamondsSpaceBetween * 2);
	positioned_diamonds[2].setInitialY(diamondsYPoz);
	positioned_diamonds[2].setX(diamondsXPoz + diamondsSpaceBetween * 2);
	positioned_diamonds[2].setY(diamondsYPoz);
	positioned_diamonds[2].setType(2);

	// fourth diamond
	positioned_diamonds[3].setInitialX(diamondsXPoz + diamondsSpaceBetween * 3);
	positioned_diamonds[3].setInitialY(diamondsYPoz);
	positioned_diamonds[3].setX(diamondsXPoz + diamondsSpaceBetween * 3);
	positioned_diamonds[3].setY(diamondsYPoz);
	positioned_diamonds[3].setType(3);


	// red squares positions
	red_squareXPoz = diamondsXPoz + diamondsSpaceBetween * 4.5;
	red_squareSpaceBetween = resolutionX / 11;
	red_squareYPoz = resolutionY - resolutionY / 10;
	// red rectangle
	red_rectangleYPoz = resolutionY / 3.35;
	red_rectangleXPoz = resolutionX / 40;

	green_squareXPoz = resolutionX / 10;
	green_squareSpaceBetween = resolutionX / 9;
	green_squareYPoz = resolutionY / 10;
	green_squareSpaceBehind = resolutionX / 9;

	grey_starXpoz = -diamondsXPoz / 3;
	grey_starYpoz = -diamondsYPoz / 7;

	// logic variables

	// starting point variables
	starCount = 5;
	livesCount = 3;

	hexagonsLastSpawnTime = glfwGetTime();
	starsLastSpawnTime = glfwGetTime();
	presentsLastSpawnTime = glfwGetTime();

	timeToSpawnHexagons = 5;

	// drag and drop
	isPressed = -1;
	typeOfDiamondPressed = -1;

	// manually initializing the Square objects to don t get overwritten
	square_matrix[0][0] = Square(green_squareXPoz, green_squareYPoz);
	for (int i = 0; i < 2; i++) {
		square_matrix[i + 1][0] = Square(green_squareXPoz + green_squareSpaceBetween * (i + 1), green_squareYPoz);
	}
	square_matrix[0][1] = Square(green_squareXPoz, green_squareYPoz + green_squareSpaceBehind);
	for (int i = 0; i < 2; i++) {
		square_matrix[i + 1][1] = Square(green_squareXPoz + green_squareSpaceBetween * (i + 1), green_squareYPoz + green_squareSpaceBehind);
	}
	square_matrix[0][2] = Square(green_squareXPoz, green_squareYPoz + green_squareSpaceBehind * 2);
	for (int i = 0; i < 2; i++) {
		square_matrix[i + 1][2] = Square(green_squareXPoz + green_squareSpaceBetween * (i + 1), green_squareYPoz + green_squareSpaceBehind * 2);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			square_matrix[i][j].setIsFree(true);
		}
	}

	presentSpawnType = 0;
}