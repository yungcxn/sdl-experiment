# sdl-experiment
This C+SDL game aims to be:
- minimal
- performant
- modular in regards to graphics libraries: should be easy to exchange
- no bloat
- run on wayland (changeable)
- still multiplatform 

## Install

### Arch
```
sudo pacman -S sdl2 sdl2_mixer gcc make
```

### Fedora
```
sudo dnf install SDL2 SDL2_mixer 
```

## Urgent TODOs

- initialise and destroy functions for complex structs