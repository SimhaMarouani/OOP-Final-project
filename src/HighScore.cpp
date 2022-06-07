#include "HighScore.h"

HighScore::HighScore()
{
	load();

	std::cout << "here\n";
	for (std::map<int, int, std::greater<int>>::const_iterator iter = m_levelsScore.begin();
		iter != m_levelsScore.end(); ++iter)
		std::cout << iter->first << '\t'
		<< iter->second << '\n';
}

HighScore::~HighScore()
{
	//TODO: save in file
}

HighScore& HighScore::instance()
{
	static HighScore inst;
	return inst;
}

void HighScore::load()
{
	std::string filneName = "high_score.txt";
	std::ifstream scoreFile;
	std::string line;
	int level, score;
	std::stringstream ssline;

	scoreFile.exceptions(std::ifstream::badbit);
	ssline.exceptions(ssline.failbit | ssline.badbit);

	scoreFile.open(filneName);
	scoreFile.seekg(0);

	//reading first row level end score (columns name)
	getline(scoreFile, line);
	ssline.clear();

	//getline(scoreFile, line);

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
