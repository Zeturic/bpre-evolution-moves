#pragma once
#include "types.h"

#include "constants/mon-data.h"

#include "structs.h"
#include "locations.h"
#include "functions.h"

#ifndef USE_JAMBO_LEARNSET_HACK
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) ((ls)->lvl == 0x7F && (ls)->move == 0x1FF)
#else
#define IS_LEVEL_UP_LEARNSET_TERMINATOR(ls) ((ls)->lvl == 0xFF && (ls)->move == 0x0)
#endif