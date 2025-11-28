#pragma once
#include "CommandAbs.h"
#include "Application.h"


using namespace std;

class DeplacerCmd : public CommandAbs {
    public:
        DeplacerCmd(Application& app, int id, int nouveauX, int nouveauY);
        ~DeplacerCmd();
        void execute() override;
        void cancel() override;


    private:
        Application& app;
        int id;
        int nouveauX;
        int nouveauY;
        int ancienX;
        int ancienY;
    
};