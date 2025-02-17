#pragma once
#include "../../header/UI/UIElement/ImageView.h"

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

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
        

        PlayerView(PlayerController* controller) : player_controller(controller)
        {
            game_window = nullptr;
            player_image = new UI::UIElement::ImageView();
        }            
	     
        PlayerView();
		
        ~PlayerView();

		

		void initialize();
		void update();
		void render();
	};
}