#include "internal.h"


namespace renderer { // неймспейс рендере
	namespace internal { // неймспейма интернала
		utils::e_status init( ) { // утилс тип функции инит, определение функции инита
			TRACE_FN; // логгирование

			L_ASSERT( !FAILED( // ассерт НЕ ФАЙИЛЕД, этот файлед вообще из стандартной либы
				D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_d2d ) 
			), "failed to create render factory" );
			L_ASSERT( !FAILED( 
				DWriteCreateFactory( 
					DWRITE_FACTORY_TYPE_SHARED, 
					__uuidof( IDWriteFactory ), 
					reinterpret_cast< IUnknown** >( ( &m_factory ) )
				) 
			), "failed to create factory" );

			L_ASSERT( !FAILED( m_d2d->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties( 
					D2D1_RENDER_TARGET_TYPE_DEFAULT,
					D2D1::PixelFormat( DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED )
				),
				D2D1::HwndRenderTargetProperties(
					overlay::vars::m_window_hwnd,
					overlay::vars::m_window_size
				),
				&m_render_target
			) ), "failed to create render target" );

			return utils::e_status::status_ok;
		}

		utils::e_status shutdown( ) {
			TRACE_FN;

			m_d2d->Release( );
			m_factory->Release( );
			m_render_target->Release( );

			return utils::e_status::status_ok;
		}
	}
}