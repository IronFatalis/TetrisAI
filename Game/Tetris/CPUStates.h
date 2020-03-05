#ifndef CPUSTATES_H
#define CPUSTATES_H
#include "State.h"
#include "Random.h"
#include "GameScreen.h"


class CPU;

class ST_CHECKPIECE : public State
{
private:

    ST_CHECKPIECE() {}

    ST_CHECKPIECE(const ST_CHECKPIECE&);
    ST_CHECKPIECE& operator=(const ST_CHECKPIECE&);

public:

    static ST_CHECKPIECE* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class ST_MOVEPIECE : public State
{
private:

    ST_MOVEPIECE() {}

    ST_MOVEPIECE(const ST_MOVEPIECE&);
    ST_MOVEPIECE& operator=(const ST_MOVEPIECE&);

public:

    static ST_MOVEPIECE* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class ST_ROTATE : public State
{
private:

    ST_ROTATE() {}

    ST_ROTATE(const ST_ROTATE&);
    ST_ROTATE& operator=(const ST_ROTATE&);

public:

    static ST_ROTATE* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class ST_DROP : public State
{
private:

    ST_DROP() {}

    ST_DROP(const ST_DROP&);
    ST_DROP& operator=(const ST_DROP&);

public:

    static ST_DROP* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};


#endif