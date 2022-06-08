#include "HighScore.h"

HighScore::HighScore()
{
	load();
}

HighScore::~HighScore()
{
	//TODO: save in file
	save();
}

void HighScore::addScore(int level, int score)
{
	auto iter = m_levelsScore.find(level);
	if (level != m_levelsScore.size() + 1) return; //cant add level if its previous not exist
	if (iter != m_levelsScore.end()) // update
		iter->second = score;
	else // add new
		m_levelsScore.insert(std::pair<int, int>(level, score)); 
}

HighScore& HighScore::instance()
{
	static HighScore inst;
	return inst;
}

void HighScore::load()
{
	std::string filneName = "high_score.txt"; //TODO: add to const
	std::ifstream scoreFile;
	std::string line;
	int level, score;
	std::stringstream ssline;

	scoreFile.open(filneName);
	if (!scoreFile)
		std::cout << "cannot open score file to read\n";

	scoreFile.seekg(0);

	//reading first row level and score (columns name)
	getline(scoreFile, line);
	ssline.clear();

	//reading contents of level
	while (!scoreFile.eof())
	{
		getline(scoreFile, line);
		ssline.clear();
		ssline.str(line);
		ssline >> level >> score;
		
		m_levelsScore.insert(std::pair<int, int>(level, score));
	}
	scoreFile.close();
}

void HighScore::save()
{
	std::ofstream outputScoreFile;
	outputScoreFile.open("hige_score.txt", std::ofstream::out | std::ofstream::trunc);

	if (!outputScoreFile)
		std::cout << "cannot open score file to write\n";

	outputScoreFile << "level\tscore=time(sec)\n";
	for (std::map<int, int, std::less<int>>::const_iterator iter = m_levelsScore.begin();
		iter != m_levelsScore.end(); ++iter)
		outputScoreFile << iter->first << '\t'
		<< iter->second << '\n';

	outputScoreFile.close();
}
