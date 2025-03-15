#!/bin/sh

if [ -z "$1" ] || [ -z "$2" ]
then
    >&2 echo 'Missing argument(s)'
    exit 1
fi

if [ ! -d "$1" ]
then
    >&2 echo 'Directory does not exist'
    exit 1
fi

filesdir="$1"
searchstr="$2"

numfiles=$(grep -rl "$searchstr" "$filesdir" | wc -l)
numlines=$(grep -ra "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $numfiles and the number of matching lines are $numlines"

exit 0
