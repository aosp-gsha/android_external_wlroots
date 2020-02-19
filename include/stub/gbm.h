#define GBM_BO_IMPORT_FD_MODIFIER       0x5504
/**
 * \file gbm.h
 * \brief Generic Buffer Manager
 */

struct gbm_device;
struct gbm_bo;
struct gbm_surface;

struct gbm_import_fd_modifier_data {
   uint32_t width;
   uint32_t height;
   uint32_t format;
   uint32_t num_fds;
   int fds[GBM_MAX_PLANES];
   int strides[GBM_MAX_PLANES];
   int offsets[GBM_MAX_PLANES];
   uint64_t modifier;
};

uint32_t
gbm_bo_get_stride_for_plane(struct gbm_bo *bo, int plane);

uint32_t
gbm_bo_get_offset(struct gbm_bo *bo, int plane);

uint64_t
gbm_bo_get_modifier(struct gbm_bo *bo);

int
gbm_bo_get_plane_count(struct gbm_bo *bo);

union gbm_bo_handle
gbm_bo_get_handle_for_plane(struct gbm_bo *bo, int plane);


struct gbm_surface *
gbm_surface_create_with_modifiers(struct gbm_device *gbm,
                                  uint32_t width, uint32_t height,
                                  uint32_t format,
                                  const uint64_t *modifiers,
                                  const unsigned int count);

