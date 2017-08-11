#include "libtorrent_w/add_torrent_params.hpp"
#include "libtorrent_w/torrent_info.hpp"

#include "libtorrent/aux_/disable_warnings_push.hpp"
#include "libtorrent/add_torrent_params.hpp"
#include "libtorrent/aux_/disable_warnings_pop.hpp"
#include "libtorrent/torrent_info.hpp"

#include <boost/shared_ptr.hpp>

namespace libtorrent_w
{
  add_torrent_params::add_torrent_params()
    : add_torrent_params_impl(new libtorrent::add_torrent_params())
    , version(add_torrent_params_impl->version)
    , trackers(add_torrent_params_impl->trackers)
    , url_seeds(add_torrent_params_impl->url_seeds)
    , dht_nodes(add_torrent_params_impl->dht_nodes)
    , name(add_torrent_params_impl->name)
    , save_path(add_torrent_params_impl->save_path)
    , resume_data(add_torrent_params_impl->resume_data)
    , trackerid(add_torrent_params_impl->trackerid)
    , url(add_torrent_params_impl->url)
    , info_hash(add_torrent_params_impl->info_hash)
    , max_uploads(add_torrent_params_impl->max_uploads)
    , max_connections(add_torrent_params_impl->max_connections)
    , upload_limit(add_torrent_params_impl->upload_limit)
    , download_limit(add_torrent_params_impl->download_limit)
  { }

  add_torrent_params::~add_torrent_params()
  {
    delete add_torrent_params_impl;
  }

  void add_torrent_params::set_ti(torrent_info* ti)
  {
    this->add_torrent_params_impl->ti.reset(ti->torrent_info_impl);
  }
  torrent_info* add_torrent_params::get_ti()
  {
    return new torrent_info(this->add_torrent_params_impl->ti.get());
  }

  void add_torrent_params::set_flags(uint64_t flags)
  {
    this->add_torrent_params_impl->flags = flags;
  }
  uint64_t add_torrent_params::get_flags()
  {
    return this->add_torrent_params_impl->flags;
  }
}
