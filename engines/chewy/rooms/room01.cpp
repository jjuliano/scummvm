/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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

#include "chewy/defines.h"
#include "chewy/events.h"
#include "chewy/globals.h"
#include "chewy/room.h"
#include "chewy/rooms/room01.h"

namespace Chewy {
namespace Rooms {

void Room1::gottenCard() {
	_G(det)->hideStaticSpr(2);
	startSetAILWait(4, 1, ANI_FRONT);
	_G(gameState)._personHide[P_CHEWY] = false;
	_G(atds)->delControlBit(7, ATS_COUNT_BIT, ATS_DATA);
}

void Room1::gedAction(int index) {
	#define KABELABDECKUNG 1

	if (index == 0 && !_G(gameState).R2ElectrocutedBork) {
		bool flag = false;
		if (_G(gameState).AkInvent == KABEL_INV) {
			flag = true;
			delInventory(_G(gameState).AkInvent);
		} else if (_G(obj)->checkInventory(KABEL_INV)) {
			flag = true;
			_G(obj)->del_obj_use(KABEL_INV);
			remove_inventory(KABEL_INV);
		}

		if (flag) {
			startAadWait(54);
			_G(atds)->set_ats_str(8, TXT_MARK_LOOK, 0, ATS_DATA);
			_G(gameState).room_s_obj[KABELABDECKUNG].ZustandFlipFlop = 2;
			_G(obj)->calc_rsi_flip_flop(KABELABDECKUNG);
			_G(obj)->calc_all_static_detail();
		}
	}
}

} // namespace Rooms
} // namespace Chewy
