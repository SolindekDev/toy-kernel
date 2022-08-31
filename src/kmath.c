#include <utils.h>
#include <kmath.h>

double pow(double base, double exponent) {
    double _base = base;
    for (double i = 0; i < (exponent - 1); i++)
        _base = _base * base;
    return _base;
}

double sqrt() {
    ASSERT(x);
    unimplemented("sqrt (kmath.c) is not implemented");
    return 0.00;
}

double ceil() {
    ASSERT(x);
    unimplemented("ceil (kmath.c) is not implemented");
    return 0.00;
}

double floor(double x) {
    double _x = x;
    long partent = (long)_x;

    if (_x < 0)
        return partent-1;
    else 
        return partent;
}

double precent(double value, double max) {
    return (value / max) * 100.0;
}

double kb_to_gb(long kb) {
    return (double)kb / 1048576;
}

double b_to_gb(long b) {
    ASSERT(x);
    unimplemented("b_to_gb (kmath.c) is not implemented");
    return 0.00;
}

double mb_to_gb(long mb) {
    ASSERT(x);
    unimplemented("mb_to_gb (kmath.c) is not implemented");
    return 0.00;
}