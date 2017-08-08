#include "libtorrent/torrent_handle.hpp"
#include "libtorrent_w/torrent_handle.hpp"

namespace libtorrent_w
{
  torrent_handle::torrent_handle(libtorrent::torrent_handle* th_impl)
    : torrent_handle_impl(th_impl)
  { }

  torrent_handle::torrent_handle(torrent_handle const& t)
    : torrent_handle_impl(new libtorrent::torrent_handle(*t.torrent_handle_impl))
  {

  }
}
