#!/bin/bash

INFILES=$(ls Classic)

for f in $INFILES
do
	echo "croping image $f ..."
	convert -gravity East -chop 75%x0 +repage Scaled/$f Cropped/$f  
done
