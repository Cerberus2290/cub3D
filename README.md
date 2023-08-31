<h1 align="center">✋ BEWARE ✋</h1>

## If you are a 42 Student, do not copy/paste this project, it will be considered cheating and you will be grated -42.

# 42 Wolfsburg Cursus
## cub3D
## My first RayCaster with miniLibX

## Inspired by the world-famous Wolfenstein 3D. </br>Use raycasting to create a dynamic view inside a maze. </br> This was a group project. A big thank you to my teammate [Andrei Putiev](https://github.com/Anderscarnegie).

# Contents

1. [Goals](#goals)
2. [Mandatory Part](#manda)
3. [Bonus](#bonus)

# <a name="goals">Goals</a>

| Goals | ![Logo_Monolith_small](https://user-images.githubusercontent.com/120580537/209333599-dc44418d-8ee7-42b6-8a4a-7ff328778d87.png) |
| ----- | ----- |
* This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
* As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
* To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
* With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

<p align="center">
    <img src="https://github.com/Cerberus2290/cub3D/assets/120580537/8e97011b-fc95-4ef5-937a-ac408d10e7f8" />
</p>
    
| Here is the original -->| [Wolfenstein 3D](http://users.atw.hu/wolf3d/) |

# <a name="manda">Mandatory Part</a>

| Mandatory Part | ![Logo_Monolith_small](https://user-images.githubusercontent.com/120580537/209333599-dc44418d-8ee7-42b6-8a4a-7ff328778d87.png) |
| ----- | ----- |
| Program name | cub3D |
| Turn in files | All your files |
| Makefile | all, clean, fclean, re, bonus |
| Arguments | a map in format *.cub |
| External functs | open, close, read, write,</br>printf, malloc, free, perror</br>strerror, exit</br>All functions of the math library (-lm man man 3 math)</br>All functions of the MinilibX |
| Libft authorized | Yes |
| Description | You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier. |

The constraints are as follows:

* You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.

* The management of your window must remain smooth: changing to another win- dow, minimizing, etc.

* Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).

* Your program must be able to set the floor and ceiling colors to two different ones.

* The program displays the image in a window and respects the following rules:

    * The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
    * The W, A, S, and D keys must allow you to move the point of view through the maze.
    * Pressing ESC must close the window and quit the program cleanly.
    * Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
    * The use of images of the minilibX is strongly recommended.

* Your program must take as a first argument a scene description file with the .cub extension.

    * The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.</br>This is a simple valid map:
    ```
    111111
    100101
    101001
    1100N1
    111111
    ```
    * The map must be closed/surrounded by walls, if not the program must return an error.
    * Except for the map content, each type of element can be separated by one or more empty line(s).
    * Except for the map content which always has to be the last, each type of element can be set in any order in the file.
    * Except for the map, each type of information from an element can be separated by one or more space(s).
    * The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.