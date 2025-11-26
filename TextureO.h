#pragma once
#include "DecorateurPoint.h"

class TextureO : public DecorateurPoint {
    public:
    TextureO(Point* p): DecorateurPoint(p) {}

    std::string obtenirTexture() const override;
};
