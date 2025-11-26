#include "StrategieConstruction.h"
#include <algorithm>
#include <cmath>
#include <limits>

std::vector<std::pair<Point*, Point*>> StrategieConstruction1::construireNuage(std::vector<Point*> points) {
    std::vector<std::pair<Point*, Point*>> aretes;
    
    if (points.size() < 2) {
        return aretes;
    }
    
    std::sort(points.begin(), points.end(), [](Point* a, Point* b) {
        return a->obtenirId() < b->obtenirId();
    });
    
    for (size_t i = 0; i < points.size() - 1; ++i) {
        aretes.push_back(std::make_pair(points[i], points[i + 1]));
    }
    
    aretes.push_back(std::make_pair(points[points.size() - 1], points[0]));
    
    return aretes;
}

std::vector<std::pair<Point*, Point*>> StrategieConstruction2::construireNuage(std::vector<Point*> points) {
    std::vector<std::pair<Point*, Point*>> aretes;
    
    if (points.size() < 2) {
        return aretes;
    }
    
    std::vector<Point*> visites;
    std::vector<Point*> nonVisites = points;
    
    Point* pointCourant = nonVisites[0];
    visites.push_back(pointCourant);
    nonVisites.erase(nonVisites.begin());
    
    while (!nonVisites.empty()) {
        double distanceMin = std::numeric_limits<double>::max();
        size_t indexMin = 0;
        
        for (size_t i = 0; i < nonVisites.size(); ++i) {
            double dx = pointCourant->obtenirX() - nonVisites[i]->obtenirX();
            double dy = pointCourant->obtenirY() - nonVisites[i]->obtenirY();
            double distance = std::sqrt(dx*dx + dy*dy);
            
            if (distance < distanceMin) {
                distanceMin = distance;
                indexMin = i;
            }
        }
        
        Point* pointSuivant = nonVisites[indexMin];
        aretes.push_back(std::make_pair(pointCourant, pointSuivant));
        
        visites.push_back(pointSuivant);
        nonVisites.erase(nonVisites.begin() + indexMin);
        pointCourant = pointSuivant;
    }
    
    aretes.push_back(std::make_pair(pointCourant, visites[0]));
    
    return aretes;
}
