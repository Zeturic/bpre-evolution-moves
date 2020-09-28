## Evolution Moves

Sun and Moon introduced a feature where Pokémon can learn one or more moves when evolving, regardless of what level it evolves on. For example, Vaporeon will learn Water Gun when it evolves, regardless of whether it evolves on level 1 or level 100, or anywhere in between.

This brings that to Fire Red.

### Build Instructions

See [here](https://gist.github.com/Zeturic/db1611cc7b17c3140f9b9af32e1b596b) for the prequisites and help in installing them.

#### Cloning the repo

Open your terminal to whatever folder you want to download this repo into. Then, do the following to download the repo and build the included tools:

```shell
$ git clone https://github.com/Zeturic/bpre-evolution-moves.git
$ cd bpre-evolution-moves
```

#### Adding your ROM

Copy your ROM to this directory and rename it `rom.gba`.

#### Configuration

Open `config.mk` in a text editor to set some compile-time configuration.

The build system is smart enough to find enough free space on its own, but if you want it to be inserted at a particular address, you can specify it by updating the definition of `START_AT`.

If the given address is acceptable (i.e. is word-aligned and has enough bytes of free space), it will be inserted there. Otherwise, it will just use `START_AT` to determine where in the ROM it should start looking for free space.

If you are using Jambo's learnset hack to allow for moves above `511` to be used in level-up learnsets, set `USE_JAMBO_LEARNSET_HACK` to `1`; otherwise, keep it at `0`.

### Usage Instructions

If you wanted, for example, Blastoise to learn Hydro Cannon upon evolving, you would add Hydro Cannon to the beginning of Blastoise's level up moves as a level 0 move. That's it.

PGE doesn't let you set a move to level 0 *unless* you are using Jambo-style learnsets. G3T lets you set a move to level 0, but doesn't support Jambo-style learnsets at all.

In short, if you're using regular-style learnsets, add your evolution moves using G3T. If you're using Jambo-syle learnsets, add your evolution moves using PGE.

### Credits

The project structure and some of the build tools are from [pokeemerald](https://github.com/pret/pokeemerald).
