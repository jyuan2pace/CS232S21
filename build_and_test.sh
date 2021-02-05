#!/bin/bash
#$0 is labdir
labdir=$1
curdir=`pwd` #if you are testing lab2, curdir=CS232 and labdir=lab2
cd "tests_$labdir"
for taskdir in *; do
    echo "***********now testing $taskdir***************************"
    cd "$curdir/tests_$labdir/$taskdir"
    if [ ! -f "buildit.sh" ]; then
	echo "no tests. $taskdir is to be manually graded"
    else
	mkdir playpen	
	cp -r $curdir/$labdir/$taskdir/* ./playpen
	rm ./playpen/input* >/dev/null 2>&1
	rm ./playpen/output* >/dev/null 2>&1
	chmod 755 sanity_check.sh
	./sanity_check.sh
	if [ 0 == $? ]; then	
	    cp -r ./*.sh input* output* ./playpen
            cd ./playpen
	    chmod 755 buildit.sh
	    chmod 755 testit.sh
	    ./buildit.sh
	    if [ 0 == $? ]; then
	        ./testit.sh
	    fi
	    cd ..
	fi
	rm -fr ./playpen
    fi
    echo "***********DONE testing $taskdir***************************"
done
