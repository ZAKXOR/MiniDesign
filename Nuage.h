#pragma once
#include <vector>
#include "Point.h"
#include "StrategieConstruction.h"
#include <string>
#include <sstream>

class Nuage {
    private:
    std::vector<int> nuagesDansNuage = std::vector<int>();
    std::vector<int> pointsDansNuage = std::vector<int>();
    std::vector<Point*>& pointsApplication;

    char texture;
    int id;
    static int ordreTexture;
    public:
    Nuage(std::vector<Point*>& points, const std::vector<int>& idsAAjouter);
    ~Nuage();
    const int NOMBRE_DE_TEXTURE = 3;
    void ajouterPoint(int id);
    void ajouterNuage(int id);
    std::vector<int> obtenirIdPoints() const;
    std::vector<Point*> obtenirPoints();
    void supprimerPoint(int id);
    std::string afficher() const;
    std::string filtrerTextures(std::string textures) const;
    int obtenirId();
};
