#pragma once 
#include <cmath>

enum class SupportType {
  FixedSupport,
  FreeEdge,
  HingeSupport,
  ElasticSupport
};

class Support {
public:
  Support(double position) : position_(position_) {};
  double position() {
    return position_;
  }
  
  SupportType type() const;

  virtual std::shared_ptr<Support> get_shared_ptr() const = 0;
protected:
  const SupportType type_;
  double position_;
};

class FixedSupport : public Support {
public:
  FixedSupport(double position)
  : type_(SupportType::FixedSupport), position_(position) {};

  std::shared_ptr<Support> get_shared_ptr() const override;
}

class HingeSupport : public Support {
public:
  HingeSupport(double position)
  : type_(SupportType::HingeSupport), position_(position) {};

  std::shared_ptr<Support> get_shared_ptr() const override;
  double ReactionCoefficient(double end_position) const;
};

class ElasticSupport : public Support {
public:
  ElasticSupport(double position)
  : type_(SupportType::ElasticSupport), position_(position) {};
  virtual double ReactionCoefficient(double end_position) const;

  std::shared_ptr<Support> get_shared_ptr() const override
private:
  double young_modulus;
};

// class FreeEdge : public Support {
// public:
//   FreeEdge(double position)
//   : type_(SupportType::FreeEdge), position_(position) {};
// }