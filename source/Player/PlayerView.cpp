#include "../../header/Player/PlayerView.h"
#include "../../header/UI/UIElement/ImageView.h" // Add this include to resolve the ImageView identifier
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include <iostream>
#include "../../header/Global/Config.h" //-------------Needed for Config






namespace Player
{
	using namespace Global; //-------------Needed for Config
	using namespace UI::UIElement; //-------------Needed for ImageView
	using namespace Level; //-------------Needed for BoxDimensions

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		player_image = new ImageView();
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}

	void PlayerView::update()
	{
		updatePlayerPosition();
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		
		}
	}

	void PlayerView::calculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path,
			player_width,
			player_height,
			sf::Vector2f(0, 0));
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}


	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}