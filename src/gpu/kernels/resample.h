#ifndef __KERNEL_RESAMPLE_H__
#define __KERNEL_RESAMPLE_H__

#include <cuda.h>
#include <cuda_runtime.h>

void resample_perspective_transform(uchar4* result, cudaTextureObject_t text,
                                    const int cols, const int rows,
                                    float* x_pos, float* y_pos, const float* mat3x3,
                                    bool inverse = true, cudaStream_t stream=0);

void resample_mask(unsigned char* result, cudaTextureObject_t text, const int cols,
                   const int rows, const float* x_pos, const float* y_pos,
                   const float threshold=0.5f, cudaStream_t stream=0);

void transform_blend(uchar4 * canvas, const int cw, const int ch,
                     cudaTextureObject_t frame, const int fw, const int fh,
                     const int nw, const int nh, const float* mat3x3,
                     const int tx, const int ty, cudaTextureObject_t frame_mask,
                     float * canvas_wts, cudaTextureObject_t frame_wts, cudaStream_t stream=0);

//!
//! \brief Resample from \c tex to obtain
//! \c undistorted image according to new
//! coordinates \c x and \c y
//! \param tex
//! \param x
//! \param y
//! \param cols
//! \param rows
//! \param undistorted
//! \param stream
//!
void resample_undistort(cudaTextureObject_t tex,
                        const float * x, const float * y,
                        const size_t cols, const size_t rows,
                        float * undistorted,
                        cudaStream_t stream = 0);


#endif
