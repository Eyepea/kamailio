/*
 * $Id$
 * This file is part of SIP-router, a free SIP server.
 *
 * SIP-router is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * SIP-router is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*!
 * \file 
 * \brief Rtpengine :: Configuration
 * \ingroup Rtpengine
 */


#include "../../cfg/cfg.h"
#include "../../parser/msg_parser.h" /* method types */

#include "config.h"

struct cfg_group_rtpengine	default_rtpengine_cfg = {
		60,	/* default disable timeout in seconds */
		1000,	/* default wait timeout in milliseconds */
		MAX_RTPP_TRIED_NODES,
        5, /* rtprengine retries */
	    };

void	*rtpengine_cfg = &default_rtpengine_cfg;

cfg_def_t	rtpengine_cfg_def[] = {
	{"rtpengine_disable_tout",	CFG_VAR_INT | CFG_ATOMIC, 	0, 0, 0, 0,
		"The time after which rtpengine will try to communicate to an RTP proxy after it has been marked disabled automatically. "},
	{"rtpengine_tout_ms",		CFG_VAR_INT | CFG_ATOMIC, 	0, 0, 0, 0,
		"The total number of nodes inside a set to be queried before giving up establishing a session"},
	{"queried_nodes_limit",     CFG_VAR_INT | CFG_ATOMIC,   0, MAX_RTPP_TRIED_NODES, 0, 0,
		"Timeout value expressed in milliseconds in waiting for reply from RTP proxy"},
	{"rtpengine_retr",	CFG_VAR_INT | CFG_ATOMIC,	0, 0, 0, 0,
		"How many times the module should retry to send and receive after timeout was generated"},
	{0, 0, 0, 0, 0, 0}
};