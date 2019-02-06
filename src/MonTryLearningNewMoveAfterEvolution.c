#include "global.h"

u16 MonTryLearningNewMoveAfterEvolution(struct Pokemon * mon, bool8 firstMove) {
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    const LevelUpLearnset * learnset;

    if (firstMove)
        sLearningMoveTableID = 0;

    learnset = &gLevelUpLearnsets[species][sLearningMoveTableID];

    while (!IS_LEVEL_UP_LEARNSET_TERMINATOR(learnset)) {
        if (!learnset->lvl || learnset->lvl == level) {
            ++sLearningMoveTableID;
            gMoveToLearn = learnset->move;
            return GiveMoveToMon(mon, gMoveToLearn);
        }

        ++sLearningMoveTableID;
        ++learnset;
    }

    return 0;
}