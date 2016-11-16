#!/bin/bash

INFILES=$(ls Classic)

for f in $INFILES
do
	echo "scaling image $f by %10 ..."
	convert -scale %15 +repage Classic/$f Scaled/$f  
done
