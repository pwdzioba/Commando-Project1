#pragma once
#include "Enemy.h"
#include "Animation.h"
#include "Path.h"

class EnemyJump :
	public Enemy
{


private: 
	Path movement;
	Animation e1_forward;
	Animation e1_backward;
	Animation e1_left;
	Animation e1_right;
	Animation e1_up_right;
	Animation e1_up_left;
	Animation e1_down_right;
	Animation e1_down_left;
	Animation death;
	Animation walk;
	Animation jump;
	
	bool jump_int = true;
	float jump_speed = -3;
	int jump_state = 0;
	 
	int dir;

	Animation* GetAnimationForDirection(int dir);
	int angle;
	int collision = false;
	bool dying = false;
	int timer;

public:
	EnemyJump(int x, int y, int angle, int sub_type);
	virtual ~EnemyJump();

	virtual void Move();
	virtual void OnCollision(Collider* collider);
};


