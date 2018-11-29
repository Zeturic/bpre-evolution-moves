### Evolution Moves

Sun and Moon introduced a feature where Pokémon can learn one or more moves when evolving, regardless of what level it evolves on. For example, Vaporeon will learn Water Gun when it evolves, regardless of whether it evolves on level 1 or level 100.

This brings that to Fire Red.

#### How do I add evolution moves?

If you wanted, for example, Blastoise to learn Hydro Cannon upon evolving, you would add Hydro Cannon to the beginning of Blastoise's level up moves as a level 0 move. That's it.

PGE doesn't let you set a move to level 0 *unless* you are using Jambo-style learnsets. G3T lets you set a move to level 0, but doesn't support Jambo-style learnsets at all.

In short, if you're using regular-style learnsets, add your evolution moves using G3T. If you're using Jambo-syle learnsets, add your evolution moves using PGE.

#### How do I build this?

If the array of moveset data pointers - in a vanilla game, located at `0x0825D7B4` - has been repointed, update the definition of `pokemon_attack_table` in `constants.s`.

If you are using Jambo's learnset hack to allow for moves above `511` to be used in level-up learnsets, ensure `JAMBO_LEARNSETS` isn't commented out in the `defines` section of `config.ini`.

After that, update `free-space` in the `main` section of `config.ini` to where you would like it to start looking for free space.

Once everything has been configured, check [here](scripts/makinoa/README.md) for build instructions.