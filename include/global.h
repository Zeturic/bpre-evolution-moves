#pragma once

#include "gba/gba.h"
#include "constants/global.h"

#define NAKED __attribute__((naked))

#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")

struct Pokemon;
