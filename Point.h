#pragma once
#include <string>
#include <vector>

const int LARGEUR = 30;
const int HAUTEUR = 20;

class Point {
    protected:
    static int prochainId;

    private:
    int x;
    int y;
    int id;
    
    public:
    Point(int x, int y, bool skipID = false);
    ~Point();
    virtual int obtenirId() const;
    virtual int obtenirX() const;
    virtual int obtenirY() const;
    virtual void modifierXY(int newX, int newY);
    virtual std::string obtenirTexture() const;
    virtual std::string afficher() const;
    void decrementerId();
};