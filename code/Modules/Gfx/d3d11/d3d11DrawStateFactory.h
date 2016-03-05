#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::d3d11DrawStateFactory
    @ingroup _priv
    @brief D3D11 implementation of drawStateFactory
*/
#include "Gfx/Resource/drawStateFactoryBase.h"
#include "Core/Containers/Map.h"
#include "Gfx/d3d11/d3d11_decl.h"

namespace Oryol {
namespace _priv {

class d3d11DrawStateFactory : public drawStateFactoryBase {
public:
    /// destructor
    ~d3d11DrawStateFactory();

    /// setup the factory
    void Setup(const gfxPointers& ptrs);
    /// discard the factory
    void Discard();
    /// setup drawState resource
    ResourceState::Code SetupResource(drawState& ds);
    /// destroy the drawState
    void DestroyResource(drawState& ds);

private:
    /// create or return existing input layout object
    ID3D11InputLayout* createInputLayout(const drawState& ds);

    ID3D11Device* d3d11Device = nullptr;
};

} // namespace _priv
} // namespace Oryol

