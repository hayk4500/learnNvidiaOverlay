#pragma once
#include "internal.h"
#include "../utils/vec2.h"
#include "../utils/fnv.h"
#include <unordered_map>


namespace renderer { // неймспейс рендеред
	// @note: es3n1n: if you are scared of stl n shit then you can hardcode all colors/fonts in their namespaces

	namespace colors { // вложенный неймспейс рендер калорс
		inline std::unordered_map<uint32_t, ID2D1SolidColorBrush*> _colors = {}; // короче это стандартный шаблон который управляет последовательностую элементов в данном случае задание тип юинт32 и солид бруш который закрашиывает область сплощным цветом назвазние _колорс

		ID2D1SolidColorBrush* get( uint32_t col ); // обьявление функции гет которая возврашает тип солид бруш то есть закрашивание области сплошным цветом аргумент тут один это юинт32 с названием кол скорее всего это код цвета
		utils::e_status shutdown( ); // обьявление функции шутдаун в нейспейсе утилс и возврашает значение е статус
	}

	namespace fonts { // пространство имёт фонтс
		inline std::unordered_map<uint32_t,  IDWriteTextFormat*> _fonts = {}; // стандартная либа шаблонов с привязкой ключ значение, тип юинт32т и IDWriteTextFormat это интерфейс который описывает свойства шрифта и абзаца

		IDWriteTextFormat* get( const char* name, float size ); // обьявление функции гет, которая возвращает разименователь айдиврафттекстформат, принимате аргумент ытип констр чара как имя и флоата как размера
		utils::e_status shutdown( );
	}

	namespace scene {
		void start( ); // alias for begin() & clear()
		void begin( );
		void end( );
		void clear( );

		void text( utils::vec2 pos, const wchar_t* text, ID2D1SolidColorBrush* color, IDWriteTextFormat* font );

		void shutdown( );
	}

	utils::e_status init( ); // обьявление функции инита в статус утилсов
	utils::e_status shutdown( ); // обьявление функции шутдаун в статус утилсов
}


#define COL_GET( hex_code ) ::renderer::colors::get( hex_code )
#define FONT_GET( font_name, font_size_float ) ::renderer::fonts::get( font_name, font_size_float )
