#pragma once
#include "MovementDirection.h"
#include "../Event/EventService.h"

namespace Player
{

	class PlayerView;
	class PlayerModel;
	
	enum class PlayerState;
	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		int getCurrentPosition();
		void move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool isPositionInBound(int targetPosition); // Add this line
		void readInput();
		void takeDamage();
		void reset();
	};
}