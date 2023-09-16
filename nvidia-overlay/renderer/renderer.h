#pragma once
#include "internal.h"
#include "../utils/vec2.h"
#include "../utils/fnv.h"
#include <unordered_map>


namespace renderer { // ��������� ��������
	// @note: es3n1n: if you are scared of stl n shit then you can hardcode all colors/fonts in their namespaces

	namespace colors { // ��������� ��������� ������ ������
		inline std::unordered_map<uint32_t, ID2D1SolidColorBrush*> _colors = {}; // ������ ��� ����������� ������ ������� ��������� ������������������� ��������� � ������ ������ ������� ��� ����32 � ����� ���� ������� ������������ ������� �������� ������ ��������� _������

		ID2D1SolidColorBrush* get( uint32_t col ); // ���������� ������� ��� ������� ���������� ��� ����� ���� �� ���� ������������ ������� �������� ������ �������� ��� ���� ��� ����32 � ��������� ��� ������ ����� ��� ��� �����
		utils::e_status shutdown( ); // ���������� ������� ������� � ��������� ����� � ���������� �������� � ������
	}

	namespace fonts { // ������������ ��� �����
		inline std::unordered_map<uint32_t,  IDWriteTextFormat*> _fonts = {}; // ����������� ���� �������� � ��������� ���� ��������, ��� ����32� � IDWriteTextFormat ��� ��������� ������� ��������� �������� ������ � ������

		IDWriteTextFormat* get( const char* name, float size ); // ���������� ������� ���, ������� ���������� �������������� ��������������������, ��������� �������� ���� ������ ���� ��� ��� � ������ ��� �������
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

	utils::e_status init( ); // ���������� ������� ����� � ������ �������
	utils::e_status shutdown( ); // ���������� ������� ������� � ������ �������
}


#define COL_GET( hex_code ) ::renderer::colors::get( hex_code )
#define FONT_GET( font_name, font_size_float ) ::renderer::fonts::get( font_name, font_size_float )
