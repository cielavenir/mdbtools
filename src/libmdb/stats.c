/* MDB Tools - A library for reading MS Access database files
 * Copyright (C) 2000 Brian Bruns
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "mdbtools.h"

/**
 * @brief Begins collection of statistics on an MDBHandle.
 * @param mdb: Handle to the (open) MDB file to collect stats on.
 *
 *
 * Statistics in LibMDB will track the number of reads from the MDB file.  The
 * collection of statistics is started and stopped with the mdb_stats_on and
 * mdb_stats_off functions.  Collected statistics are accessed by reading the
 * MdbStatistics structure or calling mdb_dump_stats.
 * 
 */
void
mdb_stats_on(MdbHandle *mdb)
{
	if (!mdb->stats) 
		mdb->stats = g_malloc0(sizeof(MdbStatistics));

	mdb->stats->collect = TRUE;
}
/**
 * @brief Turns off statistics collection.
 * @param mdb: pointer to handle of MDB file with active stats collection.
 *
 *
 * If mdb_stats_off() is not called, statistics will be turned off when handle
 * is freed using mdb_close().
 **/
void
mdb_stats_off(MdbHandle *mdb)
{
	if (!mdb->stats) return;

	mdb->stats->collect = FALSE;
}
/**
 * @brief Dumps current statistics to stdout.
 * @param mdb: pointer to handle of MDB file with active stats collection.
 *
 *
 **/
void
mdb_dump_stats(MdbHandle *mdb)
{
	if (!mdb->stats) return;

	fprintf(stdout, "Physical Page Reads: %lu\n", mdb->stats->pg_reads);
}
