#!/bin/bash

for i in scaled slice
do
  for j in clubs diamonds hearts spades
  do
    mv $i/$j/1.png $i/$j/14.png
  done
done
