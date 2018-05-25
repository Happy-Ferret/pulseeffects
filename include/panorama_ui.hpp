#ifndef PANORAMA_UI_HPP
#define PANORAMA_UI_HPP

#include <gtkmm/adjustment.h>
#include <gtkmm/grid.h>
#include "plugin_ui_base.hpp"

class PanoramaUi : public Gtk::Grid, public PluginUiBase {
   public:
    PanoramaUi(BaseObjectType* cobject,
               const Glib::RefPtr<Gtk::Builder>& refBuilder,
               std::string settings_name);
    ~PanoramaUi();

    static std::shared_ptr<PanoramaUi> create(std::string settings_name);

    void reset();

   private:
    Gtk::Adjustment* position;
};

#endif
