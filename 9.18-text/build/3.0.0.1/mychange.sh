#!/bin/sh
if [ $# -ne 1 ];then
	echo "Invalid params"
fi

bin="bin/*"
root_bin="/opt/BDFZ/RAV/bin"

lib="lib/*"
root_lib="/opt/BDFZ/RAV/lib"

ACTION=$1
case $ACTION in
	bin)
		sudo cp $bin $root_bin
		;;
	lib)
		sudo cp $lib $root_lib
		;;
	*)
		;;
esac

