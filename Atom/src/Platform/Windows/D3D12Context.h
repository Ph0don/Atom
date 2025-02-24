#pragma once

#include "GraphicsContext.h"
#include "Win32Window.h"

#include <memory>

#include <wrl.h>
#include <dxgi.h>
#include <d3d12.h>

using Microsoft::WRL::ComPtr;

namespace atom
{

    class D3D12Context : GraphicsContext
    {
    public:
        D3D12Context(std::shared_ptr<Win32Window> window);
        D3D12Context() = delete;

        virtual void StartFrame()override;
        virtual void EndFrame()override;

    private:
        std::shared_ptr<Win32Window> m_Window;

        static constexpr int c_NumFrames = 3;
        
        UINT m_FrameIndex = 0;

        ComPtr<ID3D12Device> m_Device;
        ComPtr<ID3D12DescriptorHeap> m_rtvDescriptorHeap;
        ComPtr<ID3D12DescriptorHeap> m_srvDescriptorHeap;
        ComPtr<ID3D12CommandQueue> m_DirectCommandQueue;
        ComPtr<ID3D12GraphicsCommandList> m_DirectCommandList;
        ComPtr<ID3D12Fence> m_Fence;
        HANDLE m_FenceEvent;


    };

}