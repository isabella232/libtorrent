#ifndef TORRENT_HANDLE_HPP_INCLUDED_W
#define TORRENT_HANDLE_HPP_INCLUDED_W

#include <memory>

#include "libtorrent_w/export.hpp"

namespace libtorrent
{
  struct torrent_handle;
}

namespace libtorrent_w
{
  class session;
  
  struct TORRENT_EXPORT_W torrent_handle
  {
  public:
    torrent_handle(libtorrent::torrent_handle* th_impl);
    torrent_handle(torrent_handle const& t);
    ~torrent_handle();
  private:
    friend class session;
    libtorrent::torrent_handle* torrent_handle_impl;
  };
}

#endif
