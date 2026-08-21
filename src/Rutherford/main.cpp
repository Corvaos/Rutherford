#include <iostream>

#include "Rutherford/Application.h"
#include "Rutherford/Config.h"

int main()
{
  Application application = Application();

  application.initCoreParticles();
  application.launchWave(Config::RESOLUTION);

  while (application.active())
  {
    application.run(Config::DT);
  }

  return 0;
}
