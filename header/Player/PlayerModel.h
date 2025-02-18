#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:

		PlayerState player_state;
		int current_position;
		const int max_lives = 3;
		int current_lives;

	public:
		void initialize();
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
		void setCurrentPosition(int new_position);
		void resetPlayer();
		void decrementLife();
		int getCurrentLives() const;
		void resetPosition();
	};
}

