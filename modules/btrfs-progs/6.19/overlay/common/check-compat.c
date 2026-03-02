/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Weak-link defaults for check/ symbols referenced by common/clear-cache.c.
 *
 * clear-cache.c includes check/repair.h and uses two symbols defined in
 * check/repair.c: the global variable opt_check_repair and the function
 * btrfs_mark_used_blocks().  Because //common:common is built with
 * alwayslink=True, clear-cache.o is always pulled into every binary,
 * including test binaries that do not link //check:check_lib.
 *
 * These weak definitions satisfy the linker for such binaries.  When
 * //check:check_lib IS linked (btrfs, mkfs.btrfs, …) the strong definitions
 * in check/repair.c override these automatically.
 */
#include "check/repair.h"

__attribute__((weak)) int opt_check_repair = 0;

__attribute__((weak)) int btrfs_mark_used_blocks(struct btrfs_fs_info *fs_info,
						 struct extent_io_tree *tree)
{
	return 0;
}
