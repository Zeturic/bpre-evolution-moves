## Evolution Moves

Sun and Moon introduced a feature where Pokémon can learn one or more moves when evolving, regardless of what level it evolves on. For example, Vaporeon will learn Water Gun when it evolves, regardless of whether it evolves on level 1 or level 100, or anywhere in between.

This brings that to Fire Red.

### What do I do before I build this?

If you are using Jambo's learnset hack to allow for moves above `511` to be used in level-up learnsets, ensure `USE_JAMBO_LEARNSET_HACK` isn't commented out in the `defines` section of `config.ini`.

The build script will search for adequate free space, but if you need to insert the code in a particular place, you can tell it where to start looking by modifying `start-at` in `config.ini`. If the given address is acceptable (i.e. is word-aligned and has enough bytes of free space), it will be inserted there.

### How do I build this?

Once everything has been configured, check [here](scripts/makinoa/README.md) for build instructions.

### How do I add evolution moves?

If you wanted, for example, Blastoise to learn Hydro Cannon upon evolving, you would add Hydro Cannon to the beginning of Blastoise's level up moves as a level 0 move. That's it.

PGE doesn't let you set a move to level 0 *unless* you are using Jambo-style learnsets. G3T lets you set a move to level 0, but doesn't support Jambo-style learnsets at all.

In short, if you're using regular-style learnsets, add your evolution moves using G3T. If you're using Jambo-syle learnsets, add your evolution moves using PGE.

### What if I might want to add Jambo's learnset hack later?

If there's any chance whatsoever you'll need/want it later, add the learnset hack now. It'll use more space than not using it, but it's not enough to be worth caring about.