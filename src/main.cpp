#include <cstdio>
#include <Tuple.h>

using namespace tuple;

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
    const struct environment e{vector(0, -0.1, 0), vector(-0.01, 0, 0)};
    struct projectile p{tuple::point(0, 1, 0), normalize(vector(1, 1, 0))};
    while (p.position.y() >= 0) {
        printf("p.position is [ %lf, %lf, %lf ]\n", p.position.x(), p.position.y(), p.position.z());
        p = tick(e, p);
    }
    return 0;
}
