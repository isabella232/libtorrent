#include "libtorrent_w/torrent_info.hpp"
#include "libtorrent/torrent_info.hpp"

namespace libtorrent_w
{

  torrent_info::torrent_info(std::string const& filename)
    : torrent_info_impl(new libtorrent::torrent_info(filename))
  { }

  torrent_info::torrent_info(libtorrent::torrent_info* ti)
    : torrent_info_impl (ti)
  { }
}
