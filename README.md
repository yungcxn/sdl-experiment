# sdl-experiment
This COMPLETELY FROM SCRATCH! C + SDL game aims to be:
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
sudo dnf install SDL2-devel SDL2_mixer-devel
```

## Build & Run

```
./build.sh
```

## Urgent TODOs

- work on input
- work on player
- solve world sprite update

## Notes

- use a fixed color pallet 
- implement hue shifting on sprites
- implement the color table in the res.h header
- transform rgba color arrays into 
- use Input Buffers
- resource handler as hashworld: id to bool
- camera should not need a height
- camera should have a small delay and move like a bezier curve?
- camera should have fine jitter effect on special event
- debug draw collision and damage boxes
- guis vs gui guioverlays (hud, textbox, interactionbox)
- hardcoded font?
- interactive_object like chests
- sensable_area for player to change hostile mob from idle to aggro
- breadcrumbs to let hostile mob move to last one after exiting sensable_area
- move hovered text! this is nice
- normalized move distance vectors
- move acceleration, not instantanious
- darkness in caves manages by dithering!
