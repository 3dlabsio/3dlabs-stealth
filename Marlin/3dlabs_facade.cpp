/**
 * Marlin 3D Printer Firmware For 3D Labs Stealth
 *
 * Copyright (C) 2020 3D Labs [https://github.com/3dlabsio/]
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

#include "3dlabs.h"
#include "3dlabs_.h"

#ifdef DEBUG
#pragma message "This is a DEBUG build"
#endif

#if defined(ADVi3PP_SIMULATOR)
#pragma message "This is a ADVi3++ Simulator build"
#endif

namespace _3dlabs {

inline namespace singletons
{
    extern PidTuning pid_tuning;
    extern AutomaticLeveling automatic_leveling;
    extern SensorSettings sensor_settings;
    extern Print print;
}

// --------------------------------------------------------------------
// ADVi3++
// --------------------------------------------------------------------

//! Initialize the printer and its LCD.
void _3DLabs::setup()
{
    _3dlabs.setup();
}

void _3DLabs::setup_lcd_serial()
{
    _3dlabs.setup_lcd_serial();
}

void _3DLabs::change_baudrate()
{
    _3dlabs.change_baudrate();
}

//! Read data from the LCD and act accordingly.
void _3DLabs::idle()
{
    _3dlabs.idle();
}

//! PID automatic tuning is finished.
void _3DLabs::auto_pid_finished(bool success)
{
    pid_tuning.finished(success);
}

void _3DLabs::g29_leveling_finished(bool success)
{
    automatic_leveling.g29_leveling_finished(success);
}

void _3DLabs::pause_finished()
{
    print.pause_finished();
}

//! Store presets in permanent memory.
//! @param write Function to use for the actual writing
//! @param eeprom_index
//! @param working_crc
void _3DLabs::write(eeprom_write write, int& eeprom_index, uint16_t& working_crc)
{
    _3dlabs.write(write, eeprom_index, working_crc);
}

//! Restore presets from permanent memory.
//! @param read Function to use for the actual reading
//! @param eeprom_index
//! @param working_crc
bool _3DLabs::read(eeprom_read read, int& eeprom_index, uint16_t& working_crc)
{
    return _3dlabs.read(read, eeprom_index, working_crc);
}

//! Reset presets.
void _3DLabs::reset()
{
    _3dlabs.reset();
}

//! Return the size of data specific to ADVi3++
uint16_t _3DLabs::size_of()
{
    return _3dlabs.size_of();
}

//! Inform the user that the EEPROM data are not compatible and have been reset
void _3DLabs::eeprom_settings_mismatch()
{
    _3dlabs.eeprom_settings_mismatch();
}

//! Called when a temperature error occurred and display the error on the LCD.
void _3DLabs::temperature_error(const FlashChar* message)
{
    _3dlabs.temperature_error(message);
}

void _3DLabs::set_brightness(int16_t britghness)
{
    _3dlabs.set_brightness(britghness);
}

bool _3DLabs::has_status()
{
    return _3dlabs.has_status();
}

void _3DLabs::set_status(const char* message)
{
    _3dlabs.set_status(message);
}

void _3DLabs::set_status(const FlashChar* message)
{
    _3dlabs.set_status(message);
}

void _3DLabs::set_status(const char * const fmt, va_list& args)
{
    _3dlabs.set_status(fmt, args);
}

void _3DLabs::set_status(const FlashChar* const fmt, va_list& args)
{
    _3dlabs.set_status(fmt, args);
}

void _3DLabs::set_status_v(const FlashChar* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    set_status(fmt, args);
    va_end(args);
}

void  _3DLabs::advanced_pause_show_message(AdvancedPauseMessage message)
{
    _3dlabs.advanced_pause_show_message(message);
}

void _3DLabs::reset_status()
{
    _3dlabs.reset_status();
}

void _3DLabs::buzz(long duration, uint16_t)
{
    _3dlabs.buzz(duration);
}

void _3DLabs::on_set_temperature(TemperatureKind kind, uint16_t temperature)
{
    _3dlabs.on_set_temperature(kind, temperature);
}

void _3DLabs::stop_and_wait()
{
    _3dlabs.stop_and_wait();
}

void _3DLabs::process_command(const GCodeParser& parser)
{
    _3dlabs.process_command(parser);
}

double _3DLabs::x_probe_offset_from_extruder()
{
    return sensor_settings.x_probe_offset_from_extruder();
}

double _3DLabs::y_probe_offset_from_extruder()
{
    return sensor_settings.y_probe_offset_from_extruder();
}

int _3DLabs::left_probe_bed_position()
{
    return sensor_settings.left_probe_bed_position();
}

int _3DLabs::right_probe_bed_position()
{
    return sensor_settings.right_probe_bed_position();
}

int _3DLabs::front_probe_bed_position()
{
    return sensor_settings.front_probe_bed_position();
}

int _3DLabs::back_probe_bed_position()
{
    return sensor_settings.back_probe_bed_position();
}

// --------------------------------------------------------------------

}
