#!/bin/sh

if [ -z "$1"  ] || [ -z "$2" ]
then
    echo 'Missing argument(s)' >&2
    exit 1
fi

writefile="$1"
writestr="$2"


mkdir -p `dirname "$writefile"` && echo "$writestr" >"$writefile" && exit 0 || echo "File could not be created" >&2 && exit 1
