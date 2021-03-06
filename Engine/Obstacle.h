#pragma once

#include "Graphics.h"
#include "Player.h"
#include "Vec2.h"

class Obstacle
{
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	bool TestCollision(const Player& player) const;
	void Draw(Graphics& gfx) const;
	void Respawn(const Vec2& pos_in);
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool initialized = false;
};