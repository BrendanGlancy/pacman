#pragma once

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Color;

static const Color BLACK_COLOR = {0, 0, 0, 255};
static const Color BLUE_COLOR = {3, 138, 255, 1};
static const Color PACMAN_COLOR = {255, 255, 0, 255};

#define FPS_DELAY 100 // 60 FPS would be approximately 16ms delay
