#include "renderer.h"


namespace renderer { // неймспей рендера
	utils::e_status init( ) { // инит функция в неймспейса рендер утилс
		TRACE_FN; // логгирование

		L_ASSERT( internal::init( ), "failed to init internal render stuff" ); // ассерт функции интернал инита, выведет сообщение при оштбке

		return utils::e_status::status_ok;
	}

	utils::e_status shutdown( ) {
		TRACE_FN;

		scene::shutdown( );
		L_ASSERT( internal::shutdown( ), "failed to shutdown internal render stuff" );
		L_ASSERT( colors::shutdown( ), "failed to shutdown colors" );
		L_ASSERT( fonts::shutdown( ), "failed to shutdown colors" );

		return utils::e_status::status_ok;
	}
}
