# Makefile for SeriesTracker Files

# A few variables

CC=g++
CPPSTD=c++17
ARGS=-lncurses -lsqlite3

EXE_DIR=out
EXE=series_tracker

EXE_PATH=${EXE_DIR}/${EXE}

#INCLUDE_PATH=libs/
INCLUDE_PATH := $(shell find libs -type d | awk '{print "-I" $$0}')

#SRC_FILES := ${wildcard *.cpp}
SRC_FILES := $(shell find . -name "*.cpp")

${EXE_PATH}: ${SRC_FILES}
	@mkdir -p ${EXE_DIR}
	${CC} -g  ${INCLUDE_PATH} $^ -o $@ ${ARGS} -std=${CPPSTD}

all: ${EXE_PATH}

install: ${EXE_PATH}
	cp ${EXE_PATH} /usr/local/bin

clean:
	@rm -f ${EXE_PATH}
