//
// Created by Scrin on 14.10.2020.
//
#include "Beam.h"

using namespace std;

void Beam::addAction(const Action& action) {
  actions.insert(action.get_shared_ptr());
}

void Beam::AddSupport(const Support& support) {
  if(support.position == 0) {
    left_edge = support.type();
    return;
  } else if(support.position == length_) {
    right_edge = support.type();
    return;
  }

  supports.insert(support.get_shared_ptr());
}
// Do not know how to avoid hardcode
vector<double> Beam::CalculateInitialParameters() const{
  vector<double> matrix(16);
  vector<double> b(4);
  
  auto fill = [matrix, b](vector<double> matrix_elements, 
  vector<double> b_elements, size_t lm, size_t rm, size_t lb, size_t rb)
  {
    for(int i = lm; i < rm; ++i) {
        matrix[i] = matrix_rows[i];
      }
      for(int i = lb; i < rb; ++i) {
        b[i] = b_elements[i];
  }

  switch(left_edge) {
    case FixedSupport:
      vector<double> matrix_elements = {1, 0, 0, 0,
                                        0, 1, 0, 0};
      vector<double> b_elements = {0, 0};
      fill(matrix_elements, b_elements, 0, 8, 0, 2);
      break;
    case FreeEdge:
      vector<double> matrix_elements = {0, 0, 1, 0,
                                        0, 0, 0, 1};
      vector<double> b_elements = {-resultant_moment, -resultant_force};
      fill(matrix_elements, b_elements, 8, 16, 2, 4);
      break;
    case HingeSupport:
      vector<double> matrix_elements = {1, 0, 0, 0,
                                        0, 0, 1, 0};
      vector<double> b_elements = {0, -resultant_moment};
      fill(matrix_elements, b_elements, 0, 4, 0, 1);
      fill(matrix_elements, b_elements, 8, 12, 2, 3);
      break;
    case ElasticSupport:
      vector<double> matrix_elements = {1, 0, 0, 0,
                                        0, 0, 1, 0};
      vector<double> b_elements = {0, -resultant_moment};
      fill(matrix_elements, b_elements, 0, 4, 0, 1);
      fill(matrix_elements, b_elements, 8, 12, 2, 3);
      break;
  }
}

void Beam::CalculateReactions() const {
  
}

void Beam::plot() const {
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