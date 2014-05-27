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

#include "System.h"


uint16_t SystemClass::getVCC()
{
		analogReference(INTERNAL1V5);
		delay(1);
		uint16_t data = analogRead(A11);
		if (data==0x3ff) {
			analogReference(INTERNAL2V5);
			delay(1);
			data = (uint16_t)map(analogRead(A11), 0, 1023, 0, 5000);
		} 
		else {
			data = (uint16_t)map(data, 0, 1023, 0, 3000);
		}
		return data-1000;  
}


void SystemClass::sleep(uint16_t duration)
{ 
  disableWatchDog();
  TA0CCTL0  = CCIE; // CCR0 interrupt enabled
  TA0CCR0  = duration*8;
  TA0CTL  = TASSEL_1 + MC_1; // SMCLK, contmode
  _BIS_SR(LPM3_bits+GIE);                 // Enter LPM3 w/interrupt
}

#pragma vector=  TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
  _BIC_SR_IRQ(LPM3_bits);                   // Clear LPM3 bits from 0(SR)
  enableWatchDog();
  TA0CCTL0  = 0;
}

SystemClass System;
