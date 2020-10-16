#include "Supports.h"

SupportType Support::type() {
  return type_;
}

double HingeSupport::ReactionCoefficient(double end_position) const {
  return position_ * std::pow(end_position - position_, 2) / 2 +
   std::pow(end_position - position_, 3) / 6;
}

double ElasticSupport::ReactionCoefficient(double position) const {
  return 1;
}
