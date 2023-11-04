#pragma once

#include "constants/pokemon.h"

struct __attribute__((packed)) JamboLevelUpLearnset {
    u16 move;
    u8 lvl;
};

struct __attribute__((packed)) VanillaLevelUpLearnset {
    u16 move : 9;
    u16 lvl : 7;
};

#if USE_JAMBO_LEARNSET_HACK == 0

typedef struct VanillaLevelUpLearnset LevelUpLearnset;
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) ((ls)->lvl == 0x7F && (ls)->move == 0x1FF)

#else

typedef struct JamboLevelUpLearnset LevelUpLearnset;
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) ((ls)->lvl == 0xFF && (ls)->move == 0x0)

#endif

// extern const LevelUpLearnset *const gLevelUpLearnsets[];
typedef const LevelUpLearnset *const gLevelUpLearnsetsType[];
extern const gLevelUpLearnsetsType * const gLevelUpLearnsetsPtr;
#define gLevelUpLearnsets (*gLevelUpLearnsetsPtr)

u32 GetMonData(struct Pokemon *mon, s32 field);
u16 GiveMoveToMon(struct Pokemon *mon, u16 move);
