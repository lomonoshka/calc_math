#include <iostream>
#include "Beam.h"
#include <unistd.h>

int main() {
  Beam beam(10);
  beam.addAction(Force(1., 5.));
  beam.addAction(Moment(1, 10));
  return 0;
}
