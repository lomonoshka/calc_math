#include "Actions.h"

double Action::position() const {
  return position_;
}

double Action::value() const {
  return value_;
}

bool operator<(const Action& lhs, const Action& rhs) {
  return lhs.position() < rhs.position();
}

double Force::ContributionToMainEquation(double end_position) const {
  return value_ * std::pow(end_position - position_, 3) / 6 + 
  value_ * position_ * std::pow(end_position - position_, 2) / 2; 
}

double Force::ContributionToResultantForce() const {
  return value_;
}

double Force::ContributionToResultantMoment() const {
  return value_ * position_;
}

std::shared_ptr<Action> Force::get_shared_ptr() const {
  return std::make_shared<Force>(*this);
}

double Moment::ContributionToMainEquation(double end_position) const {
  return value_ * std::pow(end_position - position_, 2);
}

double Moment::ContributionToResultantForce() const {
  return 0;
}

double Moment::ContributionToResultantMoment() const {
  return value_;
}

std::shared_ptr<Action> Moment::get_shared_ptr() const {
  return std::make_shared<Moment>(*this);
}


double UniformLoad::ContributionToMainEquation(double end_position) const {
  double contribution = value_ * std::pow(end_position - position_, 4) / 24; 
  
  if(position_ + size_ < end_position) {
    contribution -= value_ * std::pow(end_position - (position_ + size_), 4) / 24;
  }
  return contribution;
}

double UniformLoad::ContributionToResultantForce() const {
  return size_ * value_;
}
double UniformLoad::ContributionToResultantMoment() const {
  return size_ * value_ * (position_ + size_ / 2);
}
std::shared_ptr<Action> UniformLoad::get_shared_ptr() const {
  return std::make_shared<UniformLoad>(*this);
}