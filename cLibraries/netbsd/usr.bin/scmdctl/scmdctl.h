/*	$NetBSD: scmdctl.h,v 1.1 2021/12/07 17:39:55 brad Exp $	*/

/*
 * Copyright (c) 2021 Brad Spencer <brad@anduin.eldar.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _SCMDCTL_H_
#define _SCMDCTL_H_

#define SCMD_IDENTIFY 1
#define SCMD_DIAG 2
#define SCMD_MOTOR 3
#define SCMD_SUBMOTORGET 3000
#define SCMD_SUBMOTORSET 3001
#define SCMD_SUBMOTORINVERT 3002
#define SCMD_SUBMOTORBRIDGE 3003
#define SCMD_SUBMOTORDISABLE 3004
#define SCMD_SUBMOTORENABLE 3005
#define SCMD_READ 4
#define SCMD_WRITE 5
#define SCMD_RESTART 6
#define SCMD_ENUMERATE 7
#define SCMD_UPDATERATE 8
#define SCMD_SUBURGET 8000
#define SCMD_SUBURSET 8001
#define SCMD_SUBURFORCE 8002
#define SCMD_EBUS 9
#define SCMD_SUBEBUSGET 9000
#define SCMD_SUBEBUSSET 9001
#define SCMD_LOCK 10
#define SCMD_SUBLOCKGET 10000
#define SCMD_SUBLOCKLOCK 10001
#define SCMD_SUBLOCKUNLOCK 10002
#define SCMD_SPIREADONE 11

#define SCMD_ENABLE 100
#define SCMD_DISABLE 101

#define SCMD_ANY_MODULE 0xff
#define SCMD_ANY_MOTOR 'C'
#define SCMD_NO_MOTOR 0xff00

#define SCMD_LOCAL_USER_LOCK 12000
#define SCMD_LOCAL_MASTER_LOCK 12001
#define SCMD_GLOBAL_USER_LOCK 12002
#define SCMD_GLOBAL_MASTER_LOCK 12003
#define SCMD_LOCK_LOCKED 0x00
#define SCMD_LOCK_UNLOCK 0x01

#define UART_IS_PURE_UART 0
#define UART_IS_SPI_USERLAND 1

struct scmdcmd {
	const char	*cmd;
	const int	id;
	const char	*helpargs;
};

#endif