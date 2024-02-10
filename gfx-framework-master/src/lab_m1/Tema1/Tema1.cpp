#include "Tema1.h"

#include <vector>
#include <iostream>

#include "transform2D.h"
#include "object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();

	resolutionX = resolution.x;
	resolutionY = resolution.y;

	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	length = 100;
	// made this variable because i used the purple star length more
	purple_starLength = length * 0.4f;
	// initialise all the meshes used
	// all of them use the length relative to the variable length
	Mesh* green_square = object2D::CreateSquareR("green_square", length * 0.5, glm::vec3(0, 1, 0));
	AddMeshToList(green_square);

	Mesh* black_frame_square = object2D::CreateSquareFrame("black_frame_square", length * 0.5, glm::vec3(0, 0, 0));
	AddMeshToList(black_frame_square);

	Mesh* red_square = object2D::CreateSquareR("red_square", length * 0.4, glm::vec3(1, 0, 0));
	AddMeshToList(red_square);

	Mesh* blue_green_hexagon = object2D::CreateHexagon("blue_green_hexagon", length * 0.35, glm::vec3(0.227, 0.216, 0.949), glm::vec3(0.114, 0.659, 0.533));
	AddMeshToList(blue_green_hexagon);

	Mesh* yellow_green_hexagon = object2D::CreateHexagon("yellow_green_hexagon", length * 0.35, glm::vec3(0.98, 0.933, 0.02), glm::vec3(0.114, 0.659, 0.533));
	AddMeshToList(yellow_green_hexagon);

	Mesh* orange_green_hexagon = object2D::CreateHexagon("orange_green_hexagon", length * 0.35, glm::vec3(0.902, 0.6, 0.043), glm::vec3(0.114, 0.659, 0.533));
	AddMeshToList(orange_green_hexagon);

	Mesh* purple_green_hexagon = object2D::CreateHexagon("purple_green_hexagon", length * 0.35, glm::vec3(0.949, 0.031, 0.949), glm::vec3(0.114, 0.659, 0.533));
	AddMeshToList(purple_green_hexagon);

	Mesh* grey_star = object2D::CreateStar("grey_star", length * 0.2, glm::vec3(0.83, 0.83, 0.82), 1);
	AddMeshToList(grey_star);

	Mesh* purple_star = object2D::CreateStar("purple_star", purple_starLength, glm::vec3(0.8, 0.067, 0.839), 3);
	AddMeshToList(purple_star);

	Mesh* orange_star = object2D::CreateStar("orange_star", length * 0.2f, glm::vec3(0.902, 0.6, 0.043), 3);
	AddMeshToList(orange_star);

	Mesh* blue_star = object2D::CreateStar("blue_star", length * 0.2f, glm::vec3(0.227, 0.216, 0.949), 3);
	AddMeshToList(blue_star);

	Mesh* yellow_star = object2D::CreateStar("yellow_star", length * 0.2f, glm::vec3(0.98, 0.933, 0.02), 3);
	AddMeshToList(yellow_star);

	Mesh* purple_projectile_star = object2D::CreateStar("purple_projectile_star", length * 0.2f, glm::vec3(0.949, 0.031, 0.949), 3);
	AddMeshToList(purple_projectile_star);

	Mesh* blue_diamond = object2D::CreateDiamond("blue_diamond", length * 0.12, glm::vec3(0, 0, 1));
	AddMeshToList(blue_diamond);

	Mesh* yellow_diamond = object2D::CreateDiamond("yellow_diamond", length * 0.12, glm::vec3(1, 1, 0));
	AddMeshToList(yellow_diamond);

	Mesh* orange_diamond = object2D::CreateDiamond("orange_diamond", length * 0.12, glm::vec3(1, 0.6, 0));
	AddMeshToList(orange_diamond);

	Mesh* purple_diamond = object2D::CreateDiamond("purple_diamond", length * 0.12, glm::vec3(0.7, 0, 0.7));
	AddMeshToList(purple_diamond);

	Mesh* red_rectangle = object2D::CreateRectangle("red_rectangle", 1.92 * length, length * 0.25, glm::vec3(1, 0, 0));
	AddMeshToList(red_rectangle);

	// bonus 
	Mesh* heart = object2D::CreateHeart("heart", 0.3 * length, glm::vec3(1, 0, 0));
	AddMeshToList(heart);

	Mesh* present = object2D::CreatePresent("present", 0.3 * length);
	AddMeshToList(present);

	initVariables();
}

void Tema1::displayScene() {

	// the black squares surrounding the diamonds
	renderSquareFrames();
	// render the static table and red rectangle
	renderRedRectangleAndGreenSquares();
	// render and display are synonyms
	displayCurrentLives();
	displayCurrentStars();
	renderspawnedStars();
}

void Tema1::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// Sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->GetResolution();
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);

	resolutionX = resolution.x;
	resolutionY = resolution.y;

	displayScene();
	
	// generates the stars
	spawnStars();
	// spawn enemies hexagons
	spawnHexagons();
	// check for hexagon reaching end
	hexagonReachRectangle();
	// render hexagons
	renderspawnedHexagons(deltaTimeSeconds);
	// render diamonds
	renderDiamonds(deltaTimeSeconds);
	// removes diamonds when they collide with hexagons
	removeDiamondOnCollision();
	// generates and renders the projectiles
	generateProjectileStars();
	renderProjectileStars(deltaTimeSeconds);
	//check for collisions between projectiles and hexagons
	checkCollisionsProjectileHexagons();
	// generate and render presents
	// bonus
	generatePresents();
	renderspawnedPresents();
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}


void Tema1::OnKeyPress(int key, int mods)
{
	// Add key press event

}


void Tema1::OnKeyRelease(int key, int mods)
{
	// Add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	int conversieMouseY = resolutionY - mouseY;
	glm::vec2 punctApasare(mouseX, conversieMouseY);
	int type = isPressed;

	// if the mouse is pressed
	if (isPressed != -1) {
		// follow the cursor
		positioned_diamonds[type].setInitialX(mouseX);
		positioned_diamonds[type].setInitialY(conversieMouseY);
	}
	// if the mouse isn t pressed
	// search if its close enough to any matrix square
	// put him in
	else if(isPressed == -1 && typeOfDiamondPressed != -1){
		bool fixed = false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				glm::vec2 punctPatrat(square_matrix[i][j].getX(), square_matrix[i][j].getY());
				float distance = glm::distance(punctPatrat, punctApasare);
				if (distance <= length * 0.5 + length * 0.12 && square_matrix[i][j].getIsFree() && starCount >= (typeOfDiamondPressed + 1)) {
					fixed = true;
					starCount -= typeOfDiamondPressed + 1;
					square_matrix[i][j].setIsFree(false);
	
					Diamond new_diamond;
					new_diamond.setX(square_matrix[i][j].getX());
					new_diamond.setY(square_matrix[i][j].getY());
					new_diamond.setType(typeOfDiamondPressed);
					new_diamond.setMatrixXPosition(i);
					new_diamond.setMatrixYPosition(j);
	
					new_diamond.setIsAlive(true);
					new_diamond.setScalingFactor(1);
					new_diamond.setProjectileLastSpawnTime(glfwGetTime());

					new_diamonds.push_back(new_diamond);
					
					positioned_diamonds[typeOfDiamondPressed].setInitialX(positioned_diamonds[typeOfDiamondPressed].getX());
					positioned_diamonds[typeOfDiamondPressed].setInitialY(positioned_diamonds[typeOfDiamondPressed].getY());
				}
			}
		}
		if (!fixed) {
			for (int i = 0; i < 4; i++) {
				positioned_diamonds[i].setInitialX(positioned_diamonds[i].getX());
				positioned_diamonds[i].setInitialY(positioned_diamonds[i].getY());
			}
		}
		typeOfDiamondPressed = -1;
	}
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	int conversieMouseY = resolutionY - mouseY;
	glm::vec2 punctApasare(mouseX, conversieMouseY);

	glm::vec2 diamond_0(positioned_diamonds[0].getInitialX(), positioned_diamonds[0].getInitialY());
	glm::vec2 diamond_1(positioned_diamonds[1].getInitialX(), positioned_diamonds[1].getInitialY());
	glm::vec2 diamond_2(positioned_diamonds[2].getInitialX(), positioned_diamonds[2].getInitialY());
	glm::vec2 diamond_3(positioned_diamonds[3].getInitialX(), positioned_diamonds[3].getInitialY());

	float distance_0 = glm::distance(diamond_0, punctApasare);
	float distance_1 = glm::distance(diamond_1, punctApasare);
	float distance_2 = glm::distance(diamond_2, punctApasare);
	float distance_3 = glm::distance(diamond_3, punctApasare);

	// on left click of mouse
	if (button == 1) {
		// drag and drop logic for diamonds
		modelMatrix = glm::mat3(1);
		// diamond length is 0.12 * length
		if (distance_0 <= length * 0.5 && (isPressed == -1 || isPressed == 0)) {
			isPressed = 0;
			typeOfDiamondPressed = 0;
		}
		else if (distance_1 <= length * 0.5 && (isPressed == -1 || isPressed == 1)) {
			isPressed = 1;
			typeOfDiamondPressed = 1;
		}
		else if (distance_2 <= length * 0.5 && (isPressed == -1 || isPressed == 2)) {
			isPressed = 2;
			typeOfDiamondPressed = 2;
		}
		else if (distance_3 <= length * 0.5 && (isPressed == -1 || isPressed == 3)) {
			isPressed = 3;
			typeOfDiamondPressed = 3;
		}
		else {
			isPressed = -1;
		}
		// here is the stars logic
		int indice = -1;
		for (int i = 0; i < stars.size(); i++)
		{
			glm::vec2 punctOrigine(stars[i].getX(), stars[i].getY());

			float distanta = glm::distance(punctOrigine, punctApasare);

			if (distanta <= purple_starLength) {
				indice = i;
				// increase the collected number of stars
				starCount++;

				break;
			}

		}
		if (indice != -1) {
			stars.erase(stars.begin() + indice);
		}

		// bonus -> presents logic
		int stop = -1;

		for (int i = 0; i < presents.size(); i++) {
			glm::vec2 presents_pos(presents[i].getX(), presents[i].getY());
			float distance_presents = glm::distance(punctApasare, presents_pos);

			if (distance_presents <= length * 0.3) {
				if (presents[i].getType() == 0) {
					// on type 0 you get 5 stars
					starCount += 5;
				}
				else {
					// on type 1 all hexagons disappear
					for (int j = 0; j < hexagons.size(); j++) {
						hexagons[j].setAlive(false);
						hexagons[j].setKilled(false);
					}
				}
				stop = i;
				break;
			}
		}
		if (stop != -1) {
			presents.erase(presents.begin() + stop);
		}
	}
		// diamond remove from table logic
		if (button == 2) {
			for (int i = 0; i < new_diamonds.size(); i++) {
				glm::vec2 punctApasare(mouseX, conversieMouseY);
				glm::vec2 diamond_remove(new_diamonds[i].getX(), new_diamonds[i].getY());

				float distance_remove = glm::distance(diamond_remove, punctApasare);
				// hexagon length
				if (distance_remove <= length * 0.3) {
					/// matrix position is set to be free
					square_matrix[new_diamonds[i].getMatrixXPosition()][new_diamonds[i].getMatrixYPosition()].setIsFree(true);
					// retrieve collected stars
					if (new_diamonds[i].getType() == 0) {
						starCount += 1;
					}
					else if (new_diamonds[i].getType() == 1) {
						starCount += 2;
					}
					else if (new_diamonds[i].getType() == 2) {
						starCount += 3;
					}
					else if (new_diamonds[i].getType() == 3) {
						starCount += 4;
					}

					new_diamonds[i].setIsAlive(false);
					return;
				}
			}
		}
	}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// Add mouse button release event
	if (button == 1) {
		isPressed = -1;
		//cout << "Released" << endl;
	}
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
