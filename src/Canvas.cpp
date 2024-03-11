#include <sstream>
#include <cmath>
#include <Canvas.h>

namespace canvas {

std::string to_ppm(const Canvas& c) {
    std::ostringstream header;
    header << "P3\n" << c.width() << ' ' << c.height() << "\n255\n";

    std::string ret = header.str();
    for (unsigned y = 0; y < c.height(); ++y) {
        std::stringstream data;
        for (unsigned x = 0; x < c.width(); ++x) {
            tuple::Tuple color = c.at(x, y);
            unsigned r = scale(color.r(), 255);
            unsigned g = scale(color.g(), 255);
            unsigned b = scale(color.b(), 255);
            data << r << ' ' << g << ' ' << b << ' ';
        }

        unsigned line_size = 0;
        std::string num;
        while (data >> num) {
            if (line_size == 0) {
                ret += num;
                line_size += num.size();
            } else if (line_size > 0 && line_size + num.size() < 70) {
                ret += ' ' + num;
                line_size += 1 + num.size();
            } else {
                ret += '\n' + num;
                line_size = num.size();
            }
        }
        ret += '\n';
    }

    return ret;
}

unsigned scale(double i, unsigned max) {
    if (i <= 0) return 0;
    if (i >= 1) return max;
    return ceill(i * max);
}

}