#!/bin/bash

BASEDIR=/tmp/abcd/werf/
TESTDIR=${BASEDIR}/log_link/abc/qqq/www
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