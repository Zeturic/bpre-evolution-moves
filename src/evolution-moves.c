#include "global.h"
#include "battle.h"
#include "pokemon.c.h"
#include "pokemon.h"

u16 MonTryLearningNewMoveAfterEvolution(struct Pokemon *mon, bool8 firstMove)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    const LevelUpLearnset * learnset;

    if (firstMove)
        sLearningMoveTableID = 0;

    learnset = &gLevelUpLearnsets[species][sLearningMoveTableID];

    while (!IS_LEVEL_UP_LEARNSET_TERMINATOR(learnset))
    {
        if (!learnset->lvl || learnset->lvl == level)
        {
            ++sLearningMoveTableID;
            gMoveToLearn = learnset->move;
            return GiveMoveToMon(mon, gMoveToLearn);
        }

        ++sLearningMoveTableID;
        ++learnset;
    }

    return 0;
}

void NAKED Task_EvolutionScene__Hook(void)
{
    asm_unified("\n\
        ldr r1, =gTasks\n\
        mov r2, r8\n\
        adds r0, r2, r7\n\
        lsls r0, #3\n\
        adds r5, r0, r1\n\
        ldrb r1, [r5, #0x10]\n\
        mov r0, r9\n\
        ldr r3, =MonTryLearningNewMoveAfterEvolution\n\
        bl call\n\
        ldr r3, =0x080CEDDC |1\n\
    call:\n\
        bx r3\n\
    .pool");
}
