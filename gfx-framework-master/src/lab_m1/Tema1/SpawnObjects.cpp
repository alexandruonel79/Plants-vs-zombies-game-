#include "Tema1.h"
#include "transform2D.h"

void m1::Tema1::spawnStars() {
	// once ten seconds the stars spawn
	if (glfwGetTime() - starsLastSpawnTime >= 10) {
		// reinitialise the last time spawned
		starsLastSpawnTime = glfwGetTime();

		srand(time(nullptr));
		// number of stars to spawn per wave - max 5
		int nrOfStars = rand() % 5 + 1;

		for (int i = 0; i < nrOfStars; i++) {

			int pozitionX = rand() % resolutionX + 1;
			int pozitionY = rand() % resolutionY + 1;

			// store the star
			stars.push_back(Star(pozitionX, pozitionY));
		}
	}
}
void m1::Tema1::spawnHexagons() {

	// once ten seconds the stars spawn
	if (glfwGetTime() - hexagonsLastSpawnTime >= timeToSpawnHexagons) {
		srand(time(nullptr));

		timeToSpawnHexagons = rand() % 10 + 1;
		// reinitialise the last time spawned
		hexagonsLastSpawnTime = glfwGetTime();

		srand(time(nullptr));

		// there are 3 available rows
		int hexagonRow = rand() % 3;
		// there are 4 types of hexagons
		int hexagonType = rand() % 4;

		Hexagon new_hexagon = Hexagon(hexagonType, hexagonRow);
		// we start from the maximum right
		new_hexagon.setX(resolutionX);
		// already have the Y position stored in the square matrix
		new_hexagon.setY(square_matrix[0][hexagonRow].getY());
		new_hexagon.setRow(hexagonRow);
		new_hexagon.setScalingFactor(1);
		new_hexagon.setLifes(3);
		new_hexagon.setKilled(false);
		hexagons.push_back(new_hexagon);
	}
}

void m1::Tema1::generateProjectileStars() {
	// if any hexagon is present
	// we spawn a projectile with the correct type
	for (int i = 0; i < new_diamonds.size(); i++) {
		for (int j = 0; j < hexagons.size(); j++) {

			if (hexagons[j].getRow() == new_diamonds[i].getMatrixYPosition() &&
				hexagons[j].getType() == new_diamonds[i].getType()) {
				// frequency rate is 1 second
				if (glfwGetTime() - new_diamonds[i].getProjectileLastSpawnTime() >= 1) {
					new_diamonds[i].setProjectileLastSpawnTime(glfwGetTime());
					// create the projectile
					Star projectile = Star(new_diamonds[i].getX() + length * 0.5, new_diamonds[i].getY());
					projectile.setType(new_diamonds[i].getType());
					projectile.setRotationAngle(0);
					projectileStars.push_back(projectile);
				}
			}
		}
	}
}

void m1::Tema1::generatePresents() {
	// presents spawn time is set to 20 seconds
	if (glfwGetTime() - presentsLastSpawnTime >= 20) {
		// reinitialise the last time spawned
		presentsLastSpawnTime = glfwGetTime();

		int x = rand() % resolutionX + 1;
		int y = rand() % resolutionY + 1;

		int type = -1;
		// there are two types of presents
		// one gives 5 stars
		// one eliminates all hexagons
		if (presentSpawnType % 2 == 0) {
			type = 0;
			presentSpawnType = 1;
		}
		else {
			type = 1;
			presentSpawnType = 0;
		}
	
		Present new_present = Present(x, y, type);

		presents.push_back(new_present);
	}
}