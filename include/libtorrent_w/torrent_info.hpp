#include <string>

#ifndef TORRENT_INFO_HPP_INCLUDED_W
#define TORRENT_INFO_HPP_INCLUDED_W

#include <memory>
#include "libtorrent_w/export.hpp"

namespace libtorrent
{
  class torrent_info;
}

namespace libtorrent_w
{
  class TORRENT_EXPORT_W torrent_info
  {
  public:
    torrent_info(std::string const& filename);
    ~torrent_info();
  private:
    friend struct add_torrent_params;
    torrent_info(libtorrent::torrent_info* ti);
    
    libtorrent::torrent_info* torrent_info_impl;
  };
}

#endif
