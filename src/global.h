#pragma once
#include "types.h"

#include "constants/mon-data.h"

#include "structs.h"
#include "locations.h"
#include "functions.h"

#ifndef USE_JAMBO_LEARNSET_HACK
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) (*((u16*) (ls)) == 0xFFFF)
#else
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) ((ls)->lvl == 0xFF)
#endif