#pragma once
#include "DecorateurPoint.h"

class TextureDiese : public DecorateurPoint {
    public:
    TextureDiese(Point* p): DecorateurPoint(p) {}

    std::string obtenirTexture() const override;
};
