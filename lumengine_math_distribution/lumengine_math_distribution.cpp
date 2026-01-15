#include <iostream>
#include "include/lum_math_common.hpp"
#include "include/clum_mat4.h"
#include "include/clum_vec3.h"
#include "include/clum_vec4.h"
#include "include/lum_vec3.hpp"

int main() {
    lumm::Vec3f v;
    lumm::Vec3f v2;
    v.x = 100; v.y = 143; v.z = 12;
    lumm::inverse(v);
    std::cout << lumm::inverse(5) << '\n';
    lumm::print(v);
    return 0;
}
