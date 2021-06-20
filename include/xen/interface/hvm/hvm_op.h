/* SPDX-License-Identifier: MIT
 *
 * hvm_op.h
 *
 * Copyright (c) 2007, Keir Fraser
 */

#ifndef __XEN_PUBLIC_HVM_HVM_OP_H__
#define __XEN_PUBLIC_HVM_HVM_OP_H__

/* Get/set subcommands: the second argument of the hypercall is a
 * pointer to a xen_hvm_param struct.
 */
#define HVMOP_set_param           0
#define HVMOP_get_param           1
struct xen_hvm_param {
	domid_t  domid;    /* IN */
	u32 index;    /* IN */
	u64 value;    /* IN/OUT */
};

DEFINE_GUEST_HANDLE_STRUCT(xen_hvm_param);

/* Hint from PV drivers for pagetable destruction. */
#define HVMOP_pagetable_dying       9
struct xen_hvm_pagetable_dying {
	/* Domain with a pagetable about to be destroyed. */
	domid_t  domid;
	/* guest physical address of the toplevel pagetable dying */
	aligned_u64 gpa;
};

DEFINE_GUEST_HANDLE_STRUCT(xen_hvm_pagetable_dying);

enum hvmmem_type_t {
	HVMMEM_ram_rw,             /* Normal read/write guest RAM */
	HVMMEM_ram_ro,             /* Read-only; writes are discarded */
	HVMMEM_mmio_dm,            /* Reads and write go to the device model */
};

#define HVMOP_get_mem_type    15
/* Return hvmmem_type_t for the specified pfn. */
struct xen_hvm_get_mem_type {
	/* Domain to be queried. */
	domid_t domid;
	/* OUT variable. */
	u16 mem_type;
	u16 pad[2]; /* align next field on 8-byte boundary */
	/* IN variable. */
	u64 pfn;
};

DEFINE_GUEST_HANDLE_STRUCT(xen_hvm_get_mem_type);

#endif /* __XEN_PUBLIC_HVM_HVM_OP_H__ */
