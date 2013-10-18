/* Copyright (C) <2013> Dirk Van Haerenborgh <vhdirk@gmail.com>
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
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

  typedef Glib::ListHandle< Glib::RefPtr<Gst::Plugin> > GstPluginList;
  typedef Glib::ListHandle< Glib::RefPtr<Gst::PluginFeature> > GstFeatureList;

  Glib::RefPtr<Gst::Registry> reg = Gst::Registry::get();

  GstPluginList plugins = reg->get_plugin_list();

  /* loop over all plugins (.so) */
  for (GstPluginList::iterator it = plugins.begin(); it != plugins.end(); ++it)
  {
    GstFeatureList features = reg->get_feature_list( (*it)->get_name() );

    /* loop over all features within the plugin */
    for (GstFeatureList::iterator itt = features.begin(); itt != features.end(); ++itt)
    {
      //TODO: this will segfaults on a bad cast. How to I test if the feature is also a factory??
      Glib::RefPtr<Gst::ElementFactory> ef = Glib::RefPtr<Gst::ElementFactory>::cast_dynamic(*itt);
      if (!ef) continue;

      std::vector<Glib::ustring> keys = ef->get_metadata_keys();

      std::cout << "=== " << ef->get_name() << std::endl;

      for(std::vector<Glib::ustring>::iterator keyit = keys.begin();
          keyit != keys.end(); ++keyit)
      {
        std::cout << "-- " << *keyit << " : " << ef->get_metadata(*keyit) << std::endl;
      }
    }
  }

  return 0;
}
