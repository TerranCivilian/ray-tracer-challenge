#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include <Tuple.h>

namespace canvas {

class Canvas {
    std::vector<std::vector<tuple::Tuple>> pixels;
public:
    Canvas(unsigned w, unsigned h) : pixels(h, std::vector<tuple::Tuple>(w, tuple::color(0, 0, 0))) { }
    unsigned width() const { return pixels[0].size(); }
    unsigned height() const { return pixels.size(); }
    void write(unsigned x, unsigned y, const tuple::Tuple& color) { pixels[y%height()][x%width()] = color; }
    const tuple::Tuple& at(unsigned x, unsigned y) const { return pixels[y%height()][x%width()]; }
};

std::string to_ppm(const Canvas& c);
unsigned scale(double i, unsigned max);

}

#endif