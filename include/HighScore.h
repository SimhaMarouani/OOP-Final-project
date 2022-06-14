#pragma once

#include <iostream> 
#include <string> 
#include <map>
#include <memory> //
#include <vector> //
#include <sstream> //
#include <fstream> //
#include <exception> //

#include "Resources.h"
#include "Macros.h"

class HighScore
{
public:
	static HighScore& instance();

    HighScore();
    ~HighScore();

	void addScore(int level, int score);
	int getNumOfCompleteLevels()const { return static_cast<int>(m_levelsScore.size()); };
	int getLevelScore(int level) const;

	void save() const;

private:
	void load();
	void readFromFile();
	void writeToFile() const;
	HighScore(const HighScore&) = default;
	HighScore& operator=(const HighScore&) = default;

	std::map<int, int, std::less<int>> m_levelsScore;
};