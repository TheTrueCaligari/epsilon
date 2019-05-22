#include "app.h"
#include "../apps_container.h"
#include "elisa_icon.h"
#include "../i18n.h"
// #include <poincare/symbol.h>

// using namespace Poincare;
using namespace Shared;

namespace Elisa {

I18n::Message App::Descriptor::name() {
  return I18n::Message::ElisaApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::ElisaAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::ElisaIcon;
}

ElisaView::ElisaView() :
  View()
{
}

ElisaController::ElisaController() :
  ViewController(nullptr),
  m_view()
{
}

View * ElisaController::view() {
  return &m_view;
}


App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(container, this);
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

App::App(Container * container, Snapshot * snapshot) :
   ::App(container, snapshot, &elisa_controller),
   elisa_controller()
{
}
}
