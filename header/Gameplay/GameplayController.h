#pragma once
#include "../../header/Level/LevelData.h"

namespace Gameplay
{
	class GameplayController
	{
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void onPositionChanged(int position);
		void processObstacle();
		bool isObstacle(Level::BlockType value);
		void destroy();
	};
}
