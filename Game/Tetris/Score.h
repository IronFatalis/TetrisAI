#ifndef __SCORE_H
#define __SCORE_H
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "Random.h"
#include "TypeManager.h"
using namespace SDLFramework;

class Score : public GameEntity
{
private:
	static Score* sInstance;

	Random* mRandom;
	TypeManager* mTypeManager;

	//Scores
	Texture* mHiScore;
	Texture* mCurrentScore;
	Texture* mLevel;
	Texture* mLine;

	std::string Level = "01";
	int tLevel = std::stoi(Level);
	

	std::string HiScore = "100000";
	int tHiScore = std::stoi(HiScore);

	int LineNum = 0;
	
	std::string tLine = std::to_string(LineNum);

	std::string Height = "00";
	int tHeight = std::stoi(Height);

	int TStatNum = 0;
	std::string TStat = std::to_string(TStatNum);

	int JStatNum = 0;
	std::string JStat = std::to_string(JStatNum);

	int ZStatNum = 0;
	std::string ZStat = std::to_string(ZStatNum);

	int SquareStatNum = 0;
	std::string SquareStat = std::to_string(SquareStatNum);

	int SStatNum = 0;
	std::string SStat = std::to_string(SStatNum);

	int LStatNum = 0;
	std::string LStat = std::to_string(TStatNum);

	int IStatNum = 0;
	std::string IStat = std::to_string(IStatNum);

	//Type B
	Texture* mTypeB;
	Texture* mHeightBox;
	Texture* mHeight;

	//Block Stats
	Texture* mTStat;
	Texture* mJStat;
	Texture* mZStat;
	Texture* mSquareStat;
	Texture* mSStat;
	Texture* mLStat;
	Texture* mIStat;

public:
	Score();
	~Score();

	void Render() override;

	void UpdateStats();
	void AddScore(int score);
	void AddtoHiScore(std::string score);
	void AddLevel(std::string level);
	void AddHeight(std::string height);
	void AddLine(int line);
	int GetLevel();
	float GetSpeed();
	void SetSpeed(float speed);
	static Score* Instance();
	static void Release();

	float Speed = 10 / tLevel;
	int LineCounter = 0;
	int mAddScore = 0;
	std::string mScore = std::to_string(mAddScore);
};


#endif