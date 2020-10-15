#include <iostream>
#include "Beam.h"
#include <unistd.h>

int main() {
  Beam b(10);
  b.addForce(0.5, 10);
  b.addForce(4, -10);
  b.addMoment(6, 3);
  b.addUniformLoad(5, 8, 2);
  b.addUniformLoad(1, 3, 6);
  b.plot();
  return 0;
}
