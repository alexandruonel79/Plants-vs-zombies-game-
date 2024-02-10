#include "Tema1.h"
#include "transform2D.h"

void m1::Tema1::hexagonReachRectangle()
{
	int indice = -1;
	// go through all the hexagons
	// and check it it reached the red rectangle
	for (int i = 0; i < hexagons.size(); i++) {
		if (hexagons[i].getX() <= length * 0.5) {
			indice = i;
			break;
		}
	}
	// if any hexagon went past, set it to be killed
	if (indice != -1) {
		hexagons[indice].setAlive(false);
		hexagons[indice].setKilled(true);
	}
}

void m1::Tema1::removeDiamondOnCollision() {
	// goes through all the diamonds and hexagons
	// checks the collision using glm::distance
	for (int i = 0; i < new_diamonds.size(); i++) {
		for (int j = 0; j < hexagons.size(); j++) {
			glm::vec2 punctDiamant(new_diamonds[i].getX(), new_diamonds[i].getY());
			glm::vec2 punctHexagon(hexagons[j].getX(), hexagons[j].getY());

			float distanceCol = glm::distance(punctDiamant, punctHexagon);

			if (distanceCol <= length * 0.7 + length * 0.12 && (new_diamonds[i].getX() < hexagons[j].getX())) {
				square_matrix[new_diamonds[i].getMatrixXPosition()][new_diamonds[i].getMatrixYPosition()].setIsFree(true);
				new_diamonds[i].setIsAlive(false);
				return;
			}
		}
	}
}

void m1::Tema1::checkCollisionsProjectileHexagons() {
	// goes through all the hexagons and projectiles
	// checks the collision, by knowing the exact positions
	// it s the same as the function from above, but tried
	// without glm::distance
	for (int i = 0; i < hexagons.size(); i++) {
		for (int j = 0; j < projectileStars.size(); j++) {
			if (hexagons[i].getY() == projectileStars[j].getY()
				&& hexagons[i].getX() < projectileStars[j].getX() + length * 0.4f
				&& hexagons[i].getType() == projectileStars[j].getType()) {
				hexagons[i].setLifes(hexagons[i].getLifes() - 1);

				if (hexagons[i].getLifes() == 0) {
					hexagons[i].setAlive(false);
					hexagons[i].setKilled(false);
					return;
				}

				// the projectile dies anyway
				projectileStars.erase(projectileStars.begin() + j);
				return;
			}
		}
	}
}