#include "Vector.hpp"
#include <cassert>

int main() 
{
  Vector<int> vec1;
  Vector<int> vec2;

  for (unsigned int i = 0; i < 128; i++) {
    vec1.push_back(i);
  }

  assert(vec1.size() == 128);
  assert(vec1.capacity() == 128);
  
  vec2 = vec1;

  assert(vec2.size() == 128);
  assert(vec2.capacity() == 128);

  vec2.push_back(129);

  Vector<int> vec3 = vec2;

  assert(vec3.size() == 129);
  assert(vec3.capacity() > 128);

  assert(vec3[vec3.back()] = 129);
  assert(vec3[vec3.front()] = 129);

  return 0;
}
