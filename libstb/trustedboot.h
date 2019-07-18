// SPDX-License-Identifier: Apache-2.0
/* Copyright 2013-2017 IBM Corp. */

#ifndef __TRUSTEDBOOT_H
#define __TRUSTEDBOOT_H

#include <platform.h>

void trustedboot_init(void);

/**
 * As defined in the TCG Platform Firmware Profile specification, the
 * digest of 0xFFFFFFFF or 0x00000000  must be extended in PCR[0-7] and
 * an EV_SEPARATOR event must be recorded in the event log for PCR[0-7]
 * prior to the first invocation of the first Ready to Boot call.
 *
 * This function must be called just before BOOTKERNEL is executed. Every call
 * to trustedboot_measure() will fail afterwards.
 */
int trustedboot_exit_boot_services(void);

/**
 * trustedboot_measure - measure a resource
 * @id    : resource id
 * @buf   : data to be measured
 * @len   : buf length
 *
 * This measures a resource downloaded from PNOR if trusted mode is on. That is,
 * an EV_ACTION event is recorded in the event log for the mapped PCR, and the
 * the sha1 and sha256 measurements are extended in the mapped PCR.
 *
 * For more information please refer to 'doc/stb.rst'
 *
 * returns: 0 or an error as defined in status_codes.h
 */
int trustedboot_measure(enum resource_id id, void *buf, size_t len);

#endif /* __TRUSTEDBOOT_H */
