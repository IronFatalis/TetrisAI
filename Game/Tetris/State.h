#ifndef STATE_H
#define STATE_H

class State
{
public:

    virtual ~State() {}

    virtual void Enter(int currentPiece, int currentState) = 0;

    virtual void Execute(int currentPiece, int currentState) = 0;

    virtual void Exit(int currentPiece, int currentState) = 0;

};

#endif