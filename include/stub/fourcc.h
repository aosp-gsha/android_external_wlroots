/* Reserve 0 for the invalid format specifier */
#define DRM_FORMAT_INVALID	0

/* Vendor Ids: */

#define DRM_FORMAT_MOD_NONE           0
#define DRM_FORMAT_MOD_VENDOR_NONE    0
#define DRM_FORMAT_MOD_VENDOR_INTEL   0x01
#define DRM_FORMAT_MOD_VENDOR_AMD     0x02
#define DRM_FORMAT_MOD_VENDOR_NVIDIA  0x03
#define DRM_FORMAT_MOD_VENDOR_SAMSUNG 0x04
#define DRM_FORMAT_MOD_VENDOR_QCOM    0x05
#define DRM_FORMAT_MOD_VENDOR_VIVANTE 0x06
#define DRM_FORMAT_MOD_VENDOR_BROADCOM 0x07
/* add more to the end as needed */

#define DRM_FORMAT_RESERVED           ((1ULL << 56) - 1)

#define wlr_fourcc_mod_code(vendor, val) \
	((((__u64)DRM_FORMAT_MOD_VENDOR_## vendor) << 56) | ((val) & 0x00ffffffffffffffULL))

/*
 * Format Modifier tokens:
 *
 * When adding a new token please document the layout with a code comment,
 * similar to the fourcc codes above. drm_fourcc.h is considered the
 * authoritative source for all of these.
 */

/*
* Invalid Modifier
*
* This modifier can be used as a sentinel to terminate the format modifiers
* list, or to initialize a variable with an invalid modifier. It might also be
* used to report an error back to userspace for certain APIs.
*/
 
#define DRM_FORMAT_MOD_INVALID  fourcc_mod_code(NONE, DRM_FORMAT_RESERVED)
 
/*
* Linear Layout
*
* Just plain linear layout. Note that this is different from no specifying any
* modifier (e.g. not setting DRM_MODE_FB_MODIFIERS in the DRM_ADDFB2 ioctl),
* which tells the driver to also take driver-internal information into account
* and so might actually result in a tiled framebuffer.
*/
#define DRM_FORMAT_MOD_LINEAR   fourcc_mod_code(NONE, 0)
