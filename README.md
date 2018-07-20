### Evolution Moves

Sun and Moon introduced a feature where Pokémon can learn one or moves when evolving, regardless of what level it evolves on. For example, Vaporeon will learn Water Gun when it evolves, regardless of whether it evolves on level 1 or level 100.

This brings that to Fire Red.

### How do I add evolution moves?

If you wanted, for example, Blastoise to learn Hydro Cannon upon evolving, you would add Hydro Cannon to the beginning of Blastoise's level up moves as a level 0 move. That's it.

Note that PGE doesn't support setting a move to level 0. You can do it with G3T's Pokémon Editor, however.

### How do I build this?

If the array of moveset data pointers - in a vanilla game, located at `0x0825D7B4` - has been repointed, update the definition of `pokemon_attack_table` in `constants.s`.

If you are using Jambo's learnset hack to allow for moves above `511` to be used in level-up learnsets, uncomment out the definition of `JAMBO_LEARNSETS` in `src/defines.h`.

After that, update `free-space` in `config.ini` to where you would like it to start looking for free space.

Put your ROM in the project root directory and name it `rom.gba`.

Run `python scripts/makinoa`. Your output will be in `test.gba`; `rom.gba` won't be modified.

### A word of caution

At this point, I wouldn't use this other than to experiment with it. It needs to be more exhaustively tested (especially with Jambo-style learnsets) before I'd feel comfortable recommending you use this in your hack.

There appears to be an issue where a Pokemon won't learn regular moves it's supposed to learn on that level if it learns an evolution move. Further hacking is necessary. **Edit**: Seems to have been fixed with an edit.