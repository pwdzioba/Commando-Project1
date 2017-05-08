#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneGame.h"
#include "ModuleSceneCongrats.h"
#include "ModuleSound.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "Moduleenemies.h"
#include "ModuleFonts.h"
#include "ModuleObjects.h"
#include "ModuleInterface.h"
#include "ModuleLevel3.h"
Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = sound = new ModuleSound();
	modules[5] = scene_congrats = new ModuleSceneCongrats();
	modules[6] = scene_welcome = new ModuleSceneWelcome();
	modules[7] = scene_game = new ModuleSceneGame();
	modules[8] = level_3 = new ModuleLevel3();
	modules[9] = player = new ModulePlayer();
	modules[10] = enemies = new ModuleEnemies();
	modules[11] = objects = new ModuleObjects();
	modules[12] = particles = new ModuleParticles();
	modules[13] = collision = new ModuleCollision();
	modules[1] = fonts = new ModuleFonts();
	modules[15] = render = new ModuleRender();
	modules[14] = fade = new ModuleFadeToBlack();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();

	// Disable the map that you do not start with
	level_3->Disable();
	scene_game->Disable();
	scene_congrats->Disable();
	scene_welcome->Enable();
	enemies->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}