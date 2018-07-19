#include "defines.h"

u16 moves_during_evolution(struct pokemon* pokemon, u8 unk) {
    u16 species = pokemon_getattr(pokemon, REQ_SPECIES, 0);
    u8 level = pokemon_getattr(pokemon, REQ_LEVEL, 0);

    struct learnset_move* learnset_move = pokemon_attack_table[species] + learnset_move_index;

    if (!unk) {
        u8 req_level = learnset_move->level;
        if (req_level && req_level != level) return 0;

        MOVESET_PAD;
    }

    learnset_move_index = 0;
    learnset_move = pokemon_attack_table[species] + learnset_move_index;

    for (; *((u16*) learnset_move) != 0xFFFF; ++learnset_move, ++learnset_move_index) {
        u8 req_level = learnset_move->level;

        if (!req_level || req_level == level) {
            MOVESET_PAD;
        }
    }

    return 0;
}