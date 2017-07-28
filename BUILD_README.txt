mk.sh builds the project
There should be a builder for each of linux, osx, and windows, and one complete builder
To build for a platform, use:
./mk.sh [linux] [osx] [windows]

if the project is being built from outside of this repo's root directory, set LIBTORRENT_DIR to the directory of this repo

To zip up the artifacts, use:
./mk.sh zip

all artifacts will be placed in the builds directory, which will be created in the current directory
builds for windows will put artifacts in builds/win64 and builds/win32
builds for linux will put artifacts in builds/linux64 and builds/linux32
builds for osx will put artifacts in builds/osx64 and builds/osx32

the complete builder assumes that all artifacts for linux, osx, and windows exist in the builds directory, and will output a builds.zip in the builds folder

Dependencies:
- This project relies on boost, and the BOOST_ROOT must be set when calling mk.sh. Please let me know if I should be including this in the libtorrent repo instead, since I've been informed that this isn't preinstaled katana
- OpenSSL should be placed somewhere that gcc can find it
- mingw32 or a compiler that can cross compile to windows is needed
