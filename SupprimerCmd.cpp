#include "SupprimerCmd.h"
#include "CommandAbs.h"
#include "Application.h"
#include <vector>
#include <algorithm>

using namespace std;

SupprimerCmd::SupprimerCmd(Application& app, int id) : app(app), id(id) {
    point = app.obtenirPoint(id);
}

SupprimerCmd::~SupprimerCmd() = default;

void SupprimerCmd::execute() {
    for (Nuage* nuage : app.obtenirNuages()) {
        vector<int> pointsDansNuage = nuage->obtenirIdPoints();
        auto it = find(pointsDansNuage.begin(), pointsDansNuage.end(), id);
        if (it != pointsDansNuage.end()){
            nuagesContenantPoint.push_back(nuage->obtenirId());
        }
    }

    point = app.retirerPoint(id);
}


void SupprimerCmd::cancel() {
    app.ajouterPoint(point);

    for (Nuage* nuage : app.obtenirNuages()) {
        auto it = std::find(nuagesContenantPoint.begin(), nuagesContenantPoint.end(), nuage->obtenirId());
        if (it != nuagesContenantPoint.end()){
            nuage->ajouterPointSansTexture(id);
        }
    }
}







