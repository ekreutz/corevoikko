/* Libvoikko: Finnish spellchecker and hyphenator library
 * Copyright (C) 2010 Harri Pitkänen <hatapitk@iki.fi>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *********************************************************************************/

#include "character/SimpleChar.hpp"

namespace libvoikko { namespace character {

wchar_t SimpleChar::lower(wchar_t input) {
	// Basic Latin
	if (input >= 0x41 && input <= 0x5A) {
		// A-Z
		return input + 0x20;
	}
	// Latin-1 Supplement
	if (input >= 0xC0 && input <= 0xD6) {
		// À-Ö
		return input + 0x20;
	}
	if (input >= 0xD8 && input <= 0xDD) {
		// Ø-Ý
		return input + 0x20;
	}
	// Latin Extended-A
	if (input >= 0x0100 && input <= 0x0136 && input % 2 == 0) {
		// Ā-Ķ
		return input + 1;
	}
	if (input >= 0x0139 && input <= 0x0147 && input % 2 == 1) {
		// Ĺ-Ň
		return input + 1;
	}
	if (input >= 0x014A && input <= 0x0176 && input % 2 == 0) {
		// Ŋ-Ŷ
		return input + 1;
	}
	if (input >= 0x0179 && input <= 0x017D && input % 2 == 1) {
		// Ź-Ž
		return input + 1;
	}
	// TODO: other Unicode character ranges are not yet mapped
	return input;
}

bool SimpleChar::isUpper(wchar_t input) {
	return input != lower(input);
}

} }
