#ifndef __DEFINES_H
#define __DEFINES_H

// asteroids
#define ASTEROID_SPEED_MIN 0.05f
#define ASTEROID_SPEED_MAX 0.11f
#define MAX_ASTEROIDS 100
#define NO_ASTEROID_RADIUS 0.19f
#define NUM_ASTEROID_SHAPES 4

// player
#define SHIP_ACCELERATION 0.45f
#define SHIP_DEATH_DELAY 1.7f
#define SHIP_EXPLOSION_LENGTH 0.3f
#define SHIP_EXPLOSION_SHARD_ROT_SPEED 1.0f
#define SHIP_EXPLOSION_SHARDS 5
#define SHIP_EXPLOSION_SPEED 0.03f
#define SHIP_LIVES 3
#define SHIP_PIVOT 0.025f
#define SHIP_RADIUS 0.038f
#define SHIP_ROTATION_SPEED 4.0f
#define SHIP_THRUSTER_BLINK 0.03f

// bullets
#define BULLET_DELAY 0.25f
#define BULLET_SPEED 0.8f
#define MAX_BULLETS 10
#define MAX_BULLET_DISTANCE (1.0f / 2.0f - SHIP_PIVOT)

// explosions
#define EXPLOSION_LENGTH 0.3f
#define EXPLOSION_PARTICLES 11
#define EXPLOSION_SPEED 0.4f
#define MAX_EXPLOSIONS 20
#define MAX_EXPLOSION_SHARDS 10

#endif