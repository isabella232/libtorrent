#include "libtorrent/session.hpp"
#include "libtorrent/torrent_handle.hpp"

#include "libtorrent_w/session.hpp"
#include "libtorrent_w/torrent_handle.hpp"

namespace libtorrent_w
{
  session::session() :
    session_impl(new libtorrent::session)
  { }

  torrent_handle session::add_torrent(add_torrent_params const& params)
  {
    return torrent_handle(new libtorrent::torrent_handle(session_impl->add_torrent(*params.add_torrent_params_impl)));
  }
  void session::async_add_torrent(add_torrent_params const& params)
  {
    session_impl->async_add_torrent(*params.add_torrent_params_impl);
  }

  void session::remove_torrent(const torrent_handle& h, int options)
  {
    session_impl->remove_torrent(*h.torrent_handle_impl, options);
  }

  void session::pop_alerts(std::vector<alert*>* alerts)
  {
    session_impl->pop_alerts(alerts);
  }
}
