//
// Created by Scrin on 14.10.2020.
//
#include "Beam.h"

using namespace std;
template <typename collection> 
void writeCollection(collection c, string name);
template <typename l, typename r> 
ofstream& operator<<(ofstream& stream, pair<l, r> p);

void Beam::addForce(double position, double value) {
  forces[position] = value;
}

void Beam::addUniformLoad(double start_position, double end_position, double value) {
  uniform_loads[std::make_pair(start_position, end_position)] = value;
}

void Beam::addMoment(double position, double value) {
  moments[position] = value;
}

void Beam::addBoundary(double position, const Boundary& boundary) {
  boundaries[position] = boundary;
}

void Beam::plot() const {
  writeCollection(forces, "beam_data/forces");
  writeCollection(uniform_loads, "beam_data/uniform_loads");
  writeCollection(moments, "beam_data/moments");
  //writeCollection(beam_data, forces);
  system("python3 my_script.py");
}

template <typename l, typename r> 
ofstream& operator<<(ofstream& stream, pair<l, r> p) {
  stream << p.first << " " << p.second;
  return stream;
}

template <typename collection> 
void writeCollection(collection c, string name) {
  ofstream keys(name + "_key.txt");
  ofstream values(name + "_value.txt");
  for(auto [key, value] : c) {
    keys << key << " ";
    values << value << " ";
  }
  keys.close();
  values.close();
}