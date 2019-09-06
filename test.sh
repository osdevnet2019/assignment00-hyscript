#replace awk or fmt part with 'lowercase' or 'makewords' program of your own to test
#cat $1 | awk '{print tolower($0)}' | fmt -1 | uniq | sort| sed 's/\.//g' | comm -13 ../dictionary -
