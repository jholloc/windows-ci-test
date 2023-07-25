#!/bin/sh

mkdir lib 2>/dev/null
mkdir include 2>/dev/null

# Check if the platform is Windows
if [ "$OS" = "Windows_NT" ]
then
	# install CMake or GNU make compilation (make by default)
	if [ $# -ge 1 ] && [ ${1,,} == "cmake" ]
	then
		# libxdr.a is generated by CMake command
		cp -af portablexdr-4.9.1/libxdr.a lib
	else
		# libportablexdr.? are generated by GNU make command
		cp -af portablexdr-4.9.1/.libs/libportablexdr.a lib
		cp -af portablexdr-4.9.1/.libs/libportablexdr.la lib
		cp -af portablexdr-4.9.1/.libs/libportablexdr.dll.a lib
		cp -af portablexdr-4.9.1/.libs/libportablexdr-0.dll lib
	fi
else
	cp -af portablexdr-4.9.1/.libs/libportablexdr.a lib
	cp -af portablexdr-4.9.1/.libs/libportablexdr.la lib
	cp -af portablexdr-4.9.1/.libs/libportablexdr.so lib
fi

mkdir include/rpc 2>/dev/null

# Check if the platform is Windows
if [ "$OS" = "Windows_NT" ]
then
	cp -raf portablexdr-4.9.1/rpc include/rpc/
	cp -raf portablexdr-4.9.1/config.h include/rpc/rpc
else
	cp -raf portablexdr-4.9.1/rpc include/rpc/
	cp -raf portablexdr-4.9.1/config.h include/rpc/rpc
fi