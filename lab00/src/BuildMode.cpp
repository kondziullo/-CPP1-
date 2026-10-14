#include "BuildMode.h"

const char* buildMode() {
#ifdef NDEBUG
    return "Release";
#else
    return "Debug";
#endif
}


