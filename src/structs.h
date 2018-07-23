#pragma once
#include "types.h"

#ifndef JAMBO_LEARNSETS

struct learnset_move {
    u16 move : 9;
    u16 level : 7;
};

#else

struct learnset_move {
    u16 move;
    u8 level;
} __attribute__((packed));

#endif

struct pokemon {
  u8 _[100];
};
