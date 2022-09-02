#include <iostream>
#include <stdlib.h>
#include "Game.hpp"
#include "Roll.hpp"

Game::Game()
{
	// BONUS {0: none, 1: spare, 2: strike}
	std::fill(m_bonuses, m_bonuses+10, 0);
	std::fill(m_scores, m_scores+10, 0);
}

Game::~Game()
{
	
}

void Game::play()
{
	int max_frames = 10;
	for (int frame = 0; frame < max_frames; frame++) {
		Roll *roll = new Roll();
		m_scores[frame] = roll->play();
		m_bonuses[frame] = roll->getBonusType();
		delete roll;
		std::cout << "." << std::flush;
	}
	std::cout << std::endl;

	computeScoreForAllFrames();
}

void Game::computeScoreForAllFrames()
{
	int max_frames = 10;
	int final_score = 0;
	for (int frame = 0; frame < max_frames; frame++) {
		switch (m_bonuses[frame]) {
			case 0:
				final_score += m_scores[frame];
				break;
			case 1:
				final_score += m_scores[frame] + computeSpareBonus(frame);
				break;
			case 2:
				final_score += m_scores[frame] + computeStrikeBonus(frame);
				break;
		}
		displayRoll( (frame+1), m_scores[frame], m_bonuses[frame], final_score);
	}

}

void Game::displayRoll(int frame, int tour, int bonus, int total)
{
	char* extra = "";
	switch (bonus) {
		case 1:
			extra = "Spare";
			break;
		case 2:
			extra = "Strike";
			break;
	}
	printf("%d - Tour : %d, (Total : %d) %s", frame, tour, total, extra);
	std::cout << std::endl;
}

int Game::computeSpareBonus(int frame)
{
	int bonus = 0;
	switch (frame) {
		case 10:
			bonus += 0;
			break;
		default:
			bonus += m_scores[frame+1];
			break;
	}
	return bonus;
}

int Game::computeStrikeBonus(int frame)
{
	int bonus = 0;
	switch (frame) {
		case 10:
			bonus += 0;
			break;
		case 9:
			bonus += m_scores[frame + 1];
			break;
		default:
			bonus += m_scores[frame+1];
			bonus += m_scores[frame+2];
			break;
	}
	return bonus;
}
