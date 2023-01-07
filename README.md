# Chess

Symbolically link the following directories from Huldra Dropbox

For Unix:

> ln -s ~/Huldra\ Dropbox/Chess/data data

For Windows:

> mklink /D data "..\Huldra Dropbox"\Chess\data

If you use the qbs system, please add the following build step before qbs build

For Unix:

> make acp

For Windows, please add /c/Program\ Files/Git/usr/bin to your PATH and use mingw make

> mingw32-make.exe acp



