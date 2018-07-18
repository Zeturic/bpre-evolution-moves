.gba
.thumb

.open "test.gba", 0x08000000

.org free_space

.area reservation
    evolution_hook:
        ldr r1, =tasks
        mov r2, r8
        add r0, r2, r7
        lsl r0, r0, #3
        add r5, r0, r1
        ldrb r1, [r5, #0x10]
        mov r0, r9
        ldr r3, =sub_803EA88 |1
        bl @@call
        ldr r3, =evolution_hook_return |1
    @@call:
        bx r3
    .pool
.endarea

.org _evolution_hook_
.area 0x12, 0xFF
    ldr r3, =evolution_hook |1
    bx r3
    .pool
.endarea

.close

.include "functions.s"

.arm
.include "constants.s"