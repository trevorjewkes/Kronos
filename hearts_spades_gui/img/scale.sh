#!/bin/bash

INFILES=$(ls Cards)

for f in $INFILES
do
	echo "scaling image $f by %10 ..."
	convert -scale %15 +repage Cards/$f scaled/$f  
done

#for i in back.png blank.png
#do
#  convert -scale %15 +repage Cards/$i scaled/$i  
#done
