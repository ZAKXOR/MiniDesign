#include "DeplacerCmd.h"
#include "CommandAbs.h"
#include "Application.h"

using namespace std;

DeplacerCmd::DeplacerCmd(Application& app, int id, int nouveauX, int nouveauY) : app(app), id(id), nouveauX(nouveauX), nouveauY(nouveauY) {
    Point* point = app.obtenirPoint(id);
    ancienX = point->obtenirX();
    ancienY = point->obtenirY();
}

DeplacerCmd::~DeplacerCmd() = default;

void DeplacerCmd::execute() {
    app.deplacerPoint(id, nouveauX, nouveauY);
}

void DeplacerCmd::cancel() {
    app.deplacerPoint(id, ancienX, ancienY);
}



