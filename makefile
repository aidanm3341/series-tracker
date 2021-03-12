# Makefile for SeriesTracker Files

# A few variables

CC=g++
CPPSTD=c++20
ARGS=-lncurses

EXE_DIR=out
EXE=series_tracker

EXE_PATH=${EXE_DIR}/${EXE}

INCLUDE_PATH=libs/

#SRC_FILES := ${wildcard *.cpp}
SRC_FILES := $(shell find . -name "*.cpp")

${EXE_PATH}: ${SRC_FILES}
	@mkdir -p ${EXE_DIR}
	${CC} -g  -I${INCLUDE_PATH} $^ -o $@ ${ARGS} -std=${CPPSTD}

all: ${EXE_PATH}

clean:
	@rm -f ${EXE_PATH}
