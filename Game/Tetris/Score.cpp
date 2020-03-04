#include "Score.h"

Score* Score::sInstance = nullptr;
Score::Score()
{
	mRandom = Random::Instance();
	mTypeManager = TypeManager::GetInstance();

	//Type B only
	mTypeB = new Texture("GameSprites.png", 287, 25, 58, 18);
	mTypeB->SetParent(this);
	mTypeB->SetPosition(Graphics::SCREEN_WIDTH * 0.12f, Graphics::SCREEN_HEIGHT * 0.102f);
	mTypeB->SetScale(Vector2(3.0f, 3.25f));

	mHeightBox = new Texture("GameSprites.png", 452, 182, 64, 32);
	mHeightBox->SetParent(this);
	mHeightBox->SetPosition(Graphics::SCREEN_WIDTH * 0.765f, Graphics::SCREEN_HEIGHT * 0.82f);
	mHeightBox->SetScale(Vector2(3.0f, 3.25f));

	mHeight = new Texture(Height, "emulogic.ttf", 32, { 255, 255, 255 });
	mHeight->SetParent(this);
	mHeight->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.89f);


	//Scores
	mHiScore = new Texture(HiScore, "emulogic.ttf", 28, { 255, 255, 255 });
	mHiScore->SetParent(this);
	mHiScore->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.175f);

	mCurrentScore = new Texture(mScore, "emulogic.ttf", 28, { 255, 255, 255 });
	mCurrentScore->SetParent(this);
	mCurrentScore->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.285f);

	mLevel = new Texture(Level, "emulogic.ttf", 32, { 255, 255, 255 });
	mLevel->SetParent(this);
	mLevel->SetPosition(Graphics::SCREEN_WIDTH * 0.835f, Graphics::SCREEN_HEIGHT * 0.745f);

	mLine = new Texture(tLine, "emulogic.ttf", 32, { 255, 255, 255 });
	mLine->SetParent(this);
	mLine->SetPosition(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.09f);


	//Block Stats
	mTStat = new Texture(TStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mTStat->SetParent(this);
	mTStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.4f);

	mJStat = new Texture(JStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mJStat->SetParent(this);
	mJStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.475f);

	mZStat = new Texture(ZStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mZStat->SetParent(this);
	mZStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.55f);

	mSquareStat = new Texture(SquareStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mSquareStat->SetParent(this);
	mSquareStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.625f);

	mSStat = new Texture(SStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mSStat->SetParent(this);
	mSStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.7f);

	mLStat = new Texture(LStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mLStat->SetParent(this);
	mLStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.775f);

	mIStat = new Texture(IStat, "emulogic.ttf", 28, { 255, 255, 255 });
	mIStat->SetParent(this);
	mIStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.85f);

	//add to the side stats
	switch (mRandom->GetCurrentPiece())
	{
	case 0:
		TStatNum += 1;
		TStat = std::to_string(TStatNum);
		mTStat = new Texture(TStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mTStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.4f);
		break;
	case 1:
		JStatNum += 1;
		JStat = std::to_string(JStatNum);
		mJStat = new Texture(JStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mJStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.475f);
		break;
	case 2:
		ZStatNum += 1;
		ZStat = std::to_string(ZStatNum);
		mZStat = new Texture(ZStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mZStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.55f);
		break;
	case 3:
		SquareStatNum += 1;
		SquareStat = std::to_string(SquareStatNum);
		mSquareStat = new Texture(SquareStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mSquareStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.625f);
		break;
	case 4:
		SStatNum += 1;
		SStat = std::to_string(SStatNum);
		mSStat = new Texture(SStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mSStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.7f);
		break;
	case 5:
		LStatNum += 1;
		LStat = std::to_string(LStatNum);
		mLStat = new Texture(LStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mLStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.775f);
		break;
	case 6:
		IStatNum += 1;
		IStat = std::to_string(IStatNum);
		mIStat = new Texture(IStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mIStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.85f);
		break;
	}
}

Score::~Score()
{
	Release();
}

void Score::Render()
{
	mHiScore->Render();
	mCurrentScore->Render();
	mLevel->Render();
	mLine->Render();

	if (mTypeManager->GetGameType())
	{
		mTypeB->Render();
		mHeightBox->Render();
		mHeight->Render();
	}


	mTStat->Render();
	mJStat->Render();
	mZStat->Render();
	mSquareStat->Render();
	mSStat->Render();
	mLStat->Render();
	mIStat->Render();
}

void Score::UpdateStats()
{
	switch (mRandom->GetCurrentPiece())
	{
	case 0:
		TStatNum += 1;
		TStat = std::to_string(TStatNum);
		mTStat = new Texture(TStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mTStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.4f);
		break;
	case 1:
		JStatNum += 1;
		JStat = std::to_string(JStatNum);
		mJStat = new Texture(JStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mJStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.475f);
		break;
	case 2:
		ZStatNum += 1;
		ZStat = std::to_string(ZStatNum);
		mZStat = new Texture(ZStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mZStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.55f);
		break;
	case 3:
		SquareStatNum += 1;
		SquareStat = std::to_string(SquareStatNum);
		mSquareStat = new Texture(SquareStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mSquareStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.625f);
		break;
	case 4:
		SStatNum += 1;
		SStat = std::to_string(SStatNum);
		mSStat = new Texture(SStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mSStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.7f);
		break;
	case 5:
		LStatNum += 1;
		LStat = std::to_string(LStatNum);
		mLStat = new Texture(LStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mLStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.775f);
		break;
	case 6:
		IStatNum += 1;
		IStat = std::to_string(IStatNum);
		mIStat = new Texture(IStat, "emulogic.ttf", 28, { 255, 255, 255 });
		mIStat->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.85f);
		break;
	}
	
	if (LineCounter == 10)
	{
		tLevel += 1;
		SetSpeed(10);
		Level = std::to_string(tLevel);
		mLevel = new Texture(Level, "emulogic.ttf", 32, { 255, 255, 255 });
		mLevel->SetParent(this);
		mLevel->SetPosition(Graphics::SCREEN_WIDTH * 0.835f, Graphics::SCREEN_HEIGHT * 0.745f);
		LineCounter = 0;
	}
}

void Score::AddScore(int score)
{
	mAddScore += score;
	mScore = std::to_string(mAddScore);
	mCurrentScore = new Texture(mScore, "emulogic.ttf", 28, { 255, 255, 255 });
	mCurrentScore->SetParent(this);
	mCurrentScore->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.285f);
}

void Score::AddtoHiScore(std::string score)
{
	tHiScore += std::stoi(score);
	HiScore = std::to_string(tHiScore);
	mHiScore = new Texture(HiScore, "emulogic.ttf", 28, { 255, 255, 255 });
	mHiScore->SetParent(this);
	mHiScore->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.175f);
}

void Score::AddLevel(std::string level)
{
	tLevel += std::stoi(level);
	Level = std::to_string(tLevel);
	mLevel = new Texture(Level, "emulogic.ttf", 32, { 255, 255, 255 });
	mLevel->SetParent(this);
	mLevel->SetPosition(Graphics::SCREEN_WIDTH * 0.835f, Graphics::SCREEN_HEIGHT * 0.745f);
}

void Score::AddHeight(std::string height)
{
	tHeight += std::stoi(height);
	Height = std::to_string(tHeight);
	mHeight = new Texture(Height, "emulogic.ttf", 32, { 255, 255, 255 });
	mHeight->SetParent(this);
	mHeight->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.89f);
}

void Score::AddLine(int line)
{
	LineNum = line;
	tLine = std::to_string(LineNum);
	mLine = new Texture(tLine, "emulogic.ttf", 32, { 255, 255, 255 });
	mLine->SetParent(this);
	mLine->SetPosition(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.09f);
}

int Score::GetLevel()
{
	return tLevel;
}

float Score::GetSpeed()
{
	return Speed;
}

void Score::SetSpeed(float speed)
{
	Speed = speed / tLevel;
}

Score* Score::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new Score();
	}
	return sInstance;
}

void Score::Release()
{
	sInstance = nullptr;
	delete sInstance;
}
