#ifndef CPUSTATES_H
#define CPUSTATES_H
#include "State.h"
#include "Random.h"
#include "LockGrid.h"
#include "GameScreen.h"

namespace SDLFramework
{
    class ST_CHECKPIECE : public State
    {
    private:

        ST_CHECKPIECE() {}

    public:

        static ST_CHECKPIECE* Instance(int currentPiece, int currentState);

        virtual void Enter(int currentPiece, int currentState);

        virtual void Execute(int currentPiece, int currentState);

        virtual void Exit(int currentPiece, int currentState);
    };



    class ST_MOVEPIECE : public State
    {
    private:

        ST_MOVEPIECE() {}

    public:

        static ST_MOVEPIECE* Instance(int currentPiece, int currentState);

        virtual void Enter(int currentPiece, int currentState);

        virtual void Execute(int currentPiece, int currentState);

        virtual void Exit(int currentPiece, int currentState);

        bool rotate = true;
        bool position = false;
    };



    class ST_ROTATE : public State
    {
    private:

        ST_ROTATE() {}

    public:
        int rotateAmount;
        bool rotate = false;
        bool position;

        static ST_ROTATE* Instance(int currentPiece, int currentState);

        virtual void Enter(int currentPiece, int currentState);

        virtual void Execute(int currentPiece, int currentState);

        virtual void Exit(int currentPiece, int currentState);
    };



    class ST_DROP : public State
    {
    private:

        ST_DROP() {}

    public:

        static ST_DROP* Instance(int currentPiece, int currentState);

        virtual void Enter(int currentPiece, int currentState);

        virtual void Execute(int currentPiece, int currentState);

        virtual void Exit(int currentPiece, int currentState);
    };
}

#endif