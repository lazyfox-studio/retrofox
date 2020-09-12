#pragma once

#ifdef slots
#undef slots
#define _SLOTS_WERE_UNDEF_
#endif

#include "pythonenv.h"
#include "pythonref.h"
#include "pythonmainthread.h"
#include "pythonthread.h"
#include "pythonthreadcontroller.h"
#include "pythonfunctions.h"

#ifdef _SLOTS_WERE_UNDEF_
#define slots
#undef _SLOTS_WERE_UNDEF_
#endif
