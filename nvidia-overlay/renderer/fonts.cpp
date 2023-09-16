#include "renderer.h"


namespace renderer { // пространство имен рендерер
	namespace fonts { // вложенное пространство имен рендерер фонтс
		IDWriteTextFormat* get( const char* name, float size ) { // определдение функции гета принимает аргумент констр чар и флоат
			char _id[ 256 ]; // массив из символов 256 длинной
			sprintf_s( _id, "%s_%f", name, size ); // спринтует записывает у буфер с айди переменную имя и размер переданных значений
			const uint32_t id = hash::fnv1<uint32_t>::hash( _id ); // инициация айди с типом юинт32т константа, присваиваетс хэш

			if ( _fonts.find( id ) != _fonts.end( ) )
				return _fonts.at( id );

			size_t font_name_size;
			wchar_t font_name[ 100 ];
			mbstowcs_s( &font_name_size, font_name, name, strlen( name ) );  // @note: es3n1n: this shit sucks

			_fonts[ id ] = NULL;
			internal::m_factory->CreateTextFormat(
				font_name, NULL,
				DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"en-us",
				&_fonts.at( id )
			);

			return _fonts[ id ];
		}

		utils::e_status shutdown( ) {
			TRACE_FN;

			for ( auto&& p : _fonts )
				p.second->Release( );  // @note: es3n1n: why would i care, nullptr here is an unexpected behavior!

			return utils::e_status::status_ok;
		}
	}
}