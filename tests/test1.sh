#!/bin/bash

BASEDIR=/tmp/abcd/werf/
TESTDIR=/tmp/abcd/werf/log_link/abc
mkdir -p ${BASEDIR}

function end()
{
    rm -rf ${TESTDIR}
    rm -rf ${BASEDIR}
    exit $1
}

pushd ${BASEDIR}
mkdir log
ln -s log ./log_link
popd
../src/mkdirp ${TESTDIR}
end $?