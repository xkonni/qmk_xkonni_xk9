# xk9

qmk config loosely based on `handwired/6key` and several other keyboards

## features

- 8 keys
- 1 rotary encoder
- VIA support

## installation

- clone to qmk/keyboards/xkonni/xk9
- build with `make xkonni:xk9:default`
- flash with `make xkonni:xk9:default:flash`

- customize with VIA
  - load keymaps/default/via.json

- rotary encoder


## components

- Arduino Pro Micro
- 8 switches
- EC11 rotary encoder
- ssd1306 display
- case from this repository

## Layout

| R/C  | COL1 | COL2 | COL3 |
|------|------|------|------|
| ROW1 |  k00 | k01  | k02  |
| ROW2 |  k03 | k04  | k05  |
| ROW3 |  k02 | k07  | k08  |


## Pin Out

**If you wire the components differently, change these values in `config.h`**

### Arduino Pro Micro

```
PD3 TXD |---------| RAW RAW
PD2 RXI |         | GND GND
GND GND |         | RST RST
GND GND |         | VCC VCC
PD1   2 | Arduino | A3  PF4
PD0   3 |   Pro   | A2  PF5
PD4   4 |  Micro  | A1  PF6
PC6   5 |         | A0  PF7
PD7   6 |         | 15  PB1
PE6   7 |         | 14  PB3
PB4   8 |         | 16  PB2
PB5   9 |---------| 10  PB6
```


### Display

- SSD1306
  - `VCC VCC`
  - `GND GND`
  - `SCL PD0`
  - `SDA PD1`


### EC11 Rotary Encoder

- rotary encoder
  - `PAD_A PF4`
  - `GND   GND`
  - `PAD_B PF5`


### MATRIX

- ROWS
  - `ROW1 PD4`
  - `ROW2 PC6`
  - `ROW3 PD7`

- COLS
  - `COL1 PE6`
  - `COL2 PB4`
  - `COL3 PB5`
