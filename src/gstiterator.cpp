/* Copyright (C) <2013> Dirk Van Haerenborgh <vhdirk@gmail.com>
 * This file is part of GstEditor.
 *
 * GstEditor is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include <glibmm.h>
#include <gtkmm.h>
#include <gstreamermm.h>

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);
  Gst::init(argc, argv);

  Glib::RefPtr<Gst::Element> element = Gst::ElementFactory::create_element("videoconvert");

  typedef Gst::Iterator<Gst::Pad> PadIter;

  PadIter iter = element->iterate_pads();

  //iter.begin();
  while(iter && !iter.is_end())
  {
    std::cout << iter->get_name() << std::endl;

    Glib::RefPtr<Gst::Caps> anycaps = Gst::Caps::create_any();
    Glib::RefPtr<Gst::Caps> caps = iter->query_caps(anycaps);
  }

  return 0;
}
