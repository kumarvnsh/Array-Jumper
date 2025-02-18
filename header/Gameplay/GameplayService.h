#pragma once
#include "GameplayController.h"

namespace Gameplay
{
	class GameplayService
	{
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
		void onPositionChanged(int position);
		void onDeath();
		void destroy();

	private:
		GameplayController* gameplay_controller;
	};
}
