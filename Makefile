#############################################################################
# Executable name
#############################################################################

TARGET = app

#############################################################################
# Libraries 
#############################################################################

LIBS = \
    -lcore

#############################################################################
# Source files
#############################################################################

SOURCES = \
    source/main.cpp

#############################################################################
# Assets (This will soon be automated)
#############################################################################

TEXT_FILES = \
    intermediate/project.json \
    intermediate/simple.vert \
    intermediate/simple.frag

IMAGE_FILES = \
    intermediate/logo_inv_jpg.jpg

#############################################################################
# Setup build platform rules 
#############################################################################

SOLIDCORE = ../solid

include $(SOLIDCORE)/Makefile.rules

#############################################################################
# Build as executable
#############################################################################

debug: bin/$(OUTPUT_DIR)/$(TARGET)$(EXE)
release: bin/$(OUTPUT_DIR)/$(TARGET)$(EXE)

bin/$(OUTPUT_DIR)/$(TARGET)$(EXE): nullaudio nullscript portaudioaudio stdfilesystem nullfilesystem nullphysics nullrenderer gles2renderer solid

