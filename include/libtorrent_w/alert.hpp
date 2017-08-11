/*

Copyright (c) 2003-2016, Arvid Norberg, Daniel Wallin
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef TORRENT_ALERT_HPP_INCLUDED_W
#define TORRENT_ALERT_HPP_INCLUDED_W

#include "libtorrent/export.hpp"

namespace libtorrent
{
  class alert;
}

namespace libtorrent_w
{
  class TORRENT_EXPORT alert
  {
  public:
    alert();
    ~alert();

    // returns an integer that is unique to this alert type. It can be
    // compared against a specific alert by querying a static constant called ``alert_type``
    // in the alert. It can be used to determine the run-time type of an alert* in
    // order to cast to that alert type and access specific members.
    // 
    // e.g:
    //
    // .. code:: c++
    //
    //	std::vector<alert*> alerts;
    //	ses.pop_alerts(&alerts);
    //	for (alert* i : alerts) {
    //		switch (a->type()) {
    // 
    //			case read_piece_alert::alert_type:
    //			{
    //				read_piece_alert* p = (read_piece_alert*)a;
    //				if (p->ec) {
    //					// read_piece failed
    //					break;
    //				}
    //				// use p
    //				break;
    //			}
    //			case file_renamed_alert::alert_type:
    //			{
    //				// etc...
    //			}
    //		}
    //	}
    virtual int type() const = 0;

    // returns a string literal describing the type of the alert. It does
    // not include any information that might be bundled with the alert.
    virtual char const* what() const = 0;

    // generate a string describing the alert and the information bundled
    // with it. This is mainly intended for debug and development use. It is not suitable
    // to use this for applications that may be localized. Instead, handle each alert
    // type individually and extract and render the information from the alert depending
    // on the locale.
    virtual std::string message() const = 0;

    // returns a bitmask specifying which categories this alert belong to.
    virtual int category() const = 0;

  private:
    libtorrent::alert* alert_impl;
  };

  template <class T> T* alert_cast(alert* a)
  {
    if (a == 0) return 0;
    if (a->type() == T::alert_type) return static_cast<T*>(a);
    return 0;
  }

  template <class T> T* alert_cast(alert const* a)
  {
    if (a == 0) return 0;
    if (a->type() == T::alert_type) return static_cast<T const*>(a);
    return 0;
  }
}

#endif
