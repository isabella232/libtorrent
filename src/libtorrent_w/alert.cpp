#include "libtorrent_w/alert.hpp"
#include "libtorrent/alert.hpp"

namespace libtorrent_w
{
  alert::alert()
    : alert_impl(new libtorrent::alert())
  { }

  alert::~alert()
  {
    delete alert_impl;
  }
}
