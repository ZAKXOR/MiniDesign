#pragma once
#include "Nuage.h"
#include "StrategieAffichage.h"
#include "StrategieConstruction.h"
#include <vector>

using namespace std;

class Application {
    private:
        std::vector<Nuage*> nuages;
        std::vector<Point*> points;
        StrategieAffichage* strategieAffichage;
        StrategieConstruction* strategieConstruction;

    public:
        Application();
        ~Application();
        void afficherGrille();
        void afficherPointsEtNuage();
        void deplacerPoint(int id, int newX, int newY);
        void fusionnerPoints(vector<int> ids);
        void modifierStrategieAffichage(StrategieAffichage* nouvelleStrategie);
        void modifierStrategieConstruction(StrategieConstruction* nouvelleStrategie);
        void supprimerPoint(int id);
        void commande(const std::string& cmd);
        void ajouterPoint(Point* point);
        void ajouterPoint(std::vector<Point*> pts);
        void tracerLigne(vector<vector<char>>& grille, int x0, int y0, int x1, int y1);
};
