#pragma once
#include "types.h"

#include "structs.h"
#include "functions.h"
#include "locations.h"

#include "defines/getattr.h"

#define MOVESET_PAD {                                       \
    ++learnset_move_index;                                  \
    move_to_learn = learnset_move->move;                    \
    return pokemon_moveset_pad(pokemon, move_to_learn);     \
}

#ifndef JAMBO_LEARNSETS
    #define CONDITION (*((u16*) learnset_move) != 0xFFFF)
#else
    #define CONDITION (learnset_move->level != 0xFF)
#endif  
