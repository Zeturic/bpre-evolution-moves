#pragma once
#include "types.h"
#include "structs.h"

// extern const LevelUpLearnset * const gLevelUpLearnsets[];
typedef const LevelUpLearnset * const LevelUpLearnsetType[];
extern LevelUpLearnsetType * const gLevelUpLearnsetsPtr;
#define gLevelUpLearnsets (*gLevelUpLearnsetsPtr)

extern u8 sLearningMoveTableID;

extern u16 gMoveToLearn;