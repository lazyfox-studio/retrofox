#pragma once

#ifdef slots
#undef slots
#define _SLOTS_WERE_UNDEF_
#endif

#include "api-service/pythonenv.h"
#include "api-service/pythonref.h"
#include "api-service/pythonmainthread.h"
#include "api-service/pythonthread.h"
#include "api-service/pythonthreadcontroller.h"
#include "api-service/pythonfunctions.h"

#ifdef _SLOTS_WERE_UNDEF_
#define slots
#undef _SLOTS_WERE_UNDEF_
#endif
