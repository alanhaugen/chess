# Chess

A simple chess game implemented with solid

![Alt Text](https://previews.dropbox.com/p/thumb/AB3ZHZGsiXeAZxwW-Ci77Wpckg4_S7G-d7nUX7HHfKIlIyWSGwMKZK3ozcM86f61FBlpcXeX1AtBxyYFJqRaejHjccnw4v6_y200f5z4AtUYVHhKWfFnqZ84NeNIMm7V_EMgSy9OpzaWIMbWE7yFLdWKckP9MXrOr2KopS06lR8Y09YcdbJ9oKzBRySvXR72oFt7V9LlNOad8TXE2dXRt61pVlGnV3bYBK-cPLy5r33HJWKmyNPb_W9Y_VywU9BVb325p38Uqmhm6yu9LSG114FK_6PH4487GS1JYSmcYMNVpaYs6cE1Rv00BcmBxd5jgH4axhrUxrvNxjtUZFVZ8y28vDIQGpMlaKl4dDDY61I7ig/p.gif)

## Attribution

Cubemaps are used from Emil Persson, aka Humus.
http://www.humus.name

# Instructions

Symbolically link the following directories from Huldra Dropbox

For Unix:

> ln -s ~/Huldra\ Dropbox/Chess/data data

For Windows:

> mklink /D data "..\Huldra Dropbox"\Chess\data

## Instructions for use of the QtCreator (Download from qt.io) qbs build system

Open chess.qbs with QtCreator

Change the run working directory to the following:

> %{sourceDir}/intermediate

Add the following build step before qbs build

For Unix:

> make acp

For Windows, please add /c/Program\ Files/Git/usr/bin to your PATH and use mingw make:

> mingw32-make.exe acp

For this build step, regardless of platform, change the build working directory to the following:

> %{sourceDir}
