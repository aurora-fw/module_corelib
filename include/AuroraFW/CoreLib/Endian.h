/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_CORELIB_ENDIAN_H
#define AURORAFW_CORELIB_ENDIAN_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/CoreLib/Endian.h>

#if defined(AFW_TARGET_KERNEL_LINUX) || defined(AFW_TARGET_CYGWIN)
	#include <endian.h>
#elif defined(AFW_TARGET_PLATFORM_APPLE)
	#include <libkern/OSByteOrder.h>

	#define htobe16(x) OSSwapHostToBigInt16(x)
	#define htole16(x) OSSwapHostToLittleInt16(x)
	#define be16toh(x) OSSwapBigToHostInt16(x)
	#define le16toh(x) OSSwapLittleToHostInt16(x)

	#define htobe32(x) OSSwapHostToBigInt32(x)
	#define htole32(x) OSSwapHostToLittleInt32(x)
	#define be32toh(x) OSSwapBigToHostInt32(x)
	#define le32toh(x) OSSwapLittleToHostInt32(x)

	#define htobe64(x) OSSwapHostToBigInt64(x)
	#define htole64(x) OSSwapHostToLittleInt64(x)
	#define be64toh(x) OSSwapBigToHostInt64(x)
	#define le64toh(x) OSSwapLittleToHostInt64(x)

	#define __BYTE_ORDER BYTE_ORDER
	#define __BIG_ENDIAN BIG_ENDIAN
	#define __LITTLE_ENDIAN LITTLE_ENDIAN
	#define __PDP_ENDIAN PDP_ENDIAN
#elif defined(AFW_TARGET_KERNEL_OPENBSD)
	#include <sys/endian.h>
#elif defined(AFW_TARGET_KERNEL_NETBSD) || defined(AFW_TARGET_KERNEL_FREEBSD) || defined(AFW_TARGET_KERNEL_DRAGONFLY)
	#include <sys/endian.h>
	#define be16toh(x) betoh16(x)
	#define le16toh(x) letoh16(x)

	#define be32toh(x) betoh32(x)
	#define le32toh(x) letoh32(x)

	#define be64toh(x) betoh64(x)
	#define le64toh(x) letoh64(x)
#elif defined(AFW_TARGET_PLATFORM_WINDOWS)
	#include <winsock2.h>
	#include <sys/param.h>

	#if BYTE_ORDER == LITTLE_ENDIAN
		#define htobe16(x) htons(x)
		#define htole16(x) (x)
		#define be16toh(x) ntohs(x)
		#define le16toh(x) (x)

		#define htobe32(x) htonl(x)
		#define htole32(x) (x)
		#define be32toh(x) ntohl(x)
		#define le32toh(x) (x)

		#define htobe64(x) htonll(x)
		#define htole64(x) (x)
		#define be64toh(x) ntohll(x)
		#define le64toh(x) (x)
	#elif BYTE_ORDER == BIG_ENDIAN

		#define htobe16(x) (x)
		#define htole16(x) __builtin_bswap16(x)
		#define be16toh(x) (x)
		#define le16toh(x) __builtin_bswap16(x)

		#define htobe32(x) (x)
		#define htole32(x) __builtin_bswap32(x)
		#define be32toh(x) (x)
		#define le32toh(x) __builtin_bswap32(x)

		#define htobe64(x) (x)
		#define htole64(x) __builtin_bswap64(x)
		#define be64toh(x) (x)
		#define le64toh(x) __builtin_bswap64(x)
	#endif

	#define __BYTE_ORDER BYTE_ORDER
	#define __BIG_ENDIAN BIG_ENDIAN
	#define __LITTLE_ENDIAN LITTLE_ENDIAN
	#define __PDP_ENDIAN PDP_ENDIAN
#endif

#endif // AURORAFW_CORELIB_ENDIAN_H
