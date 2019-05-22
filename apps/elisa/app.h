#ifndef ELISA_APP_H
#define ELISA_APP_H

// #include "../shared/text_field_delegate_app.h"
#include <escher.h>

namespace Elisa {

class ElisaView : public View {
  public:
    ElisaView();
};

class ElisaController : public ViewController {
  public:
    ElisaController();
    View * view() override;
  private:
    ElisaView m_view;
};

class App : public ::App {
public:
  class Descriptor : public ::App::Descriptor {
  public:
    I18n::Message name() override;
    I18n::Message upperName() override;
    const Image * icon() override;
  };
  class Snapshot : public ::App::Snapshot {
  public:
    App * unpack(Container * container) override;
    // void reset() override;
    Descriptor * descriptor() override;
    // ElisaStore * elisaStore() { return &m_elisaStore; }
  private:
    //ElisaStore m_elisaStore;
  };

private:
  App(Container * container, Snapshot * snapshot);
  ElisaController elisa_controller;
};

}

#endif
