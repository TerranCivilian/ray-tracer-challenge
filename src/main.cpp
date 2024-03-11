#include <cstdio>
#include <fstream>
#include <Tuple.h>
#include <Canvas.h>

using namespace tuple;
using namespace canvas;

struct projectile {
    Tuple position;
    Tuple velocity;
};

struct environment {
    Tuple gravity;
    Tuple wind;
};

const struct projectile tick(const struct environment& e, const struct projectile& p) {
    Tuple position = p.position + p.velocity;
    Tuple velocity = p.velocity + e.gravity + e.wind;
    return (struct projectile){position, velocity};
}

int main(void) {
    Tuple start = point(0, 1, 0);
    Tuple velocity = normalize(vector(1, 1.8, 0)) * 11.25;
    struct projectile p{start, velocity};

    Tuple gravity = vector(0, -0.1, 0);
    Tuple wind = vector(-0.01, 0, 0);
    const struct environment e{gravity, wind};

    Canvas c(900, 550);

    while (p.position.y() >= 0) {
        printf("p.position is [ %lf, %lf, %lf ]\n", p.position.x(), p.position.y(), p.position.z());
        c.write(p.position.x(), c.height()-p.position.y(), color(1, 1, 1));
        p = tick(e, p);
    }

    std::string ppm = to_ppm(c);
    std::ofstream output("output.ppm");
    output << ppm;
    output.close();
    
    return 0;
}
