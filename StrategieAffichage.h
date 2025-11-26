#pragma once
#include "Nuage.h"

class StrategieAffichage {
    public:
        virtual void afficher(const std::vector<Point*>& points, std::vector<std::vector<char>>& grille) const = 0;
        virtual ~StrategieAffichage() {}
};

class StrategieAffichage1 : public StrategieAffichage {
    public:
        StrategieAffichage1() {}
        ~StrategieAffichage1() {}
        void afficher(const std::vector<Point*>& points, std::vector<std::vector<char>>& grille) const override;
};

class StrategieAffichage2 : public StrategieAffichage {
    public:
        StrategieAffichage2() {}
        ~StrategieAffichage2() {}
        void afficher(const std::vector<Point*>& points, std::vector<std::vector<char>>& grille) const override;
};