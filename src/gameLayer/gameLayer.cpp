#define GLM_ENABLE_EXPERIMENTAL
#include "gameLayer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "platformInput.h"
#include "imgui.h"
#include <iostream>
#include <sstream>
#include "imfilebrowser.h"
#include <gl2d/gl2d.h>
#include <platformTools.h>
#include <tiledRenderer.h>

struct GameplayData
{
	glm::vec2 playerPos = { 100,100 };
};

GameplayData data;

gl2d::Renderer2D renderer;
gl2d::Texture spaceship_texture;
gl2d::Texture background_texture[4];
TiledRenderer tiledRenderer[4];

bool initGame()
{
	//initializing stuff for the renderer
	gl2d::init();
	renderer.create();

	spaceship_texture.loadFromFile(RESOURCES_PATH "spaceShip/ships/purple.png", true);
	background_texture[0].loadFromFile(RESOURCES_PATH "background1.png", true);
	background_texture[1].loadFromFile(RESOURCES_PATH "background2.png", true);
	background_texture[2].loadFromFile(RESOURCES_PATH "background3.png", true);
	background_texture[3].loadFromFile(RESOURCES_PATH "background4.png", true);
	
	tiledRenderer[0].texture = background_texture[0];
	tiledRenderer[1].texture = background_texture[1];
	tiledRenderer[2].texture = background_texture[2];
	tiledRenderer[3].texture = background_texture[3];
	
	tiledRenderer[0].paralaxStrength = 0;
	tiledRenderer[1].paralaxStrength = 0.2;
	tiledRenderer[2].paralaxStrength = 0.4;
	tiledRenderer[3].paralaxStrength = 0.7;
	return true;
}



bool gameLogic(float deltaTime)
{
#pragma region init stuff
	int w = 0; int h = 0;
	w = platform::getFrameBufferSizeX(); //window w
	h = platform::getFrameBufferSizeY(); //window h
	
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT); //clear screen

	renderer.updateWindowMetrics(w, h);
#pragma endregion
#pragma region background
	renderer.currentCamera.zoom = 0.5;
	for(int i=0;i<=3;i++)tiledRenderer[i].render(renderer);
#pragma endregion



#pragma region movement
	glm::vec2 move = {};
	if (platform::isButtonHeld(platform::Button::W) || platform::isButtonHeld(platform::Button::Up)) {
		move.y=-1;
	}
	if (platform::isButtonHeld(platform::Button::A) || platform::isButtonHeld(platform::Button::Left)) {
		move.x = -1;
	}
	if (platform::isButtonHeld(platform::Button::S) || platform::isButtonHeld(platform::Button::Down)) {
		move.y = 1;
	}
	if (platform::isButtonHeld(platform::Button::D) || platform::isButtonHeld(platform::Button::Right)) {
		move.x = 1;
	}
	if (move.x != 0 || move.y != 0) {
		move=glm::normalize(move);
		move *=deltaTime*1000; //1000 pixels per second;
		data.playerPos +=move;
	}

#pragma endregion

	renderer.currentCamera.follow(data.playerPos, deltaTime * 200, 10, 200, w, h);
	renderer.renderRectangle({data.playerPos, 150, 150}, spaceship_texture); //{Coordinates,size of rectagnle},texture
	

	renderer.flush();


	//ImGui::ShowDemoWindow();


	return true;
#pragma endregion

}

//This function might not be be called if the program is forced closed
void closeGame()
{



}
