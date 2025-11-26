#include "DecorateurPoint.h"

DecorateurPoint::DecorateurPoint(Point* p): Point(p->obtenirX(), p->obtenirY(), true), point(p) { point = p; }

DecorateurPoint::~DecorateurPoint() {
    delete point;
}
int DecorateurPoint::obtenirId() const {
    return point->obtenirId();
}
int DecorateurPoint::obtenirX() const {
    return point->obtenirX();
}
int DecorateurPoint::obtenirY() const {
    return point->obtenirY();
}
void DecorateurPoint::modifierXY(int newX, int newY) {
    point->modifierXY(newX, newY);
}
std::string DecorateurPoint::afficher() const {
    return std::to_string(obtenirId()) + ": (" + std::to_string(obtenirX()) + "," + std::to_string(obtenirY()) + ")  textures: '" + obtenirTexture() + "'";
}
