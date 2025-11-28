#include "SupprimerCmd.h"
#include "CommandAbs.h"
#include "Application.h"

using namespace std;

SupprimerCmd::SupprimerCmd(Application& app, int id) : app(app), id(id) {
    point = app.obtenirPoint(id);
}

SupprimerCmd::~SupprimerCmd() = default;

void SupprimerCmd::execute() {
    app.supprimerPoint(id);
}

void SupprimerCmd::cancel() {
    app.ajouterPoint(point);
}





