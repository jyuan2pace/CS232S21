#!/bin/bash
. ./buildcmd.sh
RED='\033[0;31m'
NC='\033[0m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
echo "$cmd"
echo "*******Now start building***************"
cp ../pre_test_get_bits.c test_get_bits.c
output=`$cmd 2<&1`
echo $output

if [[ -z $output ]]; then
   echo -e "${GREEN}*******Your code builds successfully!*************${NC}"
elif [ -f $executable ]; then
   echo -e "${YELLOW}*******Your code builds with warnings!******${NC}"
   echo -e "${YELLOW}**Please fix it or you will lose points!****${NC}"
   exit 0
else
   echo -e "${RED}*******Your code builds with errors!******${NC}"
   echo "*******no test will be done, aborting***************"
   exit -1
fi

