#ifndef GAME_H
#define GAME_H

class Game
{
	public :
		Game();
		~Game();
		void play();

	private :
		int m_scores[10];
		int m_bonuses[10];
		void computeScoreForAllFrames();
		void displayFrames();
		void displayRoll(int frame, int tour, int bonus, int total);
		int computeSpareBonus(int frame);
		int computeStrikeBonus(int frame);
};

#endif