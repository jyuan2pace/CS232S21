#!/bin/bash
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
NC='\033[0m'
. ./param.sh
cd playpen
noredu=1
abort=0
for file in *; do
     for expected_file in $expected; do
     	if [ $file == $expected_file ];then
	    break;		
	fi
     done
     if [ $file != $expected_file ]; then 
         echo -e "${YELLOW}$file should not exist! consider deleting it!${NC}"
         noredu=0
     fi
done

for expected_file in $expected; do
    for file in *; do
	if [ $file == $expected_file ]; then
	    break;
	fi
    done
    if [ $file != $expected_file ]; then
        echo -e "${RED}$expected_file is nowhere to be found${NC}"
	abort=1
	break;
    fi
done

  
if [ $abort == "1" ]; then
    echo -e "${RED}***********failed sanity test***********************${NC}"
    cd ..
    exit -1
elif [ $noredu == "0" ]; then
    echo -e "${YELLOW}***********failed sanity test***********************${NC}"
    cd ..
    exit 0
else
    echo -e "${GREEN}***********passed sanity test***********************${NC}"
    cd ..
    exit 0
fi

