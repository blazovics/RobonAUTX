/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RaceControlUnit.h"

/**
 * RaceControlUnit implementation
 */


/**
 * Should raie exception when the teamID is not valid.
 * @param teamID
 * @return Team
 */
RaceControlUnit::RaceControlUnit()
{

}

RaceControlUnit::~RaceControlUnit()
{

}

void RaceControlUnit::TeamListUpdated(QList<Team> teams)
{

}

void RaceControlUnit::SkillRaceInitiated(quint32 teamID)
{

}

void RaceControlUnit::SpeedRaceInitiated(quint32 teamID)
{

}

void RaceControlUnit::raceStarted()
{

}

void RaceControlUnit::RaceFinished(bool aborted)
{

}

void RaceControlUnit::LaserLapTimeUpdated(quint32 time)
{

}

void RaceControlUnit::ManualLapTimeUpdated(quint32 time)
{

}

void RaceControlUnit::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{

}

void RaceControlUnit::CheckpointStateUpdated(quint32 checkpointID, bool checked)
{

}

void RaceControlUnit::VehicleStartConfirmed(bool achieved)
{

}

void RaceControlUnit::LaneChangeConfirmed(bool achieved)
{

}

void RaceControlUnit::SkillPointUpdated(quint32 skillPoint)
{

}

void RaceControlUnit::SafetyCarFollowingConfirmed(bool achieved)
{

}

void RaceControlUnit::SafetyCarOvertakeConfirmed(bool achieved)
{

}

void RaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{

}
