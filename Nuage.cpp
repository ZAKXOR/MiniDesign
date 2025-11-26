#include "Nuage.h"
#include "TextureDiese.h"
#include "TextureDollar.h"
#include "TextureO.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Nuage::ordreTexture = 0;

void Nuage::ajouterPoint(Point* p) {
    switch(texture) {
        case '#':
            p = new TextureDiese(p);
            break;
        case '$':
            p = new TextureDollar(p);
            break;
        case 'o':
            p = new TextureO(p);
            break;
    }
    pointsDansNuage.push_back(p);
}

std::vector<Point*> Nuage::obtenirPoints() const {
    return pointsDansNuage;
}

void Nuage::supprimerPoint(int id) {
    pointsDansNuage.erase(
        std::remove_if(
            pointsDansNuage.begin(),
            pointsDansNuage.end(),
            [id](Point* p) { return p->obtenirId() == id; }
        ),
        pointsDansNuage.end()
    );
}

Nuage::Nuage(std::vector<Point*>& points) {
    const char textures[] = {'o', '#', '$'};
    this->texture = textures[ordreTexture % NOMBRE_DE_TEXTURE];
    ordreTexture++;

    std::for_each(points.begin(), points.end(), [this](Point* p) {this->ajouterPoint(p);});
}

Nuage::~Nuage() {
    for (Point* p : pointsDansNuage) {
        delete p;
    }
    pointsDansNuage.clear();
}

std::string Nuage::afficher() const {
    std::ostringstream oss;
    std::string textures = "";

    for (Point* p : pointsDansNuage) {
        textures += p->obtenirTexture();
    }

    oss << "Nuage '" << texture << "' contient les points: ";
    for (size_t i = 0; i < pointsDansNuage.size(); ++i) {
        oss << pointsDansNuage[i]->obtenirId();
        if (i < pointsDansNuage.size() - 1) {
            oss << ", ";
        }
    }
    
    return oss.str();
}

std::string Nuage::filtrerTextures(std::string textures) const {
    std::string t = "";
    for (char c: textures) {
        std::size_t found = t.find_first_of(c);
        if (found == std::string::npos) {
            t.append(std::string(1, c));
        }
    }
    return t;
}
