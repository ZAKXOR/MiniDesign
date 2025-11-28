#include "Point.h"
#include <sstream>

int Point::prochainId = 0;

void Point::decrementerId() {
    id--;
}

Point::Point(int x, int y, bool skipID): x(x), y(y) {
    id = prochainId;
    if (!skipID) {
        prochainId++;
    }
}

Point::~Point() {}

int Point::obtenirId() const {
    return id;
}

int Point::obtenirX() const {
    return x;
}

int Point::obtenirY() const {
    return y;
}

void Point::modifierXY(int newX, int newY) {
    x = newX;
    y = newY;
}
std::string Point::obtenirTexture() const {
    return "";
}
std::string Point::afficher() const {
    return std::to_string(id) + ": (" + std::to_string(x) + "," + std::to_string(y) + ")  textures: " + obtenirTexture();
}

int Point::getProchainId() {
    return prochainId;
}

void Point::incrementProchainId() {
    prochainId++;
}