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
	~HighScore();

	void addScore() {}; //TODO: if exist update. if new insert
	int getNumOfCompleteLevels() { return m_levelsScore.size(); };
private:
	HighScore();
	HighScore(const HighScore&) = default;
	HighScore& operator=(const HighScore&) = default;

	void load();
	void save();

	std::map<int, int, std::less<int>> m_levelsScore;
};