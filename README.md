# app-template
Clone this repo to get a solid app

# Fetching the game engine too
The solid game engine is added as a submodule. To get the engine, you can:

git clone --recursive git://github.com/alanhaugen/app-template

If you have already cloned the repo and you don't have the solid folder, fetch it with this command:

git submodule update --init --recursive

## NOTE: Right now this is not added. Download solid and put it in the parent directory

# Import project with QtCreator

You can import the project from QtCreator. File->New File or Project->Git clone OR Import Existing Project->...

# Running program

Building the project should be as simple as running make

make all

Make all will build solid and the app. Both debug and release will be built

The program is found in the bin directory. Set working directory to the folder with the executable app. You can also run the program by typing make run

make run
# chess
