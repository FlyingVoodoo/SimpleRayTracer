#pragma once

#include "Hittable.hpp"
#include <vector>

class World : public Hittable {
public:
    std::vector<HittablePtr> objects;

    World() {}
    World(const HittablePtr object) {
        add(object);
    }

    void add(const HittablePtr object) {
        objects.push_back(object);
    }

    void clear() {
        objects.clear();
    }

    virtual bool hit(const Rayd& r, double t_min, double t_max, hit_record& rec) const override;
    
    virtual ~World() = default;
};


