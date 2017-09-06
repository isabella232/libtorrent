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
    echo "usage: ${0} [linux] [macosx] [windows] [zip]"
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
	macosx)
	    MACOSX=true
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
   [[ "$MACOSX" != "true" ]] && \
   [[ "$WINDOWS" != "true" ]] && \
   [[ "$ZIP" != "true" ]];
then
    usage
    exit 1
fi

mkdir -p builds

if [[ $LINUX = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=linux --address-model=64 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/linux64/lib --includedir=builds/include link=static
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=linux --address-model=32 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/linux32/lib --includedir=builds/include link=static
fi

if [[ $MACOSX = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=darwin --address-model=64 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/macosx64/lib --includedir=builds/include link=static
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=darwin --address-model=32 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/macosx32/lib --includedir=builds/include link=static
fi

if [[ $WINDOWS = true ]]
then
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=windows --address-model=64 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/windows64/lib --includedir=builds/include link=static
    $BOOST_ROOT/b2 -sBOOST_ROOT="$BOOST_ROOT" -q $BUILD_VARIANT target-os=windows --address-model=32 --build-dir=$LIBTORRENT_DIR/bin install --libdir=builds/windows32/lib --includedir=builds/include link=static
fi

if [[ $ZIP = true ]]
then
     cp -R $BOOST_ROOT/boost builds/include/boost
    ( cd builds ; zip -r builds.zip include linux64 linux32 macosx64 macosx32 windows64 windows32 )
fi
