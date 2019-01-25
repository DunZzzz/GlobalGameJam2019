#
# Makefile
# Copyright (C) 2018 emilien <emilien@emilien-pc>
#
# Distributed under terms of the MIT license.
#

BUILD_DIR = ./build/

FLAGS_DEBUG = -DCMAKE_BUILD_TYPE=DEBUG --debug-output
FLAGS_RELEASE = -DCMAKE_BUILD_TYPE=RELEASE

all: setup
	cd $(BUILD_DIR) && cmake .. && cmake --build .

debug: setup
	cd $(BUILD_DIR) && cmake .. $(FLAGS_DEBUG) && cmake --build .

release: setup
	cd $(BUILD_DIR) && conan install .. && cmake .. $(FLAGS_RELEASE) -G "Unix Makefiles" && cmake --build .

rebuild: setup
	cd $(BUILD_DIR) && conan install .. --build

setup:
	if [ ! -d $(BUILD_DIR) ]; \
	then mkdir $(BUILD_DIR); \
	fi;
	
clean:
	if [ -d $(BUILD_DIR) ]; \
	then rm -rf $(BUILD_DIR); \
	fi;

re: clean all
