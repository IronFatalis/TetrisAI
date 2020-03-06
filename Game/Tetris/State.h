#ifndef STATE_H
#define STATE_H

class State
{
public:

    virtual ~State() {}

    virtual void Enter(int currentPiece) = 0;

    virtual void Execute(int currentPiece) = 0;

    virtual void Exit(int currentPiece) = 0;

};

#endif