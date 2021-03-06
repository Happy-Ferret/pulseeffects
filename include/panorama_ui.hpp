#ifndef PANORAMA_UI_HPP
#define PANORAMA_UI_HPP

#include <gtkmm/grid.h>
#include "plugin_ui_base.hpp"

class PanoramaUi : public Gtk::Grid, public PluginUiBase {
   public:
    PanoramaUi(BaseObjectType* cobject,
               const Glib::RefPtr<Gtk::Builder>& builder,
               const std::string& settings_name);
    virtual ~PanoramaUi();

    void reset();

   private:
    Glib::RefPtr<Gtk::Adjustment> position;
};

#endif
