#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "Roll.hpp"

Roll::Roll()
{
	m_roll = 0;
	std::fill(m_score, m_score+2, 0);
}

Roll::~Roll() {

}

int Roll::play()
{
	srand(time(NULL));
	do {
		launchBowl();
	} while (m_roll < 2);

	computeBonus();

	return sumRolls();
}

void Roll::launchBowl()
{
	int pins_down = sumRolls();
	int pins_up = 10 - pins_down;
	m_score[m_roll] = rand() % (pins_up + 1);
	sleep(1);
	m_roll++;
}

void Roll::computeBonus()
{
	m_bonus = 0;

	// Strike (should be the sum of the 2 next rolls)
	if (m_score[0] == 10) {
		m_bonus = 2;
	}

	// Spare (should be the sum of the next roll)
	if (
		( m_score[0] == 9 && m_score[1] == 1) ||
		( m_score[0] == 1 && m_score[1] == 9 ) 
	) {
		m_bonus = 1;
	}
}

int Roll::getBonusType()
{
	return m_bonus;
}

int Roll::sumRolls()
{
	int sum = 0;
	for (int i=0; i<2; i++) {
		sum += m_score[i];
	}
	return sum;
}