#!/bin/bash

TESTDIR=/tmp/abcd/werf
function end()
{
    rm -rf ${TESTDIR}
    exit $1
}
../src/mkdirp ${TESTDIR}
end $?