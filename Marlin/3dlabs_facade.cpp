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
void ADVi3pp::setup()
{
    _3dlabs.setup();
}

void ADVi3pp::setup_lcd_serial()
{
    _3dlabs.setup_lcd_serial();
}

void ADVi3pp::change_baudrate()
{
    _3dlabs.change_baudrate();
}

//! Read data from the LCD and act accordingly.
void ADVi3pp::idle()
{
    _3dlabs.idle();
}

//! PID automatic tuning is finished.
void ADVi3pp::auto_pid_finished(bool success)
{
    pid_tuning.finished(success);
}

void ADVi3pp::g29_leveling_finished(bool success)
{
    automatic_leveling.g29_leveling_finished(success);
}

void ADVi3pp::pause_finished()
{
    print.pause_finished();
}

//! Store presets in permanent memory.
//! @param write Function to use for the actual writing
//! @param eeprom_index
//! @param working_crc
void ADVi3pp::write(eeprom_write write, int& eeprom_index, uint16_t& working_crc)
{
    _3dlabs.write(write, eeprom_index, working_crc);
}

//! Restore presets from permanent memory.
//! @param read Function to use for the actual reading
//! @param eeprom_index
//! @param working_crc
bool ADVi3pp::read(eeprom_read read, int& eeprom_index, uint16_t& working_crc)
{
    return _3dlabs.read(read, eeprom_index, working_crc);
}

//! Reset presets.
void ADVi3pp::reset()
{
    _3dlabs.reset();
}

//! Return the size of data specific to ADVi3++
uint16_t ADVi3pp::size_of()
{
    return _3dlabs.size_of();
}

//! Inform the user that the EEPROM data are not compatible and have been reset
void ADVi3pp::eeprom_settings_mismatch()
{
    _3dlabs.eeprom_settings_mismatch();
}

//! Called when a temperature error occurred and display the error on the LCD.
void ADVi3pp::temperature_error(const FlashChar* message)
{
    _3dlabs.temperature_error(message);
}

void ADVi3pp::set_brightness(int16_t britghness)
{
    _3dlabs.set_brightness(britghness);
}

bool ADVi3pp::has_status()
{
    return _3dlabs.has_status();
}

void ADVi3pp::set_status(const char* message)
{
    _3dlabs.set_status(message);
}

void ADVi3pp::set_status(const FlashChar* message)
{
    _3dlabs.set_status(message);
}

void ADVi3pp::set_status(const char * const fmt, va_list& args)
{
    _3dlabs.set_status(fmt, args);
}

void ADVi3pp::set_status(const FlashChar* const fmt, va_list& args)
{
    _3dlabs.set_status(fmt, args);
}

void ADVi3pp::set_status_v(const FlashChar* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    set_status(fmt, args);
    va_end(args);
}

void  ADVi3pp::advanced_pause_show_message(AdvancedPauseMessage message)
{
    _3dlabs.advanced_pause_show_message(message);
}

void ADVi3pp::reset_status()
{
    _3dlabs.reset_status();
}

void ADVi3pp::buzz(long duration, uint16_t)
{
    _3dlabs.buzz(duration);
}

void ADVi3pp::on_set_temperature(TemperatureKind kind, uint16_t temperature)
{
    _3dlabs.on_set_temperature(kind, temperature);
}

void ADVi3pp::stop_and_wait()
{
    _3dlabs.stop_and_wait();
}

void ADVi3pp::process_command(const GCodeParser& parser)
{
    _3dlabs.process_command(parser);
}

double ADVi3pp::x_probe_offset_from_extruder()
{
    return sensor_settings.x_probe_offset_from_extruder();
}

double ADVi3pp::y_probe_offset_from_extruder()
{
    return sensor_settings.y_probe_offset_from_extruder();
}

int ADVi3pp::left_probe_bed_position()
{
    return sensor_settings.left_probe_bed_position();
}

int ADVi3pp::right_probe_bed_position()
{
    return sensor_settings.right_probe_bed_position();
}

int ADVi3pp::front_probe_bed_position()
{
    return sensor_settings.front_probe_bed_position();
}

int ADVi3pp::back_probe_bed_position()
{
    return sensor_settings.back_probe_bed_position();
}

// --------------------------------------------------------------------

}
