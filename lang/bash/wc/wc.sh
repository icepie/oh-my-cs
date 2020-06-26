#!/bin/bash
formart_star=`grep -o 'star' 2701.txt | wc -l` 
echo 'star:' $formart_star

formart_stars=`grep -o 'stars' 2701.txt | wc -l` 
echo 'stars:' $formart_stars

formart_state=`grep -o 'state' 2701.txt | wc -l` 
echo 'state:' $formart_state

formart_states=`grep -o 'states' 2701.txt | wc -l` 
echo 'states:' $formart_states

# 1) state-room 과 같이 하이픈으로 연결된 경우
formart_s=`grep -o '*-*' 2701.txt | wc -l` 
echo 'like "state-room":' $formart_s
# 2) stars. 와 같이 .으로 끝나년 경우.
formart_s=`grep -o '*.' 2701.txt | wc -l` 
echo 'like "stars.":' $formart_s
