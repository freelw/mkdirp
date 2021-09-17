#!/bin/bash

TESTDIR=/tmp/abcd/werf
function end()
{
    rm -rf ${TESTDIR}
    exit $1
}
mkdir -p ${TESTDIR}
../src/mkdirp ${TESTDIR}
end $?