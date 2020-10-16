#pragma once

#include <string>
#include <set>
#include <fstream>
#include <memory>
#include "Actions.h"
#include "Supports.h"

class Beam {
public:
  explicit Beam(double length) : length_(length){};
  void addAction(const Action& action);
  void addSupport(const Support& support);
  void plot() const;
  void CalculateReactions() const;
private:
  vector<double> CalculateInitialParameters() const;

  double length_;
  SuportType left_edge = SupportType::FreeEdge;
  SuportType right_edge = SupportType::FreeEdge;
  double resultant_moment;
  double resultant_forse;
  std::set<std::shared_ptr<Action>> actions;
  std::set<std::shared_ptr<Support>> supports;
};

template <typename collection> 
void writeCollection(collection c, string name);
template <typename l, typename r> 
ofstream& operator<<(ofstream& stream, pair<l, r> p);