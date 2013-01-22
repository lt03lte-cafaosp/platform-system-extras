/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ext4_utils.h"
#include "wipe.h"

#if defined(__linux__)

#include <linux/fs.h>
#include <sys/ioctl.h>

#ifndef BLKDISCARD
#define BLKDISCARD _IO(0x12,119)
#endif

#ifndef BLKSECDISCARD
#define BLKSECDISCARD _IO(0x12,125)
#endif

#define MAX_DISCARD_BLOCK 0xfff80000ull

int wipe_block_device(int fd, s64 len)
{
	u64 range[2], parm[2];
	u64 offset = 0;
	int ret, rc = 0;

	while (len > 0) {
		parm[0] = range[0] = offset;
		parm[1] = range[1] = (len > MAX_DISCARD_BLOCK) ? MAX_DISCARD_BLOCK : len;
		len -= range[1];
		offset += range[1];

		warn("Wiping from offset %llu for %llu bytes (%lld bytes remaining)", range[0], range[1], len);

		ret = (rc == 0) ? ioctl(fd, BLKSECDISCARD, &range) : -1;
		if (ret < 0) {
			rc = 1;  // indicates secure discard failed
			range[0] = parm[0];
			range[1] = parm[1];
			ret = ioctl(fd, BLKDISCARD, &range);
			if (ret < 0) {
				rc = 2;
				break;
			}
		}
	}

	switch (rc) {
	case 1:
		warn("Wipe via secure discard failed, used discard instead\n");
		break;
	case 2:
		warn("Discard failed\n");
		break;
	default:
		;  // success
	}

	return (rc != 0);
}
#else
int wipe_block_device(int fd, s64 len)
{
	error("wipe not supported on non-linux platforms");
	return 1;
}
#endif

