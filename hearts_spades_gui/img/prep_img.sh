#!/bin/bash

INDIR=$(ls -d Classic/*/)
#rename all files in dir tree
for i in $INDIR
do
	rename 's/[cdsh]0?(.{1,2}\.png)$/$1/' $i*
done

#IMG=$(ls Classic/*/*.png)
#
#for i in $IMG
#do
#	echo $i
#	#convert -scale %15 +repage $IN $OUT
#done
