#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
    MissionCriticalError ret("Not enough water to achieve the mission.", "WaterReclaimer");
    _started = true;
    if (_water < 100)
        throw ret;
}

void
WaterReclaimer::useWater(int water)
{
    LifeCriticalError lf("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    if (water <= 0)
    {
        UserError userError("Water use should be positif.", "WaterReclaimer");
        throw userError;
    }
    if (_started == false)
    {
        UserError errStart("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
        throw errStart;
    }
    _water -= water;
    if (_water < 10)
        throw lf;
}

void
WaterReclaimer::generateWater()
{
    NasaError ns("Cannot generate water, reclaimer already full.", "WaterReclaimer");
    if (_water == 100)
        throw ns;
    _water += 10;
}