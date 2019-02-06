#pragma once
#include "types.h"

#define packed __attribute__((packed))

struct packed Pokemon {
    u8 filler_0[100];
};

struct packed JamboLevelUpLearnset {
    u16 move;
    u8 lvl;
};

struct packed VanillaLevelUpLearnset {
    u16 move : 9;
    u16 lvl : 7;
};

#ifndef USE_JAMBO_LEARNSET_HACK
typedef struct VanillaLevelUpLearnset LevelUpLearnset;
#else
typedef struct JamboLevelUpLearnset LevelUpLearnset;
#endif