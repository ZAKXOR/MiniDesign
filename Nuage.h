#pragma once
#include <vector>
#include "Point.h"
#include "StrategieConstruction.h"
#include <string>
#include <sstream>

class Nuage {
    private:
    std::vector<Point*> pointsDansNuage = std::vector<Point*>();
    char texture;
    static int ordreTexture;
    public:
    Nuage(std::vector<Point*>& points);
    ~Nuage();
    const int NOMBRE_DE_TEXTURE = 3;

    void ajouterPoint(Point* p); // TODO: DECORER LE POINT DEPENDANT DE LA TEXTURE DU NUAGE
    std::vector<Point*> obtenirPoints() const;
    void supprimerPoint(int id);
    std::string afficher() const;
    std::string filtrerTextures(std::string textures) const;

    
};
