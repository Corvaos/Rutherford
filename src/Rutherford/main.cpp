#include <iostream>

#include "Rutherford/Application.h"
#include "Rutherford/Config.h"

int main()
{
  const Application application = Application();

  application.setup(Config::GOLD_RESOLUTION, Config::GOLD_ROWS);

  while (application.active())
  {
    application.run(Config::DT);
  }

  return 0;
}
