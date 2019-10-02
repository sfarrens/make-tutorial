#include <cmath>
#include "sphere_trig.hpp"

double deg2rad (double angle) {
  // Function that converts angle from degrees to radians.
  return angle * M_PI / 180.0;
}

double rad2deg (double angle) {
  // Function that converts angle from radians to degrees.
  return angle * 180.0 / M_PI;
}

double angsep (double ra1, double dec1, double ra2, double dec2) {
  // Function that returns the angular separation (in radians) between two points.
  if(ra1 == ra2 && dec1 == dec2)
    return 0.0;
  else
    return acos(sin(deg2rad(dec1)) * sin(deg2rad(dec2)) + cos(deg2rad(dec1)) *
		cos(deg2rad(dec2)) * cos(deg2rad(ra1) - deg2rad(ra2)));
}
