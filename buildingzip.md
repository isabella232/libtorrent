#Requirements#
Boost must be installed to build libtorrent. This can be downloaded from [boost's website](http://www.boost.org/users/download/)
Extract the downloaded archive cd into the it, then run `./bootstrap.sh`

#Building#
cd into the libtorrent directory and run `./mk.sh [target os]`. To build a zip for multiple operating systems, run this command for each operating system. To then build the zip, run `./mk.sh zip`. This will create a builds.zip in `builds/`.
