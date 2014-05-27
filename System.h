/*
SHT2x - Library for the SHT2x series of Sensirion sensors.

Copyright 2012 Eduard Iten

Supported devices:
SHT20*
SHT21
SHT25

*The SHT20 has not been tested so far, but should work according
the Sensirion datasheet. If anyone can confirm this, please report.

This library is free software, it is released under the GNU GPL v3.
Please find the terms and conditions in the attached gpl.txt or
in the world wide web: <http://www.gnu.org/licenses/>

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
or check in the web: <http://www.gnu.org/licenses/>
*/

#ifndef SYSTEMUTILITIES_H
#define SYSTEMUTILITIES_H

#include <inttypes.h>
#include <Wire.h>
#include "Energia.h"


class SystemClass {
public:
	uint16_t getVCC();
	void sleep(uint16_t duration);
private:

};

extern SystemClass System;

#endif
