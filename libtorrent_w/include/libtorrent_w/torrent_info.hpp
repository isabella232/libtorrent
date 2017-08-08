#include <string>

#ifndef TORRENT_INFO_HPP_INCLUDED_W
#define TORRENT_INFO_HPP_INCLUDED_W

namespace libtorrent
{
  class torrent_info;
}

namespace libtorrent_w
{
  class torrent_info
  {
  public:
    torrent_info(std::string const& filename);
  private:
    friend class add_torrent_params;

    torrent_info(libtorrent::torrent_info* ti);
    
    std::unique_ptr<libtorrent::torrent_info> torrent_info_impl;
  };
}

#endif
