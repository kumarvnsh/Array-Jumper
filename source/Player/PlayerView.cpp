#include "../../header/Player/PlayerView.h"
#include "../../header/UI/UIElement/ImageView.h" // Add this include to resolve the ImageView identifier
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include <iostream>
#include "../../header/Global/Config.h" //-------------Needed for Config

using namespace Global; //-------------Needed for Config

namespace Player
{
	PlayerView::PlayerView()
	{
		game_window = nullptr;

		player_image = new UI::UIElement::ImageView(); // Fully qualify the ImageView identifier
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}

	void PlayerView::update()
	{
		//Yet to implement
		
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		default:
			break;
		}
	}

	void PlayerView::calculatePlayerDimensions()
	{
		player_height = 1000.f;
		player_width = 1000.f;
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

	sf::Vector2f calulcatePlayerPosition()
	{
		return sf::Vector2f(0, 0);
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calulcatePlayerPosition());
	}

	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}