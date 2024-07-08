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

## Build & Run

```
./build.sh
```

## Urgent TODOs

- initialise and destroy functions for complex structs

## Notes

- Use a fixed color pallet 
- Implement hue shifting on sprites
- Implement the color table in the res.h header
- Transform rgba color arrays into 
- Use Input Buffers
- Resource handler as hashmap: id to bool
- Camera should not need a height
- Camera should have a small delay and move like a bezier curve?
- debug draw collision and damage boxes
- guis vs gui guioverlays (hud, textbox, interactionbox)
- hardcoded font?
- interactive_object like chests