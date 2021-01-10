#include <math.h>
#include <stdlib.h>

#ifdef _MSC_VER
#include <SDL.h>
#endif

#include "shape.h"
#include "types.h"
#include "util.h"

extern const struct shape asteroid_shapes[];

extern const struct vec_2d origin;

float calculate_asteroid_radius(unsigned int shape)
{
    float r;
    float r_max = 0.0f;

    const float *vertices = asteroid_shapes[shape].vertices;

    unsigned int i;
    unsigned int n = asteroid_shapes[shape].num_vertices;;

    for (i = 0; i < n * 2; i += 2) {
        r = sqrtf(vertices[i] * vertices[i] + vertices[i + 1] * vertices[i + 1]);
        if (r_max < r) {
            r_max = r;
        }
    }

    return r_max;
}

void randomise_asteroid_position(struct asteroid *a)
{
    float x;
    float y;
    float dist = 0.0f;

    do {
        x = random_float(0 - origin.x, origin.x);
        y = random_float(0 - origin.y, origin.y);
        dist = sqrtf(x * x + y * y);
    } while (dist < NO_ASTEROID_RADIUS);

    a->pos.x = x;
    a->pos.y = y;
}

void randomise_asteroid_rotation(struct asteroid *a)
{
    a->rot = random_float(0, 2.0f * (float) M_PI);
}

void randomise_asteroid_velocity(struct asteroid *a, float vel_scale)
{
    const float speed = random_float(ASTEROID_SPEED_MIN, ASTEROID_SPEED_MAX);
    const float rot = random_float(0, 2.0f * (float) M_PI);

    a->vel.x = sinf(rot) * speed * vel_scale;
    a->vel.y = 0 - cosf(rot) * speed * vel_scale;
}

void init_asteroid(struct asteroid *a)
{
    randomise_asteroid_position(a);
    randomise_asteroid_velocity(a, 1.0f);
    randomise_asteroid_rotation(a);

    a->pos_prev.x = a->pos.x;
    a->pos_prev.y = a->pos.y;
    a->visible = true;
    a->size = ASIZE_LARGE;
    a->shape = rand() % ASTEROID_SHAPES;
    a->radius = calculate_asteroid_radius(a->shape) / (float)(a->size);
}

void update_asteroids(struct asteroid *aa, unsigned int n, float f)
{
    unsigned int i;
    for (i = 0; i < n; i++, aa++) {
        if (true == aa->visible) {
            aa->pos_prev.x = aa->pos.x;
            aa->pos_prev.y = aa->pos.y;
            aa->pos.x += aa->vel.x * f;
            aa->pos.y += aa->vel.y * f;
            if (wrap_position(&aa->pos, aa->radius)) {
                aa->pos_prev.x = aa->pos.x;
                aa->pos_prev.y = aa->pos.y;
            }
        }
    }
}
