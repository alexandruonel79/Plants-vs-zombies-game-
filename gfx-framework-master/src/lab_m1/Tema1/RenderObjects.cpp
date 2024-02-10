#include "Tema1.h"
#include "transform2D.h"

void m1::Tema1::displayCurrentStars() {

	int greyStarYPozLocal = red_squareYPoz - length * 0.75;
	int greyStarXPozLocal = red_squareXPoz - length * 0.7;

	if (starCount > 0) {

		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(greyStarXPozLocal, greyStarYPozLocal);
		modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
		RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		// go through all the stars and render them according to last position
		// modelMatrix does not reset
		for (int i = 0; i < starCount - 1; i++) {
			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		}
	}

}

void m1::Tema1::displayCurrentLives() {
	if (livesCount > 0) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(red_squareXPoz, red_squareYPoz);
		RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);

		for (int i = 0; i < livesCount - 1; i++) {
			// go through all the lives and render them accordin to last position
			// modelMatrix does not reset
			modelMatrix *= transform2D::Translate(red_squareSpaceBetween, 0);
			RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
		}
	}
}

void m1::Tema1::renderDiamonds(float deltaTimeSeconds) {

	int nrOfPozDiamonds = 4;

	for (int i = 0; i < nrOfPozDiamonds; ++i) {
		modelMatrix = glm::mat3(1);

		modelMatrix *= transform2D::Translate(positioned_diamonds[i].getX(), positioned_diamonds[i].getY());
		// for each type there are a different amount of stars to render
		// so the type is checked and rendered accordingly
		if (positioned_diamonds[i].getType() == 0) {
			RenderMesh2D(meshes["orange_diamond"], shaders["VertexColor"], modelMatrix);
			// display just one grey star
			modelMatrix *= transform2D::Translate(grey_starXpoz, grey_starYpoz);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 1) {
			RenderMesh2D(meshes["blue_diamond"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(grey_starXpoz, grey_starYpoz);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 2) {
			RenderMesh2D(meshes["yellow_diamond"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(grey_starXpoz, grey_starYpoz);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 3) {
			RenderMesh2D(meshes["purple_diamond"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(grey_starXpoz, grey_starYpoz);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);

			modelMatrix *= transform2D::Translate(-grey_starXpoz, 0);
			RenderMesh2D(meshes["grey_star"], shaders["VertexColor"], modelMatrix);
		}
	}
	// renders the floating diamonds
	for (int i = 0; i < nrOfPozDiamonds; ++i) {
		modelMatrix = glm::mat3(1);

		modelMatrix *= transform2D::Translate(positioned_diamonds[i].getInitialX(), positioned_diamonds[i].getInitialY());
		//modelMatrix *= transform2D::Translate(positioned_diamonds[i].getNewInitialX(), positioned_diamonds[i].getNewInitialY());

		if (positioned_diamonds[i].getType() == 0) {
			RenderMesh2D(meshes["orange_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 1) {
			RenderMesh2D(meshes["blue_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 2) {
			RenderMesh2D(meshes["yellow_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (positioned_diamonds[i].getType() == 3) {
			RenderMesh2D(meshes["purple_diamond"], shaders["VertexColor"], modelMatrix);
		}
	}
	// render the diamonds on the squares
	for (int i = 0; i < new_diamonds.size(); i++) {
		modelMatrix = glm::mat3(1);

		if (new_diamonds[i].getIsAlive() == false) {
			if (new_diamonds[i].getScalingFactor() < 0)
			{
				new_diamonds.erase(new_diamonds.begin() + i);
				return;
			}
			new_diamonds[i].setScalingFactor(new_diamonds[i].getScalingFactor() - deltaTimeSeconds * 5);
			modelMatrix *= transform2D::Translate(new_diamonds[i].getX(), new_diamonds[i].getY());
			modelMatrix *= transform2D::Scale(new_diamonds[i].getScalingFactor(), new_diamonds[i].getScalingFactor());
			modelMatrix *= transform2D::Translate(-new_diamonds[i].getX(), -new_diamonds[i].getY());
		}

		modelMatrix *= transform2D::Translate(new_diamonds[i].getX(), new_diamonds[i].getY());

		if (new_diamonds[i].getType() == 0) {
			RenderMesh2D(meshes["orange_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (new_diamonds[i].getType() == 1) {
			RenderMesh2D(meshes["blue_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (new_diamonds[i].getType() == 2) {
			RenderMesh2D(meshes["yellow_diamond"], shaders["VertexColor"], modelMatrix);
		}
		else if (new_diamonds[i].getType() == 3) {
			RenderMesh2D(meshes["purple_diamond"], shaders["VertexColor"], modelMatrix);
		}
	}
}

void m1::Tema1::renderspawnedStars() {
	for (int i = 0; i < stars.size(); ++i) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(stars[i].getX(), stars[i].getY());
		RenderMesh2D(meshes["purple_star"], shaders["VertexColor"], modelMatrix);
	}
}

void m1::Tema1::renderspawnedHexagons(float deltaTimeSeconds) {
	for (int i = 0; i < hexagons.size(); ++i) {
		// remove unnecesary hexagons
		if (hexagons[i].getX() < 0)
		{
			hexagons.erase(hexagons.begin() + i);
			livesCount--;
			return;
		}

		modelMatrix = glm::mat3(1);

		if (hexagons[i].getAlive() == false) {

			float scalingFactor = hexagons[i].getScalingFactor();
			scalingFactor -= deltaTimeSeconds * 5;
			hexagons[i].setScalingFactor(scalingFactor);
			// if it's not showing anymore
			// it can be erased
			if (scalingFactor <= 0) {
				if (hexagons[i].getKilled() == true) {
					livesCount--;
				}

				hexagons.erase(hexagons.begin() + i);
				continue;
			}
			modelMatrix *= transform2D::Translate(hexagons[i].getX(), hexagons[i].getY());
			modelMatrix *= transform2D::Scale(scalingFactor, scalingFactor);
			modelMatrix *= transform2D::Translate(-hexagons[i].getX(), -hexagons[i].getY());
		}

		modelMatrix *= transform2D::Translate(hexagons[i].getX(), hexagons[i].getY());
		hexagons[i].setX(hexagons[i].getX() - deltaTimeSeconds * 100);

		// blue green hexagon
		if (hexagons[i].getType() == 0) {
			RenderMesh2D(meshes["orange_green_hexagon"], shaders["VertexColor"], modelMatrix);
		}
		// yellow green hexagon
		if (hexagons[i].getType() == 1) {
			RenderMesh2D(meshes["blue_green_hexagon"], shaders["VertexColor"], modelMatrix);
		}
		// orange green hexagon
		if (hexagons[i].getType() == 2) {
			RenderMesh2D(meshes["yellow_green_hexagon"], shaders["VertexColor"], modelMatrix);
		}
		// purple green hexagon
		if (hexagons[i].getType() == 3) {
			RenderMesh2D(meshes["purple_green_hexagon"], shaders["VertexColor"], modelMatrix);
		}

	}
}

void m1::Tema1::renderProjectileStars(float deltaTimeSeconds) {
	for (int i = 0; i < projectileStars.size(); i++) {
		// remove unecessary projectiles
		if (projectileStars[i].getX() > resolutionX)
		{
			projectileStars.erase(projectileStars.begin() + i);
			return;
		}

		modelMatrix = glm::mat3(1);
		// rotation logic
		modelMatrix *= transform2D::Translate(projectileStars[i].getX(), projectileStars[i].getY());
		modelMatrix *= transform2D::Rotate(projectileStars[i].getRotationAngle());
		modelMatrix *= transform2D::Translate(-projectileStars[i].getX(), -projectileStars[i].getY());
		projectileStars[i].setRotationAngle(projectileStars[i].getRotationAngle() + deltaTimeSeconds);

		modelMatrix *= transform2D::Translate(projectileStars[i].getX(), projectileStars[i].getY());
		projectileStars[i].setX(projectileStars[i].getX() + deltaTimeSeconds * 100);
		// based on its type it's rendered accordingly
		if (projectileStars[i].getType() == 0) {
			RenderMesh2D(meshes["orange_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (projectileStars[i].getType() == 1) {
			RenderMesh2D(meshes["blue_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (projectileStars[i].getType() == 2) {
			RenderMesh2D(meshes["yellow_star"], shaders["VertexColor"], modelMatrix);
		}
		else if (projectileStars[i].getType() == 3) {
			RenderMesh2D(meshes["purple_projectile_star"], shaders["VertexColor"], modelMatrix);
		}


	}
}

void m1::Tema1::renderSquareFrames() {
	// renders the square frames for drag and drop
	for (int i = 0; i < 4; i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(positioned_diamonds[i].getX(), positioned_diamonds[i].getY());
		RenderMesh2D(meshes["black_frame_square"], shaders["VertexColor"], modelMatrix);
	}
}

void m1::Tema1::renderRedRectangleAndGreenSquares() {
	/// red rectangle
	red_rectangleYPoz = resolutionY / 3.35;
	red_rectangleXPoz = resolutionX / 40;

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(red_rectangleXPoz, red_rectangleYPoz);
	RenderMesh2D(meshes["red_rectangle"], shaders["VertexColor"], modelMatrix);


	/// green squares
	green_squareXPoz = resolutionX / 10;
	green_squareSpaceBetween = resolutionX / 9;
	green_squareYPoz = resolutionY / 10;

	// down ones
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(green_squareXPoz, green_squareYPoz);
	RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);


	for (int i = 0; i < 2; i++) {
		modelMatrix *= transform2D::Translate(green_squareSpaceBetween, 0);
		RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);
	}

	green_squareSpaceBehind = resolutionX / 9;

	// middle ones
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(green_squareXPoz, green_squareYPoz + green_squareSpaceBehind);
	RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);


	for (int i = 0; i < 2; i++) {
		modelMatrix *= transform2D::Translate(green_squareSpaceBetween, 0);
		RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);
	}


	// up ones
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(green_squareXPoz, green_squareYPoz + green_squareSpaceBehind * 2);
	RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);

	for (int i = 0; i < 2; i++) {
		modelMatrix *= transform2D::Translate(green_squareSpaceBetween, 0);
		RenderMesh2D(meshes["green_square"], shaders["VertexColor"], modelMatrix);
	}
}

void m1::Tema1::renderspawnedPresents() {
	// the bonus
	// renders the presents on the screen
	for (int i = 0; i < presents.size(); ++i) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(presents[i].getX(), presents[i].getY());
		RenderMesh2D(meshes["present"], shaders["VertexColor"], modelMatrix);
	}
}