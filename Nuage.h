#pragma once
#include <vector>
#include "Point.h"
#include "StrategieConstruction.h"
#include <string>
#include <sstream>
const int NOMBRE_DE_TEXTURE = 3;

class Nuage {
    private:
    std::vector<int> nuagesDansNuage = std::vector<int>();
    std::vector<int> pointsDansNuage = std::vector<int>();
    std::vector<Point*>& pointsApplication;
    std::vector<Nuage*>& nuagesApplication;
    char texture;
    int id;
    static int ordreTexture;


    public:
    Nuage(std::vector<Point*>& points, std::vector<Nuage*>&, const std::vector<int>& idsAAjouter);
    ~Nuage();
    void ajouterPoint(int id);
    void ajouterNuage(int id);
    std::vector<int> obtenirIdPoints() const;
    std::vector<Point*> obtenirPoints();
    std::vector<Point*> obtenirToutLesPoints();
    void supprimerPoint(int id);
    std::string afficher() const;
    std::string filtrerTextures(std::string textures) const;
    int obtenirId();
    void ajouterPointSansTexture(int id);

};
