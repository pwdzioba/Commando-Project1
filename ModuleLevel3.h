#ifndef __ModuleLevel3_H__
#define __ModuleLevel3_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleSceneGame.h"
#include "ModuleEnemies.h"

struct SDL_Texture;
struct Mix_Chunk;

class _Mix_Music;
typedef _Mix_Music Mix_Music;

class ModuleLevel3 :
	public ModuleSceneGame
{
private:
	Mix_Music* motivationsong;
	uint timer;
	bool global;
	bool global_on;
	bool spawning;
	int counter;
	EnemySpawner* Global;


public:
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void onFadeInEnd();

	ModuleLevel3();
	virtual ~ModuleLevel3();
};

#endif