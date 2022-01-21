// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2022

#include <stdint.h>

#define GBA_SCREEN_W            240
#define GBA_SCREEN_H            160

#define REG_DISPCNT             *((volatile uint16_t *)0x04000000)

#define DISPCNT_BG_MODE_MASK    (0x7)
#define DISPCNT_BG_MODE(n)      ((n) & DISPCNT_BG_MODE_MASK) // 0 to 5

#define DISPCNT_BG2_ENABLE      (1 << 10)

#define MEM_VRAM_MODE3_FB       ((uint16_t *)0x06000000)

static inline uint16_t RGB15(uint16_t r, uint16_t g, uint16_t b)
{
    return (r & 0x1F) | ((g & 0x1F) << 5) | ((b & 0x1F) << 10);
}

int main(int argc, char *argv[])
{
    REG_DISPCNT = DISPCNT_BG_MODE(3) | DISPCNT_BG2_ENABLE;

    MEM_VRAM_MODE3_FB[120 + 80 * GBA_SCREEN_W] = RGB15(31, 0, 0);
    MEM_VRAM_MODE3_FB[136 + 80 * GBA_SCREEN_W] = RGB15(0, 31, 0);
    MEM_VRAM_MODE3_FB[120 + 96 * GBA_SCREEN_W] = RGB15(0, 0, 31);

    while(1);

    return 0;
}
