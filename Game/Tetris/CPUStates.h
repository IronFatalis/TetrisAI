#ifndef CPUSTATES_H
#define CPUSTATES_H
#include "State.h"


class CPU;

class CPUCheckFirstPiece : public State
{
private:

    CPUCheckFirstPiece() {}

    CPUCheckFirstPiece(const CPUCheckFirstPiece&);
    CPUCheckFirstPiece& operator=(const CPUCheckFirstPiece&);

public:

    static CPUCheckFirstPiece* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class CPUCheckHole : public State
{
private:

    CPUCheckHole() {}

    CPUCheckHole(const CPUCheckHole&);
    CPUCheckHole& operator=(const CPUCheckHole&);

public:

    static CPUCheckHole* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class CPUMoveToHole : public State
{
private:

    CPUMoveToHole() {}

    CPUMoveToHole(const CPUMoveToHole&);
    CPUMoveToHole& operator=(const CPUMoveToHole&);

public:

    static CPUMoveToHole* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class CPUDropPiece : public State
{
private:

    CPUDropPiece() {}

    CPUDropPiece(const CPUDropPiece&);
    CPUDropPiece& operator=(const CPUDropPiece&);

public:

    static CPUDropPiece* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



class CPUNextPiece : public State
{
private:

    CPUNextPiece() {}

    CPUNextPiece(const CPUNextPiece&);
    CPUNextPiece& operator=(const CPUNextPiece&);

public:

    static CPUNextPiece* Instance();

    virtual void Enter(CPU* CPU);

    virtual void Execute(CPU* CPU);

    virtual void Exit(CPU* CPU);
};



#endif