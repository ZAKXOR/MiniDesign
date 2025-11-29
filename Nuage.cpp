#include "Nuage.h"
#include "TextureDiese.h"
#include "TextureDollar.h"
#include "TextureO.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Nuage::ordreTexture = 0;

void Nuage::ajouterPoint(int id) {
    auto it = std::find_if(pointsApplication.begin(), pointsApplication.end(),
                              [id](Point* p) { return p->obtenirId() == id; });
    switch(texture) {
        case '#':
            *it = new TextureDiese(*it);
            break;
        case '$':
            *it = new TextureDollar(*it);
            break;
        case 'o':
            *it = new TextureO(*it);
            break;
    }
    pointsDansNuage.push_back((*it)->obtenirId());
    
}

std::vector<int> Nuage::obtenirIdPoints() const {
    return pointsDansNuage;
}

void Nuage::supprimerPoint(int id) {
    pointsDansNuage.erase(
        std::remove_if(
            pointsDansNuage.begin(),
            pointsDansNuage.end(),
            [id](int pointId) { return pointId == id; }
        ),
        pointsDansNuage.end()
    );
}

Nuage::Nuage(std::vector<Point*>& points) : pointsApplication(points) {
    const char textures[] = {'o', '#', '$'};
    this->texture = textures[ordreTexture % NOMBRE_DE_TEXTURE];
    ordreTexture++;
    id = Point::getProchainId();
    Point::incrementProchainId();
    std::for_each(points.begin(), points.end(), [this](Point* p) {this->ajouterPoint(p->obtenirId());});
}

Nuage::Nuage(std::vector<Point*>& points, const std::vector<int>& idsAAjouter) 
    : pointsApplication(points) {
    const char textures[] = {'o', '#', '$'};
    this->texture = textures[ordreTexture % NOMBRE_DE_TEXTURE];
    ordreTexture++;
    id = Point::getProchainId();
    Point::incrementProchainId();
    
    for (int pointId : idsAAjouter) {
        this->ajouterPoint(pointId);
    }
}

Nuage::~Nuage() {
    pointsDansNuage.clear();
    nuagesDansNuage.clear();
}

std::vector<Point*> Nuage::obtenirPoints() {
    std::vector<Point*> res = std::vector<Point*>();
    std::for_each(pointsDansNuage.begin(), pointsDansNuage.end(), [this, &res](int id) {
        auto it = std::find_if(pointsApplication.begin(), pointsApplication.end(),
                               [id](Point* &p) { return p->obtenirId() == id; });
        if (it != pointsApplication.end()) {
            res.push_back(*it);
        }
    });
    return res;
}

std::string Nuage::afficher() const {
    std::ostringstream oss;
    std::string textures = "";

    for (int i : pointsDansNuage) {
        auto it = std::find_if(pointsApplication.begin(), pointsApplication.end(),
                              [i](Point* p) { return p->obtenirId() == i; });
        if (it != pointsApplication.end()) {
            textures += (*it)->obtenirTexture();
        }
    }

    

    oss << id << ": Nuage '" << texture << "' contient les points: ";
    for (size_t i = 0; i < pointsDansNuage.size(); ++i) {
        oss << pointsDansNuage[i];
        if (i < pointsDansNuage.size() - 1 || !nuagesDansNuage.empty()) {
            oss << ", ";
        }
    }
    for (size_t i = 0; i < nuagesDansNuage.size(); ++i) {
        oss << nuagesDansNuage[i];
        if (i < nuagesDansNuage.size() - 1) {
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

int Nuage::obtenirId() {
    return id;
}

void Nuage::ajouterNuage(int id) {
    nuagesDansNuage.push_back(id);
    /*
    
    for (int i : n->pointsDansNuage) {
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
    }
    */
}