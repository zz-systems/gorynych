#!/usr/bin/env bash

cd "${TRAVIS_BUILD_DIR}/${BUILD_DIR}"

if [ ${DOC_BUILDER} = 1 ] &&  [ ${TRAVIS_BRANCH} = "master" ]; then
    cmake --build . --config ${BUILD_TYPE} --target zacc.documentation
fi