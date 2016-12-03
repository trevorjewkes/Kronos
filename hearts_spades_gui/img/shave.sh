#!/bin/bash

INFILES=$(ls Cards)

for f in $INFILES
do
	echo "croping image $f ..."
	convert -gravity East -chop 75%x0 +repage scaled/$f slice/$f  
done

#for i in back.png blank.png
#do
#	convert -gravity East -chop 75%x0 +repage scaled/$i slice/$i  
#done
