#ifndef ROLL_H
#define ROLL_H

class Roll 
{
	public :
		Roll();
		~Roll();
		int play();
		int getBonusType();

	private :
		int m_score[2];
		int m_bonus;
		int m_roll;
		void launchBowl();
		void computeBonus();
		int sumRolls();
};

#endif