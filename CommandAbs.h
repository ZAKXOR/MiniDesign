#pragma once

using namespace std;

class CommandAbs {
    public:
        CommandAbs() = default;
        virtual ~CommandAbs() = default;
        virtual void cancel() = 0;
        virtual void execute() = 0;
};



