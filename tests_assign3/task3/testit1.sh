#!/bin/bash
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
NC='\033[0m'
. ./buildcmd1.sh
echo -e "${GREEN}********Starting Valgrind Test on ${executable}***************${NC}"
	valgrind --leak-check=full --error-exitcode=1 ./${executable} > vrep 2>&1 
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

