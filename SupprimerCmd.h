#pragma once
#include "CommandAbs.h"
#include "Application.h"
#include <vector>


using namespace std;

class SupprimerCmd : public CommandAbs {
    public:
        SupprimerCmd(Application& app, int id);
        ~SupprimerCmd();
        void execute();
        void cancel();

    private:
        Application& app;
        Point* point;
        int id;
        vector<int> nuagesContenantPoint;
};

