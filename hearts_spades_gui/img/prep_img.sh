#!/bin/bash

#INDIR=$(ls -d Cards/*/)
##rename all files in Cards folder
#for i in $INDIR
#do
#	rename 's/[cdsh]0?(.{1,2}\.png)$/$1/' $i*
#done

#echo "scale images to %15..."
#for i in clubs spades diamonds hearts
#do
#	for j in $(ls Cards/$i) #get the card name
#	do
#		echo "Scaling Cards/$i/$j to scaled/$i/$j"
#		convert -scale %15 +repage Cards/$i/$j scaled/$i/$j
#	done
#done

echo "cropping scaled cards..."
for i in clubs spades diamonds hearts
do
	for j in $(ls scaled/$i) #get the card name
	do
		echo "cropping scaled/$i/$j to scaled/$i/$j"
		convert -gravity East -chop 75%x0 +repage scaled/$i/$j slice/$i/$j  
	done
done
