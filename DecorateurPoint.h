#pragma once
#include "Point.h"

class DecorateurPoint : public Point {
    protected:
    Point* point;

    public:
    DecorateurPoint(Point* p);
    virtual ~DecorateurPoint();
    int obtenirId() const override;
    int obtenirX() const override;
    int obtenirY() const override;
    void modifierXY(int newX, int newY) override;
    std::string afficher() const override;
    virtual std::string obtenirTexture() const = 0;
};
