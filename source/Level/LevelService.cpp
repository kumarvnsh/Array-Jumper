#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService() { destroy(); }

	void LevelService::intialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	BoxDimensions LevelService::getBoxDimensions()
	{
		return level_controller->getBoxDimensions();
	}

	BlockType LevelService::getCurrentBoxValue(int position)
	{
		// Add logic to get the current box value based on the position
		// This is a placeholder implementation
		return level_controller->getCurrentBoxValue(position);
	}

	

	void LevelService::destroy()
	{
		delete(level_controller);
	}
}