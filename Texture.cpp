#include "TextureDiese.h"
#include "TextureO.h"
#include "TextureDollar.h"

std::string TextureDiese::obtenirTexture() const {
    return point->obtenirTexture() + "#";
}

std::string TextureO::obtenirTexture() const {
    return point->obtenirTexture() + "o";
}

std::string TextureDollar::obtenirTexture() const {
    return point->obtenirTexture() + "$";
}