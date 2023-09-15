#pragma once
#include "../logger/logger.h"
#include <d2d1.h>
#include <stdio.h>
#include <dwmapi.h> 
#pragma comment(lib, "Dwmapi.lib") 


namespace overlay { // неймспкйс оверлей
	namespace vars { // вложенный неймспейс варс
		inline HWND m_window_hwnd; // определение хендла м виндов 
		inline RECT m_window_rect; // определение пр€моугольника окна виндов рект
		inline D2D1_SIZE_U m_window_size; // специальна€ переменна€ из директ2д котора€ помогает хранить значени€ размера пр€моугольника
	}

	utils::e_status init( ); // инициализаиц€ функции инит в неймспейпе оверле€
}
