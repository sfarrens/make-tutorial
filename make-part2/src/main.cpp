#include "sphere_trig.hpp"
#include "print.hpp"

int main()
{
    double ra_m31 = 10.6833;
    double dec_m31 = 41.2692;
    double ra_b33 = 85.2458;
    double dec_b33 = -2.4583;
    say_hello();
    print_separation(rad2deg(angsep(ra_m31, dec_m31, ra_b33, dec_b33)));
}
