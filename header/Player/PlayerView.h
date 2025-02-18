#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"

namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;
		PlayerController* player_controller;

		float player_height;
		float player_width;
		Level::BoxDimensions current_box_dimensions;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
        

		PlayerView(PlayerController* controller);

        ~PlayerView();

		

		void initialize();
		void update();
		void render();
	};
}