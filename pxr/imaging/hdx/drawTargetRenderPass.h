//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_IMAGING_HDX_DRAW_TARGET_RENDER_PASS_H
#define PXR_IMAGING_HDX_DRAW_TARGET_RENDER_PASS_H

#include "pxr/pxr.h"
#include "pxr/imaging/hdx/api.h"
#include "pxr/imaging/hdSt/renderPass.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdStDrawTargetRenderPassState;
class HdRprimCollection;

/// \class HdxDrawTargetRenderPass
///
/// Represents a render pass that renders to AOVs and camera specified in the
/// HdStDrawTargetRenderPassState 
///
/// \note This is a temporary API to aid transition to Hydra, and is subject
/// to major changes.  It is likely this functionality will be absorbed into
/// the base class.
///
class HdxDrawTargetRenderPass final {
public:
    HDX_API
    HdxDrawTargetRenderPass(HdRenderIndex *index);
    HDX_API
    ~HdxDrawTargetRenderPass();

    /// Sets the non-context dependent state.  The object is expected to
    /// live longer than this class.
    HDX_API
    void SetDrawTargetRenderPassState(
        const HdStDrawTargetRenderPassState *renderPassState);

    /// Sets the collection of rprims associated to this render pass.
    HDX_API
    void SetRprimCollection(HdRprimCollection const& col);

    /// Sync the draw target render pass
    HDX_API
    void Sync();

    /// Prepare the draw target render pass
    HDX_API
    void Prepare();

    /// Execute the draw target render pass
    HDX_API
    void Execute(HdRenderPassStateSharedPtr const &renderPassState,
                 TfTokenVector const &renderTags);

private:
    /// RenderPass
    HdSt_RenderPass _renderPass;

    /// drawtarget renderPass state
    const HdStDrawTargetRenderPassState *_drawTargetRenderPassState;
    unsigned int         _collectionObjectVersion;

    // No default/copy
    HdxDrawTargetRenderPass()                                            = delete;
    HdxDrawTargetRenderPass(const HdxDrawTargetRenderPass &)             = delete;
    HdxDrawTargetRenderPass &operator =(const HdxDrawTargetRenderPass &) = delete;
};


PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_IMAGING_HDX_DRAW_TARGET_RENDER_PASS_H
