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
    timeout 2s ./${executable} <$input >output${input:5}.yours	
    if [ 0 == $? ]; then
    	diff output${input:5} output${input:5}.yours 
    else
	timeout=1
    fi 
    if [[ $timeout == 1 || 0 != $? ]]; then
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
echo -e "${GREEN}********Starting Valgrind Test on ${executable}***************${NC}"
	valgrind --leak-check=full --error-exitcode=1 ./${executable} <input01 > vrep 2>&1 
	if [ 0 != $? ]; then
		echo -e "${YELLOW} failed valgrind test! ${NC}"
		if grep -q "no leaks are possible" vrep; then	
			echo -e "${YELLOW} no leaks, but there are other memory violations! this could cause point losses because your implementation may have failed to follow certain requirements ${NC}"
		else
			echo -e "${RED} There are leaks! ${NC}"
		fi
	else
		
		echo -e "${GREEN}*****Passed Valgrind Test!****${NC}"
	fi

