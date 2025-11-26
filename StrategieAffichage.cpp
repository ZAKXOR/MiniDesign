#include "StrategieAffichage.h"

void StrategieAffichage1::afficher(const std::vector<Point*>& points, std::vector<std::vector<char>>& grille) const {
    for (const Point* p : points) {
        int i = 0;
        if (p->obtenirTexture().empty()) {
            grille[p->obtenirY()][p->obtenirX()] = '.';
        }
        else {
            for (const char c : p->obtenirTexture()) {
            grille[p->obtenirY()][p->obtenirX() + i] = c;
            i++;
            }
        }  
    }
}

void StrategieAffichage2::afficher(const std::vector<Point*>& points, std::vector<std::vector<char>>& grille) const {
    for (const Point* p : points) {
        std::string idStr = std::to_string(p->obtenirId());
        for (size_t i = 0; i < idStr.size(); ++i) {
            grille[p->obtenirY()][p->obtenirX() + i] = idStr[i];
        }
    }
}