/**
 * Marlin 3D Printer Firmware For 3D Labs Stealth
 *
 * Copyright (C) 2020 3D Labs [https://github.com/3dlabsio/]
 * Copyright (C) 2017-2020 Sebastien Andrivet [https://github.com/andrivet/]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef ADV_I3_PLUS_PLUS_ENUMS_H
#define ADV_I3_PLUS_PLUS_ENUMS_H

#include <stdint.h>
#include "3dlabs_bitmasks.h"

namespace _3dlabs {


//! List of variables and their addresses.
enum class Variable: uint16_t
{
    // 0 - Statuses
    TargetBed               = 0x0000,
    Bed                     = 0x0001,
    TargetChamber           = 0x0002,
    Chamber                 = 0x0003,
    TargetHotEnd1           = 0x0004,
    HotEnd1                 = 0x0005,
    TargetHotEnd2           = 0x0006,
    HotEnd2                 = 0x0007,
    FanSpeed                = 0x0008,
    ZHeight                 = 0x0009,
    ZLayer                  = 0x000A,
    ProgressLow             = 0x000B,
    ProgressHigh            = 0x000C,
    SensorActive            = 0x000D,
    Feedrate                = 0x000E,
    Fan2Speed               = 0x000F,
    Message                 = 0x0010,
    CenteredMessage         = 0x0028,
    Progress                = 0x0040,
    ET                      = 0x0058,
    TC                      = 0x005C,

    // 1 - Texts
    ShortText0              = 0x0100,
    ShortText1              = 0x0108,
    ShortText2              = 0x0110,
    ShortText3              = 0x0118,
    LongText0               = 0x0120,
    LongText1               = 0x0138,
    LongText2               = 0x0150,
    LongText3               = 0x0168,
    LongText4               = 0x0180,
    LongTextCentered0       = 0x0198,

    // 2 - Versions
    _3DLabsVersion          = 0x0200,
    ADVi3ppBuild            = 0x0208,
    ADVi3ppDGUSVersion      = 0x0210,
    ADVi3ppMarlinVersion    = 0x0218,

    // 3 - Values
    Value0                  = 0x0300,
    Value1                  = 0x0301,
    Value2                  = 0x0302,
    Value3                  = 0x0303,
    Value4                  = 0x0304,
    Value5                  = 0x0305,
    Value6                  = 0x0306,
    Value7                  = 0x0307,
    Value8                  = 0x0308,
    Value9                  = 0x0309,
    Value10                 = 0x0310,
    Value11                 = 0x0311,
};

//! List of actions sent by the LCD.
enum class Action: uint16_t
{
    // 4 - Actions
    Screen                  = 0x0400,
    PrintCommand            = 0x0401,
    Wait                    = 0x0402,
    LoadUnload              = 0x0403,
    Preheat                 = 0x0404,
    Move                    = 0x0405,
    SdCard                  = 0x0406,
    FactoryReset            = 0x0407,
    ManualLeveling          = 0x0408,
    ExtruderTuning          = 0x0409,
    AutomaticLeveling       = 0x040A,
    PidTuning               = 0x040B,
    SensorSettings          = 0x040C,
    Babysteps               = 0x040D,
    LCD                     = 0x040F,
    Statistics              = 0x0410,
    Versions                = 0x0411,
    PrintSettings           = 0x0412,
    PIDSettings             = 0x0413,
    StepsSettings           = 0x0414,
    FeedrateSettings        = 0x0415,
    AccelerationSettings    = 0x0416,
    JerkSettings            = 0x0417,
    Copyrights              = 0x0418,
    SensorTuning            = 0x0419,
    SensorGrid              = 0x041A,
    SensorZHeight           = 0x041B,
    ChangeFilament          = 0x041C,
    EEPROMMismatch          = 0x041D,
    LinearAdvanceTuning     = 0x041F,
    LinearAdvanceSettings   = 0x0420,
    Temperatures            = 0x0422,

    // 5 - Increments
    MoveXMinus              = 0x0500,
    MoveXPlus               = 0x0501,
    MoveYMinus              = 0x0502,
    MoveYPlus               = 0x0503,
    MoveZMinus              = 0x0504,
    MoveZPlus               = 0x0505,
    MoveEMinus              = 0x0506,
    MoveEPlus               = 0x0507,
    BabyMinus               = 0x0508,
    BabyPlus                = 0x0509,
    ZHeightMinus            = 0x050A,
    ZHeightPlus             = 0x050B,

    FeedrateMinus           = 0x050C,
    FeedratePlus            = 0x050D,
    FanMinus                = 0x050E,
    FanPlus                 = 0x050F,
    Hotend1Minus            = 0x0510,
    Hotend1Plus             = 0x0511,
    Hotend2Minus            = 0x0512,
    Hotend2Plus             = 0x0513,
    BedMinus                = 0x0514,
    BedPlus                 = 0x0515,
    EnclosureMinus          = 0x0516,
    EnclosurePlus           = 0x0517,
    LCDBrightness           = 0x0518,
    Fan2Minus               = 0x0519,
    Fan2Plus                = 0x051A,

    Undefined               = 0xFFFF
};

//! Key values used by the LCD screens.
enum class KeyValue: uint16_t
{
    Show                    = 0x0000,

    Temps                   = 0x0000,
    Print                   = 0x0001,
    Controls                = 0x0002,
    Tuning                  = 0x0003,
    Settings                = 0x0004,
    Infos                   = 0x0005,
    Motors                  = 0x0006,
    Leveling                = 0x0007,
    PrintSettings           = 0x0008,

    PrintStop               = 0x0001,
    PrintPause              = 0x0002,
    PrintAdvancedPause      = 0x0003,

    Load                    = 0x0001,
    Unload                  = 0x0002,
    Hotend1                 = 0x0003,
    Hotend2                 = 0x0004,

    PresetPrevious          = 0x0001,
    PresetNext              = 0x0002,
    Cooldown                = 0x0003,

    MoveXHome               = 0x0001,
    MoveYHome               = 0x0002,
    MoveZHome               = 0x0003,
    MoveAllHome             = 0x0004,
    DisableMotors           = 0x0005,

    SDLine1                 = 0x0001,
    SDLine2                 = 0x0002,
    SDLine3                 = 0x0003,
    SDLine4                 = 0x0004,
    SDLine5                 = 0x0005,
    SDUp                    = 0x0006,
    SDDown                  = 0x0007,

    LevelingPoint1          = 0x0001,
    LevelingPoint2          = 0x0002,
    LevelingPoint3          = 0x0003,
    LevelingPoint4          = 0x0004,
    LevelingPoint5          = 0x0005,
    LevelingPointA          = 0x0006,
    LevelingPointB          = 0x0007,
    LevelingPointC          = 0x0008,
    LevelingPointD          = 0x0009,

    ExtruderTuningHotend1   = 0x0001,
    ExtruderTuningHotend2   = 0x0002,
    ExtruderTuningStep2     = 0xFFFD,
    ExtruderTuningSave      = 0xFFFE,

    PidTuningStep2          = 0x0001,
    PidTuningHotend1        = 0x0002,
    PidTuningHotend2        = 0x0003,
    PidTuningBed            = 0x0004,

    SensorSettingsPrevious  = 0x0001,
    SensorSettingsNext      = 0x0002,

    LCDDimming              = 0x0001,
    BuzzerOnAction          = 0x0002,
    BuzzOnPress             = 0x0003,

    MismatchForward         = 0x0001,

    PidSettingsHotend1      = 0x0001,
    PidSettingsHotend2      = 0x0002,
    PidSettingsBed          = 0x0003,
    PidSettingPrevious      = 0x0004,
    PidSettingNext          = 0x0005,

    SensorSelfTest          = 0x0001,
    SensorReset             = 0x0002,
    SensorDeploy            = 0x0003,
    SensorStow              = 0x0004,

    Multiplier1             = 0x0001,
    Multiplier2             = 0x0002,
    Multiplier3             = 0x0003,

    Baby1                   = 0x0001,
    Baby2                   = 0x0002,
    Baby3                   = 0x0003,

    Save                    = 0xFFFE,
    Back                    = 0xFFFF
};

//! Set of possible feature to enable or disable
enum class Feature: uint16_t
{
    None                = 0b0000000000000000,
    Dimming             = 0b0000000000000100,
    Buzzer              = 0b0000000000001000,
    BuzzOnPress         = 0b0000000000010000
};
ENABLE_BITMASK_OPERATOR(Feature);

enum class FanIndex: uint8_t
{
    Fan1 = 0,
    Fan2 = 2
};

}

#endif //ADV_I3_PLUS_PLUS_ENUMS_H
