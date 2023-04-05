#############################################################################
# Executable name
#############################################################################

TARGET = Chess

#############################################################################
# Libraries 
#############################################################################

LIBS = \
    -lcore

#############################################################################
# Source files
#############################################################################

SOURCES = \
    $(wildcard source/*.cpp)

#############################################################################
# Setup Asset Conditioning Pipeline
#############################################################################

PROJECT_FILES = $(SOURCES) data/project.json 

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

ifneq ($(COMPILE_PLATFORM),webasm)
bin/$(OUTPUT_DIR)/$(TARGET)$(EXE): nullaudio nullscript portaudioaudio stdfilesystem nullfilesystem nullphysics nullrenderer gles2renderer solid
else
bin/$(OUTPUT_DIR)/$(TARGET)$(EXE): nullaudio nullscript stdfilesystem nullfilesystem nullphysics nullrenderer gles2renderer solid
endif
