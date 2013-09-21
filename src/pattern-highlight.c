/* -*- mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* config.c - configuration loading/saving via gnome-config routines

   Copyright (C) 2013 Mislav Blažević

   GHex is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   GHex is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GHex; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "gtkhex.h"

void gtk_hex_highlight_pattern(GtkHex* gh);

void gtk_hex_highlight_pattern(GtkHex* gh)
{
	gint start_pos, end_pos;
	guchar *text;

	start_pos = MIN(gh->selection.start, gh->selection.end);
	end_pos = MAX(gh->selection.start, gh->selection.end);
	gtk_hex_delete_autohighlight(gh, gh->pattern_highlight);
	if (start_pos == end_pos)
	{
		gh->pattern_highlight = NULL;
		return;
	}
	text = hex_document_get_data(gh->document, start_pos, end_pos - start_pos);
	gh->pattern_highlight = gtk_hex_insert_autohighlight(gh, text, end_pos - start_pos, "red");
	g_free(text);
}
