# Makefile for SeriesTracker Files

# A few variables

CC=g++
LIBS=-lncurses

EXE_DIR=.
EXE=series_tracker

EXE_PATH=${EXE_DIR}/${EXE}

#SRC_FILES := ${wildcard *.cpp}
SRC_FILES := $(shell find . -name "*.cpp")

${EXE_PATH}: ${SRC_FILES}
	@mkdir -p ${EXE_DIR}
	${CC} -g $^ -o $@ ${LIBS}

all: ${EXE_PATH}

clean:
	@rm -f ${EXE_PATH}
