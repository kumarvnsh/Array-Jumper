#include "../../header/Player/PlayerModel.h"




namespace Player
{

	void PlayerModel::initialize()
	{
		// Initialize player state and position
		player_state = PlayerState::ALIVE;
		current_position = 0;
		current_lives = max_lives;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}

	int PlayerModel::getCurrentPosition()
	{
		return current_position;
	}

	void PlayerModel::setCurrentPosition(int new_position)
	{
		current_position = new_position;
	}

	void PlayerModel::resetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
		current_lives = max_lives;
	}

	void PlayerModel::decrementLife()
	{
		current_lives--;
	}

	int PlayerModel::getCurrentLives() const
	{
		return current_lives;
	}

	void PlayerModel::resetPosition()
	{
		current_position = 0;
	}
}