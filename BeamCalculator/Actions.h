#pragma once

#include <memory>
#include <cmath>

class Action {
  public:
  Action() : position_(0), value_(0) {};
  Action(const Action& action) : value_(action.value_) {};
  Action(double position, double value) : position_(position), value_(value) {}; 
  
  double position() const; 
  double value() const;

  virtual std::shared_ptr<Action> get_shared_ptr() const = 0;
  virtual double ContributionToMainEquation(double position) const = 0;
  virtual double ContributionToResultantForce() const = 0;
  virtual double ContributionToResultantMoment() const = 0;

protected:
  double position_;
  double value_;
};

bool operator<(const Action& lhs, const Action& rhs);

class Force : public Action {
  public:
  using Action::Action;
  double ContributionToMainEquation(double position) const override;
  double ContributionToResultantForce() const override;
  double ContributionToResultantMoment() const override;
  std::shared_ptr<Action> get_shared_ptr() const override;
};

class Moment : public Action {
  using Action::Action;
  double ContributionToMainEquation(double position) const override;
  double ContributionToResultantForce() const override;
  double ContributionToResultantMoment() const override;
  std::shared_ptr<Action> get_shared_ptr() const override;
};

class UniformLoad : public Action {
  UniformLoad(double position, double size, double value)
  : Action(position_, value_), size_(size) {};
  double ContributionToMainEquation(double position) const override;
  double ContributionToResultantForce() const override;
  double ContributionToResultantMoment() const override;
  std::shared_ptr<Action> get_shared_ptr() const override;
private:
  double size_;
};

