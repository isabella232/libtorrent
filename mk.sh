#!/bin/bash

set -e

if [ -z ${BOOST_ROOT+x} ];
then
    echo "BOOST_ROOT" must be set
    exit 1
fi

LIBTORRENT_DIR=${LIBTORRENT_DIR:=`pwd`}

BUILD_VARIANT=release

usage ()
{
    echo "usage: ${0} [linux] [osx] [windows] [zip]"
}

if [ $# = 0 ]
then
    usage
    exit 1
fi

while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
	linux)
	    LINUX=true
	    ;;
	osx)
	    OSX=true
	    ;;
	windows)
	    WINDOWS=true
	    ;;
	zip)
	    ZIP=true
	    ;;
	*)
	    echo "Unkown arg: " "$1"
	    usage
	    exit 1
	    ;;
    esac
    shift
done

if [[ "$LINUX" != "true" ]] && \
   [[ "$OSX" != "true" ]] && \
   [[ "$WINDOWS" != "true" ]] && \
   [[ "$ZIP" != "true" ]];
then
    usage
    exit 1
fi

mkdir -p builds

if [[ $LINUX = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=linux --address-model=64 --build-dir=builds/linux64
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=linux --address-model=32 --build-dir=builds/linux32
fi

if [[ $OSX = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=darwin --address-model=64 --build-dir=builds/osx64
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=darwin --address-model=32 --build-dir=builds/osx32
fi

if [[ $WINDOWS = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=windows --address-model=64 --build-dir=builds/win64
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=windows --address-model=32 --build-dir=builds/win32
fi

if [[ $ZIP = true ]]
then
    # forces us to update everything, and remove things that no longer exist
    rm -rf builds/lib/linux64
    rm -rf builds/lib/linux32
    rm -rf builds/lib/osx64
    rm -rf builds/lib/osx32
    rm -rf builds/lib/windows64
    rm -rf builds/lib/windows32
    rm -rf builds/include

    mkdir -p builds/include
    mkdir -p builds/lib
    
    mkdir -p builds/lib/linux64
    mkdir -p builds/lib/linux32
    mkdir -p builds/lib/osx64
    mkdir -p builds/lib/osx32
    mkdir -p builds/lib/win64
    mkdir -p builds/lib/win32
    
    cp `find builds/linux64 -iname "*.a"` builds/lib/linux64
    cp `find builds/linux64 -iname "libtorrent.so*"` builds/lib/osx64
    cp `find builds/linux32 -iname "*.a"` builds/lib/linux32
    cp `find builds/linux32 -iname "libtorrent.so*"` builds/lib/osx64

    cp `find builds/osx64 -iname "*.a"` builds/lib/osx64
    cp `find builds/osx64 -iname "libtorrent.dylib*"` builds/lib/osx64
    cp `find builds/osx32 -iname "*.a"` builds/lib/osx32
    cp `find builds/osx32 -iname "libtorrent.dylib*"` builds/lib/osx64

    cp `find builds/win64 -iname "*.a"` builds/lib/win64
    cp `find builds/win64 -iname "*.dll*"` builds/lib/win64
    cp `find builds/win32 -iname "*.a"` builds/lib/win32
    cp `find builds/win32 -iname "*.dll*"` builds/lib/win32    
    
    cp -R $LIBTORRENT_DIR/include/libtorrent/* builds/include
    ( cd builds ; zip builds.zip include lib )
fi
