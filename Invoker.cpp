#include "CommandAbs.h"
#include "Invoker.h"
#include <stack>


Invoker::Invoker() = default;

Invoker::~Invoker() {
    while (!cmdDone.empty()){
        delete cmdDone.top();
        cmdDone.pop();
    }

    while (!cmdUndone.empty()){
        delete cmdUndone.top();
        cmdUndone.pop();
    }
}

void Invoker::execute(CommandAbs* cmdPtr){
    cmdPtr->execute();
    cmdDone.push(cmdPtr);
}

void Invoker::undo() {
    if (!cmdDone.empty()){
        CommandAbs* cmd = cmdDone.top();
        cmd->cancel();
        cmdDone.pop();
        cmdUndone.push(cmd);
    }
}

void Invoker::redo() {
    if (!cmdUndone.empty()){
        CommandAbs* cmd = cmdUndone.top();
        cmd->execute();
        cmdUndone.pop();
        cmdDone.push(cmd);
    }
}


