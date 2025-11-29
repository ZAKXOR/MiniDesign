#include "Application.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Application::Application(): strategieAffichage(nullptr), strategieConstruction(nullptr) {}

void Application::supprimerPoint(int id) {
    Point* pointSupprimer = nullptr;
    auto it = std::find_if(points.begin(), points.end(),
                          [id](Point* p) { return p->obtenirId() == id; });
    if (it != points.end()) {
        pointSupprimer = *it;
        points.erase(it);
    }
    for (Nuage* n : nuages) {
        n->supprimerPoint(id);
    }
    delete pointSupprimer;
}

void Application::deplacerPoint(int id, int newX, int newY) {
    for (Point* p : points) {
        if (p->obtenirId() == id) {
            p->modifierXY(newX, newY);
            break;
        }
    }
}

void Application::fusionnerPoints(vector<int> ids) {
    vector<int> idsPoints;
    vector<int> idsNuages;
    
    for (int id : ids) {
        auto it = find_if(points.begin(), points.end(), 
                         [id](Point* p) { return p->obtenirId() == id; });
        if (it != points.end()) {
            idsPoints.push_back(id);
        }
        
        auto itN = find_if(nuages.begin(), nuages.end(), 
                          [id](Nuage* n) { return n->obtenirId() == id; });
        if (itN != nuages.end()) {
            idsNuages.push_back(id);
        }
    }
    
    if (!(idsPoints.empty() && idsNuages.empty())) {
        Nuage* nouveauNuage = new Nuage(points, nuages, idsPoints);
        nuages.push_back(nouveauNuage);

        for (int idNuage : idsNuages) {
            nouveauNuage->ajouterNuage(idNuage);
        }
    }
}


void Application::ajouterPoint(Point* point) {
    points.push_back(point);
    std::sort(points.begin(), points.end(), [](const Point* a, const Point* b) { return a->obtenirId() < b->obtenirId();});
}

void Application::ajouterPoint(std::vector<Point*> pts) {
    for (Point* point : pts) {
        points.push_back(point);
    }
}

void Application::tracerLigne(vector<vector<char>>& grille, int x0, int y0, int x1, int y1) {
    // Distance verticale
    int lignes = abs(y1 - y0);
    // Si la ligne est horizontale 
    if (lignes == 0) {
        // On prend distance horizontale 
        lignes = abs(x1 - x0);
        for (int i = 0; i <= lignes; ++i) {
            // On trace chaque point de la ligne, de gauche à droite ou de droite à gauche selon la direction.
            int x = (x0 < x1) ? x0 + i : x0 - i;
            if (y1 >= 0 && y1 < HAUTEUR && x >= 0 && x < LARGEUR)
                grille[y1][x] = '/';
        }
    } else {
        // Si la ligne est verticale ou diagonale 
        for (int i = 0; i <= lignes; ++i) {
            double t = (double)i / lignes;
            // On fait une interpolation lineaire
            int x = round(x0 + t * (x1 - x0));
            int y = round(y0 + t * (y1 - y0));
            if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
                grille[y][x] = '/';
        }
    }
}

void Application::modifierStrategieAffichage(StrategieAffichage* nouvelleStrategie) {        
    delete strategieAffichage;
    strategieAffichage = nouvelleStrategie;
}

void Application::modifierStrategieConstruction(StrategieConstruction* nouvelleStrategie) { 
    delete strategieConstruction;
    strategieConstruction = nouvelleStrategie;
}

void Application::afficherPointsEtNuage() {
    for (Point* point : points) {
        std::cout << point->afficher() << std::endl;
    }
    
    for (Nuage* nuage : nuages) {
        std::cout << nuage->afficher() << std::endl;
    }
    
}

void Application::afficherGrille() {
    vector<vector<char>> grille(HAUTEUR, vector<char>(LARGEUR, ' '));
    
    if (strategieAffichage) {
        
        for (Nuage* nuage : nuages) {      
            if (strategieConstruction) {
                auto aretes = strategieConstruction->construireNuage(nuage->obtenirPoints());
                for (const auto& arete : aretes) {
                    tracerLigne(grille, 
                               arete.first->obtenirX(), arete.first->obtenirY(),
                               arete.second->obtenirX(), arete.second->obtenirY());
                }
            }
        }
    }
    strategieAffichage->afficher(points, grille);
    for (int y = HAUTEUR - 1; y >= 0; --y) {
        for (int x = 0; x < LARGEUR; ++x) {
            cout << grille[y][x];
        }
        cout << '\n';
    }
}


Point* Application::obtenirPoint(int id){
    for (Point* p : points) {
        if (p->obtenirId() == id) {
            return p;
        }
    }
}

Application::~Application() {
    for (Point* point : points) {
        delete point;
    }

    for (Nuage* nuage : nuages) {
        delete nuage;
    }

    delete strategieAffichage;
    delete strategieConstruction;
}




