#!/bin/sh
if [ $# -ne 1 ];then
	echo "Invalid params"
fi

bin="ipporttable.cpp"
bin_1="myipporttable.cpp"
bin_44="oipporttable.cpp"

lib="ipporttable.h"
lib_1="myipporttable.h"
lib_44="oipporttable.h"

ACTION=$1
case $ACTION in
	o)
		mv $bin $bin_44
		mv $bin_1 $bin
		mv $lib $lib_44
		mv $lib_1 $lib
		;;
	m)
		mv $bin $bin_1
		mv $bin_44 $bin
		mv $lib $lib_1
		mv $lib_44 $lib
		;;
	*)
		;;
esac

