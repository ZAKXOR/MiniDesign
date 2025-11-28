#pragma once
#include "CommandAbs.h"
#include <stack>


using namespace std;

class Invoker {
    public:
        Invoker();
        ~Invoker();
        void execute(CommandAbs* cmd);
        void undo();
        void redo();

    private:
        stack<CommandAbs*> cmdDone;
        stack<CommandAbs*> cmdUndone;
};