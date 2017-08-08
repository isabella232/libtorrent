#ifndef TORRENT_HANDLE_HPP_INCLUDED_W
#define TORRENT_HANDLE_HPP_INCLUDED_W

namespace libtorrent
{
  struct torrent_handle;
}

namespace libtorrent_w
{
  class session;
  
  struct torrent_handle
  {
  public:
    torrent_handle();
    torrent_handle(libtorrent::torrent_handle* th_impl);
    torrent_handle(torrent_handle const& t);
  private:
    friend class session;
    std::unique_ptr<libtorrent::torrent_handle> torrent_handle_impl;
  };
}

#endif
