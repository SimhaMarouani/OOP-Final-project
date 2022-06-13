#include "HighScore.h"

HighScore::HighScore()
{
	load();
}

HighScore::~HighScore()
{
	static bool s;
	if (s) return;
	else
	{
		s = true;
		save();
	}
}

void HighScore::addScore(int level, int score)
{
	auto iter = m_levelsScore.find(level);
	if (level > m_levelsScore.size() + 1)
		return; //cant add level if its previous not exist
	if (iter != m_levelsScore.end()) // update
		iter->second = score;
	else // add new
		m_levelsScore.insert(std::pair<int, int>(level, score)); 
}

int HighScore::getLevelScore(int level) const
{
	auto iter = m_levelsScore.find(level);
	if(iter != m_levelsScore.end()) // update
		 return iter->second;
	return -1;
}

HighScore& HighScore::instance()
{
	static HighScore inst;
	return inst;
}

void HighScore::load()
{
	try
	{
		readFromFile();
	}
	catch(...)
	{
		std::cerr << "cant load scores from file\n"; 
		m_levelsScore.clear();
	}
}

void HighScore::writeToFile()
{
	std::ofstream outputScoreFile;
	outputScoreFile.open(HIGH_SCORE_FILE_NAME, std::ofstream::out | std::ofstream::trunc);

	outputScoreFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	/*if (!outputScoreFile)
		std::cout << "cannot open score file to write\n";*/

	outputScoreFile << "level\tscore=time(sec)\n";
	for (std::map<int, int, std::less<int>>::const_iterator iter = m_levelsScore.begin();
		iter != m_levelsScore.end(); ++iter)
		outputScoreFile << iter->first << '\t'
		<< iter->second << '\n';

	outputScoreFile.close();
}

void HighScore::readFromFile()
{
	std::string filneName = HIGH_SCORE_FILE_NAME; //TODO: add to const
	std::ifstream scoreFile;
	std::string line;
	int level, score;
	std::stringstream ssline;

	scoreFile.exceptions(std::ifstream::badbit);
	//ssline.exceptions(ssline.failbit | ssline.badbit);

	scoreFile.open(filneName);
	scoreFile.seekg(0);

	//reading first row level and score (columns name)
	getline(scoreFile, line);
	ssline.clear();

	//reading contents of level
	while (getline(scoreFile, line))
	{
		//getline(scoreFile, line);
		ssline.clear();
		ssline.str(line);
		ssline >> level >> score;
		
		m_levelsScore.insert(std::pair<int, int>(level, score));

		if (scoreFile.eof()) break;
	}
	scoreFile.close();
}

void HighScore::save()
{
	try
	{
		writeToFile();
	}
	catch (...)
	{
		std::cerr << "unable writing the score file\n";
			
	}
}


