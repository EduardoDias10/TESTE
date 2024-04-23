#!/bin/sh

output=0

echo -en "\033[33;1m"

for test in "$@"
do
    if [ -x "${test}" ]
    then
        echo -e "\033[33;1mMEMTEST: ${test}"
        if valgrind --leak-check=full --error-exitcode=1 -s "${test}" --success >out 2>&1
        then
            echo -e "\033[32;1mPASED memtest ${test}\033[0m"
        else
            echo -e "\033[31;1mFAILED memtest ${test}\033[0m"
            output=1
        fi
        cat out | sed -n -e "s/==[^=]*== //" -e "/MEMTEST:/p;/LEAK SUMMARY/,/ERROR SUMMARY/p"
    fi
done

echo -en "\033[0m"

exit ${output}
