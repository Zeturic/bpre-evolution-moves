.gba

.arm
.include "locations.s"

.thumb
.include "functions.s"

.open "rom.gba", "test.gba", 0x08000000

.org allocation
.area allocation_size
    .importobj "obj/relocatable.o"

    .align 2

    Task_EvolutionScene__Hook:
        ldr r1, =gTasks
        mov r2, r8
        add r0, r2, r7
        lsl r0, #3
        add r5, r0, r1
        ldrb r1, [r5, #0x10]
        mov r0, r9
        ldr r3, =MonTryLearningNewMoveAfterEvolution |1
        bl @@call
        ldr r3, =Task_EvolutionScene__HookReturn |1
    @@call:
        bx r3

    .pool
.endarea

.org Task_EvolutionScene__HookAddr
.area 0x12, 0xFE
    ldr r3, =Task_EvolutionScene__Hook |1
    bx r3
    .pool
.endarea

.close