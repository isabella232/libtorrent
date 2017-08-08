#include <vector>
#include <memory>

#include "libtorrent_w/add_torrent_params.hpp"
#include "libtorrent_w/torrent_handle.hpp"


#ifndef SESSION_HPP_INCLUDED_W
#define SESSION_HPP_INCLUDED_W

namespace libtorrent
{
  class session;
}

namespace libtorrent_w
{
  class session
  {
  public:
    session();
    ~session();

    torrent_handle add_torrent(add_torrent_params const& params);
    void async_add_torrent(add_torrent_params const& params);

    void remove_torrent(const torrent_handle& h, int options = 0);

    void pop_alerts(std::vector<alert*>* alerts);
  private:
    std::unique_ptr<libtorrent::session> session_impl;
  };
  
}

#endif
