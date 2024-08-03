#pragma once

#include "vectors/vec4.h"
#include <cmath>

namespace blitz {

    inline float toRadians(float degrees) {
        return degrees * (M_PI / 180.0f);
    }
    
}