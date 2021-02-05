#!/bin/bash
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
NC='\033[0m'
. ./buildcmd.sh
total=0
fail=0
for input in input*; do
    total=$(($total+1))
    timeout 2s ./${executable} 
    if [ 0 != $? ]; then
	    echo -e "${RED}failed test [$input] ${NC}"
            fail=$(($fail+1))
    else
	    echo "passed test [$input]"
    fi
done
if [ 0 == $fail ]; then
   echo -e "${GREEN}********wow, all tests passed! good job***************${NC}"
else
   echo -e "${RED}********"$fail out of $total" tests failed **********${NC}"
fi
