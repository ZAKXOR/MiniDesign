#pragma once
#include "DecorateurPoint.h"

class TextureDollar : public DecorateurPoint {
    public:
    TextureDollar(Point* p): DecorateurPoint(p) {}

    std::string obtenirTexture() const override;
};
