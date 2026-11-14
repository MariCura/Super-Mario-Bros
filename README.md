# Super Mario Bros XYZ — Proyecto 1, Parte 2

Programación II (CS6003) — UTEC — Prof. Wilder Nina Choquehuayta

Juego en consola en C++ con secuencias de escape ANSI. Mundo de 50 x 240 celdas
con una ventana visible de 50 x 90 que sigue a Mario.

---

## Cómo compilar

**CLion** (Windows o Linux): abrir la carpeta y darle a Run. El `CMakeLists.txt`
ya está listo.

**Consola Linux / macOS:**
```
g++ -std=c++17 -o mario main.cpp Colors.cpp Sprite.cpp Entity.cpp Player.cpp Goomba.cpp Block.cpp World.cpp Camera.cpp Game.cpp
./mario
```

**Consola Windows (MinGW):**
```
g++ -std=c++17 -o mario.exe main.cpp Colors.cpp Sprite.cpp Entity.cpp Player.cpp Goomba.cpp Block.cpp World.cpp Camera.cpp Game.cpp
mario.exe
```

### Portabilidad (Windows y Linux)

Lo único que cambia entre sistemas operativos es la función `habilitarAnsi()` de
`Colors.cpp`, y está encerrada en un `#ifdef _WIN32`:

- En **Windows** le pide a la consola que interprete las secuencias ANSI
  (`SetConsoleMode` con `ENABLE_VIRTUAL_TERMINAL_PROCESSING`). Sin eso se verían
  los códigos `[41m` en texto plano.
- En **Linux y macOS** no hace nada porque ya vienen activadas.

Además se pinta con **color de fondo + espacios** (`\033[41m` + `"  "`) en vez
del carácter de bloque `█` del proyecto 1. El espacio es ASCII puro, así que se
ve igual en cualquier consola; `█` es UTF-8 y se rompe en la consola de Windows.

Si la escena se ve muy ancha o muy angosta, cambia `ANCHO_CELDA` en `Colors.h`
(2 por defecto; con 3 se ve como el proyecto 1).

---

## Comandos

| Comando | Qué hace |
|---|---|
| `right` / `left` | mueve 12 columnas |
| `up` | salta 16 filas y cae |
| `up-right` / `up-left` | mueve 12 columnas y salta 16 filas |
| `save` | guarda la partida en `partida.txt` |
| `load` | carga `partida.txt` |
| `exit` | sale |

Se pueden escribir varios movimientos en una línea: `right right right`.
Si el movimiento sale del mundo se imprime `invalid operation` y el juego sigue.

---

## Las 8 clases

| Clase | Archivos | Para qué |
|---|---|---|
| `Sprite` | `Sprite.h/.cpp` | Un dibujo: matriz de índices + paleta |
| `Entity` | `Entity.h/.cpp` | Clase **abstracta** base de todo lo que se dibuja |
| `Player` | `Player.h/.cpp` | Mario: se mueve, salta, cuenta monedas |
| `Goomba` | `Goomba.h/.cpp` | Enemigo estático; al tocarlo se acaba el juego |
| `Block` | `Block.h/.cpp` | Signo, madera, arbusto y tubería |
| `World` | `World.h/.cpp` | Matriz 50 x 240 + lista de entidades |
| `Camera` | `Camera.h/.cpp` | Calcula el offset y pinta las 90 columnas visibles |
| `Game` | `Game.h/.cpp` | Dueño de todo: bucle, comandos, `save` y `load` |

`Colors.h/.cpp` **no es una clase**: es el módulo de constantes (enum `Color`,
sprites y paletas), igual que el `colors.cpp` del proyecto 1.

---

## Dónde está cada función que pide el enunciado

| Función del enunciado | Clase y método |
|---|---|
| `create_world()` | `World::create_world()` |
| `draw_world()` | `World::draw_world()` |
| `draw_scene()` | `Camera::draw_scene(const World&)` |
| `draw_player()` | `Player::draw(World&)`, heredado de `Entity::draw` |
| `move_player(option)` | `Player::move_player(string, int, int)` |
| `collect_coins(option)` | `World::collect_coins(Player&)` → llama a `Entity::onTouch` |
| `save()` | `Game::save(string)` |
| `load()` | `Game::load(string)` |

## Dónde están los requisitos de POO

| Requisito | Dónde |
|---|---|
| **Herencia** | `Entity` → `Player`, `Goomba`, `Block` |
| **Polimorfismo** | `Entity::onTouch` es virtual pura; `Entity::draw` es virtual y `Block` la redefine. `World::collect_coins` llama a `onTouch` sin saber qué clase es |
| **Composición** | `Entity` ◆ `Sprite`; `Game` ◆ `World`, `Camera` y las entidades (las crea y las borra) |
| **Agregación** | `World` ◇ `Entity`: solo guarda punteros para dibujarlas, no las destruye |
| **Memoria dinámica** | `Color** grid` (50 x 240) en `World`, `Entity** entidades` en `World` y `Game`, `int** pixeles` y `Color* paleta` en `Sprite`. Todo se libera en los destructores |
| **Manejo de archivos** | `Game::save` con `ofstream`, `Game::load` con `ifstream` |

---

## La cámara

```
limite = ANCHO_ESCENA - anchoMario - MARGEN = 90 - 12 - 42 = 36
maximo = COLS_MUNDO   - ANCHO_ESCENA        = 240 - 90     = 150

offset = colMario - limite
si offset < 0      -> offset = 0        (inicio del mapa)
si offset > maximo -> offset = maximo   (final: la cámara se congela)
```

Con eso siempre quedan 42 celdas libres a la derecha de Mario. Comprobado
contra las figuras del enunciado:

| Figura | Columna de Mario | offset | Ventana | Libre a la derecha |
|---|---|---|---|---|
| 2 (inicio) | 24 | 0 | 0–89 | 54 |
| 3 | 36 | 0 | 0–89 | 42 |
| 5 | 48 | 12 | 12–101 | 42 |
| 6 (final) | 228 | 150 | 150–239 | 0 |

---

## Escenario

El piso ocupa las filas 44 a 49, así que todo lo que va en el suelo termina
justo en la fila 44.

| Elemento | Cantidad | Posiciones (fila, columna) |
|---|---|---|
| Arbustos (7 x 8) | 3 | (37, 40) (37, 100) (37, 180) |
| Tubería (12 x 14) | 1 | (32, 150) |
| Bloques de madera (9 x 9) | 3 | (10, 108) (10, 132) (10, 188) |
| Bloques de signo (9 x 9) | 3 | (10, 36) (10, 120) (10, 200) |
| Goomba (16 x 16) | 1 | (28, 224) |
| Mario (16 x 12) | 1 | (28, 24) al iniciar |

El goomba va al final del mapa. Como Mario avanza de 12 en 12 columnas y el
goomba mide 16 de ancho, un goomba en medio del recorrido sería un muro
imposible de pasar. Puesto al final, Mario puede recorrer el mundo completo y
recoger las 3 monedas; la última posición segura es la columna 204.

Para sacar las 3 monedas: `up-right`, luego 7 `right`, `up`, 6 `right`, `up`.

---

## Qué cambió respecto al proyecto 1

| Proyecto 1 | Parte 2 |
|---|---|
| `draw_player`, `draw_goomba`, `draw_tree`, `draw_madera`, `draw_signo`, `draw_coin` (6 dobles for iguales) | un solo `Entity::pintarSprite` |
| Globales `papita`, `coins`, `bl_check[3]`, `blrow[3]`, `blcol[3]` | atributos dentro de `World`, `Player` y `Block` |
| `touch()`, `Over()` | `Entity::collides` + `onTouch` polimórfico |
| `COLS = 120`, todo visible | `COLS = 240`, ventana de 90 con `Camera` |
| `if (colorIndex != 0)` repetido en cada función | el índice 0 de cada paleta es `Color::NONE` y `World::paint` lo ignora |
| movimiento inválido = fin del juego | movimiento inválido = `invalid operation` y el juego sigue |
| todo en `supermario.h` | 8 clases con su `.h` y su `.cpp` |

---

## Comprobado

- Compila sin warnings con `g++ -std=c++17 -Wall -Wextra`
- Sin fugas de memoria: valgrind reporta 293 reservas y 293 liberaciones
- Las 3 monedas se pueden recoger, el goomba termina el juego, `save` y `load`
  recuperan el estado
