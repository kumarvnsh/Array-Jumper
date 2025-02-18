#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Level/BlockType.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Level/LevelService.h"

namespace Gameplay
{
	GameplayController::GameplayController() {}
	GameplayController::~GameplayController() { destroy(); }

	void GameplayController::initialize() {}
	void GameplayController::update() {}
	void GameplayController::render() {}
	void GameplayController::destroy() {}

	void GameplayController::onPositionChanged(int position)
	{
		Level::BlockType value = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();
	}

	void GameplayController::processObstacle()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	bool Gameplay::GameplayController::isObstacle(Level::BlockType value)
	{
		if (value == Level::BlockType::OBSTACLE_ONE || value == Level::BlockType::OBSTACLE_TWO)
			return true;
		return false;
	}

}
