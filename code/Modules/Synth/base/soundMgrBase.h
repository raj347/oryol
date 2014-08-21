#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Synth::soundMgrBase
    @brief sound manager base class
*/
#include "Synth/Core/SynthSetup.h"
#include "Synth/Core/item.h"
#include "Synth/Core/generator.h"
#include "Time/TimePoint.h"
#include "Core/Containers/Queue.h"

namespace Oryol {
namespace Synth {
    
class soundMgrBase {
public:
    /// constructor
    soundMgrBase();
    /// destructor
    ~soundMgrBase();
    
    /// setup the sound system
    void Setup(const SynthSetup& setupAttrs);
    /// discard the sound system
    void Discard();
    /// return true if has been setup
    bool IsValid() const;
    
    /// update the sound system
    void Update();
    
    /// start playing a new sound
    void Play(uint32 voice, const Sound& snd, float32 timeOffset);    
    
protected:
    bool isValid;
    SynthSetup setup;
    int32 curTick;
    generator waveGenerator;
};
    
} // namespace Synth
} // namespace Oryol