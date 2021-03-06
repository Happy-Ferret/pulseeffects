#include "delay_ui.hpp"

DelayUi::DelayUi(BaseObjectType* cobject,
                 const Glib::RefPtr<Gtk::Builder>& builder,
                 const std::string& settings_name)
    : Gtk::Grid(cobject), PluginUiBase(builder, settings_name) {
    name = "delay";

    // loading glade widgets

    builder->get_widget("d_l", d_l);
    builder->get_widget("d_r", d_r);

    get_object(builder, "m_l", m_l);
    get_object(builder, "m_r", m_r);
    get_object(builder, "cm_l", cm_l);
    get_object(builder, "cm_r", cm_r);
    get_object(builder, "temperature", temperature);

    // gsettings bindings

    auto flag = Gio::SettingsBindFlags::SETTINGS_BIND_DEFAULT;

    settings->bind("installed", this, "sensitive", flag);
    settings->bind("m-l", m_l.get(), "value", flag);
    settings->bind("m-r", m_r.get(), "value", flag);
    settings->bind("cm-l", cm_l.get(), "value", flag);
    settings->bind("cm-r", cm_r.get(), "value", flag);
    settings->bind("temperature", temperature.get(), "value", flag);

    settings->set_boolean("post-messages", true);
}

DelayUi::~DelayUi() {
    settings->set_boolean("post-messages", false);

    util::debug(name + " ui destroyed");
}

void DelayUi::on_new_tempo(std::array<double, 2> value) {
    std::ostringstream msg_l, msg_r;

    msg_l.precision(2);
    msg_r.precision(2);

    msg_l << std::fixed << value[0] << " ms";
    msg_r << std::fixed << value[1] << " ms";

    d_l->set_text(msg_l.str());
    d_r->set_text(msg_r.str());
}

void DelayUi::reset() {
    settings->reset("state");
    settings->reset("m_l");
    settings->reset("m_r");
    settings->reset("cm_l");
    settings->reset("cm_r");
    settings->reset("temperature");
}
