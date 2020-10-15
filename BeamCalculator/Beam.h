//
// Created by Scrin on 14.10.2020.
//
#ifndef BEAM_CALCULATOR_BEAM_H
#define BEAM_CALCULATOR_BEAM_H
#include <string>
#include <map>
#include <fstream>
struct  Boundary {

};

class Beam {
public:
  explicit Beam(double length) : length_(length){};
  void addForce(double position, double value);
  void addUniformLoad(double start_position, double end_position, double value);
  void addMoment(double position, double value);
  void addBoundary(double position, const Boundary& boundary);
  void plot() const;
private:
  double length_;
  std::map<double, double> forces;
  std::map<std::pair<double, double>, double> uniform_loads;
  std::map<double, double> moments;
  std::map<double, Boundary> boundaries;
};

#endif //BEAM_CALCULATOR_BEAM_H
