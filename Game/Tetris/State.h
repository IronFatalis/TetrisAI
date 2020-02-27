#ifndef STATE_H
#define STATE_H

class CPU;

class State
{
public:

    virtual ~State() {}

    virtual void Enter(CPU*) = 0;

    virtual void Execute(CPU*) = 0;

    virtual void Exit(CPU*) = 0;

};

#endif