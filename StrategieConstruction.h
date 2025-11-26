#pragma once
#include <vector>
#include "Point.h"

class StrategieConstruction {
    public:
        virtual std::vector<std::pair<Point*, Point*>> construireNuage(std::vector<Point*> points) = 0;
        virtual ~StrategieConstruction() {}
};

class StrategieConstruction1 : public StrategieConstruction {
    public:
        StrategieConstruction1() {}
        ~StrategieConstruction1() {}
        std::vector<std::pair<Point*, Point*>> construireNuage(std::vector<Point*> points) override;
};

class StrategieConstruction2 : public StrategieConstruction {
    public:
        StrategieConstruction2() {}
        ~StrategieConstruction2() {}
        std::vector<std::pair<Point*, Point*>> construireNuage(std::vector<Point*> points) override;
};